local function myOnKeyCallback(e)
	if( e.pressed and e.isControlDown ) then
		tes3.messageBox({ message = "You pressed Ctrl-Z, but you can't undo all your mistakes." })
	end
end

-- Filter by the scan code to get Z key presses only.
event.register(tes3.event.key, myOnKeyCallback, { filter = tes3.scanCode.z } )