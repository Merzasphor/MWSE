--- @meta
--- @diagnostic disable:undefined-doc-name

--- A list of spells. Used by actors, birthsigns, and races.
--- @class tes3spellList
--- @field iterator tes3iterator *Read-only*. Deprecated. Use `for index, spell in pairs(spellList)` to iterate over spells.
--- 	
--- Direct access to the spells in this list.
tes3spellList = {}

--- Adds a spell to the list.
--- @param spell string|tes3spell The spell.
--- @return boolean result No description yet available.
function tes3spellList:add(spell) end

--- Checks if the specified spell is contained in the spell list.
--- @param spell string|tes3spell The spell.
--- @return boolean result No description yet available.
function tes3spellList:contains(spell) end

--- Finds the first spell with the type provided.
--- @param spellType number A value from [`tes3.spellType`](https://mwse.github.io/MWSE/references/spell-types/) enumeration.
--- @return tes3spell result No description yet available.
function tes3spellList:containsType(spellType) end

--- Finds the castable spell in the list with the lowest casting cost.
--- @return tes3spell result No description yet available.
function tes3spellList:getCheapest() end

--- Removes a spell from the list.
--- @param spell string|tes3spell The spell.
--- @return boolean result No description yet available.
function tes3spellList:remove(spell) end

