--- @meta

--- This is an extension of Lua Debug library.
--- @class debuglib
--- @field logCache table An table containing all the output values of `debug.log()`. The table index is `path` with the line number appended, while the table key is the message.
debug = {}

--- Logs a message to `MWSE.log` file. The output format is `[path] "msg" = msg`, where the `path` is the path and line at which the function was called.
--- @param value string The message to log.
--- @return string value No description yet available.
function debug.log(value) end

