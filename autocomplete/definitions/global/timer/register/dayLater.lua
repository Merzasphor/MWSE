
local function showMessage()
	tes3.messageBox("One day later...")
end

timer.register("testExample:OneDayTimer", showMessage)

timer.start({
    type = timer.game,
    persist = true,
    iterations = 1,
    duration = 24,
    callback = "testExample:OneDayTimer" -- Notice that the callback isn't a function, but a custom timer.
})