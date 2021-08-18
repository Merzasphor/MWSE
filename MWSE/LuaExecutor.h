#pragma once

namespace mwse::lua {
	class LuaExecutor : public std::enable_shared_from_this<LuaExecutor> {
	public:
		LuaExecutor(const char* _command);
		~LuaExecutor();

		HRESULT start();

		bool isValid() const;
		sol::optional<DWORD> getExitCode() const;
		DWORD getErrorCode() const;

		void wait() const;
		bool ready() const;

		std::string getCommand() const;
		std::string getOutput();

		static void defineLuaBindings();

	private:
		static void keepSharedPointerAliveUntilExit(std::shared_ptr<LuaExecutor> executor);

		static DWORD __stdcall readDataFromExtProgram(void* argh);

		// Handles for reading program output.
		HANDLE handleStdOutRead;
		HANDLE handleStdOutWrite;

		// The handle to the created process.
		HANDLE handleCreatedProcess;
		HANDLE handleCreatedThread;

		// The command that is queued to be run.
		std::string command;

		// The error code that the command returned.
		DWORD errorCode;

		// Async future responsible for keeping the LuaExecutor alive until the background program exits.
		std::future<void> backgroundAliveFuture;

		// Stream that builds stdout output as the command runs.
		std::stringstream outputBuilder;
		std::mutex outputBuilderMutex;
	};
}
