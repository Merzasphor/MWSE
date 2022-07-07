local common = require("mwse.common")

function tes3.canCastSpells(params)
	-- Validate parameters.
	assert(type(params) == "table", "Invalid parameters provided. Must be a table.")
	local reference = common.getRelatedReference(params.target)
	assert(reference, "Invalid 'target' parameter provided. Must be a tes3reference, tes3mobileObject or tes3physicalObject.")

	-- Only npcs and creatures can cast spells.
	local object = reference.object
	if object then
		return object.objectType == tes3.objectType.npc or object.objectType == tes3.objectType.creature
	end
	return false
end

---@param spells tes3spellList
---@param spellType number
---@param target table
local function addFilteredSpellsToTable(spells, spellType, target)
	if spells then
		for _, spell in pairs(spells) do
			if spellType == -1 or spell.castType == spellType then
				table.insert(target, spell)
			end
		end
	end
end

function tes3.getSpells(params)
	-- Validate parameters.
	assert(type(params) == "table", "Invalid parameters provided. Must be a table.")

	local reference = common.getRelatedReference(params.target)
	assert(reference, "Invalid 'target' parameter provided. Must be a tes3reference, tes3mobileObject or tes3physicalObject.")
	assert(tes3.canCastSpells{target = reference}, "Invalid 'target' parameter provided. Must be able to cast spells.")
	local mobile = reference.mobile
	local object = reference.object

	local spellType = params.spellType or -1
	assert(type(spellType) == "number", "Invalid 'spellType' parameter provided. Must be a number or nil.")

	local getActorSpells = common.ternary(params.getActorSpells ~= nil, params.getActorSpells, true)
	local getRaceSpells = common.ternary(params.getRaceSpells ~= nil, params.getRaceSpells, true)
	local getBirthsignSpells = common.ternary(params.getBirthsignSpells ~= nil, params.getBirthsignSpells, true)

	-- Create the resulting spell table.
	local result = {}

	-- Filter the actor's spells.
	if getActorSpells then
		addFilteredSpellsToTable(object.spells, spellType, result)
	end

	-- Filter the race's spells.
	if getRaceSpells and object.race then
		addFilteredSpellsToTable(object.race.abilities, spellType, result)
	end

	-- Filter the birthsign's spells.
	if getBirthsignSpells and mobile.birthsign then
		addFilteredSpellsToTable(mobile.birthsign.spells, spellType, result)
	end

	return result;
end
