local common = {}

local eventCallback = {}
local eventCallbackHelper = {}

---@param e tes3uiEventData
function eventCallback.focusOnClick(e)
	tes3ui.acquireTextInput(e.source)
end

---@param e tes3uiEventData
function eventCallbackHelper.getKeyPressed(e)
	return bit.band(e.data0, 0x7FFFFFFF) --- @diagnostic disable-line
end

---@param e tes3uiEventData
function eventCallbackHelper.getCharacterPressed(e)
	if (e.data0 <= 0) then --- @diagnostic disable-line
		return nil
	end
	return string.char(eventCallbackHelper.getKeyPressed(e))
end

common.eventCallback = eventCallback
common.eventCallbackHelper = eventCallbackHelper
return common
