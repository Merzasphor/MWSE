--
-- mkdocs generator for MWSE-lua definitions.
--

local lfs = require("lfs")
local common = require("builders.common")

common.log("Starting build of mkdocs source files...")

-- Recreate meta folder.
local docsSourceFolder = lfs.join(common.pathAutocomplete, "..\\docs\\source")
lfs.remakedir(lfs.join(docsSourceFolder, "apis"))
lfs.remakedir(lfs.join(docsSourceFolder, "types"))
lfs.remakedir(lfs.join(docsSourceFolder, "events"))

-- Base containers to hold our compiled data.
local libraries = {}
local classes = {}
local events = {}


--
-- Utility functions.
--

common.log("Definitions folder: %s", common.pathDefinitions)


--
-- Compile data
--

common.compilePath(lfs.join(common.pathDefinitions, "global"), libraries, "lib")
common.compilePath(lfs.join(common.pathDefinitions, "namedTypes"), classes, "class")
common.compilePath(lfs.join(common.pathDefinitions, "events", "standard"), events, "event")


--
-- Building
--

local function buildParentChain(className)
	local package = assert(classes[className])
	local ret = ""
	if (classes[className]) then
		ret = string.format("[%s](../../types/%s)", className, className)
	else
		ret = className
	end
	if (package.inherits) then
		ret = ret .. ", " .. buildParentChain(package.inherits)
	end
	return ret
end

local function breakoutTypeLinks(type)
	local types = {}
	for _, t in ipairs(string.split(type, "|")) do
		if (classes[t]) then
			table.insert(types, string.format("[%s](../../types/%s)", t, t))
		else
			table.insert(types, t)
		end
	end
	return table.concat(types, ", ")
end

--- comment
--- @param package table
--- @param field any
--- @param results any
--- @return table
local function getPackageComponentsDictionary(package, field, results)
	results = results or {}

	local onThis = package[field]
	if (onThis) then
		for k, v in pairs(onThis) do
			if (results[k] == nil) then
				results[k] = v
			end
		end
	end

	if (package.inherits and classes[package.inherits]) then
		return getPackageComponentsDictionary(classes[package.inherits], field, results)
	end

	return results
end

--- comment
--- @param package table
--- @param field any
--- @param results any
--- @return table
local function getPackageComponentsArray(package, field, results)
	results = results or {}

	local onThis = package[field]
	if (onThis) then
		for _, v in ipairs(table.values(onThis)) do
			if (results[v.key] == nil) then
				results[v.key] = v
			end
		end
	end

	if (package.inherits and classes[package.inherits]) then
		return getPackageComponentsArray(classes[package.inherits], field, results)
	end

	return results
end

local function sortPackagesByKey(A, B)
	return A.key:lower() < B.key:lower()
end

local function writeArgument(file, argument, indent)
	indent = indent or ""

	file:write(string.format("%s* `%s`", indent, argument.name or "unnamed"))

	if (argument.type) then
		file:write(string.format(" (%s)", breakoutTypeLinks(argument.type)))
	end

	if (argument.description) then
		file:write(string.format(": %s", argument.description))
	end

	file:write("\n")

	if (argument.tableParams) then
		for _, tableArg in ipairs(argument.tableParams) do
			writeArgument(file, tableArg, "\t" .. indent)
		end
	end
end

local function getArgumentCode(argument)
	if (argument.tableParams) then
		local tableArgs = {}
		for _, arg in ipairs(argument.tableParams) do
			table.insert(tableArgs, string.format("%s = ...", arg.name))
		end
		return string.format("{ %s }", table.concat(tableArgs, ", "))
	end
	return argument.name or "unknown"
end

local function writeSubPackage(file, package, from)
	local key = package.key
	if (from.type == "lib") then
		key = string.format("%s.%s", from.namespace, package.key)
	end
	file:write(string.format("### `%s`\n\n", key))

	file:write(string.format("%s\n\n", package.description or common.defaultNoDescriptionText))

	local returns = common.getConsistentReturnValues(package)
	if (package.type == "method" or package.type == "function") then
		file:write(string.format("```lua\n",  package.namespace))
		if (returns) then
			local returnNames = {}
			for i, ret in ipairs(returns) do
				table.insert(returnNames, ret.name or string.format("unnamed%d", i))
			end
			file:write(string.format("local %s = ", table.concat(returnNames, ", ")))
		end
		file:write(string.format("%s%s%s(", package.parent.namespace, package.type == "method" and ":" or ".", package.key))
		if (package.arguments) then
			local args = {}
			for _, arg in pairs(package.arguments) do
				table.insert(args, getArgumentCode(arg))
			end
			file:write(table.concat(args, ", "))
		end
		file:write(string.format(")\n```\n\n", package.namespace))
	end

	if (package.arguments) then
		file:write(string.format("**Parameters**:\n\n"))
		for _, argument in ipairs(package.arguments) do
			writeArgument(file, argument, "")
		end
		file:write("\n")
	end

	if (returns) then
		file:write(string.format("**Returns**:\n\n"))
		for _, ret in ipairs(returns) do
			writeArgument(file, ret, "")
		end
		file:write("\n")
	end

	if (package.examples) then
		local exampleKeys = table.keys(package.examples, true)
		for _, name in ipairs(exampleKeys) do
			local example = package.examples[name]
			file:write(string.format("??? example \"Example: %s\"\n\n", example.title or name))
			file:write(string.format("\t```lua\n"))
			for line in io.lines(lfs.join(package.folder, package.key, name .. ".lua")) do
				file:write(string.format("\t%s\n", line))
			end
			file:write(string.format("\n\t```\n\n"))
		end
	end
end

local typeToDirectory = {
	class = "types",
	event = "events",
	lib = "apis",
}

local function build(package)
	-- Load our base package.
	common.log("Building " .. package.type .. ": " .. package.namespace .. " ...")

	-- Get the package.
	local outPath = lfs.join(docsSourceFolder, typeToDirectory[package.type], package.namespace .. ".md")
	local file = assert(io.open(outPath, "w"))

	file:write(string.format("# %s\n\n", package.namespace))

	-- Write description.
	file:write(string.format("%s\n\n", package.description or common.defaultNoDescriptionText))
	if (package.type == "class" and package.inherits) then
		file:write(string.format("This type inherits the following: %s\n", buildParentChain(package.inherits)))
	elseif (package.type == "event") then
		file:write(string.format("```lua\n--- @param e %sEventData\nlocal function %sCallback(e)\nend\nevent.register(\"%s\", %sCallback)\n```\n\n", package.key, package.key, package.key, package.key))
		if (package.filter) then
			file:write(string.format("!!! tip\n\tThis event can be filtered based on the **`%s`** event data.\n\n", package.filter))
		end
		if (package.blockable) then
			file:write("!!! tip\n\tThis event supports blocking by setting `e.block` to `true` or returning `false`. Blocking the event prevents vanilla behavior from happening. For example, blocking an `equip` event prevents the item from being equipped.\n\n")
		end
		file:write("!!! tip\n\tAn event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.\n\n")
	end

	-- Write out fields.
	local values = table.values(getPackageComponentsArray(package, "values"), sortPackagesByKey)
	if (#values > 0) then
		file:write("## Properties\n\n")
		for _, value in ipairs(values) do
			writeSubPackage(file, value, package)
			file:write("***\n\n")
		end
	end

	-- Write out methods.
	local methods = table.values(getPackageComponentsArray(package, "methods"), sortPackagesByKey)
	if (#methods > 0) then
		file:write("## Methods\n\n")
		for _, method in ipairs(methods) do
			writeSubPackage(file, method, package)
			file:write("***\n\n")
		end
	end

	-- Write out functions.
	local functions = table.values(getPackageComponentsArray(package, "functions"), sortPackagesByKey)
	if (#functions > 0) then
		file:write("## Functions\n\n")
		for _, fn in ipairs(functions) do
			writeSubPackage(file, fn, package)
			file:write("***\n\n")
		end
	end

	-- Events are more top-level, need to do special handling...
	if (package.type == "event") then
		-- Write out event data.
		if (package.eventData) then
			file:write("## Event Data\n\n")
			local eventDataKeys = table.keys(package.eventData, true)
			for _, key in ipairs(eventDataKeys) do
				local data = package.eventData[key]
				data.name = key
				writeArgument(file, data)
			end
			file:write("\n")
		end

		-- Write out examples.
		if (package.examples) then
			file:write("## Examples\n\n")
			local exampleKeys = table.keys(package.examples, true)
			for _, filename in ipairs(exampleKeys) do
				local example = package.examples[filename]
				file:write(string.format("!!! example \"Example: %s\"\n\n", example.title or filename))
				file:write(string.format("\t```lua\n"))
				for line in io.lines(lfs.join(package.folder, package.key, filename .. ".lua")) do
					file:write(string.format("\t%s\n", line))
				end
				file:write(string.format("\n\t```\n\n"))
			end
		end
	end

	-- Ensure that sub-libraries are built.
	if (package.libs) then
		for _, lib in ipairs(package.libs) do
			build(lib)
		end
	end

	-- Close up shop.
	file:close()
end

for _, package in pairs(libraries) do
	build(package)
end

for _, package in pairs(classes) do
	build(package)
end

for _, package in pairs(events) do
	build(package)
end

--
-- Custom file setup.
--

-- Add our .pages files for retitling directories.
io.createwith(lfs.join(docsSourceFolder, "apis", ".pages"), "title: APIs")
