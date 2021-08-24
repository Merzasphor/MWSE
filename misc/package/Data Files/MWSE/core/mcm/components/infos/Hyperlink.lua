--[[
	A clickable hyperlink 
]]--

local Parent = require("mcm.components.infos.Info")

local Hyperlink = Parent:new()
Hyperlink.sExecute = mwse.mcm.i18n("Open web browser?")

function Hyperlink:execute()
	tes3.messageBox({
		message = self.sExecute,
		buttons = { self.sYes, self.sNo },
		callback = function(e)
			if e.button == 0 then
				os.openURL(self.url)
			end
		end,
	})
end

function Hyperlink:makeComponent(parentBlock)
	-- Convert legacy exec param to a URL.
	if (not self.url and self.exec) then
		self.url = self.exec:gsub("^start ", "")
	end

	if not self.text or not self.url then
		mwse.log("ERROR: Text field missing for the following setting: ")
		self:printComponent()
	end

	local link = parentBlock:createTextSelect{ text = self.text }
	link.color = tes3ui.getPalette("link_color")
	link.widget.idle = tes3ui.getPalette("link_color")
	link.widget.over = tes3ui.getPalette("link_over_color")
	link.widget.pressed = tes3ui.getPalette("link_pressed_color")

	link.borderRight = self.indent -- * 2
	link.wrapText = true
	link.text = self.text
	link.autoHeight = true
	link.autoWidth = true
	link.widthProportional = 1.0
	link:register("mouseClick", function(e)
		self:execute()
	end)

	self.elements.info = link
	return link
end

return Hyperlink
