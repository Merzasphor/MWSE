--
-- mkdocs generator for MWSE-lua definitions.
--

local lfs = require("lfs")
local common = require("builders.common")

common.log("Starting build of mkdocs source files...")

-- Recreate meta folder.
local docsSourceFolder = lfs.join(common.pathAutocomplete, "..\\docs\\source")
lfs.remakedir(lfs.join(docsSourceFolder, "apis"))
-- lfs.remakedir(lfs.join(docsSourceFolder, "events"))
-- lfs.remakedir(lfs.join(docsSourceFolder, "types"))

-- Base containers to hold our compiled data.
local libraries = {}
local classes = {}


--
-- Utility functions.
--

common.log("Definitions folder: %s", common.pathDefinitions)


--
-- Compile data
--

common.compilePath(lfs.join(common.pathDefinitions, "global"), libraries, "lib")
-- common.compilePath(lfs.join(common.pathDefinitions, "namedTypes"), classes, "class")


--
-- Building
--

local function buildParentChain(className)
	local package = assert(classes[className])
	if (package.inherits) then
		return className .. ", " .. buildParentChain(package.inherits)
	end
	return className
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
		file:write(string.format("%s(", package.namespace))
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
		for name, example in pairs(package.examples) do
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
	end

	-- Write out fields.
	if (package.values) then
		file:write("## Properties\n\n")
		for _, value in ipairs(package.values) do
			writeSubPackage(file, value, package)
			file:write("***\n\n")
		end
	end

	-- Write out methods.
	if (package.type == "class" and package.methods) then
		file:write("## Methods\n\n")
		for _, method in ipairs(package.methods) do
			writeSubPackage(file, method, package)
			file:write("***\n\n")
		end
	end

	-- Write out functions.
	if (package.functions) then
		file:write("## Functions\n\n")
		for _, fn in ipairs(package.functions) do
			writeSubPackage(file, fn, package)
			file:write("***\n\n")
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
	-- build(package)
end

--
-- Custom file setup.
--

-- Add our .pages files for sorting directories.
do
	local file = io.open(lfs.join(docsSourceFolder, "apis", ".pages"), "w")
	file:write("title: APIs")
	file:close()
end
