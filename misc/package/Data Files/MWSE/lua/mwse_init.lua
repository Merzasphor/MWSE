-------------------------------------------------
-- Global includes
-------------------------------------------------

-- Require lua files from the right folder, instead of just the root Morrowind directory.
package.path = "./Data Files/MWSE/lua/?.lua;"

_G.tes3 = require("mwse.tes3.init")
_G.event = require("mwse.event")

-------------------------------------------------
-- Extend API: table
-------------------------------------------------

-- The # operator only really makes sense for continuous arrays. Get the real value.
function table.size(t)
	local count = 0
	for _ in pairs(t) do
		count = count + 1
	end
	return count
end

-- Report that we're initialized.
print("MWSE Lua interface initialized.")
