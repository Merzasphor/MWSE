--- @meta
--- @diagnostic disable:undefined-doc-name

--- A handle to safely operate on ([tes3object](https://mwse.github.io/MWSE/types/tes3object/)).
--- @class mwseSafeObjectHandle
mwseSafeObjectHandle = {}

--- Returns the object of this handle.
--- @return tes3activator|tes3alchemy|tes3apparatus|tes3armor|tes3bodyPart|tes3book|tes3clothing|tes3container|tes3containerInstance|tes3creature|tes3creatureInstance|tes3door|tes3enchantment|tes3ingredient|tes3leveledCreature|tes3leveledItem|tes3light|tes3lockpick|tes3misc|tes3npc|tes3npcInstance|tes3probe|tes3reference|tes3repairTool|tes3spell|tes3static|tes3weapon result No description yet available.
function mwseSafeObjectHandle:getObject() end

--- Returns true if the object of this handle is still valid. Objects that are invalid do no longer exist and cannot be used.
function mwseSafeObjectHandle:valid() end

