--[[
	An Info is a component that does not have children and can not be
	interacted with. This includes things suchj as text boxes, 
	hyperlinks and images. 

	The default behaviour of an Info is a text box with word wrapping.

	As this uses word wrap, it is strongly recommended you include a propHeight
	value for all parent categories and pages to ensure wrapping works correctly
]]--

local Parent = require("mcm.components.settings.Setting")

local Info = Parent:new()
Info.componentType = "Info"
Info.text = ""
-- CONTROL METHODS

function Info:disable()
	Parent.disable(self)
	self.elements.info.color = tes3ui.getPalette("disabled_color")
end

function Info:update()
	if self.variable and self.variable.value then
		self.text = tostring(self.variable.value)
	end
end
-- UI METHODS

function Info:makeComponent(parentBlock)
	local info = parentBlock:createLabel({ id = tes3ui.registerID("Info") })
	info.borderRight = self.indent -- * 2
	info.wrapText = true
	info.text = self.text
	info.autoHeight = true
	info.autoWidth = true
	info.widthProportional = 1.0

	self.elements.info = info
	table.insert(self.mouseOvers, info)
	self:update()
	info:getTopLevelParent():updateLayout()
end

return Info
