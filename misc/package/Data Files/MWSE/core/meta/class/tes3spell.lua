--- @meta

--- A spell game object.
--- @class tes3spell : tes3object, tes3baseObject
--- @field alwaysSucceeds boolean A flag that determines if casting the spell will always succeed.
--- @field autoCalc boolean Determines if the magicka cost for the spell is autocalculated, and if the spell may be automatically assigned to NPCs if they are skillful enough to cast it.
--- @field basePurchaseCost number Calculates the base cost to purchase the spell. This value is not adjusted by mercantile skills.
--- @field castType number The spell's cast type. Maps to [`tes3.spellType`](https://mwse.github.io/MWSE/references/spell-types/) constants.
--- @field effects table *Read-only*. An array-style table of the [`tes3effect`](https://mwse.github.io/MWSE/types/tes3effect/) data on the object.
--- @field flags number A bit field for the spell's flags.
--- @field isActiveCast boolean *Read-only*. True if the spell is actively cast. If false, the spell's effects are always passively affecting the owner.
--- @field magickaCost number No description yet available.
--- @field name string The name of the spell.
--- @field playerStart boolean A flag that determines if the spell may be assigned to the player at character generation if the player has enough skill to cast it.
--- @field value number *Read-only*. The calculated base price of the spell. This is the `magickaCost` of the spell multiplied by the `fSpellValueMult` GMST.
tes3spell = {}

--- Use [`tes3.createObject()`](https://mwse.github.io/MWSE/apis/tes3/#tes3createobject) instead. This function created a new spell object, which will be stored as part of the current saved game.
--- @deprecated
--- @param id string The new object's ID. Must be unique.
--- @param name string *Optional*. The new object's name.
function tes3spell.create(id, name) end

--- Calculates the chance that a caster can cast a given spell.
--- @param params tes3spell.calculateCastChance.params This table accepts the following values:
--- 
--- `checkMagicka`: boolean — *Optional*. Determines if the caster's magicka should be taken into account during the calculation.
--- 
--- `caster`: tes3reference|tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer — The caster to perform the calculation against.
--- @return number result No description yet available.
function tes3spell:calculateCastChance(params) end

---Table parameter definitions for `tes3spell.calculateCastChance`.
--- @class tes3spell.calculateCastChance.params
--- @field checkMagicka boolean *Optional*. Determines if the caster's magicka should be taken into account during the calculation.
--- @field caster tes3reference|tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer The caster to perform the calculation against.

--- Gets the number of active effects in the spell effect table.
--- @return number result No description yet available.
function tes3spell:getActiveEffectCount() end

--- Gets the first index of an effect ID in the spell effect table.
--- @param effectId number The ID of a `tes3effect` object to look for.
--- @return number result No description yet available.
function tes3spell:getFirstIndexOfEffect(effectId) end

--- Returns the effect of the spell that a given actor is least proficient with.
--- @param actor tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer|tes3reference|tes3npc|tes3npcInstance The actor to calculate for. A mobile actor is preferred, as passing only a `tes3npc` will not use up to date skill information.
--- @return tes3effect|nil effect The least proficient effect, or `nil` if the spell has no valid effects.
function tes3spell:getLeastProficientEffect(actor) end

--- Returns the school of the least proficient effect on the spell, for a given actor.
--- @param actor tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer|tes3reference|tes3npc|tes3npcInstance The actor to calculate for. A mobile actor is preferred, as passing only a `tes3npc` will not use up to date skill information.
--- @return number|nil schoolID The least proficient school ID, or `nil` if the spell has no valid effects.
function tes3spell:getLeastProficientSchool(actor) end

