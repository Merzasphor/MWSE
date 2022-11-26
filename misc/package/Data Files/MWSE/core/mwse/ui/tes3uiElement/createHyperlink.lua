local metatable = {}
metatable.__index = metatable

function metatable:openURL()
	-- Create a message box to confirm.
	if (self.confirm) then
		tes3.messageBox({
			message = self.confirmText or mwse.mcm.i18n("Open web browser?"),
			buttons = {
				tes3.findGMST(tes3.gmst.sYes).value --[[@as string]],
				tes3.findGMST(tes3.gmst.sNo).value --[[@as string]],
			},
			callback = function(btnCallbackData)
				if btnCallbackData.button == 0 then
					os.openURL(self.url)
				end
			end,
		})
	else
		os.openURL(self.url)
	end
end

---@param e tes3uiEventData
local function onHyperlinkClicked(e)
	local widget = e.source.widget ---@cast widget tes3uiHyperlink
	widget:openURL()
end

function tes3uiElement:createHyperlink(params)
	-- Validate params.
	assert(type(params) == "table", "Invalid parameters provided.")
	assert(type(params.text) == "string", "Invalid 'text' parameter provided.")
	assert(type(params.url) == "string", "Invalid 'url' parameter provided.")

	-- Create and define basic properties.
	local link = self:createTextSelect({ id = params.id, text = params.text })
	link.color = tes3ui.getPalette("link_color")

	-- Set our textSelect properties. We'll be overriding the widget type so this is the last time we have access to this.
	local textSelectWidget = link.widget
	textSelectWidget.idle = tes3ui.getPalette("link_color")
	textSelectWidget.over = tes3ui.getPalette("link_over_color")
	textSelectWidget.pressed = tes3ui.getPalette("link_pressed_color")

	-- Define as a custom widget.
	link:makeLuaWidget("hyperlink", {
		confirm = table.get(params, "confirm", true),
		url = params.url,
	})

	-- Register callbacks.
	link:registerAfter("mouseClick", onHyperlinkClicked)

	return link
end

tes3ui.defineLuaWidget({
	name = "hyperlink",
	metatable = metatable,
})
