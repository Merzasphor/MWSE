--- @param e dispositionEventData
local function onDispositionCalculation(e)
	-- Get some context.
	local reference = e.reference
	local npc = reference.object
	local player = tes3.player
	local playerMobile = tes3.mobilePlayer

	-- Get our starting disposition.
	local disposition = npc.baseDisposition

	-- Same-race gives a bonus.
	if (npc.race == player.object.race) then
		local fDispRaceMod = tes3.findGMST(tes3.gmst.fDispRaceMod).value
		disposition = disposition + fDispRaceMod
	end

	-- Adjust disposition by personality.
	local fDispPersonalityBase = tes3.findGMST(tes3.gmst.fDispPersonalityBase).value
	local fDispPersonalityMult = tes3.findGMST(tes3.gmst.fDispPersonalityMult).value
	disposition = disposition + (playerMobile.personality.current - fDispPersonalityBase) * fDispPersonalityMult

	-- If they have a faction, adjust it accordingly.
	local faction = npc.faction
	if (faction) then
		-- Figure out the reaction to use.
		local reaction = 0
		local pairedFaction = nil --- @type tes3faction?
		if (not faction.playerJoined or faction.playerExpelled) then
			local lowestReaction, lowestFaction = faction:getLowestJoinedReaction()
			if (lowestReaction) then
				reaction, pairedFaction = lowestReaction, lowestFaction
			end
		else
			local selfReaction = faction:getReactionWithFaction(faction)
			if (selfReaction) then
				reaction = selfReaction
			end
		end

		-- Get the player rank from the faction if we found one.
		local playerRank = 0
		if (pairedFaction) then
			playerRank = faction.playerRank
		end

		-- Finally calculate our faction modifier.
		local fDispFactionRankBase = tes3.findGMST(tes3.gmst.fDispFactionRankBase).value
		local fDispFactionRankMult = tes3.findGMST(tes3.gmst.fDispFactionRankMult).value
		local fDispFactionMod = tes3.findGMST(tes3.gmst.fDispFactionMod).value
		disposition = disposition + fDispFactionMod * reaction * (fDispFactionRankBase + playerRank * fDispFactionRankMult)
	end

	-- Apply crime penalty.
	local fDispCrimeMod = tes3.findGMST(tes3.gmst.fDispCrimeMod).value
	disposition = disposition - playerMobile.bounty * fDispCrimeMod

	-- Apply disease penalty.
	if (playerMobile.isDiseased) then
		local fDispDiseaseMod = tes3.findGMST(tes3.gmst.fDispDiseaseMod).value
		disposition = disposition + fDispDiseaseMod
	end

	-- Apply weapon drawn penalty.
	if (playerMobile.weaponDrawn) then
		local fDispWeaponDrawn = tes3.findGMST(tes3.gmst.fDispWeaponDrawn).value
		disposition = disposition + fDispWeaponDrawn
	end

	-- Pass the new disposition to the event.
	assert(disposition == e.disposition, string.format("Calculated disposition of %d didn't match vanilla value of %d.", disposition, e.disposition))
	e.disposition = disposition
end
event.register(tes3.event.disposition, onDispositionCalculation)
