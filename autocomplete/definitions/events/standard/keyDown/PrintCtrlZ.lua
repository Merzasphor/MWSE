local function myOnKeyCallback(e)
	if( e.isControlDown ) then
		tes3.messageBox({ message = "You pressed Ctrl-Z, but you can't undo all your mistakes." })
	end
end

-- Filter by the scan code to get Z key presses only.
event.register(tes3.event.keyDown, myOnKeyCallback, { filter = tes3.scanCode.z } )