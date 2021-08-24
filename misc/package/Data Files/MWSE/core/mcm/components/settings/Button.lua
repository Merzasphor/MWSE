local Parent = require("mcm.components.settings.Setting")

local Button = Parent:new()
Button.disabledText = "---"
Button.leftSide = true
Button.buttonText = "---"

-- Determines what text is displayed on the button
function Button:getText()
	return self.buttonText
end

function Button:setText(newText)
	self.elements.button.text = newText
end

function Button:disable()
	Parent.disable(self)
	self.elements.button.widget.state = 2
end

function Button:update()
	self:setText(self:getText())
	Parent.update(self)
end

function Button:press()
	self:update()
end

function Button:enable()
	Parent.enable(self)
	self:setText(self:getText())
	self.elements.button:register("mouseClick", function(e)
		self:press()
	end)
end

function Button:makeComponent(parentBlock)
	local buttonText = self.buttonText or self.disabledText
	local button = parentBlock:createButton({ id = tes3ui.registerID("Button"), text = buttonText })
	button.borderAllSides = 0
	button.borderRight = self.indent
	button.autoWidth = true
	self.elements.button = button
	table.insert(self.mouseOvers, button)
end

function Button:createOuterContainer(parentBlock)
	Parent.createOuterContainer(self, parentBlock)
	-- A bit weird but it seems to line buttons up better with other settings
	self.elements.outerContainer.borderTop = self.paddingBottom
	self.elements.outerContainer.borderBottom = 0
	self.elements.outerContainer.flowDirection = "left_to_right"
end

function Button:createInnerContainer(parentBlock)
	Parent.createInnerContainer(self, parentBlock)
	self.elements.innerContainer.paddingLeft = 0
end

function Button:createContentsContainer(parentBlock)
	self:createInnerContainer(parentBlock)
	if self.leftSide then
		self:makeComponent(self.elements.innerContainer)
	end
	self:createLabel(self.elements.innerContainer)
	if not self.leftSide then
		self:makeComponent(self.elements.innerContainer)
	end
end

return Button
