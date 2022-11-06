
--- This function returns `true` if given NPC
--- or creature offers traveling service.
---@param actor tes3npc|tes3npcInstance|tes3creature|tes3creatureInstance
---@return boolean
local function offersTraveling(actor)
	local travelDestinations = actor.aiConfig.travelDestinations

	-- Actors that can't transport the player
	-- have travelDestinations equal to `nil`
	return travelDestinations ~= nil
end
