--- @meta

--- Provides various OS-specific functions.
--- @class oslib
os = {}

--- Return CPU time since Lua started in seconds.
--- @return number result No description yet available.
function os.clock() end

--- Passes command to be executed by an operating system shell. This will not display a console prompt that interrupts the game.
--- @param command string The command to run.
--- @param async boolean *Default*: `false`. If set to true, the program will be run in a separate thread. The second return value, `executor`, can be used to monitor its execution.
--- @return number exitCode The exit code of the program. If running with `async` and if successful, the exit code will be STILL_ACTIVE (259).
--- @return mwseLuaExecutor|nil executor If running with `async`, and if successful, this is a handle to the executor. This can be used to check if the program has finished running and to get the program's output.
function os.execute(command, async) end

--- Returns the current clipboard text, if any is available.
--- @return string|nil result No description yet available.
function os.getClipboardText() end

--- Sets the current clipboard text. If nil is passed, the clipboard will be cleared instead. If either operation fails, the function returns false.
--- @param text string|nil *Optional*. The text to put in the clipboard. If nil is provided instead, then the clipboard will be cleared.
--- @return boolean result No description yet available.
function os.setClipboardText(text) end

