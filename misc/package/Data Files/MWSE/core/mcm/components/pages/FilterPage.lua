local Parent = require("mcm.components.pages.SideBarPage")

local FilterPage = Parent:new()
FilterPage.placeholderSearchText = mwse.mcm.i18n("Search...")

function FilterPage:filterComponents()
	for _, component in ipairs(self.components) do
		-- look for search text inside setting label
		if component.label:lower():find(self.elements.searchBarInput.text:lower()) then
			component.elements.outerContainer.visible = true
		else
			component.elements.outerContainer.visible = false
		end
	end
end

-- UI Methods

function FilterPage:createDescription(parentBlock)
	if self.description then
		local description = parentBlock:createLabel{ text = self.description }
		description.autoHeight = true
		description.widthProportional = 1.0
		description.wrapText = true
		self.elements.description = description
	end
end

function FilterPage:createSearchBar(parentBlock)

	local searchBar = parentBlock:createThinBorder({ id = tes3ui.registerID("PageSearchBar") })
	searchBar.borderBottom = self.indent
	searchBar.autoHeight = true
	searchBar.widthProportional = 1.0

	-- Create the search input
	local input = searchBar:createTextInput({ id = tes3ui.registerID("PageSearchInput") })
	input.color = tes3ui.getPalette("disabled_color")
	input.text = self.placeholderSearchText
	input.borderLeft = 5
	input.borderRight = 5
	input.borderTop = 3
	input.borderBottom = 5
	input.widget.eraseOnFirstKey = true
	input.consumeMouseEvents = false

	-- Get text input straight away
	tes3ui.acquireTextInput(input)
	-- and also on mouseClick
	local function registerInput(element)
		element:register("mouseClick", function()
			tes3ui.acquireTextInput(input)
		end)
	end
	registerInput(input)
	registerInput(searchBar)

	-- Register keypress event to filter list each time
	input:register("keyPress", function(e)
		-- Prevent tabs/backspacing into nothing
		local inputController = tes3.worldController.inputController
		pressedTab = (inputController:isKeyDown(tes3.scanCode.tab))
		backspacedNothing = ((inputController:isKeyDown(tes3.scanCode.delete) or
		                    inputController:isKeyDown(tes3.scanCode.backspace)) and input.text == self.placeholderSearchText)

		if pressedTab then
			-- Prevent alt-tabbing from creating spacing.
			return
		elseif backspacedNothing then
			-- Prevent backspacing into nothing.
			return
		end

		input:forwardEvent(e)
		self:filterComponents()
		input:updateLayout()

		-- Reset to placeholder if nothing there
		input.color = tes3ui.getPalette("normal_color")
		if input.text == "" then
			input.text = self.placeholderSearchText
			input.color = tes3ui.getPalette("disabled_color")
		end

		self.elements.scrollPane.widget:contentsChanged()
	end)

	self.elements.searchBarInput = input

end

function FilterPage:createLeftColumn(parentBlock)
	local outerContainer = parentBlock:createThinBorder()
	outerContainer.flowDirection = "top_to_bottom"
	outerContainer.heightProportional = 1.0
	outerContainer.widthProportional = 1.0
	outerContainer.paddingAllSides = self.indent + 4
	--[[outerContainer.paddingTop = self.indent + 4
	outerContainer.paddingLeft = self.indent + 4
	outerContainer.paddingRight = self.indent + 4
	outerContainer.paddingBottom = self.indent + 4]] --
	self.elements.outerContainer = outerContainer
end

function FilterPage:createSubcomponentsContainer(parentBlock)

	local contentsScrollPane = parentBlock:createVerticalScrollPane({
		id = tes3ui.registerID("FilterPage_ContentsContainer"),
	})
	contentsScrollPane.widthProportional = 1.0
	contentsScrollPane.heightProportional = 1.0
	contentsScrollPane.autoHeight = true

	local subcomponentsContainer = contentsScrollPane:createBlock()
	subcomponentsContainer.paddingLeft = self.indent
	subcomponentsContainer.paddingTop = self.paddingBottom
	subcomponentsContainer.flowDirection = "top_to_bottom"
	subcomponentsContainer.widthProportional = 1.0
	subcomponentsContainer.heightProportional = 1.0
	subcomponentsContainer.autoHeight = true
	self.elements.scrollPane = contentsScrollPane
	self.elements.subcomponentsContainer = subcomponentsContainer

end

function FilterPage:createContentsContainer(parentBlock)
	self:createSearchBar(parentBlock)
	self:createSubcomponentsContainer(parentBlock)
	self:createSubcomponents(self.elements.subcomponentsContainer, self.components)
end

return FilterPage
