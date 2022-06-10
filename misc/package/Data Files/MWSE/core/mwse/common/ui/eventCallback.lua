local eventCallback = {}

--- The triggering element will be passed to `tes3ui.acquireTextInput`.
--- @param e tes3uiEventData
function eventCallback.acquireTextInput(e)
	tes3ui.acquireTextInput(e.source)
end

return eventCallback
