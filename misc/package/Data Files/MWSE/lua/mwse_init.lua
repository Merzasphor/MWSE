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

function table.find(t, n)
	for i, v in pairs(t) do
		if (v == n) then
			return i
		end
	end
end

function table.removevalue(t, v)
	local i = table.find(t, v)
	if (i ~= nil) then
		table.remove(t, i)
	end
end

-------------------------------------------------
-- Extend API: string
-------------------------------------------------

function string.startswith(haystack, needle)
	return string.sub(haystack, 1, string.len(needle)) == needle
end

function string.endswith(haystack, needle)
	return needle=='' or string.sub(haystack, -string.len(needle)) == needle
end

-- Report that we're initialized.
print("MWSE Lua interface initialized.")
