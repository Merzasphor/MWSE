--
-- ReadTheDocs generator for MWSE-lua definitions.
--

local function log(fmt, ...)
	print (fmt:format(...))
end

local lfs = require("lfs")
local json = require("dkjson")

local definitionsFolder = lfs.currentdir() .. "\\definitions"
log("Definitions folder: %s", definitionsFolder)

function json.loadfile(fileName)
	-- Load the contents of the file.
	local f = io.open(fileName, "r")
	if (f == nil) then
		return nil
	end
	local fileContents = f:read("*all")
	f:close()

	-- Return decoded json.
	return json.decode(fileContents)
end

function json.savefile(fileName, object, config)
	local f = assert(io.open(fileName, "w"))
	f:write(json.encode(object, config))
	f:close()
end

function isTableEmpty(t)
	for _, _ in pairs(t) do
		return false
	end
	return true
end

function table.copy(t, d)
	if (d == nil) then
		d = {}
	elseif (type(t) ~= "table" or type(d) ~= "table") then
		error("Arguments for table.copy must be tables.")
	end

	for k, v in pairs(t) do
		d[k] = v
	end

	return d
end

function table.deepcopy(t)
	local copy = nil
	if type(t) == "table" then
		copy = {}
		for k, v in next, t, nil do
			copy[table.deepcopy(k)] = table.deepcopy(v)
		end
		setmetatable(copy, table.deepcopy(getmetatable(t)))
	else
		copy = t
	end
	return copy
end

local match = string.match
function trimString(s)
   return match(s,'^()%s*$') and '' or match(s,'^%s*(.*%S)')
end

function splitString(inputstr, sep)
	if sep == nil then
		sep = "%s"
	end
	local t={}
	for str in string.gmatch(inputstr, "([^"..sep.."]+)") do
		table.insert(t, str)
	end
	return t
end

local function isDirectory(path)
	if (type(path) ~= "string") then
		return false
	end

	local attributes = lfs.attributes(path)
	return (attributes and attributes.mode == "directory")
end

local standardTypes = {
	["function"] = true,
	["table"] = true,
	["number"] = true,
	["boolean"] = true,
	["string"] = true,
	["unknown"] = true,
	["ref"] = true,
}

local rstHeaders = {
	"====================================================================================================",
	"----------------------------------------------------------------------------------------------------",
	"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
}

local typeLinks = {
	tes3actor = "lua/type/tes3/actor",
	tes3equipmentStack = "lua/type/tes3/equipmentStack",
	tes3mobileActor = "lua/type/tes3/mobileActor",
	tes3reference = "lua/type/tes3/reference",
}

-- 
-- Events
-- 

local function buildEvent(folder, key)
	-- Load our base package.
	local path = folder .. "\\" .. key .. ".lua"
	log("Building event: " .. key .. " ...")
	local package = dofile(path)

	-- Open the output file.
	local outPath = "..\\docs\\source\\lua\\event\\" .. key .. ".rst"
	local file = io.open(outPath, "w")

	-- Write out the main header.
	file:write(key .. "\n" .. rstHeaders[1] .. "\n\n")

	-- Print out the main description.
	local packagePath = folder .. "\\" .. key .. "\\"
	if (lfs.attributes(packagePath .. "\\" .. "description.rst", "mode") == "file") then
		local rstFilePath = packagePath .. "description.rst"
		local rstFile = io.open(rstFilePath, "r")
		file:write(trimString(rstFile:read("*a")) .. "\n\n")
		rstFile:close()
	elseif (package.description) then
		file:write(package.description .. "\n\n")
	else
		file:write("No description is currently available for this event." .. "\n\n")
	end

	-- Write out event data.
	if (package.eventData) then
		file:write("Event Data\n" .. rstHeaders[2] .. "\n\n")
		for k, v in pairs(package.eventData) do
			file:write(k .. "\n" .. rstHeaders[3] .. "\n\n")

			if (typeLinks[v.type]) then
				file:write("`" .. v.type .. "`_. ")
			else
				file:write(v.type .. ". ")
			end

			if (v.readonly) then
				file:write("Read-only. ")
			end

			file:write(v.description .. "\n\n")
		end
	end

	-- Write out examples.
	if (package.examples) then
		file:write("Examples\n" .. rstHeaders[2] .. "\n\n")
		for k, v in pairs(package.examples) do
			file:write((v.title or k) .. "\n" .. rstHeaders[3] .. "\n\n")

			if (v.description) then
				file:write(v.description .. "\n\n")
			end

			file:write(".. code-block:: " .. (v.language or "lua") .. "\n\n")

			local exampleFilePath = packagePath .. k .. "." .. (v.extension or "lua")
			for line in io.lines(exampleFilePath) do
				if (trimString(line) ~= "") then
					file:write("    " .. line:gsub("\t", "    ") .. "\n")
				else
					file:write("\n")
				end
			end
			file:write("\n\n")
		end
	end

	-- Write out any link information.
	if (package.links) then
		for k, v in pairs(package.links) do
			file:write(".. _`" .. k .. "`: ../../" .. v .. ".html\n")
		end
	end

	-- Also write out all our type links.
	for k, v in pairs(typeLinks) do
		file:write(".. _`" .. k .. "`: ../../" .. v .. ".html\n")
	end

	-- Close up shop.
	file:close()
end

for entry in lfs.dir(definitionsFolder .. "\\events\\standard") do
	local extension = entry:match("[^.]+$")
	if (extension == "lua") then
		buildEvent(definitionsFolder .. "\\events\\standard", entry:match("[^/]+$"):sub(1, -1 * (#extension + 2)))
	end
end

-- 
-- API
-- 

local function getStandardizedReturn(raw)
	if (type(raw.valuetype) == "string") then
		return { { type = raw.valuetype } }
	elseif (type(raw.returns) == "table") then
		local returns = {}

		for _, v in pairs(raw.returns) do
			table.insert(returns, { type = v.type })
		end

		if (#returns == 0) then
			return nil
		end

		return returns
	end
end

local function breakoutMultipleTypes(str)
	return "`" .. table.concat(splitString(str, "|"), "`_, `") .. "`_"
end

local function buildAPIEntryForFunction(package)
	local key = package.key
	local folder = package.folder
	local parent = package.parent
	parent.functions = parent.functions or {}
	table.insert(parent.functions, package)

	-- Open the output file.
	local outPath = "..\\docs\\source\\lua\\api\\" .. parent.key .. "\\" .. key .. ".rst"
	local file = io.open(outPath, "w")

	-- Write out the main header.
	file:write(parent.key .. "." .. key .. "\n" .. rstHeaders[1] .. "\n\n")

	-- Print out the main description.
	local packagePath = folder .. "\\" .. key .. "\\"
	if (lfs.attributes(packagePath .. "\\" .. "description.rst", "mode") == "file") then
		local rstFilePath = packagePath .. "description.rst"
		local rstFile = io.open(rstFilePath, "r")
		file:write(trimString(rstFile:read("*a")) .. "\n\n")
		rstFile:close()
	elseif (package.description) then
		file:write(package.description .. "\n\n")
	else
		file:write("No description is currently available." .. "\n\n")
	end

	-- Print out the return value.
	local returns = getStandardizedReturn(package)
	if (lfs.attributes(packagePath .. "\\" .. "returns.rst", "mode") == "file") then
		file:write("Returns\n" .. rstHeaders[2] .. "\n\n")
		local rstFilePath = packagePath .. "returns.rst"
		local rstFile = io.open(rstFilePath, "r")
		file:write(trimString(rstFile:read("*a")) .. "\n\n")
		rstFile:close()
	elseif (returns) then
		file:write("Returns\n" .. rstHeaders[2] .. "\n\n")
		for _, r in pairs(returns) do
			if (r.description) then
				file:write("`" .. r.type .. "`_. " .. r.description .. "\n\n")
			else
				file:write("`" .. r.type .. "`_.\n\n")
			end
		end
	end

	-- Print out parameters.
	if (package.arguments) then
		file:write("Parameters\n" .. rstHeaders[2] .. "\n\n")
		if (type(package.arguments) == "table" and #package.arguments == 1 and package.arguments[1].tableParams) then
			-- Add it to the description.
			file:write("Accepts parameters through a table with the given keys:\n\n")
			for _, param in pairs(package.arguments[1].tableParams) do
				file:write("**" .. (param.name or "...") .. "** (" .. breakoutMultipleTypes(param.type) .. ")\n")
				file:write("    ")
				if (param.default) then
					file:write("Default: ``" .. tostring(param.default) .. "``")
				elseif (param.optional) then
					file:write("Optional")
				end
				if (param.description) then
					if (param.default or param.optional) then
						file:write(". " .. param.description .. "\n\n")
					else
						file:write(param.description .. "\n\n")
					end
				else
					if (param.default or param.optional) then
						file:write(". No description available.\n\n")
					else
						file:write("No description available.\n\n")
					end
				end
			end
		else
			for _, param in ipairs(package.arguments) do
				file:write("**" .. (param.name or "...") .. "** (" .. breakoutMultipleTypes(param.type) .. ")\n")
				file:write("    ")
				if (param.default) then
					file:write("Default: ``" .. tostring(param.default) .. "``")
				elseif (param.optional) then
					file:write("Optional.")
				end
				if (param.description) then
					if (param.default or param.optional) then
						file:write(". " .. param.description .. "\n\n")
					else
						file:write(param.description .. "\n\n")
					end
				else
					file:write("No description available.\n\n")
				end
			end
		end
	end

	-- Write out examples.
	if (package.examples) then
		file:write("Examples\n" .. rstHeaders[2] .. "\n\n")
		for k, v in pairs(package.examples) do
			file:write((v.title or k) .. "\n" .. rstHeaders[3] .. "\n\n")

			if (v.description) then
				file:write(v.description .. "\n\n")
			end

			file:write(".. code-block:: " .. (v.language or "lua") .. "\n\n")

			local exampleFilePath = packagePath .. k .. "." .. (v.extension or "lua")
			for line in io.lines(exampleFilePath) do
				if (trimString(line) ~= "") then
					file:write("    " .. line:gsub("\t", "    ") .. "\n")
				else
					file:write("\n")
				end
			end
			file:write("\n\n")
		end
	end

	-- Write out any link information.
	if (package.links) then
		for k, v in pairs(package.links) do
			file:write(".. _`" .. k .. "`: ../../" .. v .. ".html\n")
		end
	end

	-- Also write out all our type links.
	for k, v in pairs(typeLinks) do
		file:write(".. _`" .. k .. "`: ../../" .. v .. ".html\n")
	end

	-- Close up shop.
	file:close()
end

local function buildAPIEntryForValue(package)
	local key = package.key
	local folder = package.folder
	local parent = package.parent
	parent.values = parent.values or {}
	table.insert(parent.values, package)

	-- Open the output file.
	local outPath = "..\\docs\\source\\lua\\api\\" .. parent.key .. "\\" .. key .. ".rst"
	local file = io.open(outPath, "w")

	-- Write out the main header.
	file:write(parent.key .. "." .. key .. "\n" .. rstHeaders[1] .. "\n\n")

	-- Print out the main description.
	local packagePath = folder .. "\\" .. key .. "\\"
	if (lfs.attributes(packagePath .. "\\" .. "description.rst", "mode") == "file") then
		local rstFilePath = packagePath .. "description.rst"
		local rstFile = io.open(rstFilePath, "r")
		file:write(trimString(rstFile:read("*a")) .. "\n\n")
		rstFile:close()
	elseif (package.description) then
		if (package.valuetype) then
			file:write(breakoutMultipleTypes(package.valuetype) .. ". " .. package.description .. "\n\n")
		else
			file:write(package.description .. "\n\n")
		end
	else
		file:write("No description is currently available." .. "\n\n")
	end

	-- Write out examples.
	if (package.examples) then
		file:write("Examples\n" .. rstHeaders[2] .. "\n\n")
		for k, v in pairs(package.examples) do
			file:write((v.title or k) .. "\n" .. rstHeaders[3] .. "\n\n")

			if (v.description) then
				file:write(v.description .. "\n\n")
			end

			file:write(".. code-block:: " .. (v.language or "lua") .. "\n\n")

			local exampleFilePath = packagePath .. k .. "." .. (v.extension or "lua")
			for line in io.lines(exampleFilePath) do
				if (trimString(line) ~= "") then
					file:write("    " .. line:gsub("\t", "    ") .. "\n")
				else
					file:write("\n")
				end
			end
			file:write("\n\n")
		end
	end

	-- Write out any link information.
	if (package.links) then
		for k, v in pairs(package.links) do
			file:write(".. _`" .. k .. "`: ../../" .. v .. ".html\n")
		end
	end

	-- Also write out all our type links.
	for k, v in pairs(typeLinks) do
		file:write(".. _`" .. k .. "`: ../../" .. v .. ".html\n")
	end

	-- Close up shop.
	file:close()
end

local apiEntryDispatchers = {
	["function"] = buildAPIEntryForFunction,
	["value"] = buildAPIEntryForValue,
}

local function buildAPIEntry(folder, key, parent)
	-- Load our base package.
	local path = folder .. "\\" .. key .. ".lua"
	local package = dofile(path)
	package.key = key
	package.folder = folder
	package.parent = parent

	local dispatch = apiEntryDispatchers[package.type]
	if (dispatch == nil) then
		log("%s: No dispatcher found for type: %s", path, package.type)
		return
	end

	dispatch(package)
end

local function buildAPI(folder, key)
	-- Load our base package.
	local path = folder .. "\\" .. key .. ".lua"
	log("Building API: " .. key .. " ...")
	local package = dofile(path)
	package.key = key

	-- We only care about libraries for now.
	if (package.type ~= "lib") then
		return
	end

	-- Open the output file.
	local outPath = "..\\docs\\source\\lua\\api\\" .. key .. ".rst"
	local file = io.open(outPath, "w")

	-- Write out the main header.
	file:write(key .. "\n" .. rstHeaders[1] .. "\n\n")

	-- Write description.
	file:write((package.description .. "\n\n") or "No description yet available.\n\n")

	-- Create a folder for children.
	lfs.mkdir("..\\docs\\source\\lua\\api\\" .. key)

	-- Write out children.
	for entry in lfs.dir(folder .. "\\" .. key) do
		local extension = entry:match("[^.]+$")
		if (extension == "lua") then
			buildAPIEntry(folder .. "\\" .. key, entry:match("[^/]+$"):sub(1, -1 * (#extension + 2)), package)
		end
	end

	-- Write TOCs.
	if (package.values) then
		file:write("Values\n" .. rstHeaders[2] .. "\n\n")
		file:write(".. toctree::\n    :maxdepth: 1\n\n")
		for _, k in pairs(package.values) do
			file:write("    " .. key .. "/" .. k.key .. "\n")
		end
		file:write("\n")
	end
	if (package.functions) then
		file:write("Functions\n" .. rstHeaders[2] .. "\n\n")
		file:write(".. toctree::\n    :maxdepth: 1\n\n")
		for _, k in pairs(package.functions) do
			file:write("    " .. key .. "/" .. k.key .. "\n")
		end
		file:write("\n")
	end

	-- Close up shop.
	file:close()
end

for entry in lfs.dir(definitionsFolder .. "\\global") do
	local extension = entry:match("[^.]+$")
	if (extension == "lua") then
		buildAPI(definitionsFolder .. "\\global", entry:match("[^/]+$"):sub(1, -1 * (#extension + 2)))
	end
end

-- 
-- Named Types
-- 

local function buildNamedTypeEntryForValue(package)
	local key = package.key
	local folder = package.folder
	local parent = package.parent
	parent.values = parent.values or {}
	table.insert(parent.values, package)

	-- Open the output file.
	local outPath = "..\\docs\\source\\lua\\type\\" .. parent.key .. "\\" .. key .. ".rst"
	local file = io.open(outPath, "w")

	-- Write out the main header.
	file:write(parent.key .. "." .. key .. "\n" .. rstHeaders[1] .. "\n\n")

	-- Print out the main description.
	local packagePath = folder .. "\\" .. key .. "\\"
	if (lfs.attributes(packagePath .. "\\" .. "description.rst", "mode") == "file") then
		local rstFilePath = packagePath .. "description.rst"
		local rstFile = io.open(rstFilePath, "r")
		file:write(trimString(rstFile:read("*a")) .. "\n\n")
		rstFile:close()
	elseif (package.description) then
		if (package.valuetype) then
			file:write(breakoutMultipleTypes(package.valuetype) .. ". " .. package.description .. "\n\n")
		else
			file:write(package.description .. "\n\n")
		end
	else
		file:write("No description is currently available." .. "\n\n")
	end

	-- Write out examples.
	if (package.examples) then
		file:write("Examples\n" .. rstHeaders[2] .. "\n\n")
		for k, v in pairs(package.examples) do
			file:write((v.title or k) .. "\n" .. rstHeaders[3] .. "\n\n")

			if (v.description) then
				file:write(v.description .. "\n\n")
			end

			file:write(".. code-block:: " .. (v.language or "lua") .. "\n\n")

			local exampleFilePath = packagePath .. k .. "." .. (v.extension or "lua")
			for line in io.lines(exampleFilePath) do
				if (trimString(line) ~= "") then
					file:write("    " .. line:gsub("\t", "    ") .. "\n")
				else
					file:write("\n")
				end
			end
			file:write("\n\n")
		end
	end

	-- Write out any link information.
	if (package.links) then
		for k, v in pairs(package.links) do
			file:write(".. _`" .. k .. "`: ../../" .. v .. ".html\n")
		end
	end

	-- Also write out all our type links.
	for k, v in pairs(typeLinks) do
		file:write(".. _`" .. k .. "`: ../../" .. v .. ".html\n")
	end

	-- Close up shop.
	file:close()
end

local typeEntryDispatchers = {
	["value"] = buildNamedTypeEntryForValue,
}

local function buildNamedTypeEntry(folder, key, parent)
	-- Load our base package.
	local path = folder .. "\\" .. key .. ".lua"
	local package = dofile(path)
	package.key = key
	package.folder = folder
	package.parent = parent

	local dispatch = typeEntryDispatchers[package.type]
	if (dispatch == nil) then
		log("%s: No dispatcher found for type: %s", path, package.type)
		return
	end

	dispatch(package)
end

local builtTypes = {}

local function buildInheritedTable(package, type)
	local result = {}

	-- 
	if (package.inherits) then
		result = buildInheritedTable(builtTypes[package.inherits], type) or {}
	end

	-- 
	if (package[type]) then
		for k, v in ipairs(package[type]) do
			result[v.key] = package
		end
	end

	-- If we have anything in the table, return it, otherwise give back nil.
	for _, _ in pairs(result) do
		return result
	end
	return nil
end

local function buildNamedType(folder, key)
	-- Load our base package.
	local path = folder .. "\\" .. key .. ".lua"
	log("Building type: " .. key .. " ...")
	local package = dofile(path)
	package.key = key
	builtTypes[key] = package

	-- We only care about libraries for now.
	if (package.type ~= "class") then
		log("%s: Skipping type '%s'", path, key)
		return
	end

	-- Handle inherited class.
	if (package.inherits and not builtTypes[package.inherits]) then
		buildNamedType(folder, package.inherits)
	end

	-- Open the output file.
	local outPath = "..\\docs\\source\\lua\\type\\" .. key .. ".rst"
	local file = io.open(outPath, "w")

	-- Write out the main header.
	file:write(key .. "\n" .. rstHeaders[1] .. "\n\n")

	-- Write description.
	file:write((package.description .. "\n\n") or "No description yet available.\n\n")

	-- Create a folder for children.
	lfs.mkdir("..\\docs\\source\\lua\\type\\" .. key)

	-- Write out children.
	for entry in lfs.dir(folder .. "\\" .. key) do
		local extension = entry:match("[^.]+$")
		if (extension == "lua") then
			buildNamedTypeEntry(folder .. "\\" .. key, entry:match("[^/]+$"):sub(1, -1 * (#extension + 2)), package)
		end
	end

	-- Write TOCs.
	local fullValues = buildInheritedTable(package, "values")
	if (fullValues) then
		file:write("Values\n" .. rstHeaders[2] .. "\n\n")
		file:write(".. toctree::\n    :maxdepth: 1\n\n")
		for k, v in pairs(fullValues) do
			file:write("    " .. v.key .. "/" .. k .. "\n")
		end
		file:write("\n")
	end
	local fullMethods = buildInheritedTable(package, "methods")
	if (fullMethods) then
		file:write("Methods\n" .. rstHeaders[2] .. "\n\n")
		file:write(".. toctree::\n    :maxdepth: 1\n\n")
		for _, k in pairs(fullMethods) do
			file:write("    " .. key .. "/" .. k.key .. "\n")
		end
		file:write("\n")
	end
	local fullFunctions = buildInheritedTable(package, "functions")
	if (fullFunctions) then
		file:write("Functions\n" .. rstHeaders[2] .. "\n\n")
		file:write(".. toctree::\n    :maxdepth: 1\n\n")
		for _, k in pairs(fullFunctions) do
			file:write("    " .. key .. "/" .. k.key .. "\n")
		end
		file:write("\n")
	end

	-- Close up shop.
	file:close()
end

for entry in lfs.dir(definitionsFolder .. "\\namedTypes") do
	local extension = entry:match("[^.]+$")
	if (extension == "lua") then
		buildNamedType(definitionsFolder .. "\\namedTypes", entry:match("[^/]+$"):sub(1, -1 * (#extension + 2)))
	end
end
