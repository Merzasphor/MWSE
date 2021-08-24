--[[
	YesNoButton: Toggles a variable between true and false, showing "On" or "Off" 
	in the button text

]]--

-- Parent class
local Parent = require("mcm.components.settings.Button")

-- Class object
local YesNoButton = Parent:new()
YesNoButton.defaultSetting = false

function YesNoButton:getText()
	local text = (self.variable.value and tes3.findGMST(tes3.gmst.sYes).value or tes3.findGMST(tes3.gmst.sNo).value)
	return text
end

function YesNoButton:press()
	-- Toggle variable
	self.variable.value = not self.variable.value
	-- Set button text
	self:setText(self:getText())
	-- Do this after changing the variable so the callback is correct
	self:update()
end

return YesNoButton
