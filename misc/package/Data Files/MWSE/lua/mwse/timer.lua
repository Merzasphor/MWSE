local this = {}

-- Internal time, updated by this.update.
local clock = 0

-- A list of currently active timers.
local timers = {}

-- A list of paused timers.
local pausedTimers = {}

-- Updates the internal clock and triggers any timers on every simulation frame.
local lastPost = 0
event.register("simulate", function(e)
	-- Update internal timer.
	clock = clock + e.delta

	-- Check for triggered timers.
	local timersToRemove = {}
	for _, t in pairs(timers) do
		if (clock >= t.f) then
			-- Decrement iterations and invoke callback.
			t.i = t.i - 1
			t.c()

			-- If the number of iterations is exactly 0, flag it for removal.
			if (t.i == 0) then
				table.insert(timersToRemove, t)
			else 
				this.reset(t)
			end
		end
	end

	-- Clear out timers that have expired.
	for _, t in pairs(timersToRemove) do
		this.cancel(t)
	end
end)

-- On game load, clear any timers.
event.register("load", function(e)
	clock = 0
	timers = {}
	pausedTimers = {}
end)

-- Creates a new timer and inserts it into the active timer table.
function this.start(time, callback, iterations)
	if (iterations == nil) then
		iterations = 1
	elseif (iterations < 0) then
		iterations = 0
	end

	local newTime = {
		t = time,
		f = clock + time,
		c = callback,
		i = iterations,
	}
	table.insert(timers, newTime)
	return newTime
end

function this.cancel(t)
	table.removevalue(timers, t)
	table.removevalue(pausedTimers, t)
	t = nil
end

function this.pause(t)
	-- Is this an active timer?
	if (not timers[t]) then
		error("Provided timer is not active.")
	end

	-- Store how much time is left on the timer.
	t.p = t.f - clock
	t.f = nil

	-- Move the timer from the active to the paused timer list.
	table.removevalue(timers, t)
	table.insert(pausedTimers, t)
end

function this.resume(t)
	-- Is this an active timer?
	if (not pausedTimers[t]) then
		error("Provided timer is not active.")
	end

	-- Store how much time is left on the timer.
	t.f = clock + t.p
	t.p = nil

	-- Move the timer from the active to the paused timer list.
	table.insert(timers, t)
	table.removevalue(pausedTimers, t)
end

function this.reset(t)
	t.f = clock + t.t
end

function this.delayOneFrame(c)
	this.start(0, c)
end

return this