local Parent = require("mcm.components.pages.Page")

local MouseOverPage = Parent:new()
MouseOverPage.noScroll = true
function MouseOverPage:createMouseOverBlock(parentBlock)
	local mouseOverBlock = parentBlock:createBlock({ id = tes3ui.registerID("MouseOver_MouseoverBlock") })
	mouseOverBlock.flowDirection = "top_to_bottom"
	mouseOverBlock.autoHeight = true
	mouseOverBlock.widthProportional = 1.0
	self.elements.mouseOverBlock = mouseOverBlock
end

--[[function MouseOverPage:createOuterContainer(parentBlock)
	local page = parentBlock:createThinBorder({ id = tes3ui.registerID("MouseOver_thinBorder") })
	page.heightProportional = 1.0
	page.widthProportional = 1.0
	page.flowDirection = "top_to_bottom"
	page.paddingTop = self.indent + 4
	page.paddingLeft = self.indent + 4


	local outerContainer = page:createBlock({ id = tes3ui.registerID("MouseOverOuterContainer") })
	outerContainer.flowDirection = "top_to_bottom"
	--outerContainer.autoHeight = true
	outerContainer.heightProportional = 1.0
	outerContainer.widthProportional = 1.0
	outerContainer.paddingLeft = self.indent
	outerContainer.paddingTop = self.indent

	self.elements.outerContainer = outerContainer

end]]--

function MouseOverPage:createContentsContainer(parentBlock)
	self:createLabel(parentBlock)
	self:createInnerContainer(parentBlock)
	self:createMouseOverBlock(self.elements.innerContainer)
	self:createSubcomponentsContainer(self.elements.innerContainer)
	self:createSubcomponents(self.elements.subcomponentsContainer, self.components)

	parentBlock:getTopLevelParent():updateLayout()
end

return MouseOverPage
