--- @meta

--- A leveled creature game object.
--- @class tes3leveledCreature : tes3physicalObject, tes3object, tes3baseObject
--- @field calculateFromAllLevels boolean If true, the leveled list is picked from the entire level range, instead of just the highest.
--- @field chanceForNothing number The percent chance, from 0 to 100, for no object to be chosen.
--- @field count number *Read-only*. The number of possible options in the leveled object container.
--- @field flags number A numerical representation of bit flags for the object.
--- @field list tes3iterator *Read-only*. The collection that itself, containing tes3leveledListNodes.
tes3leveledCreature = {}

--- This function inserts given creature in the creature leveled list. True is returned if the operation was successful.
--- @param entry tes3activator|tes3alchemy|tes3apparatus|tes3armor|tes3birthsign|tes3bodyPart|tes3book|tes3cell|tes3class|tes3clothing|tes3container|tes3containerInstance|tes3creature|tes3creatureInstance|tes3dialogue|tes3dialogueInfo|tes3door|tes3enchantment|tes3faction|tes3gameSetting|tes3globalVariable|tes3ingredient|tes3leveledCreature|tes3leveledItem|tes3light|tes3lockpick|tes3magicSourceInstance|tes3misc|tes3npc|tes3npcInstance|tes3probe|tes3quest|tes3race|tes3reference|tes3region|tes3repairTool|tes3skill|tes3sound|tes3soundGenerator|tes3spell|tes3static|tes3weapon A creature to insert.
--- @param level number At which player level the creature can be resolved from the leveled list.
--- @return boolean result No description yet available.
function tes3leveledCreature:insert(entry, level) end

--- Chooses a random item from the list, based on the player's level.
--- @return tes3creature result No description yet available.
function tes3leveledCreature:pickFrom() end

--- This function removes a creature from the creature leveled list. True is returned if the operation was successful.
--- @param entry tes3activator|tes3alchemy|tes3apparatus|tes3armor|tes3birthsign|tes3bodyPart|tes3book|tes3cell|tes3class|tes3clothing|tes3container|tes3containerInstance|tes3creature|tes3creatureInstance|tes3dialogue|tes3dialogueInfo|tes3door|tes3enchantment|tes3faction|tes3gameSetting|tes3globalVariable|tes3ingredient|tes3leveledCreature|tes3leveledItem|tes3light|tes3lockpick|tes3magicSourceInstance|tes3misc|tes3npc|tes3npcInstance|tes3probe|tes3quest|tes3race|tes3reference|tes3region|tes3repairTool|tes3skill|tes3sound|tes3soundGenerator|tes3spell|tes3static|tes3weapon A creature to remove.
--- @param level number At which player level the creature could be resolved from the leveled list.
--- @return boolean result No description yet available.
function tes3leveledCreature:remove(entry, level) end

