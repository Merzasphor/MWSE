-- parent
local Parent = require("mcm.components.Component")

-- Class object
local Template = Parent:new()

Template.componentType = "Template"

function Template:new(data)
	data.name = data.name or data.label
	local t = Parent:new(data)
	setmetatable(t, self)

	-- Create Pages
	local pages = {}
	t.pages = t.pages or {}
	for _, page in ipairs(t.pages) do
		page.class = page.class or "Page"
		local newPage = self:getComponent(page)
		table.insert(pages, newPage)
	end
	t.pages = pages

	self.__index = Template.__index
	return t
end

function Template:saveOnClose(configPath, config)
	self.onClose = function()
		mwse.saveConfig(configPath, config)
	end
end

function Template:createOuterContainer(parentBlock)
	Parent.createOuterContainer(self, parentBlock)
	self.elements.outerContainer.heightProportional = 1.0
	self.elements.outerContainer.paddingBottom = 0
	self.elements.outerContainer.paddingLeft = 0
	self.elements.outerContainer.paddingRight = 0
end

function Template:createLabel(parentBlock)
	-- header image
	local headerBlock = parentBlock:createBlock()
	headerBlock.autoHeight = true
	headerBlock.widthProportional = 1.0
	local imagePath = self.headerImagePath
	if imagePath then
		local headerImage = headerBlock:createImage({ path = imagePath })
		headerImage.absolutePosAlignX = 0.5
		headerImage.autoHeight = true
		headerImage.widthProportional = 1.0
		headerImage.imageScaleX = 0.5
		headerImage.imageScaleY = 0.5
	elseif self.label then
		headerBlock.borderAllSides = 10
		local title = headerBlock:createLabel({ text = self.label })
		title.color = tes3ui.getPalette("header_color")
	end

end

local function toggleButtonState(button, enabled)
	button.disabled = not enabled
	button.widget.state = enabled and 1 or 2
end

function Template:clickTab(thisPage)
	local pageBlock = self.elements.pageBlock
	local tabsBlock = self.elements.tabsBlock
	-- Clear previous page
	pageBlock:destroyChildren()
	-- Create new page
	thisPage:create(pageBlock)
	-- Set new page to current
	self.currentPage = thisPage
	-- Disable tabs
	for id, page in pairs(self.pages) do
		tabsBlock:findChild(page.tabUID).widget.state = 1
	end
	-- Enable tab for this page
	tabsBlock:findChild(thisPage.tabUID).widget.state = 4
	-- update view
	pageBlock:getTopLevelParent():updateLayout()

	--Enable Prev button if first tab is not active
	local tab1 = tabsBlock:findChild(self.pages[1].tabUID)
	local prevButton = self.elements.previousTabButton
	if tab1.widget.state ~= 4 then
		toggleButtonState(prevButton, true)
	else
		toggleButtonState(prevButton, false)
	end
end

local function formatTabButton(button)
	button.borderAllSides = 0
	button.paddingTop = 4
	button.paddingLeft = 8
	button.paddingRight = 8
	button.paddingBottom = 6
end

function Template:createTab(page)
	local button = self.elements.tabsBlock:createButton({ id = page.tabUID, text = page.label })
	formatTabButton(button)
	button:register("mouseClick", function()
		self:clickTab(page)
	end)
end

function Template:createTabsBlock(parentBlock)
	local outerTabsBlock = parentBlock:createBlock()
	self.elements.outerTabsBlock = outerTabsBlock
	outerTabsBlock.autoHeight = true
	outerTabsBlock.widthProportional = 1.0

	-- Create a tab for each page (no need if only one page)
	if table.getn(self.pages) > 1 then

		--Previous Button
		local prevButton = outerTabsBlock:createButton{
			id = tes3ui.registerID("MCM_PreviousButton"),
			text = "<--"
		}
		formatTabButton(prevButton)
		toggleButtonState(prevButton, false)
		self.elements.previousTabButton = prevButton

		-- Create page tab buttons
		local tabsBlock = outerTabsBlock:createBlock()
		self.elements.tabsBlock = tabsBlock
		tabsBlock.autoHeight = true
		tabsBlock.widthProportional = 1.0
		for _, page in ipairs(self.pages) do
			self:createTab(page)
		end
		local firstTab = parentBlock:findChild(self.pages[1].tabUID)
		firstTab.widget.state = 4

		--Next Button
		local nextButton = outerTabsBlock:createButton{
			id = tes3ui.registerID("MCM_NextButton"),
			text = "-->",
		}
		formatTabButton(nextButton)
		self.elements.nextTabButton = nextButton

		--Pagination

		local hiddenTabCount = 0
		nextButton:register("mouseClick", function()
			--Hide next tab
			local tabToHide = parentBlock:findChild(self.pages[hiddenTabCount + 1].tabUID)
			tabToHide.visible = false
			--Move active tab forward 1
			for i, page in ipairs(self.pages) do
				local tab = tabsBlock:findChild(page.tabUID)
				if tab.widget.state == 4 and self.pages[i+1] then
					self:clickTab(self.pages[i+1])
					break
				end
			end
			--increment hiddenTabCount
			hiddenTabCount = math.min(hiddenTabCount + 1, #self.pages)
			--If only last tab is visible, disable Next button
			if hiddenTabCount >= #self.pages-1 then
				toggleButtonState(nextButton, false)
			end
			toggleButtonState(prevButton, true)
		end)

		prevButton:register("mouseClick", function()
			--Move active tab back 1
			for i, page in ipairs(self.pages) do
				local tab = tabsBlock:findChild(page.tabUID)
				if tab.widget.state == 4 and self.pages[i-1] then
					local prevTab = parentBlock:findChild(self.pages[i-1].tabUID)
					if prevTab.visible == false then
						--decrement hiddenTabCount
						hiddenTabCount = math.max(hiddenTabCount - 1, 0)
						prevTab.visible = true
					end
					self:clickTab(self.pages[i-1])
					break
				end
			end
			--If first tab is active, disable Prev button
			if tabsBlock:findChild(self.pages[1].tabUID).widget.state == 4 then
				toggleButtonState(prevButton, false)
			end
			toggleButtonState(nextButton, true)
		end)
	end
end

function Template:createSubcomponentsContainer(parentBlock)
	local pageBlock = parentBlock:createBlock()
	pageBlock.heightProportional = 1.0
	pageBlock.widthProportional = 1.0
	self.currentPage = self.pages[1]
	self.currentPage:create(pageBlock)
	self.elements.pageBlock = pageBlock
	pageBlock.flowDirection = tes3.flowDirection.leftToRight
end

function Template:createContentsContainer(parentBlock)
	self:createLabel(parentBlock)
	self:createTabsBlock(parentBlock)
	self:createSubcomponentsContainer(parentBlock)
end

function Template:register()
	local mcm = {}

	mcm.onCreate = function(container)
		self:create(container)
		mcm.onClose = self.onClose
	end
	mwse.registerModConfig(self.name, mcm)
	mwse.log("%s mod config registered", self.name)
end

function Template.__index(tbl, key)

	local meta = getmetatable(tbl)
	local prefixLen = string.len("create")
	if string.sub(key, 1, prefixLen) == "create" then
		local component

		local class = string.sub(key, prefixLen + 1)
		local classPaths = require("mcm.classPaths")
		local classPath = classPaths.all.pages .. class
		local fullPath = lfs.currentdir() .. classPaths.basePath .. classPath .. ".lua"
		local fileExists = lfs.attributes(fullPath, "mode") == "file"
		if fileExists then
			component = require(classPath)
		end

		if component then
			return function(self, data)
				data = self:prepareData(data)
				data.class = class
				component = component:new(data)
				table.insert(self.pages, component)
				return component
			end
		end

	end
	return meta[key]
end

return Template
