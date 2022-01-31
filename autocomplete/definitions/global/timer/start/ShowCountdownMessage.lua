local timeLeft = 0;

local function onTimerExpired() 
	timeLeft = timeLeft - 1
	tes3.messageBox("%d seconds left", timeLeft)
end

local function onActivate(eventData)
	if (eventData.activator == tes3.player) then
		timeLeft = 10
		timer.start{ duration = 1, iterations = 10, type = timer.simulate, callback = onTimerExpired }
	end
end
event.register(tes3.event.activate, onActivate)