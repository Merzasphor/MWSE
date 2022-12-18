#include "WindowMain.h"

#include "LogUtil.h"
#include "MemoryUtil.h"

#include "Settings.h"

#include "CSDataHandler.h"
#include "CSGameFile.h"
#include "CSRecordHandler.h"

#include "NICamera.h"
#include "NIVector3.h"

#include "DialogRenderWindow.h"

namespace se::cs::window::main {
	using namespace se::memory;

	//
	// Patch: Throttle UI status updates.
	//

	static auto last2ndClassUpdateTime = std::chrono::milliseconds::zero();
	const auto TES3CS_UpdateStatusMessage = reinterpret_cast<void(__cdecl*)(WPARAM, LPARAM)>(0x46E680);
	void __cdecl PatchThrottleMessageUpdate(WPARAM type, LPARAM lParam) {
		if (type == 2) {
			const auto now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch());
			const auto msSinceLastUpdate = now - last2ndClassUpdateTime;
			if (msSinceLastUpdate.count() < 20) {
				return;
			}
			last2ndClassUpdateTime = now;
		}
		else {
			last2ndClassUpdateTime = std::chrono::milliseconds::zero();
		}
		TES3CS_UpdateStatusMessage(type, lParam);
	}

	//
	// Patch: Extend window messages.
	//

	bool blockNormalExecution = false;
	bool isQuickStarting = false;

	void onFinishInitialization(LPARAM& lParam) {
		// Skip any QuickStart usage if we were given a file to load.
		char* commandLineFile = (char*)0x6CE6CC;
		if (*commandLineFile != '\0') {
			return;
		}

		// We can also skip if the enabled 
		if (!settings.quickstart.enabled || settings.quickstart.data_files.empty()) {
			return;
		}

		auto dataHandler = DataHandler::get();
		auto recordHandler = dataHandler->recordHandler;

		std::unordered_set<std::string> toLoadSet;
		for (const auto& master : settings.quickstart.data_files) {
			toLoadSet.insert(master);
		}

		// Flag any game files as marked to load.
		for (auto itt = recordHandler->availableDataFiles->head; itt; itt = itt->next) {
			auto gameFile = itt->data;
			if (toLoadSet.find(gameFile->fileName) != toLoadSet.end()) {
				gameFile->setToLoadFlag(true);
			}
		}

		std::string mainFileToLoad = settings.quickstart.active_file;
		if (mainFileToLoad.empty()) {
			mainFileToLoad = settings.quickstart.data_files.back();
		}
		strncpy_s(commandLineFile, 0x224, mainFileToLoad.c_str(), mainFileToLoad.length());

		isQuickStarting = true;
	}

	void loadQuickStartCell() {
		if (!isQuickStarting) {
			return;
		}

		// Load position from settings. We need to shift down by 16,384 units because of the weird offset in the function.
		const auto& qsPos = settings.quickstart.position;
		NI::Vector3 position(qsPos[0], qsPos[1], qsPos[2]);
		position.z -= 16384.0f;

		auto dataHandler = DataHandler::get();
		auto renderController = dialog::render_window::RenderController::get();

		// Check to see if we're loading an interior cell.
		const auto& cellID = settings.quickstart.cell;
		if (!cellID.empty()) {
			auto cell = dataHandler->recordHandler->getCellByID(cellID.c_str());
			if (cell == nullptr) {
				return;
			}

			const auto setToLoadCell = reinterpret_cast<bool(__thiscall*)(DataHandler*, Cell*, NI::Vector3*)>(0x4A1370);
			setToLoadCell(dataHandler, cell, &position);
		}

		// Actually perform the loading.
		const auto loadCell = reinterpret_cast<bool(__cdecl*)(NI::Vector3*, Reference*)>(0x469B40);
		loadCell(&position, nullptr);

		// Setup orientation.
		const auto& qsRot = settings.quickstart.orientation;
		NI::Matrix33 rotationMatrix;
		rotationMatrix.fromEulerXYZ(qsRot[0], qsRot[1], qsRot[2]);
		renderController->node->setLocalRotationMatrix(&rotationMatrix);
		renderController->node->update();

		isQuickStarting = false;
	}

	LRESULT CALLBACK PatchDialogProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		blockNormalExecution = false;

		// Handle pre-patches.
		switch (msg) {
		case CUSTOM_WM_FINISH_INITIALIZATION:
			onFinishInitialization(lParam);
			break;
		}

		if (blockNormalExecution) {
			return TRUE;
		}

		// Call original function.
		const auto CS_MainWindowDialogProc = reinterpret_cast<WNDPROC>(0x444590);
		auto result = CS_MainWindowDialogProc(hWnd, msg, wParam, lParam);

		// Handle post-patches.
		switch (msg) {
		case 0xC0DE:
			loadQuickStartCell();
			break;
		}

		return result;
	}

	void installPatches() {
		// Patch: Throttle UI status updates.
		genJumpEnforced(0x404881, 0x46E680, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));

		// Patch: Extend window messages.
		genJumpEnforced(0x401EF1, 0x444590, reinterpret_cast<DWORD>(PatchDialogProc));
	}
}