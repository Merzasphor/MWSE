
--- @type table<string, table>
local luaWidgetTypes = {}

-- Allow elements to make lua widgets.
function tes3uiElement:makeLuaWidget(typeName, data)
	local metatable = assert(luaWidgetTypes[typeName], "No lua widget exists with that type.")

	-- Allow going back to the original element.
	data.element = self

	-- Tell MWSE what kind of widget this is.
	local widget = setmetatable(data, metatable)
	self:setPropertyProperty("is_part", "MWSE:LuaWidget")
	self:setLuaData("MWSE:WidgetData", widget)
	self:setLuaData("MWSE:WidgetTypeName", typeName)

	return widget
end

-- Allow defining custom lua widgets.
function tes3ui.defineLuaWidget(params)
	assert(params, "No parameters provided.")
	assert(type(params.name) == "string", "Invalid 'name' parameter provided.")
	assert(type(params.metatable) == "table", "Invalid 'metatable' parameter provided.")
	assert(luaWidgetTypes[params.name] == nil, "A lua widget of this type has already been defined.")

	luaWidgetTypes[params.name] = params.metatable
end

-- Setup our custom widgets.
dofile("mwse.ui.tes3uiElement.createHyperlink")
dofile("mwse.ui.tes3uiElement.createTextInput")
