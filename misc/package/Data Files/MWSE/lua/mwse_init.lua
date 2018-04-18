-- require lua files from "Data Files\MWSE\lua"
package.path = "./Data Files/MWSE/lua/libs/?.lua;./Data Files/MWSE/lua/?.lua;"

-- Load tes3 global.
_G.tes3 = require("tes3.init")

-- Other global libraries.
_G.json = require("json")

-------------------------------------------------
-- Extend table API
-------------------------------------------------

function table.length(T)
	local count = 0
	for _ in pairs(T) do count = count + 1 end
	return count
end

print("MWSE Lua interface initialized.")
