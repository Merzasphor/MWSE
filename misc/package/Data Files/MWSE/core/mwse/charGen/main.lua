local charGenStates = {
	none = 0,
	running = 10,
	finished = -1
}

function tes3.isCharGenFinished()
	return tes3.worldController ~= nil and tes3.worldController.charGenState.value == charGenStates.finished
end

local function onSimulate(e)
	if tes3.isCharGenFinished() then
		event.unregister(tes3.event.simulate, onSimulate)
		event.trigger(tes3.event.charGenFinished)
	end
end

local function onLoaded(e)
	if event.isRegistered(tes3.event.simulate, onSimulate) then
		event.unregister(tes3.event.simulate, onSimulate)
	end

	if e.newGame then
		event.register(tes3.event.simulate, onSimulate)
	end
end

event.register(tes3.event.loaded, onLoaded)
