local function onInitialized()
	-- This will turn the Dwemer Tube in a soul gem
	tes3.addSoulGem({ item = "misc_dwrv_artifact60" })
end
event.register(tes3.event.initialized, onInitialized)

local function onFilterSoulGemTarget(e)
	-- Make it so Vivec can only be trapped by a special container.
	if (e.reference.baseObject.id:lower() == "vivec") then
		e.filter = (e.soulGem.id == "misc_dwrv_artifact60")
	end
end
event.register(tes3.event.filterSoulGemTarget, onFilterSoulGemTarget)
