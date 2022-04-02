local function onJump(e)
	-- Multiply the velocity on the Z-Axis (Up/Down) by 2.
	e.velocity.z = e.velocity.z * 2
end
event.register(tes3.event.jump, onJump)