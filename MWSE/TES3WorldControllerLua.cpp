#include "TES3WorldControllerLua.h"

#include "LuaManager.h"

#include "TES3WorldController.h"

#include "TES3GlobalVariable.h"
#include "TES3InputController.h"
#include "TES3Script.h"
#include "TES3WeatherController.h"

namespace mwse {
	namespace lua {
		void bindTES3WorldController() {
			sol::state& state = LuaManager::getInstance().getState();

			state.new_usertype<TES3::WorldController>("TES3WorldController",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"maxFPS", &TES3::WorldController::maxFPS,
				"systemTime", &TES3::WorldController::systemTimeMillis,
				"lastFrameTime", &TES3::WorldController::lastFrameTimeMillis,
				"deltaTime", &TES3::WorldController::deltaTime,

				// "audio", &TES3::WorldController::audio,
				"inputController", &TES3::WorldController::inputController,
				"scriptGlobals", &TES3::WorldController::scriptGlobals,
				"weatherController", &TES3::WorldController::weatherController,
				// "mobController", &TES3::WorldController::mobController,
				// "splashController", &TES3::WorldController::splashController,
				// "journalController", &TES3::WorldController::journalController,

				// "spllistActiveSpells", &TES3::WorldController::spllistActiveSpells,

				"viewWidth", &TES3::WorldController::viewWidth,
				"viewHeight", &TES3::WorldController::viewHeight,

				"difficulty", &TES3::WorldController::difficulty,
				"aiDistance", &TES3::WorldController::aiDistance,

				"shadows", &TES3::WorldController::bShadows,

				"helpDelay", &TES3::WorldController::helpDelay,
				"hudStyle", &TES3::WorldController::hudStyle,
				"menuAlpha", &TES3::WorldController::menuAlpha,
				"cursorOff", &TES3::WorldController::bCursorOff,

				"werewolfFOV", &TES3::WorldController::werewolfFOV,

				"projectionDistance", &TES3::WorldController::projectionDistance,

				"hour", &TES3::WorldController::gvarGameHour,
				"year", &TES3::WorldController::gvarYear,
				"month", &TES3::WorldController::gvarMonth,
				"day", &TES3::WorldController::gvarDay,
				"daysPassed", &TES3::WorldController::gvarDaysPassed,
				"timescale", &TES3::WorldController::gvarTimescale,
				"charGenState", &TES3::WorldController::gvarCharGenState,
				"monthsToRespawn", &TES3::WorldController::gvarMonthsToRespawn,

				"parentWindowHandle", &TES3::WorldController::Win32_hWndParent,
				"windowHandle", &TES3::WorldController::Win32_hWnd,
				"instance", &TES3::WorldController::Win32_hInstance,

				"flagEventMenuModeOn", &TES3::WorldController::flagEventMenuModeOn,
				"flagEventMenuModeOff", &TES3::WorldController::flagEventMenuModeOff,
				"flagMenuMode", &TES3::WorldController::flagMenuMode,
				"flagTeleportingDisabled", &TES3::WorldController::flagTeleportingDisabled,
				"flagLevitationDisabled", &TES3::WorldController::flagLevitationDisabled,
				"useBestAttack", &TES3::WorldController::bUseBestAttack,
				"canQuickSaveAndRest", &TES3::WorldController::bQuickSaveRest,
				"shaderWaterReflectTerrain", &TES3::WorldController::shaderWaterReflectTerrain,

				"mouseSensitivityX", &TES3::WorldController::horzSensitivity,
				"mouseSensitivityY", &TES3::WorldController::mouseSensitivity,

				"shaderWaterReflectUpdate", &TES3::WorldController::shaderWaterReflectUpdate,

				"nodeCursor", &TES3::WorldController::nodeCursor,
				"camSplashscreen", &TES3::WorldController::camSplashscreen,
				"camWorld", &TES3::WorldController::camWorld,
				"characterRenderTarget", &TES3::WorldController::characterRenderTarget,
				"fogOfWarController", &TES3::WorldController::fogOfWarController,
				"menuController", &TES3::WorldController::menuController,
				"uiInventoryData", &TES3::WorldController::uiInventoryData,
				"deadFloatScale", &TES3::WorldController::deadFloatScale,
				"lstGlobalScripts", &TES3::WorldController::lstGlobalScripts,
				"listAllActors", &TES3::WorldController::listAllActors,
				"listChargableItems", &TES3::WorldController::listChargableItems,
				"bSubtitles", &TES3::WorldController::bSubtitles,
				"countMusicTracksBattle", &TES3::WorldController::countMusicTracksBattle,
				"countMusicTracksExplore", &TES3::WorldController::countMusicTracksExplore,
				"musicState", &TES3::WorldController::musicState

				);
		}
	}
}
