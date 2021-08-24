--[[
	Displays settings side by side instead of vertically
	Best used for small buttons with no labels
]] --

local Parent = require("mcm.components.categories.Category")

local SideBySideBlock = Parent:new()

function SideBySideBlock:createSubcomponentsContainer(parentBlock)
	Parent.createSubcomponentsContainer(self, parentBlock)
	self.elements.subcomponentsContainer.flowDirection = "left_to_right"
end

return SideBySideBlock
