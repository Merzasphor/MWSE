-- Converter table for a GMST's type to something more user-friendly.
local typeNames = {
	s = "string",
	i = "integer",
	f = "float",
}

-- Write our markdown header.
local f = assert(io.open("Data Files\\MWSE\\tmp\\GMSTs.md", "w"))
f:write("# GMSTs\n\n")
f:write("Index | Type    | Identifier                       | Default Value\n")
f:write("----- | ------- | -------------------------------- | --------------------------------------------\n")

-- Go through all our GMSTs...
for id = 0, 1520 do
	-- Write out most of the info.
	local gmst = tes3.findGMST(id)
	f:write(string.format("%-5d | %-7s | %-32s | ", gmst.index, typeNames[gmst.type], gmst.id))

	-- Customize how the value is written based on its type.
	if (gmst.type == "s") then
		-- Remove linebreaks and escape them.
		local value = gmst.defaultValue
		value = string.gsub(value, "\r", "\\r")
		value = string.gsub(value, "\n", "\\n")
		f:write(string.format("`\"%s\"`", value))
	elseif (gmst.type == "f") then
		f:write(string.format("`%.4f`", gmst.defaultValue))
	else
		f:write(string.format("`%d`", gmst.defaultValue))
	end

	f:write("\n")
end

-- Close up our file.
f:close()