local leftArmParts = {
	tes3.activeBodyPart.leftForearm,
	tes3.activeBodyPart.leftHand,
	tes3.activeBodyPart.leftUpperArm,
	tes3.activeBodyPart.leftWrist,
	tes3.activeBodyPart.shield
}

---@param e bodyPartsUpdatedEventData
local function ripLefties(e)
	local bpm = e.reference.bodyPartManager
	if (not bpm) then return end

	-- Hide all left arm nodes.
	for _, part in ipairs(leftArmParts) do

		-- We want to hide the body parts in all the three
		-- layers that make up the character's body.
		for _, layer in pairs(tes3.activeBodyPartLayer) do
			local activePart = bpm:getActiveBodyPart(layer, part)
			if (activePart and activePart.node) then
				activePart.node.appCulled = true
			end
		end
	end
end

event.register(tes3.event.bodyPartsUpdated, ripLefties)