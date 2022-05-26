--- @param e keybindTestedEventData
local function noJournalMenu(e)
    -- We only care about checks to see if the key was pressed.
    if (e.transition ~= tes3.keyTransition.down) then
        return
    end

    -- If the result was false, we also don't care.
    if (not e.result) then
        return
    end

    -- Set the result to false to make the game think the key wasn't pressed.
    -- We could also block this event by using `return false`.
    tes3.messageBox("You aren't allowed to open your journal.")
    e.result = false
end
event.register(tes3.event.keybindTested, noJournalMenu, { filter = tes3.keybind.journal })