-- require lua files from "Data Files\MWSE\lua"
package.path = "./Data Files/MWSE/lua/libs/?.lua;./Data Files/MWSE/lua/?.lua;"

-- Load tes3 global.
_G.tes3 = require("tes3.init")

-- Other global libraries.
_G.json = require("json")

print("MWSE Lua interface initialized.")
