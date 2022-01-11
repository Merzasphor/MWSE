local function onCalcMoveSpeed(e)
	if (e.reference == tes3.player) then
		e.speed = e.speed * 1.2
	end
end
event.register(tes3.event.calcMoveSpeed, onCalcMoveSpeed)