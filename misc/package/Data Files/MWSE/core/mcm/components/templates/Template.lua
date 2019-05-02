
--parent
local Parent = require("mcm.components.Component")
--Class object
local Template = Parent:new()

Template.componentType = "Template"

function Template:new(data)
	data.name = data.name or data.label
	local t = Parent:new(data)
	setmetatable(t, self)

	--Create Pages
	local pages = {}
	t.pages = t.pages or {}
	for _, page in ipairs(t.pages) do
		page.class = page.class or "Page"
		local newPage = self:getComponent(page)
		table.insert(pages, newPage )
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
	--header image
	local headerBlock = parentBlock:createBlock()
	headerBlock.autoHeight = true
	headerBlock.widthProportional = 1.0
	local imagePath = self.headerImagePath
	if imagePath then
		local headerImage = headerBlock:createImage({path = imagePath })
		headerImage.absolutePosAlignX = 0.5
		headerImage.autoHeight = true
		headerImage.widthProportional = 1.0
		headerImage.imageScaleX = 0.5
		headerImage.imageScaleY = 0.5
	elseif self.label then
		headerBlock.borderAllSides = 10
		local title = headerBlock:createLabel({text = self.label})
		title.color = tes3ui.getPalette("header_color")
	end

end


function Template:clickTab( thisPage )
	local pageBlock = self.elements.pageBlock
	local tabsBlock = self.elements.tabsBlock
	--Clear previous page
	pageBlock:destroyChildren()
	--Create new page
	thisPage:create(pageBlock)
	--Set new page to current
	self.currentPage = thisPage
	--Disable tabs
	for id, page in pairs(self.pages) do
		tabsBlock:findChild(page.tabUID).widget.state = 1
	end
	--Enable tab for this page
	tabsBlock:findChild(thisPage.tabUID).widget.state = 4
	--update view
	pageBlock:getTopLevelParent():updateLayout()
end


function Template:createTab(page) 
	local button = self.elements.tabsBlock:createButton({id = page.tabUID, text = page.label})
	button.borderAllSides = 0
	button.paddingTop= 4
	button.paddingLeft= 8
	button.paddingRight = 8
	button.paddingBottom = 6
	button:register(
		"mouseClick",
		function ()
			self:clickTab( page )
		end
	)
end


function Template:createTabsBlock(parentBlock)
	--Create page tab buttons
	local tabsBlock = parentBlock:createBlock()
	self.elements.tabsBlock = tabsBlock
	tabsBlock.autoHeight = true
	tabsBlock.widthProportional = 1.0

	--Create a tab for each page (no need if only one page)
	if table.getn(self.pages) > 1 then
		for _, page in ipairs(self.pages) do
			self:createTab(page)
		end
		--highlight first button
		local firstTab = parentBlock:findChild(self.pages[1].tabUID)
		firstTab.widget.state = 4
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
	mwse.log( "%s mod config registered", self.name )
end


function Template.__index(tbl, key)

	local meta = getmetatable(tbl)
	local prefixLen = string.len("create")
	if string.sub( key, 1, prefixLen ) == "create" then
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