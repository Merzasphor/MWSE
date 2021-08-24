--[[
	Top level category with a side bar that shows text for any component
	hovered over.
]]--

local Parent = require("mcm.components.pages.Page")
local SideBarPage = Parent:new()
SideBarPage.triggerOn = "MCM:MouseOver"
SideBarPage.triggerOff = "MCM:MouseLeave"

function SideBarPage:new(data)
	local t = Parent:new(data)
	t.sidebar = self:getComponent({ class = "MouseOverPage" })

	setmetatable(t, self)
	self.__index = self
	return t

end

function SideBarPage:createSidetoSideBlock(parentBlock)
	local sideToSideBlock = parentBlock:createBlock()
	sideToSideBlock.flowDirection = "left_to_right"
	sideToSideBlock.heightProportional = 1.0
	sideToSideBlock.widthProportional = 1.0
	self.elements.sideToSideBlock = sideToSideBlock
end

function SideBarPage:createLeftColumn(parentBlock)
	Parent.createOuterContainer(self, parentBlock)
end

-- Sidebar
function SideBarPage:createRightColumn(parentBlock)

	self.sidebar:create(parentBlock)
	local defaultView = self.sidebar.elements.subcomponentsContainer
	local mouseoverView = self.sidebar.elements.mouseOverBlock

	-- For backwards compatibility, add sidebarComponents elements
	if self.sidebarComponents then
		self:createSubcomponents(defaultView, self.sidebarComponents)

		-- or description
	elseif self.description then
		-- By default, sidebar is a mouseOver description pane
		local sidebarInfo = self:getComponent({
			-- label = self.label,
			text = self.description,
			class = "Info",
		})
		sidebarInfo:create(defaultView)
	end

	-- mouseover shows descriptions of settings
	local mouseOver = self:getComponent({
		-- label = self.label,
		text = self.description or "",
		class = "MouseOverInfo",
	})
	mouseOver:create(mouseoverView)
	mouseOver.elements.outerContainer.visible = false
	self.elements.mouseOver = mouseOver

	-- event to hide default and show mouseover
	local function doMouseOver(component)
		if component.description then
			mouseOver.elements.outerContainer.visible = true
			defaultView.visible = false
		end
	end

	-- event to hide mouseover and show default
	local function doMouseLeave()
		mouseOver.elements.outerContainer.visible = false
		defaultView.visible = true
	end

	-- register events
	event.register(self.triggerOn, doMouseOver)
	event.register(self.triggerOff, doMouseLeave)
	parentBlock:register("destroy", function()
		event.unregister(self.triggerOn, doMouseOver)
		event.unregister(self.triggerOff, doMouseLeave)
	end)

end

function SideBarPage:createOuterContainer(parentBlock)
	self:createSidetoSideBlock(parentBlock)
	self:createLeftColumn(self.elements.sideToSideBlock)
	self:createRightColumn(self.elements.sideToSideBlock)
end

return SideBarPage
