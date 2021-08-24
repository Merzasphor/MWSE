--[[
	Info field that shows mouseover information for settings
]]--

local Parent = require("mcm.components.infos.Info")

local MouseOverInfo = Parent:new()
MouseOverInfo.triggerOn = "MCM:MouseOver"
MouseOverInfo.triggerOff = "MCM:MouseLeave"

function MouseOverInfo:updateInfo(component)
	-- If component has a description, update mouseOver
	-- Or return to original text on mouseLeave
	local newText = (component and component.description or self.text or "")
	self.elements.info.text = newText
	self:update()
end

function MouseOverInfo:makeComponent(parentBlock)

	Parent.makeComponent(self, parentBlock)
	local info = self.elements.info

	local function updateInfo(component)
		self:updateInfo(component)
	end

	-- Register events
	event.register(self.triggerOn, updateInfo)
	event.register(self.triggerOff, updateInfo)
	parentBlock:register("destroy", function()
		event.unregister(self.triggerOn, updateInfo)
		event.unregister(self.triggerOff, updateInfo)
	end)
	self:updateInfo()
end

return MouseOverInfo
