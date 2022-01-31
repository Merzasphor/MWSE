local function onInitialized()
	tes3.addSoulGem({ item = "vivec_soul_container" })
end
event.register(tes3.event.initialized, onInitialized)

local function onFilterSoulGemTarget(e)
	-- Make it so Vivec can only be trapped by a special container.
	if (e.reference.baseObject.id:lower() == "vivec") then
		return e.soulGem.id == "vivec_soul_container"
	end
end
event.register(tes3.event.filterSoulGemTarget, onFilterSoulGemTarget)