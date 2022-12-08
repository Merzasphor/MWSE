
---@class timerCallbackData
---@field timer mwseTimer Access to our timer

---@param e timerCallbackData
local function showMessage(e)
	local timer = e.timer
	local data = timer.data
	local currentTimestamp = tes3.getSimulationTimestamp()

	-- We are sure that the timer.data ~= nil since we
	-- created that table in timer.start function.
	-- So, lets disable the warnings for a bit.
	---@diagnostic disable:need-check-nil
	tes3.messageBox(data.message:format(
		data.startTimestamp,
		data.lastIterationTimestamp,
		currentTimestamp
	))
	---@diagnostic enable:need-check-nil

	-- Save this to the data table on the timer
	data.lastIterationTimestamp = currentTimestamp
end

timer.register("testExample:OneDayTimer", showMessage)

timer.start({
	type = timer.game,
	persist = true,
	iterations = -1,
	duration = 24,
	-- Notice that the callback isn't a function, but
	-- a string passed to the timer.register function
	callback = "testExample:OneDayTimer",
	data = {
		startTimestamp = tes3.getSimulationTimestamp(),
		lastIterationTimestamp = tes3.getSimulationTimestamp(),
		message = [[One day later...
timer's starting timestamp %s
the timestamp of last iteration %s
current timestamp %s
]]
	}
})
