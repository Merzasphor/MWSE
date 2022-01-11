element:register("mouseDown", function(e)
	-- Capture must be inside a mouse event.
	tes3ui.captureMouseDrag(true)
end)

element:register("mouseRelease", function(e)
	-- Release may be anywhere.
	tes3ui.captureMouseDrag(false)
end)