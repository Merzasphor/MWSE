--[[
	A setting is a component that can be interacted with, such as a button or text input. 
	It can have, but doesn't require, an associated variable.
]]--

local Parent = require("mcm.components.Component")
local Setting = Parent:new()
Setting.componentType = "Setting"
Setting.restartRequired = false
Setting.restartRequiredMessage = mwse.mcm.i18n("The game must be restarted before this change will come into effect.")

function Setting:new(data)
	local t = Parent:new(data)

	if data and data.variable then
		-- create setting variable
		t.variable.defaultSetting = t.variable.defaultSetting or t.defaultSetting
		local typePath = ("mcm.variables." .. t.variable.class)
		t.variable = require(typePath):new(t.variable)
	end

	setmetatable(t, self)
	self.__index = self
	return t
end

function Setting:update()
	if self.restartRequired then

		tes3.messageBox { message = self.restartRequiredMessage, buttons = { self.sOK } }
	end
	if self.callback then
		self:callback()
	end
end

function Setting:checkDisabled()
	-- For components with no variable
	if self.inGameOnly ~= nil then
		return not tes3.player and self.inGameOnly
	end
	-- Components with variable
	local disabled = (self.variable and self.variable.inGameOnly == true and not tes3.player)
	return disabled
end

function Setting:createContentsContainer(parentBlock)
	self:createLabel(parentBlock)
	self:createInnerContainer(parentBlock)
	self:makeComponent(self.elements.innerContainer)
end

return Setting
