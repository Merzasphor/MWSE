local function onInitialized()
    tes3.addSoulGem({ item = "misc_dwrv_artifact60" })
end
event.register(tes3.event.initialized, onInitialized)

local function onFilterSoulGemTarget(e)
    if (e.reference.baseObject.id:lower() == "fargoth") then
        return e.soulGem.id == "misc_dwrv_artifact60"
    end
end
event.register(tes3.event.filterSoulGemTarget, onFilterSoulGemTarget)

-- calcSoulValue event allows assigning a new soul value to creatures
-- If the event was triggered for an NPC, it allows assigning a value
-- thus allowing soul-trapping the actor.
local function calcSoulValueCallback(e)
    if (e.actor.id:lower() == "fargoth") then
        e.value = 69
        mwse.log("Getting Fargoth's value.")
        return
    end
end
event.register(tes3.event.calcSoulValue, calcSoulValueCallback)
