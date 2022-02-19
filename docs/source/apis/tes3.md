# tes3

The tes3 library provides the majority of the functions for interacting with the game system.

## Properties

### `tes3.dataHandler`

One of the core game objects.

**Returns**:

* `result` ([tes3dataHandler](../../types/tes3dataHandler))

***

### `tes3.game`

One of the core game objects.

**Returns**:

* `result` ([tes3game](../../types/tes3game))

***

### `tes3.installDirectory`

The currently executed root Morrowind installation path.

**Returns**:

* `result` (string)

***

### `tes3.magicSchoolSkill`

This table is used to convert numerical magic school IDs to their respective skill IDs. These constants will return their respective `tes3.skill` constants.

**Returns**:

* `result` (number)

??? example "Example: Convert magic school from event data to a respective skill"

	```lua
	local function OnSpellFailed(e)
	
		local skill = tes3.magicSchoolSkill[e.expGainSchool] -- Note: e.expGainSchool is a value in tes3.magicSchool constants table
	
		tes3.mobilePlayer:exerciseSkill(skill, 100)
	end
	
	event.register(tes3.event.spellCastedFailure, OnSpellFailed)

	```

***

### `tes3.mobilePlayer`

The player's mobile actor.

**Returns**:

* `result` ([tes3mobilePlayer](../../types/tes3mobilePlayer))

***

### `tes3.player`

A reference to the player.

**Returns**:

* `result` ([tes3reference](../../types/tes3reference))

***

### `tes3.worldController`

One of the core game objects.

**Returns**:

* `result` ([tes3worldController](../../types/tes3worldController))

***

## Functions

### `tes3.addArmorSlot`

Registers a new armor slot. Adds a new place for armor pieces with a matching slot number to equip to.

```lua
local wasAdded = tes3.addArmorSlot({ slot = ..., name = ..., weight = ..., scalar = ... })
```

**Parameters**:

* `params` (table)
	* `slot` (number): Armor slot number. A number greater than 10 to configure a slot for.
	* `name` (string)
	* `weight` (number): *Default*: `0`. A stand-in for the armor base weight value, typically controlled by a GMST (e.g. iHelmWeight).
	* `scalar` (number): *Default*: `0.1`. A multiplier with range 0.0-1.0 that controls how much of an item's armor value applies to a character's overall armor rating. For comparison, standard chest armor uses 0.3, helmets, greaves and pauldrons use 0.1, and gauntlets use 0.05.

**Returns**:

* `wasAdded` (boolean)

***

### `tes3.addClothingSlot`

Registers a new clothing slot. Adds a new place for clothing pieces with a matching slot number to equip to.

```lua
tes3.addClothingSlot({ slot = ..., name = ... })
```

**Parameters**:

* `params` (table)
	* `slot` (number): Clothing slot number. A number greater than 9 to configure a slot for.
	* `name` (string)

***

### `tes3.addItem`

Adds an item to a given reference's inventory or mobile's inventory.

```lua
local addedCount = tes3.addItem({ reference = ..., item = ..., itemData = ..., soul = ..., count = ..., playSound = ..., limit = ..., reevaluateEquipment = ..., updateGUI = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): Who to give items to.
	* `item` ([tes3item](../../types/tes3item), [tes3leveledItem](../../types/tes3leveledItem), string): The item to add. If a leveled item is passed, it will be resolved and added.
	* `itemData` ([tes3itemData](../../types/tes3itemData)): *Optional*. The item data for the item.
	* `soul` ([tes3creature](../../types/tes3creature), [tes3npc](../../types/tes3npc)): *Optional*. For creating filled soul gems.
	* `count` (number): *Default*: `1`. The maximum number of items to add.
	* `playSound` (boolean): *Default*: `true`. If false, the up/down sound for the item won't be played.
	* `limit` (boolean): If false, items can be placed into containers that shouldn't normally be allowed. This includes organic containers, and containers that are full.
	* `reevaluateEquipment` (boolean): *Default*: `true`. If true, and the item added is armor, clothing, or a weapon, the actor will reevaluate its equipment choices to see if the new item is worth equipping. This does not affect the player.
	* `updateGUI` (boolean): *Default*: `true`. If false, the function won't manually resync the player's GUI state. This can result in some optimizations, though [`tes3ui.forcePlayerInventoryUpdate()`](https://mwse.github.io/MWSE/apis/tes3ui/#tes3uiforceplayerinventoryupdate) must manually be called after all inventory updates are finished.

**Returns**:

* `addedCount` (number)

***

### `tes3.addItemData`

Creates an item data if there is room for a new stack in a given inventory. This can be then used to add custom user data or adjust an item's condition. This will return nil if no item data could be allocated for the item -- for example if the reference doesn't have the item in their inventory or each item of that type already has item data.

```lua
local createdData = tes3.addItemData({ to = ..., item = ..., updateGUI = ... })
```

**Parameters**:

* `params` (table)
	* `to` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): The reference or mobile whose inventory will be modified.
	* `item` ([tes3item](../../types/tes3item), string): The item to create item data for.
	* `updateGUI` (boolean): *Default*: `true`. If false, the player or contents menu won't be updated.

**Returns**:

* `createdData` ([tes3itemData](../../types/tes3itemData))

***

### `tes3.addJournalEntry`

This function creates a new journal entry. It can be called once the world controller is loaded.

```lua
tes3.addJournalEntry({ text = ..., showMessage = ... })
```

**Parameters**:

* `params` (table)
	* `text` (string): The text of the new Journal entry.
	* `showMessage` (boolean): *Default*: `true`. If this parameter is true, a "Your journal has been updated" message will be displayed.

***

### `tes3.addMagicEffect`

This function creates a new custom magic effect. The effect can be scripted through lua. This function should be used inside [`magicEffectsResolved`](https://mwse.github.io/MWSE/events/magicEffectsResolved/) event callback.

```lua
local effect = tes3.addMagicEffect({ id = ..., name = ..., baseCost = ..., school = ..., size = ..., sizeCap = ..., speed = ..., description = ..., lighting = ..., icon = ..., particleTexture = ..., castSound = ..., boltSound = ..., hitSound = ..., areaSound = ..., castVFX = ..., boltVFX = ..., hitVFX = ..., areaVFX = ..., allowEnchanting = ..., allowSpellmaking = ..., appliesOnce = ..., canCastSelf = ..., canCastTarget = ..., canCastTouch = ..., casterLinked = ..., hasContinuousVFX = ..., hasNoDuration = ..., hasNoMagnitude = ..., illegalDaedra = ..., isHarmful = ..., nonRecastable = ..., targetsAttributes = ..., targetsSkills = ..., unreflectable = ..., usesNegativeLighting = ..., onTick = ..., onCollision = ... })
```

**Parameters**:

* `params` (table)
	* `id` (number): Id of the new effect. Maps to newly claimed `tes3.effect` constants with `tes3.claimSpellEffectId()`. If the effect of this id already exists, an error will be thrown.
	* `name` (string): *Default*: `Unnamed Effect`. Name of the effect.
	* `baseCost` (number): *Default*: `1`. Base magicka cost for the effect.
	* `school` (number): *Default*: `tes3.magicSchool.alteration`. The magic school the new effect will be assigned to. Maps to [`tes3.magicSchool`](https://mwse.github.io/MWSE/references/magic-schools/) constants.
	* `size` (number): *Default*: `1`. The size scale for the spells containing this magic effect.
	* `sizeCap` (number): *Default*: `1`. The maximum possible size of the projectile.
	* `speed` (number): *Default*: `1`.
	* `description` (string): *Default*: `No description available.`. Description for the effect.
	* `lighting` (table): *Optional*.
		* `x` (number): *Default*: `1`. Value of red color channel. In range of 0 - 1.
		* `y` (number): *Default*: `1`. Value of green color channel. In range of 0 - 1.
		* `z` (number): *Default*: `1`. Value of blue color channel. In range of 0 - 1.
	* `icon` (string): Path to the effect icon. Must be a string no longer than 31 characters long. Use double \ as path separator.
	* `particleTexture` (string): Path to the particle texture to use for the effect. Must be a string no longer than 31 characters long.
	* `castSound` (string): The sound ID which will be played on casting a spell with this effect. Must be a string no longer than 31 characters long. If not specified, the default sound for the spell school will be used.
	* `boltSound` (string): The sound ID which will be played when a spell with this effect is in flight. Must be a string no longer than 31 characters long. If not specified, the default sound for the spell school will be used.
	* `hitSound` (string): The sound ID which will be played when a spell with this effect hits something. Must be a string no longer than 31 characters long. If not specified, the default sound for the spell school will be used.
	* `areaSound` (string): The sound ID which will be played on area of effect impact. Must be a string no longer than 31 characters long. If not specified, the default sound for the spell school will be used.
	* `castVFX` ([tes3physicalObject](../../types/tes3physicalObject)): *Optional*. The visual played when a spell with this effect is cast.
	* `boltVFX` ([tes3physicalObject](../../types/tes3physicalObject)): *Optional*. The visual played when a spell with this effect is in flight.
	* `hitVFX` ([tes3physicalObject](../../types/tes3physicalObject)): *Optional*. The visual played when a spell with this effect hits something.
	* `areaVFX` ([tes3physicalObject](../../types/tes3physicalObject)): *Optional*. The visual played when a spell with this effect, with area of effect hits something.
	* `allowEnchanting` (boolean): *Default*: `true`. A flag which controls whether this effect can be used in a custom enchantment.
	* `allowSpellmaking` (boolean): *Default*: `true`. A flag which controls whether this effect can be used in a custom spell.
	* `appliesOnce` (boolean): *Default*: `true`. A flag which controls whether this effect applies once or is a ticking effect.
	* `canCastSelf` (boolean): *Default*: `true`. A flag which controls whether this effect can be used with cast on self range.
	* `canCastTarget` (boolean): *Default*: `true`. A flag which controls whether this effect can be used with cast on target range.
	* `canCastTouch` (boolean): *Default*: `true`. A flag which controls whether this effect can be used with cast on touch range.
	* `casterLinked` (boolean): *Default*: `true`.
	* `hasContinuousVFX` (boolean): *Default*: `true`. A flag which controls whether the effect's visual is continuously played during the whole duration of the effect.
	* `hasNoDuration` (boolean): *Default*: `true`. A flag which controls whether this effect doesn't have duration.
	* `hasNoMagnitude` (boolean): *Default*: `true`. A flag which controls whether this effect doesn't have magnitude.
	* `illegalDaedra` (boolean): *Default*: `true`. A flag which controls whether this effect is illegal to use in public, because it summons Daedra. Note: this mechanic is not implemented in the game. Some mods might rely on this parameter.
	* `isHarmful` (boolean): *Default*: `true`. A flag which controls whether this effect is considered harmful and casting it can be considered as an attack.
	* `nonRecastable` (boolean): *Default*: `true`. A flag which controls whether this effect can be recast while it already is in duration.
	* `targetsAttributes` (boolean): *Default*: `true`. A flag which controls whether this effect targets a certain attribute or attributes.
	* `targetsSkills` (boolean): *Default*: `true`. A flag which controls whether this effect targets a certain skill or skills.
	* `unreflectable` (boolean): *Default*: `true`. A flag which controls whether this effect can be reflected.
	* `usesNegativeLighting` (boolean): *Default*: `true`. A flag which controls whether this effect uses negative lighting.
	* `onTick` (function): *Optional*. A function which will be called on each tick of a spell containing this effect. A table `tickParams` will be passed to the callback function. Note: `dt`(frame time) scaling is handled automatically.
		- `tickParams` (table)
		- `effectId` (number)
		- `sourceInstance` ([tes3magicSourceInstance](https://mwse.github.io/MWSE/types/tes3magicSourceInstance/)): Access to the magic source of the effect instance. 
		- `deltaTime` (number): The time passed since the last tick of the spell.
		- `effectInstance` ([tes3magicEffectInstance](https://mwse.github.io/MWSE/types/tes3magicEffectInstance/)): Access to the magic effect instance.
		- `effectIndex` (number): The index of the effect in the spell.

		In addition, a function registerd as `onTick` can also call the following methods:
	
		- trigger(`triggerParams`): Allows the effect to run through the normal spell event system.
			**Parameters:**
			- `triggerParams` (table)
			- `negateOnExpiry` (boolean): *Optional. Default:* `true` If this flag is `true`, the effect will be negated on expiry.
			- `isUncapped` (boolean): *Optional.*
			- `attribute` (number): *Optional. Default:* `tes3.effectAttribute.nonResistable` The attribute used in resistance calculations agains this effect. Maps to values in [`tes3.effectAttribute`](https://mwse.github.io/MWSE/references/effect-attributes/) namespace.
			- `type` (number): *Optional. Default:* `tes3.effectEventType.boolean`. This flag controls how the effect behaves. For example, `tes3.effectEventType.modStatistic` will make the effect work as calling `tes3.modStatistic`. Maps to values in [`tes3.effectEventType`](https://mwse.github.io/MWSE/references/effect-event-types/) namespace.
			- `value` (number): *Optional. Default:* `0`. The variable this effect changes.
			- `resistanceCheck(resistParams)` (function): *Optional.* The function passed as `resistanceCheck` will be used on any of the game's spell resistance checks. For example, the only effect in vanilla Morrowind that implements this function is Water Walking. It disallows using a spell with Water Walking when the player is deep underwater, by setting it as expired. So, returning `true` from this function will set your effect to expired, and depending on your trigger code may stop processing. The function passed here must returns boolean values.
				**Parameters**
				- `resistParams` (table)
				- `sourceInstance` ([tes3magicSourceInstance](https://mwse.github.io/MWSE/types/tes3magicSourceInstance/)): Access to the magic source of the effect instance. 
				- `effectInstance` ([tes3magicEffectInstance](https://mwse.github.io/MWSE/types/tes3magicEffectInstance/)): Access to the magic effect instance.
				- `effectIndex` (number): The index of the effect in the spell.

		- triggerBoundWeapon(`id`): Performs vanilla weapon summoning logic. It will create a summoned version of the weapon with provided ID. 
			**Parameters:**
			- `id` (string): The ID of the weapon object to summon.

		- triggerBoundArmor(`params`): Performs vanilla armor summoning logic. It can summon one or two armor objects with provided ID(s).
			**Parameters:**
			- `params` (table)
			- `id` (string): The ID of the armor object to summon.
			- `id2` (string): *Optional.* The ID of the additional armor object to summon.

		- triggerSummon(`id`): Performs vanilla creature summoning logic. It will create a summoned version of a creature with provided ID.
			**Parameters:**
			- `id` (string): The ID of the creature object to summon.

	* `onCollision` (function): *Optional*. A function which will be called when a spell containing this spell effect collides with something.

**Returns**:

* `effect` ([tes3effect](../../types/tes3effect))

??? example "Example: Fire Damage effect"

	```lua
	-- Claiming an ID is needed before actually
	-- creating an effect with that ID
	tes3.claimSpellEffectId("customFireDmg", 220)
	
	local function onFireDmgTick(tickParams)
		-- This will print current health for any actor our spell hit
		tes3.messageBox("%s, health: %s", tickParams.effectInstance.target.object.id, tickParams.effectInstance.target.mobile.health.current)
	
		tickParams:trigger({
			type = tes3.effectEventType.modStatistic,
			-- The resistance attribute against Fire Damage should be Resist Fire
			attribute = tes3.effectAttribute.resistFire,
			value = tickParams.effectInstance.target.mobile.health,
			negateOnExpiry = false,
			isUncapped = true,
		})
	end
	
	event.register(tes3.event.magicEffectsResolved, function()
		tes3.addMagicEffect({
			-- The ID we claimed before is now available in tes3.effect namespace
			id = tes3.effect.customFireDmg,
	
			-- This information if just copied from the Construction Set --
			name = "Fire Damage",
			description = ("This spell effect produces a manifestation of elemental fire. Upon " ..
			"contact with an object, this manifestation explodes, causing damage."),
			baseCost = 5,
			school = tes3.magicSchool.destruction,
			size = 1.25,
			sizeCap = 50,
			speed = 1,
			lighting = { x = 0.99, y = 0.26, z = 0.53 },
			usesNegativeLighting = false,
	
			icon = "s\\Tx_S_fire_damage.tga",
			particleTexture = "vfx_firealpha00A.tga",
			castSound = "destruction cast",
			castVFX = "VFX_DestructCast",
			boltSound = "destruction bolt",
			boltVFX = "VFX_DestructBolt",
			hitSound = "destruction hit",
			hitVFX = "VFX_DestructHit",
			areaSound = "destruction area",
			areaVFX = "VFX_DestructArea",
			-- --
	
			appliesOnce = false,
			hasNoDuration = false,
			hasNoMagnitude = false,
			illegalDaedra = false,
			unreflectable = false,
			casterLinked = false,
			nonRecastable = false,
			targetsAttributes = false,
			targetsSkills = false,
	
			onTick = onFireDmgTick,
		})
	end)
	
	event.register(tes3.event.loaded, function()
		local spell1 = tes3.createObject({ objectType = tes3.objectType.spell })
		tes3.setSourceless(spell1)
		spell1.name = "TEST SPELL - self"
		spell1.magickaCost = 1
	
		local effect = spell1.effects[1]
		effect.id = tes3.effect.customFireDmg
		effect.rangeType = tes3.effectRange.self
		effect.min = 10
		effect.max = 10
		effect.duration = 10
		effect.radius = 0
		effect.skill = -1
		effect.attribute = -1
	
		local spell2 = tes3.createObject({ objectType = tes3.objectType.spell })
		tes3.setSourceless(spell2)
		spell2.name = "TEST SPELL - target"
		spell2.magickaCost = 1
	
		local effect = spell2.effects[1]
		effect.id = tes3.effect.customFireDmg
		effect.rangeType = tes3.effectRange.target
		effect.min = 3
		effect.max = 3
		effect.duration = 10
		effect.radius = 15
		effect.skill = -1
		effect.attribute = -1
	
		local spell3 = tes3.createObject({ objectType = tes3.objectType.spell })
		tes3.setSourceless(spell3)
		spell3.name = "TEST SPELL - touch"
		spell3.magickaCost = 1
	
		local effect = spell3.effects[1]
		effect.id = tes3.effect.customFireDmg
		effect.rangeType = tes3.effectRange.touch
		effect.min = 3
		effect.max = 3
		effect.duration = 10
		effect.radius = 0
		effect.skill = -1
		effect.attribute = -1
	
		tes3.addSpell({ reference = tes3.mobilePlayer, spell = spell1 })
		tes3.addSpell({ reference = tes3.mobilePlayer, spell = spell2 })
		tes3.addSpell({ reference = tes3.mobilePlayer, spell = spell3 })
	end)

	```

***

### `tes3.addSoulGem`

Causes a misc item to be recognized as a soul gem, so that it can be used for soul trapping.

```lua
local wasAdded = tes3.addSoulGem({ item = ... })
```

**Parameters**:

* `params` (table)
	* `item` ([tes3misc](../../types/tes3misc), string): The item to recognize as a soul gem.

**Returns**:

* `wasAdded` (boolean)

??? example "Example: Make the Dwemer Tube a Soul gem. Also, make sure Fargoth's soul alway ends up in it if the player has one avilable."

	```lua
	local function onInitialized()
	    tes3.addSoulGem({ item = "misc_dwrv_artifact60" })
	end
	event.register(tes3.event.initialized, onInitialized)
	
	local function onFilterSoulGemTarget(e)
	    if (e.reference.baseObject.id:lower() == "fargoth") then
	        return e.soulGem.id == "misc_dwrv_artifact60"
	    end
	end
	event.register(tes3.event.filterSoulGemTarget, onFilterSoulGemTarget)
	
	-- calcSoulValue event allows assigning a new soul value to creatures
	-- If the event was triggered for an NPC, it allows assigning a value
	-- thus allowing soul-trapping the actor.
	local function calcSoulValueCallback(e)
	    if (e.actor.id:lower() == "fargoth") then
	        e.value = 69
	        mwse.log("Getting Fargoth's value.")
	        return
	    end
	end
	event.register(tes3.event.calcSoulValue, calcSoulValueCallback)

	```

***

### `tes3.addSpell`

Adds a spell to an actor's spell list. If the spell is passive, the effects will be applied.

```lua
local wasAdded = tes3.addSpell({ reference = ..., actor = ..., spell = ..., updateGUI = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): Who to give the spell to. To manipulate an actor without specifying any particular reference, use `actor` instead.
	* `actor` ([tes3actor](../../types/tes3actor), string): Who to give the spell to. Providing a base actor can be done before a save has been loaded, but may not correctly update effects for instanced versions of that actor in an active save.
	* `spell` ([tes3spell](../../types/tes3spell), string): The spell to add.
	* `updateGUI` (boolean): *Default*: `true`. If true, the GUI will be updated respsecting the adding of the spell. This can be useful to disable when batch-adding many spells. The batch should be ended with [`tes3.updateMagicGUI`](https://mwse.github.io/MWSE/apis/tes3/#tes3updatemagicgui) to reflect the changes.

**Returns**:

* `wasAdded` (boolean): True if the spell was successfully added. This can be false if the actor's race or birthsign already contains the spell.

***

### `tes3.adjustSoundVolume`

Changes the volume of a sound that is playing on a given reference.

```lua
tes3.adjustSoundVolume({ sound = ..., reference = ..., mixChannel = ..., volume = ... })
```

**Parameters**:

* `params` (table)
	* `sound` ([tes3sound](../../types/tes3sound), string): The sound object, or id of the sound to look for.
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): The reference to attach the sound to.
	* `mixChannel` (number): *Default*: `tes3.soundMix.effects`. The channel to base volume off of. Maps to [`tes3.soundMix`](https://mwse.github.io/MWSE/references/sound-mix-types/) constants.
	* `volume` (number): *Default*: `1.0`. A value between 0.0 and 1.0 to scale the volume off of.

***

### `tes3.advanceTime`

Advances the game time. Can be used to simulate player resting.

```lua
local hoursPassed = tes3.advanceTime({ hours = ..., resting = ..., updateEnvironment = ... })
```

**Parameters**:

* `params` (table)
	* `hours` (number): How many hours to progress.
	* `resting` (boolean): *Optional*. Should advancing time count as resting? If set to true invokes usual sleeping mechanics: health, fatigue and magicka restoration, and possible rest interruption. The length of the rest will be equal to hours parameter, rounded down to nearest natural number.
	* `updateEnvironment` (boolean): *Default*: `true`. Controls if the weather system is updated for each hour passed.

**Returns**:

* `hoursPassed` (number)

***

### `tes3.applyMagicSource`



```lua
local instance = tes3.applyMagicSource({ reference = ..., source = ..., name = ..., effects = ..., createCopy = ..., fromStack = ..., castChance = ..., target = ..., bypassResistances = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): A reference on which the magic source will be applied.
	* `source` ([tes3object](../../types/tes3object)): *Optional*. A magic source to apply.
	* `name` (string): *Optional*. If applying alchemy as a source, you can specifiy a name for the magic source.
	* `effects` (table): *Optional*. A table of custom effects to apply as a potion. Maximal number of effects is 8.
		* `id` (boolean): *Default*: `-1`. ID of the effect.
		* `skill` (number): *Default*: `-1`. If effect parameter specified is: Absorb, Damage, Drain, Fortify or Restore Skill, a skill should be provided. This also applies to any custom spell effect which operates on a certain skill. This value maps to [`tes3.skill`](https://mwse.github.io/MWSE/references/skills/) constants.
		* `attribute` (number): *Default*: `-1`. If effect parameter specified is: Absorb, Damage, Drain, Fortify or Restore Attribute, an attribute should be provided. This also applies to any custom spell effect which operates on a certain attribute. This value maps to [`tes3.attribute`](https://mwse.github.io/MWSE/references/attributes/) constants.
		* `range` (number): *Default*: `tes3.effectRange.self`. The range of the effect. This maps to [`tes3.effectRange`](https://mwse.github.io/MWSE/references/effect-ranges/) constants.
		* `radius` (number): *Default*: `0`. The radius of the effect.
		* `duration` (number): *Default*: `0`. Number of seconds the effect is going to be active.
		* `min` (number): *Default*: `0`. The minimal magintude of the effect per tick.
		* `max` (number): *Default*: `0`. The maximal magnitude of the effect per tick.
	* `createCopy` (boolean): *Optional*. This parameter controls whether the function will return the original magic source or a copy of the magic source. This parameter is only used if source is alchemy.
	* `fromStack` ([tes3equipmentStack](../../types/tes3equipmentStack)): *Optional*. The piece of equipment this magic source is coming from. The fromStack has to be an already equipped item from tes3actor.equipment. This will probably change in the future.
	* `castChance` (number): *Optional*. This parameter allows overriding the casting chance of the magic source.
	* `target` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): *Optional*. The target of the magic.
	* `bypassResistances` (boolean): *Optional*. Is this effect going to bypass magic resistance?

**Returns**:

* `instance` ([tes3magicSourceInstance](../../types/tes3magicSourceInstance))

***

### `tes3.beginTransform`

Changes a reference to werewolf form. This function works only on a reference infected with Lycanthropy, be it the player or any other reference. Returns true if successful.

```lua
local success = tes3.beginTransform({ reference = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference)): A reference to change to werewolf form.

**Returns**:

* `success` (boolean)

***

### `tes3.calculatePrice`

Calculates a price, given a merchant and associated trading data. This is useful beyond accessing the object's `.value` field in that it raises the appropriate events to let other mods modify the values.

```lua
local price = tes3.calculatePrice({ object = ..., basePrice = ..., buying = ..., selling = ..., merchant = ..., bartering = ..., repairing = ..., training = ..., count = ..., itemData = ..., skill = ... })
```

**Parameters**:

* `params` (table)
	* `object` ([tes3object](../../types/tes3object)): *Optional*. The object to calculate the price for. If not provided, `basePrice` is required.
	* `basePrice` (number): *Optional*. The base price to calculate the end price for. This defaults to the `object` param's `value`, if provided. This parameter is required if `object` is not provided.
	* `buying` (boolean): *Default*: `true`. If `true`, uses the logic for buying a service/item. This is exclusive with `selling`.
	* `selling` (boolean): If `true`, uses the logic for selling an item. This is exclusive with `buying`.
	* `merchant` ([tes3mobileActor](../../types/tes3mobileActor)): The merchant to use for calculating the price.
	* `bartering` (boolean): If `true`, a [calcBarterPrice](https://mwse.github.io/MWSE/events/calcBarterPrice) or [calcRepairPrice](https://mwse.github.io/MWSE/events/calcRepairPrice) event will be triggered.
	* `repairing` (boolean): If `true`, a [calcRepairPrice](https://mwse.github.io/MWSE/events/calcRepairPrice) event will be triggered.
	* `training` (boolean): If `true`, a [calcTrainingPrice](https://mwse.github.io/MWSE/events/calcTrainingPrice) event will be triggered, passing the given `skill` ID.
	* `count` (number): *Default*: `1`. If `bartering`, the count passed to the [calcBarterPrice](https://mwse.github.io/MWSE/events/calcBarterPrice) event.
	* `itemData` ([tes3itemData](../../types/tes3itemData)): *Optional*. If `bartering` or `repairing`, the item data passed to the [calcBarterPrice](https://mwse.github.io/MWSE/events/calcBarterPrice) or [calcRepairPrice](https://mwse.github.io/MWSE/events/calcRepairPrice) event.
	* `skill` (number): If `training`, the skill ID passed to the [calcTrainingPrice](https://mwse.github.io/MWSE/events/calcTrainingPrice) event.

**Returns**:

* `price` (number): The calculated price, filtered by events.

***

### `tes3.cancelAnimationLoop`

Signals looping animations on the actor to stop looping and play to the end. The animation will continue, playing past the loop point until the end frame. Useful for exiting looping animations cleanly.

```lua
tes3.cancelAnimationLoop({ reference = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3mobileActor](../../types/tes3mobileActor), [tes3reference](../../types/tes3reference), string): The reference to the actor.

***

### `tes3.canRest`

This function returns true if player can rest.

```lua
local canRest = tes3.canRest({ checkForEnemies = ..., checkForSolidGround = ..., showMessage = ... })
```

**Parameters**:

* `params` (table)
	* `checkForEnemies` (boolean): *Default*: `true`. Perform a check whether there are enemies nearby before opening rest menu. If there are, false is returned.
	* `checkForSolidGround` (boolean): *Default*: `true`. Perform a check if the player is underwater. If underwater, false is returned.
	* `showMessage` (boolean): If true, a messagebox will be shown if the player can't rest because some condition isn't met.

**Returns**:

* `canRest` (boolean)

***

### `tes3.cast`

Casts a spell from a given reference to a target reference. Touch effects will hit the target at any range, while target effects will create a projectile. By default, the spell always casts successfully and does not consume magicka. By default, an actor casting will stop and perform its cast animation, but the 'instant' flag can start the cast instantly, and allow more control over the spell.

When the caster is the player, the target parameter is optional; without a target, the player's touch effects will only hit targets in front of them, and target effects will create a projectile in the direction the player is facing. Currently as a limitation, instant must be true to allow the player to cast spells.

```lua
local executed = tes3.cast({ reference = ..., target = ..., spell = ..., instant = ..., alwaysSucceeds = ..., bypassResistances = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): The caster reference.
	* `target` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): The target reference. Optional only if the caster is the player.
	* `spell` ([tes3spell](../../types/tes3spell), string): The spell the caster uses.
	* `instant` (boolean): When true, the spell is cast instantly. No animation is performed.
	* `alwaysSucceeds` (boolean): *Default*: `true`. When true, the spell cannot fail and does not consume magicka. When false, it is cast using the actor's spell skill, and requires and takes enough magicka to cast. Only applies when 'instant' is true.
	* `bypassResistances` (boolean): The spell will bypass the target's resistances. Only applies when 'instant' is true.

**Returns**:

* `executed` (boolean)

??? example "Example: This is an example of how to use tes3.cast instead of mwscript.explodeSpell"

	```lua
	-- The following code can be tested in-game by pressing Alt + l or Alt + k
	
	event.register(tes3.event.keyDown, function(e)
		if e.isAltDown then
			tes3.messageBox("mwscript.explodeSpell")
			mwscript.explodeSpell({
				reference = tes3.game.playerTarget,
				spell = "proj_trap_spell"
			})
		end
	end, { filter = tes3.scanCode.l })
	
	event.register(tes3.event.keyDown, function(e)
		if e.isAltDown then
			tes3.messageBox("tes3.cast")
			-- This will behave the same as will mwscript.explodeSpell()
			tes3.cast({
				target = tes3.game.playerTarget,
				reference = tes3.game.playerTarget,
				spell = "proj_trap_spell",
			})
		end
	end, { filter = tes3.scanCode.k })

	```

***

### `tes3.checkMerchantOffersService`

Checks if a merchant will offer a service to you, including dialogue checks like disposition and faction membership. A specific service can be checked, or if no service is given, a generic dialogue check is made. If the service is refused, the dialogue reply for the refusal may also be returned (it may be nil, as there may not always be a reply available).

```lua
local offersService, refusalReply = tes3.checkMerchantOffersService(reference, service)
```

**Parameters**:

* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string)
* `service` (number): *Optional*. The specific service to check for availability. Uses the [`tes3.merchantService`](https://mwse.github.io/MWSE/references/merchant-service-types/) constants.

**Returns**:

* `offersService` (boolean)
* `refusalReply` ([tes3dialogueInfo](../../types/tes3dialogueInfo))

***

### `tes3.checkMerchantTradesItem`

Determines if a merchant trades in a given item.

```lua
local trades = tes3.checkMerchantTradesItem({ item = ..., reference = ... })
```

**Parameters**:

* `params` (table)
	* `item` ([tes3item](../../types/tes3item), string)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string)

**Returns**:

* `trades` (boolean)

***

### `tes3.claimSpellEffectId`

This function is used to claim a unique spell effect name and id. This is needed before actually creating a new effect by calling `tes3.addMagicEffect()`. A claimed effect id is then available as: `tes3.effect.effectName` (just like any other spell effect). For examples of this function in practice see [`tes3.addMagicEffect()`](https://mwse.github.io/MWSE/apis/tes3/#tes3addmagiceffect) example.

```lua
tes3.claimSpellEffectId(name, id)
```

**Parameters**:

* `name` (string): The name of the new spell effect. Must be unique. An error will be thrown if it's non-unique.
* `id` (number): A unique number representing the new spell effect. An error will be thrown if it's non-unique.

***

### `tes3.clearMarkLocation`

This function deletes the player's mark location.

```lua
tes3.clearMarkLocation()
```

***

### `tes3.createObject`

Create an object and returns it. The created object will be part of the saved game. Supported object types are those that have their own create function, such as tes3activator for example.

```lua
local createdObject = tes3.createObject({ objectType = ..., getIfExists = ... })
```

**Parameters**:

* `params` (table)
	* `objectType` (number): Maps to [`tes3.objectType`](https://mwse.github.io/MWSE/references/object-types/) constants. Used to filter object type to create.
	* `getIfExists` (boolean): *Default*: `true`. If `true`, an existing object of the same type and ID will be returned instead of creating a new one.

**Returns**:

* `createdObject` ([tes3activator](../../types/tes3activator), [tes3alchemy](../../types/tes3alchemy), [tes3container](../../types/tes3container), [tes3enchantment](../../types/tes3enchantment), [tes3misc](../../types/tes3misc), [tes3sound](../../types/tes3sound), [tes3spell](../../types/tes3spell), [tes3static](../../types/tes3static), [tes3weapon](../../types/tes3weapon))

??? example "Example: Creates a tes3misc object"

	```lua
	local miscItemId = "create_misc_item_id"
	local miscItemName = "create_misc_item_name"
	
	mwse.log( "creating a misc item of id %s", miscItemId )
	
	-- local miscItem = tes3misc.create( {
	--   id = miscItemId,
	--   name = miscItemName
	-- } )
	
	local miscItem = tes3.createObject({
	  objectType = tes3.objectType.miscItem,
	  id = miscItemId,
	  name = miscItemName
	})
	
	if( miscItem ~= nil ) then
	  mwse.log( "misc item created : id is %s", miscItemId )
	else
	  mwse.log( "failed to create a misc item of id %s", miscItemId )
	  return
	end
	
	tes3.createReference( {
	  object = miscItem,
	  position = tes3.getPlayerEyePosition(),
	  orientation = 0,
	  cell = tes3.getPlayerCell()
	} )
	
	mwse.log( "created a reference of a misc item of id %s", miscItem.id )

	```

??? example "Example: Creates a tes3static object"

	```lua
	local staticId = "create_static_id"
	
	mwse.log( "creating a static of id %s", staticId )
	
	-- local static = tes3static.create( {
	--   id = staticId,
	--   mesh = "d\\door_dwrv_main00.nif"
	-- } )
	
	local static = tes3.createObject( {
	  objectType = tes3.objectType.static,
	  id = staticId,
	  mesh = [[d\door_dwrv_main00.nif]]
	} )
	
	if( static ~= nil ) then
	  mwse.log( "static created : id is %s", staticId )
	else
	  mwse.log( "failed to create a static of id %s", staticId )
	  return
	end
	
	tes3.createReference( {
	  object = static,
	  position = tes3.getPlayerEyePosition(),
	  orientation = 0,
	  cell = tes3.getPlayerCell()
	} )
	
	mwse.log( "created a reference of static of id %s", static.id )

	```

***

### `tes3.createReference`

Similar to mwscript's PlaceAtPC or PlaceAtMe, this creates a new reference in the game world.

```lua
local newReference = tes3.createReference({ object = ..., position = ..., orientation = ..., cell = ..., scale = ... })
```

**Parameters**:

* `params` (table)
	* `object` ([tes3physicalObject](../../types/tes3physicalObject), string): The object to create a reference of.
	* `position` ([tes3vector3](../../types/tes3vector3), table): The location to create the reference at.
	* `orientation` ([tes3vector3](../../types/tes3vector3), table): The new orientation for the created reference.
	* `cell` ([tes3cell](../../types/tes3cell), string, table): *Optional*. The cell to create the reference in. This is only needed for interior cells.
	* `scale` (number): *Default*: `1`. A scale for the reference.

**Returns**:

* `newReference` ([tes3reference](../../types/tes3reference))

***

### `tes3.decrementKillCount`

Decreases player's kill count of a certain type of actor by one.

```lua
tes3.decrementKillCount({ actor = ... })
```

**Parameters**:

* `params` (table)
	* `actor` ([tes3actor](../../types/tes3actor), string): The actor (or their ID).

***

### `tes3.deleteObject`

Deletes a game object from the system. This can be dangerous, use with caution.

```lua
tes3.deleteObject(object)
```

**Parameters**:

* `object` ([tes3object](../../types/tes3object)): The object to delete.

***

### `tes3.disableKey`

Disables the use of a keyboard key.

```lua
tes3.disableKey(keyCode)
```

**Parameters**:

* `keyCode` (number): Maps to values in [`tes3.scanCode`](https://mwse.github.io/MWSE/references/scan-codes/) namespace.

***

### `tes3.dropItem`

Drops one or more items from a reference's inventory onto the ground at their feet. It will unequip the item if it is equipped. The return value will be nil if no matching item was found.

```lua
local createdReference = tes3.dropItem({ reference = ..., item = ..., itemData = ..., matchNoItemData = ..., count = ..., updateGUI = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3mobileActor](../../types/tes3mobileActor), [tes3reference](../../types/tes3reference), string): The reference whose inventory will be modified.
	* `item` ([tes3item](../../types/tes3item), string): The item to drop.
	* `itemData` ([tes3itemData](../../types/tes3itemData)): *Optional*. The item data of the specific item to drop. Without this, the first matching item in the inventory will drop.
	* `matchNoItemData` (boolean): If true, matches an item without item data. This can be used when you want to drop an item that isn't equipped (equipped items always have item data).
	* `count` (number): *Default*: `1`. The number of items to drop.
	* `updateGUI` (boolean): *Default*: `true`. If false, the player or contents menu won't be updated.

**Returns**:

* `createdReference` ([tes3reference](../../types/tes3reference))

***

### `tes3.enableKey`

Enables the use of a keyboard key.

```lua
tes3.enableKey(keyCode)
```

**Parameters**:

* `keyCode` (number): Maps to values in [`tes3.scanCode`](https://mwse.github.io/MWSE/references/scan-codes/) namespace.

***

### `tes3.fadeIn`

Similar to the vanilla FadeIn mwscript command.

```lua
tes3.fadeIn({ fader = ..., duration = ... })
```

**Parameters**:

* `params` (table)
	* `fader` ([tes3fader](../../types/tes3fader)): *Optional*. Defaults to the transition fader.
	* `duration` (number): *Default*: `1.0`. Time, in seconds, for the fade.

***

### `tes3.fadeOut`

Similar to the vanilla FadeOut mwscript command.

```lua
tes3.fadeOut({ fader = ..., duration = ... })
```

**Parameters**:

* `params` (table)
	* `fader` ([tes3fader](../../types/tes3fader)): *Optional*. Defaults to the transition fader.
	* `duration` (number): *Default*: `1.0`. Time, in seconds, for the fade.

***

### `tes3.fadeTo`

Similar to the vanilla FadeTo mwscript command.

```lua
tes3.fadeTo({ fader = ..., duration = ..., value = ... })
```

**Parameters**:

* `params` (table)
	* `fader` ([tes3fader](../../types/tes3fader)): *Optional*. Defaults to the transition fader.
	* `duration` (number): *Default*: `1.0`. Time, in seconds, for the fade.
	* `value` (number): *Default*: `1.0`.

***

### `tes3.findActorsInProximity`

Searches for active mobile actors which are within `range` distance from the `reference` or `position` argument. It only finds mobiles which have active AI, and can include the player. This function is used by the game for area-of-effect hits. It has a small amount of overhead, so try not to use it too much.

```lua
local mobileList = tes3.findActorsInProximity({ reference = ..., position = ..., range = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): *Optional*. The position to search from, taken from a reference. Uses the position of the centre of the body if the reference is an actor.
	* `position` ([tes3vector3](../../types/tes3vector3)): *Optional*. The position to search from.
	* `range` (number): The distance around the position to search. An actor is included if the centre of their body is in range.

**Returns**:

* `mobileList` (table)

***

### `tes3.findBirthsign`

Fetches the core game birthsign object for a given birthsign ID. If the birthsign with a given ID doesn't exist, nil is returned.

```lua
local birthsign = tes3.findBirthsign({ id = ... })
```

**Parameters**:

* `params` (table)
	* `id` (string): ID of the birthsign to search for.

**Returns**:

* `birthsign` ([tes3birthsign](../../types/tes3birthsign))

***

### `tes3.findClass`

Fetches the core game character class object for a given class ID. If the class with a given ID doesn't exist, nil is returned.

```lua
local class = tes3.findClass({ id = ... })
```

**Parameters**:

* `params` (table)
	* `id` (string): ID of the class to search for.

**Returns**:

* `class` ([tes3class](../../types/tes3class))

***

### `tes3.findClosestExteriorReferenceOfObject`

Using the same engine function used by the vanilla intervention spells, locations the first reference of a given object in the exterior world.

```lua
local reference = tes3.findClosestExteriorReferenceOfObject({ object = ..., position = ... })
```

**Parameters**:

* `params` (table)
	* `object` ([tes3physicalObject](../../types/tes3physicalObject), string): The object to search for.
	* `position` ([tes3vector3](../../types/tes3vector3)): *Optional*. The position to search from. Must be an exterior position. Defaults to the last exterior position of the player if no position is provided.

**Returns**:

* `reference` ([tes3reference](../../types/tes3reference))

***

### `tes3.findDialogue`

Locates a root dialogue topic that can then be filtered down for a specific actor to return a specific dialogue info. Specify either `topic`, or both `type` and `page` for other types of dialogue.

For example, `tes3.findDialogue({type = tes3.dialogueType.greeting, page = tes3.dialoguePage.greeting.greeting0})` will return the "Greeting 0" topic, which is not available using a topic ID.

```lua
local dialogue = tes3.findDialogue({ topic = ..., type = ..., page = ... })
```

**Parameters**:

* `params` (table)
	* `topic` (string): *Optional*. The dialogue topic to look for.
	* `type` (number): *Optional*. The type of dialogue to look for. Uses [`tes3.dialogueType`](https://mwse.github.io/MWSE/references/dialogue-types/) constants.
	* `page` (number): *Optional*. The page of dialogue to fetch. Uses [`tes3.dialoguePage`](https://mwse.github.io/MWSE/references/dialogue-pages/) constants.

**Returns**:

* `dialogue` ([tes3dialogue](../../types/tes3dialogue))

***

### `tes3.findGlobal`

Fetches the core game object that represents a global variable.

```lua
local globalVariable = tes3.findGlobal(id)
```

**Parameters**:

* `id` (string)

**Returns**:

* `globalVariable` ([tes3globalVariable](../../types/tes3globalVariable))

***

### `tes3.findGMST`

Fetches the core game object that represents a game setting. While this function accepts a name, it is recommended to use the [`tes3.GMST`](https://mwse.github.io/MWSE/references/gmst/) constants.

```lua
local gameSetting = tes3.findGMST(id)
```

**Parameters**:

* `id` (number, string)

**Returns**:

* `gameSetting` ([tes3gameSetting](../../types/tes3gameSetting))

??? example "Example: Document all GMST Default Values"

	```lua
	-- Converter table for a GMST's type to something more user-friendly.
	local typeNames = {
		s = "string",
		i = "integer",
		f = "float",
	}
	
	-- Write our markdown header.
	local f = assert(io.open("Data Files\\MWSE\\tmp\\GMSTs.md", "w"))
	f:write("# GMSTs\n\n")
	f:write("Index | Type	| Identifier					   | Default Value\n")
	f:write("----- | ------- | -------------------------------- | --------------------------------------------\n")
	
	-- Go through all our GMSTs...
	for id = 0, 1520 do
		-- Write out most of the info.
		local gmst = tes3.findGMST(id)
		f:write(string.format("%-5d | %-7s | %-32s | ", gmst.index, typeNames[gmst.type], gmst.id))
	
		-- Customize how the value is written based on its type.
		if (gmst.type == "s") then
			-- Remove linebreaks and escape them.
			local value = gmst.defaultValue
			value = string.gsub(value, "\r", "\\r")
			value = string.gsub(value, "\n", "\\n")
			f:write(string.format("`\"%s\"`", value))
		elseif (gmst.type == "f") then
			f:write(string.format("`%.4f`", gmst.defaultValue))
		else
			f:write(string.format("`%d`", gmst.defaultValue))
		end
	
		f:write("\n")
	end
	
	-- Close up our file.
	f:close()

	```

??? example "Example: Retrieve value of a GMST"

	```lua
	local oldGMST = tes3.findGMST("sServiceTrainingTitle").value
	
	-- oldGMST is now "Training"
	
	-- Now let's change the message to something more appropriate.
	tes3.findGMST("sServiceTrainingTitle").value = "Cheat"

	```

***

### `tes3.findRegion`

Fetches the core game region object for a given region ID. If the region with a given ID doesn't exist, nil is returned.

```lua
local region = tes3.findRegion({ id = ... })
```

**Parameters**:

* `params` (table)
	* `id` (string): ID of the region to search for.

**Returns**:

* `region` ([tes3region](../../types/tes3region))

***

### `tes3.force1stPerson`

Forces the player's POV to first person the next simulation frame, and returns true if the POV has been changed.

```lua
local changedPOV = tes3.force1stPerson()
```

**Returns**:

* `changedPOV` (boolean)

***

### `tes3.force3rdPerson`

Forces the player's POV to third person the next simulation frame, and returns true if the POV has been changed.

```lua
local changedPOV = tes3.force3rdPerson()
```

**Returns**:

* `changedPOV` (boolean)

***

### `tes3.get3rdPersonCameraOffset`

Returns the camera's offset from the player's head while in 3rd person view.

Note this function can be used once WorldController and MobilePlayer have finished initializing.

```lua
local cameraOffset = tes3.get3rdPersonCameraOffset()
```

**Returns**:

* `cameraOffset` ([tes3vector3](../../types/tes3vector3))

***

### `tes3.getActiveCells`

Returns a table of active cells. If indoors, the table will have only one entry. If outdoors, the 9 surrounding cells will be provided.

```lua
local cells = tes3.getActiveCells()
```

**Returns**:

* `cells` (table)

***

### `tes3.getAnimationGroups`

This function fetches a reference's attached animation groups.

```lua
local animData = tes3.getAnimationGroups({ reference = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference)): A reference whose animation groups to fetch.

**Returns**:

* `animData` (table)

***

### `tes3.getAnimationTiming`

This function fetches a reference's attached animation groups' timings.

```lua
local result = tes3.getAnimationTiming({ reference = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): A reference whose animation groups' timings to fetch.

**Returns**:

* `result` (table)

***

### `tes3.getArchiveList`

Returns a 1-indexed table of active archives.

```lua
local archives = tes3.getArchiveList()
```

**Returns**:

* `archives` (table)

***

### `tes3.getAttachment`

Fetches an attachment with a given type.

```lua
tes3.getAttachment(reference, attachment)
```

**Parameters**:

* `reference` ([tes3reference](../../types/tes3reference))
* `attachment` (string)

***

### `tes3.getAttributeName`

Returns the lowercase identifying name of an attribute for a given numerical, 0-based index. E.g. "strength".

```lua
local name = tes3.getAttributeName(attributeId)
```

**Parameters**:

* `attributeId` (number): The attribute id to get the name of, from tes3.attributeName constants.

**Returns**:

* `name` (string)

***

### `tes3.getCameraPosition`

Returns the camera's position.

```lua
local vector3 = tes3.getCameraPosition()
```

**Returns**:

* `vector3` ([tes3vector3](../../types/tes3vector3))

***

### `tes3.getCameraVector`

Returns the camera look vector.

```lua
local vector3 = tes3.getCameraVector()
```

**Returns**:

* `vector3` ([tes3vector3](../../types/tes3vector3))

***

### `tes3.getCell`

Finds a cell, either by an id or an X/Y grid position.

```lua
local cell = tes3.getCell({ id = ..., x = ..., y = ... })
```

**Parameters**:

* `params` (table)
	* `id` (string): The cell's ID. If not provided, x and y must be.
	* `x` (number)
	* `y` (number)

**Returns**:

* `cell` ([tes3cell](../../types/tes3cell))

***

### `tes3.getCumulativeDaysForMonth`

Gets the number of days that have passed leading up to the start of a given month.

```lua
local days = tes3.getCumulativeDaysForMonth(month)
```

**Parameters**:

* `month` (number): The 0-based month index.

**Returns**:

* `days` (number)

***

### `tes3.getCurrentAIPackageId`

Returns an actor's current AI package ID, just as the mwscript function `GetCurrentAIPackage` would.

```lua
local packageID = tes3.getCurrentAIPackageId(reference)
```

**Parameters**:

* `reference` ([tes3mobileActor](../../types/tes3mobileActor), [tes3reference](../../types/tes3reference))

**Returns**:

* `packageID` (number)

***

### `tes3.getCurrentWeather`

Gets the currently active weather, from the player's current region.

```lua
local weather = tes3.getCurrentWeather()
```

**Returns**:

* `weather` ([tes3weather](../../types/tes3weather))

***

### `tes3.getCursorPosition`

Returns a table with values x and y that contain the current cursor position.

```lua
local table = tes3.getCursorPosition()
```

**Returns**:

* `table` (table)

***

### `tes3.getDaysInMonth`

Returns the number of days in a given month. This may be altered if a Morrowind Code Patch feature was installed.

```lua
local dayCount = tes3.getDaysInMonth(month)
```

**Parameters**:

* `month` (number)

**Returns**:

* `dayCount` (number)

***

### `tes3.getDialogueInfo`

Locates and returns a Dialogue Info by a given id. This involves file IO and is an expensive call. Results should be cached.

```lua
local dialogueInfo = tes3.getDialogueInfo(dialogue, id)
```

**Parameters**:

* `dialogue` ([tes3dialogue](../../types/tes3dialogue), string): The dialogue that the info belongs to.
* `id` (string): The numerical, unique id for the info object.

**Returns**:

* `dialogueInfo` ([tes3dialogueInfo](../../types/tes3dialogueInfo))

***

### `tes3.getEffectMagnitude`

This function returns the total magnitude and total unresisted magnitude of a certain spell effect affecting a reference. It returns a pair of numbers, the first being the post-resistance magnitude (see examples). The unresisted magnitude is the magnitude before the actor's resistances are applied; it is always an integer, so it is used in some UI elements.

```lua
local magnitude, unresistedMagnitude = tes3.getEffectMagnitude({ reference = ..., effect = ..., skill = ..., attribute = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): An associated mobile should exist for this function to be able to work.
	* `effect` (number): Effect ID. Can be any of the predefined spell effects, or one added by `tes3.claimSpellEffectId()`. Maps to values of [`tes3.effect`](https://mwse.github.io/MWSE/references/magic-effects/) constants
	* `skill` (number): *Default*: `-1`. If effect parameter specified is: Absorb, Damage, Drain, Fortify or Restore Skill, a skill should be provided. This also applies to any custom spell effect which operates on a certain skill. This value maps to [`tes3.skill`](https://mwse.github.io/MWSE/references/skills/) constants.
	* `attribute` (number): *Default*: `-1`. If effect parameter specified is: Absorb, Damage, Drain, Fortify or Restore Attribute, an attribute should be provided. This also applies to any custom spell effect which operates on a certain attribute. This value maps to [`tes3.attribute`](https://mwse.github.io/MWSE/references/attributes/) constants.

**Returns**:

* `magnitude, unresistedMagnitude` (number, number)

??? example "Example: Get both magnitudes."

	```lua
	local magnitude, unresistedMagnitude = tes3.getEffectMagnitude{reference = tes3.player, effect = tes3.effect.fireDamage}
	tes3.messageBox(string.format("fortify speed: %f (%f)", magnitude, unresistedMagnitude))

	```

??? example "Example: Get magnitude after resistances are applied."

	```lua
	local magnitude = tes3.getEffectMagnitude{reference = tes3.player, effect = tes3.effect.fortifyAttribute, attribute = tes3.attribute.speed}
	tes3.messageBox(string.format("fortify speed: %f", magnitude))

	```

***

### `tes3.getEquippedItem`

Returns an actor's equipped item stack, provided a given filter

```lua
local stack = tes3.getEquippedItem({ actor = ..., enchanted = ..., objectType = ..., slot = ..., type = ... })
```

**Parameters**:

* `params` (table)
	* `actor` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), [tes3actor](../../types/tes3actor))
	* `enchanted` (boolean): *Optional*. If true, filters to enchanted items.
	* `objectType` (number): *Optional*. Maps to [`tes3.objectType`](https://mwse.github.io/MWSE/references/object-types/) constants. Used to filter equipment by type.
	* `slot` (number): *Optional*. Maps to [`tes3.armorSlot`](https://mwse.github.io/MWSE/references/armor-slots/) or [`tes3.clothingSlot`](https://mwse.github.io/MWSE/references/clothing-slots/). Used to filter equipment by slot.
	* `type` (number): *Optional*. Maps to [`tes3.weaponType`](https://mwse.github.io/MWSE/references/weapon-types/). Used to filter equipment by type.

**Returns**:

* `stack` ([tes3equipmentStack](../../types/tes3equipmentStack))

??? example "Example: Get Player’s Equipped Light"

	```lua
	local equippedLightStack = tes3.getEquippedItem({ actor = tes3.player, objectType = tes3.objectType.light })
	if (equippedLightStack) then
		mwse.log("Equipped light: %s", equippedLightStack.object.id)
	else
		mwse.log("No light equipped.")
	end

	```

??? example "Example: Get Player’s Shield"

	```lua
	local equippedShieldStack = tes3.getEquippedItem({ actor = tes3.player, objectType = tes3.objectType.armor, slot = tes3.armorSlot.shield })
	if (equippedShieldStack) then
		mwse.log("Equipped shield: %s", equippedShieldStack.object.id)
	else
		mwse.log("No shield equipped.")
	end

	```

***

### `tes3.getFaction`

Fetches the core game faction object for a given faction ID.

```lua
local faction = tes3.getFaction(id)
```

**Parameters**:

* `id` (string)

**Returns**:

* `faction` ([tes3faction](../../types/tes3faction))

***

### `tes3.getFileExists`

Determines if a file exists in the user's Data Files.

```lua
local exists = tes3.getFileExists(path)
```

**Parameters**:

* `path` (string)

**Returns**:

* `exists` (boolean)

***

### `tes3.getFileSource`

Determines if a file exists on the filesystem or inside of a bsa. The returned string will be "file" or "bsa".

```lua
local exists = tes3.getFileSource(path)
```

**Parameters**:

* `path` (string)

**Returns**:

* `exists` (string)

***

### `tes3.getGlobal`

Retrieves the value of a global value, or nil if the global could not be found.

```lua
local value = tes3.getGlobal(id)
```

**Parameters**:

* `id` (string)

**Returns**:

* `value` (number)

***

### `tes3.getInputBinding`

Gets the input configuration for a given keybind.

```lua
local inputConfig = tes3.getInputBinding(keybind)
```

**Parameters**:

* `keybind` (number): Maps to [`tes3.keybind`](https://mwse.github.io/MWSE/references/keybinds/) constants.

**Returns**:

* `inputConfig` ([tes3inputConfig](../../types/tes3inputConfig))

***

### `tes3.getItemCount`

Returns the amount of a certain item that can be found in a reference's inventory.

```lua
local count = tes3.getItemCount({ reference = ..., item = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): The reference to get the item count for. Must be a reference that has an inventory.
	* `item` ([tes3item](../../types/tes3item), string): The item to get the count of.

**Returns**:

* `count` (number): The absolute value of the stack count in the reference's inventory.

***

### `tes3.getItemIsStolen`

This function checks item's stolen flag.

```lua
local isStolen = tes3.getItemIsStolen(item, from)
```

**Parameters**:

* `item` ([tes3item](../../types/tes3item)): The item to check.
* `from` ([tes3baseObject](../../types/tes3baseObject)): Where the item was stolen from.

**Returns**:

* `isStolen` (boolean)

***

### `tes3.getJournalIndex`

Gets the index of a given journal, or nil if no valid journal could be found.

```lua
local index = tes3.getJournalIndex({ id = ... })
```

**Parameters**:

* `params` (table)
	* `id` ([tes3dialogue](../../types/tes3dialogue), string)

**Returns**:

* `index` (number)

***

### `tes3.getKillCount`

Returns how many times the player killed an actor. If no actor is specified, total number of kills player commited will be returned.

```lua
local count = tes3.getKillCount({ actor = ... })
```

**Parameters**:

* `params` (table)
	* `actor` ([tes3actor](../../types/tes3actor), string): *Optional*. The actor (or their ID) for whom to retrieve player's kill count.

**Returns**:

* `count` (number)

***

### `tes3.getKillCounts`

Returns a table with complete player kill counts. The table returned is formated so actor IDs are table keys and kill count of that type of actor is value.

```lua
local killMap = tes3.getKillCounts()
```

**Returns**:

* `killMap` (table)

***

### `tes3.getLanguage`

Gets the language as an ISO string (e.g. "eng"), determined by the language entry in Morrowind.ini and the detected executable.

```lua
local code = tes3.getLanguage()
```

**Returns**:

* `code` (string)

***

### `tes3.getLanguageCode`

Gets the language code, determined by the language entry in Morrowind.ini and the detected executable.

```lua
local code = tes3.getLanguageCode()
```

**Returns**:

* `code` (number)

***

### `tes3.getLastExteriorPosition`

Returns the last exterior position of the player.

```lua
local vector3 = tes3.getLastExteriorPosition()
```

**Returns**:

* `vector3` ([tes3vector3](../../types/tes3vector3))

***

### `tes3.getLocked`

Determines if a given reference is a locked door or container.

```lua
local isLocked = tes3.getLocked({ reference = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string)

**Returns**:

* `isLocked` (boolean)

***

### `tes3.getLockLevel`

Gets an locked reference's lock level. If no lock data is available, it will return nil.

```lua
local level = tes3.getLockLevel({ reference = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string)

**Returns**:

* `level` (number)

***

### `tes3.getMagicEffect`

Fetches the core game Magic Effect object for a given ID.

```lua
local magicEffect = tes3.getMagicEffect(id)
```

**Parameters**:

* `id` (number)

**Returns**:

* `magicEffect` ([tes3magicEffect](../../types/tes3magicEffect))

***

### `tes3.getMagicEffectName`

Returns the complex name of a magic effect, taking into account attribute or skill values.

```lua
local complexName = tes3.getMagicEffectName({ effect = ..., attribute = ..., skill = ... })
```

**Parameters**:

* `params` (table)
	* `effect` (number): The effect ID to get the name of.
	* `attribute` (number): *Optional*. The attribute ID to use, if applicable.
	* `skill` (number): *Optional*. The skill ID to use, if applicable.

**Returns**:

* `complexName` (string)

***

### `tes3.getMagicSourceInstanceBySerial`

Fetches an instance of the magic source of a given serial number.

```lua
local magicSourceInstance = tes3.getMagicSourceInstanceBySerial({ serialNumber = ... })
```

**Parameters**:

* `params` (table)
	* `serialNumber` (number)

**Returns**:

* `magicSourceInstance` ([tes3magicSourceInstance](../../types/tes3magicSourceInstance))

***

### `tes3.getModList`

Fetches the list of the active ESM and ESP files.

```lua
local modList = tes3.getModList()
```

**Returns**:

* `modList` (table)

***

### `tes3.getObject`

Fetches the core game object for a given object ID.

```lua
local object = tes3.getObject(id)
```

**Parameters**:

* `id` (string)

**Returns**:

* `object` ([tes3object](../../types/tes3object))

***

### `tes3.getOwner`

Returns the object's owner, or nil if the object is unowned.

```lua
local object = tes3.getOwner(reference)
```

**Parameters**:

* `reference` ([tes3reference](../../types/tes3reference))

**Returns**:

* `object` ([tes3object](../../types/tes3object))

***

### `tes3.getPlayerActivationDistance`

This function returns the distance that the player can activate objects with. This is a sum of the iMaxActivateDist GMST value and the player's telekinesis strength.

```lua
local result = tes3.getPlayerActivationDistance()
```

**Returns**:

* `result` (number)

***

### `tes3.getPlayerCell`

Fetches the cell that the player is currently in.

```lua
local result = tes3.getPlayerCell()
```

**Returns**:

* `result` ([tes3cell](../../types/tes3cell))

***

### `tes3.getPlayerEyePosition`

Returns the position of the player's eyes.

```lua
local position = tes3.getPlayerEyePosition()
```

**Returns**:

* `position` ([tes3vector3](../../types/tes3vector3))

***

### `tes3.getPlayerEyeVector`

Returns the look direction of the player's eyes.

```lua
local position = tes3.getPlayerEyeVector()
```

**Returns**:

* `position` ([tes3vector3](../../types/tes3vector3))

***

### `tes3.getPlayerGold`

Gets the gold count carried by the player.

```lua
local goldCount = tes3.getPlayerGold()
```

**Returns**:

* `goldCount` (number)

***

### `tes3.getPlayerTarget`

This function is used to see what the player is looking at. Unlike a real raycast, this does not work in all circumstances. As a general rule, it will return the reference if the information box is shown when it is looked at.

```lua
local result = tes3.getPlayerTarget()
```

**Returns**:

* `result` ([tes3reference](../../types/tes3reference))

***

### `tes3.getQuickKey`

This function retrieves data for a quick key.

```lua
local result = tes3.getQuickKey({ slot = ... })
```

**Parameters**:

* `params` (table)
	* `slot` (number): The key to retrieve data for. This is a value between 1 and 9.

**Returns**:

* `result` ([tes3quickKey](../../types/tes3quickKey))

***

### `tes3.getReference`

Fetches the first reference for a given base object ID.

```lua
local reference = tes3.getReference(id)
```

**Parameters**:

* `id` (string)

**Returns**:

* `reference` ([tes3reference](../../types/tes3reference))

***

### `tes3.getRegion`

Gets the current region the player is in. This checks the player's current cell first, but will fall back to the last exterior cell.

```lua
local region = tes3.getRegion(useDoors)
```

**Parameters**:

* `useDoors` (boolean): *Optional*.

**Returns**:

* `region` ([tes3region](../../types/tes3region))

***

### `tes3.getScript`

Locates and returns a script by a given id.

```lua
local script = tes3.getScript(id)
```

**Parameters**:

* `id` (string)

**Returns**:

* `script` ([tes3script](../../types/tes3script))

***

### `tes3.getSimulationTimestamp`

Returns a UNIX-style timestamp based on in-world simulation time since the start of the era.

```lua
local timestamp = tes3.getSimulationTimestamp()
```

**Returns**:

* `timestamp` (number)

***

### `tes3.getSkill`

Fetches the core game object for a given skill ID.

```lua
local skill = tes3.getSkill(id)
```

**Parameters**:

* `id` (number): Maps to [`tes3.skill`](https://mwse.github.io/MWSE/references/skills/) constants.

**Returns**:

* `skill` ([tes3skill](../../types/tes3skill))

***

### `tes3.getSkillName`

Returns the identifying name of a skill for a given numerical, 0-based index. E.g. "Enchant".

```lua
local name = tes3.getSkillName()
```

**Returns**:

* `name` (string)

***

### `tes3.getSound`

Locates and returns a sound by a given id.

```lua
local sound = tes3.getSound(id)
```

**Parameters**:

* `id` (string)

**Returns**:

* `sound` ([tes3sound](../../types/tes3sound))

***

### `tes3.getSoundGenerator`

Returns a sound generator by a given creature id and type.

```lua
local soundGenerator = tes3.getSoundGenerator(creatureId, soundType)
```

**Parameters**:

* `creatureId` (string)
* `soundType` (number): Maps to [`tes3.soundGenType`](https://mwse.github.io/MWSE/references/sound-generator-types/) constants.

**Returns**:

* `soundGenerator` ([tes3soundGenerator](../../types/tes3soundGenerator))

***

### `tes3.getSoundPlaying`

Without a reference, this function returns true if the sound is playing unattached or on any reference. With a reference, it returns true if the sound is playing on that specific reference.

```lua
local soundIsPlaying = tes3.getSoundPlaying({ sound = ..., reference = ... })
```

**Parameters**:

* `params` (table)
	* `sound` ([tes3sound](../../types/tes3sound), string): The sound object, or the ID of the sound to look for.
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): *Optional*.

**Returns**:

* `soundIsPlaying` (boolean)

***

### `tes3.getSpecializationName`

Returns the lowercase identifying name of a specialization type for a given numerical, 0-based index. E.g. "magic".

```lua
local name = tes3.getSpecializationName()
```

**Returns**:

* `name` (string)

***

### `tes3.getTopMenu`

Gets the top-level UI menu.

```lua
local menu = tes3.getTopMenu()
```

**Returns**:

* `menu` ([tes3uiElement](../../types/tes3uiElement))

***

### `tes3.getTrap`

Gets the trap on a given reference.

```lua
local spell = tes3.getTrap({ reference = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string)

**Returns**:

* `spell` ([tes3spell](../../types/tes3spell))

***

### `tes3.getVanityMode`

The function returns true if the player is in the vanity mode. Vanity mode is triggered by a period of inactivity from the player or by a `tes3.setVanityMode()` function. The view is switched to third person (if not already), and the camera is orbiting slowly around the player character.

```lua
local result = tes3.getVanityMode()
```

**Returns**:

* `result` (boolean): Is the vanity mode currently active?

***

### `tes3.getViewportSize`

Returns both the viewport width and the viewport height. Note that this is the real resolution of the screen. For a value scaled by MGE's menu scaling, see the [same-named function](https://mwse.github.io/MWSE/apis/tes3ui/#tes3uigetviewportsize) in the tes3ui namespace. To get the scale used, check [getViewportScale](https://mwse.github.io/MWSE/apis/tes3ui/#tes3uigetviewportscale) in the tes3ui namespace.

```lua
local width, height = tes3.getViewportSize()
```

**Returns**:

* `width` (number): The width of the viewport.
* `height` (number): The height of the viewport.

***

### `tes3.getWerewolfKillCount`

Returns the number of kills player commited as a Werewolf.

```lua
local werewolfKills = tes3.getWerewolfKillCount()
```

**Returns**:

* `werewolfKills` (number)

***

### `tes3.hammerKey`

Simulates hammering a key.

```lua
tes3.hammerKey(keyCode)
```

**Parameters**:

* `keyCode` (number)

***

### `tes3.hasCodePatchFeature`

Attempts to determine if a given Morrowind Code Patch feature is enabled. This may not be possible, in which case nil will be returned.

```lua
local state = tes3.hasCodePatchFeature(id)
```

**Parameters**:

* `id` (number): The id of the feature. Maps to values in [`tes3.codePatchFeature`](https://mwse.github.io/MWSE/references/code-patch-features/) constants.

**Returns**:

* `state` (boolean, nil)

***

### `tes3.hasOwnershipAccess`

Determines if a reference has access to another object, including its inventory. References have access to their own things, and the player has access to dead NPC's items.

```lua
local hasAccess = tes3.hasOwnershipAccess({ reference = ..., target = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): *Default*: `tes3.player`. The actor to check permissions for.
	* `target` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): The reference to check access of.

**Returns**:

* `hasAccess` (boolean)

***

### `tes3.hasSpell`

Determines if the player has access to a given spell.

```lua
local hasSpell = tes3.hasSpell({ reference = ..., actor = ..., spell = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): Who to check the spell list of. To check an actor without specifying any particular reference, use `actor` instead.
	* `actor` ([tes3actor](../../types/tes3actor), string): Who to check the spell list of. Providing a base actor can be done before a save has been loaded, but may not correctly update effects for instanced versions of that actor in an active save.
	* `spell` ([tes3spell](../../types/tes3spell), string): The spell to check.

**Returns**:

* `hasSpell` (boolean): True if the spell exists in the actor's spell list, race spell list, or birthsign spell list.

***

### `tes3.incrementKillCount`

Increases player's kill count of a certain type of actor by one.

```lua
tes3.incrementKillCount({ actor = ... })
```

**Parameters**:

* `params` (table)
	* `actor` ([tes3actor](../../types/tes3actor), string): The actor (or their ID) for whom to increase player's kill count.

***

### `tes3.is3rdPerson`

Returns if the game is in 3rd person.

```lua
local state = tes3.is3rdPerson()
```

**Returns**:

* `state` (boolean)

***

### `tes3.isAffectedBy`

This function performs a check whether the provided reference is affected by a certain object or magic effect.

Note `reference.object.spells:contains(spellID)` will give the same output as this function for abilities, diseases, and curses, because having them in your spell list also makes them affect you.

```lua
local isAffectedBy = tes3.isAffectedBy({ reference = ..., effect = ..., object = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string)
	* `effect` (number): *Optional*. A numerical identifier of the magic effect to perform a check for. Maps to [`tes3.effect`](https://mwse.github.io/MWSE/references/magic-effects/) constant, including those claimed with `tes3.claimSpellEffectId()`, and then added with `tes3.addMagicEffect()`.
	* `object` ([tes3alchemy](../../types/tes3alchemy), [tes3enchantment](../../types/tes3enchantment), [tes3spell](../../types/tes3spell), [tes3magicEffect](../../types/tes3magicEffect), string): *Optional*. An object to perform a check for.

**Returns**:

* `isAffectedBy` (boolean)

***

### `tes3.isKeyEqual`

Compares two key objects and returns their equality. Returns true if the objects are equal, false otherwise.

```lua
local equal = tes3.isKeyEqual({ actual = ..., expected = ... })
```

**Parameters**:

* `params` (table)
	* `actual` (table): The key object that is being compared.
		* `keyCode` (number): Value of the actual key scan code, such as the letter `p`. Maps to [`tes3.scanCode.*`](https://mwse.github.io/MWSE/references/scan-codes/).
		* `isShiftDown` (boolean): Value of whether the shift key is pressed.
		* `isControlDown` (boolean): Value of whether the control key is pressed.
		* `isAltDown` (boolean): Value of whether the alt key is pressed.
		* `isSuperDown` (boolean): Value of whether the super (Windows key) key is pressed.
	* `expected` (table): The key object that is being compared against.
		* `keyCode` (number): Value of the expected key scan code, such as the letter `p`. Maps to [`tes3.scanCode.*`](https://mwse.github.io/MWSE/references/scan-codes/).
		* `isShiftDown` (boolean): Value of whether the shift key is expected to be pressed.
		* `isControlDown` (boolean): Value of whether the control key is expected to be pressed.
		* `isAltDown` (boolean): Value of whether the alt key is expected to be pressed.
		* `isSuperDown` (boolean): Value of whether the super (Windows key) key is pressed.

**Returns**:

* `equal` (boolean)

***

### `tes3.isModActive`

Determines if the player has a given ESP or ESM file active.

```lua
local result = tes3.isModActive(filename)
```

**Parameters**:

* `filename` (string): The filename of the mod to find, including the extension.

**Returns**:

* `result` (boolean)

***

### `tes3.iterate`

This function returns a function that iterates over a tes3iterator object. This is useful for for loops.
		
Note that tes3iterator objects support iteration with `pairs()` function.

```lua
local function = tes3.iterate(iterator)
```

**Parameters**:

* `iterator` ([tes3iterator](../../types/tes3iterator))

**Returns**:

* `function` (function)

***

### `tes3.iterateObjects`

Iteration function used for looping over game options.

```lua
local object = tes3.iterateObjects(filter)
```

**Parameters**:

* `filter` (number): Maps to [`tes3.objectType`](https://mwse.github.io/MWSE/references/object-types/) constants.

**Returns**:

* `object` ([tes3object](../../types/tes3object))

***

### `tes3.loadAnimation`

Loads an animation and uses it to override existing animations on an actor. Animation groups present in the file will replace the actor's animation groups. The actor's model must be already loaded into memory to have its animations modified. The overridden animations only persist until the actor is unloaded.

Calling this more than once will remove the previous animation override before loading the new animation. Therefore, if applying animations to the player, you should call this before every playAnimation so that different animation mods can co-exist. For NPCs under your mod's control, you only need to do it when the player enters the cell containing the NPC.

Calling this without a file argument will reset the reference's animations to default.

```lua
tes3.loadAnimation({ reference = ..., file = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3mobileActor](../../types/tes3mobileActor), [tes3reference](../../types/tes3reference), string): The reference to the actor that is having its animations modified.
	* `file` (string): *Optional*. The specified animation base file that will be loaded. e.g. For an animation composed of files anim.nif, xanim.nif and xanim.kf, you should pass file="anim.nif". The animation target skeleton _must_ match the skeleton of the actor to work. i.e. 3rd person anims for NPCs and tes3.player, 1st person anims for firstPersonReference.

***

### `tes3.loadGame`

Loads a game.

```lua
tes3.loadGame(filename)
```

**Parameters**:

* `filename` (string): The full filename of the save that we want to load, including extension.

***

### `tes3.loadMesh`

Loads a mesh file and provides a scene graph object.

```lua
local model = tes3.loadMesh(path, useCache)
```

**Parameters**:

* `path` (string): Path, relative to Data Files/Meshes.
* `useCache` (boolean): *Default*: `true`. If false, a new object will be created even if it had been previously loaded.

**Returns**:

* `model` ([niNode](../../types/niNode))

***

### `tes3.loadSourceTexture`

Loads a source texture file and provides the niSourceTexture object.

```lua
local texture = tes3.loadSourceTexture(path, useCache)
```

**Parameters**:

* `path` (string): Path, relative to Data Files/Textures.
* `useCache` (boolean): *Default*: `true`. If false, a new object will be created even if it had been previously loaded.

**Returns**:

* `texture` ([niSourceTexture](../../types/niSourceTexture))

***

### `tes3.lock`

Locks an object, and optionally sets a locked reference's lock level. Returns true if the object can be and wasn't already locked.

```lua
local locked = tes3.lock({ reference = ..., level = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string)
	* `level` (number): *Optional*.

**Returns**:

* `locked` (boolean)

***

### `tes3.loopTArray`

This function returns a function that iterates over a tes3tarray object. This is useful for for loops.

```lua
local iterationFunction = tes3.loopTArray(tarray)
```

**Parameters**:

* `tarray` (tes3tarray)

**Returns**:

* `iterationFunction` (function)

***

### `tes3.makeSafeObjectHandle`

Returns a safe handle for the object. To use the object use `:getObject()`. To check if it still exists use `:valid()`.

```lua
local object = tes3.makeSafeObjectHandle(unknown, unknown, unknown)
```

**Parameters**:


**Returns**:

* `object` ([tes3object](../../types/tes3object))

***

### `tes3.menuMode`

Returns true if the player is currently in menu mode.

```lua
local inMenuMode = tes3.menuMode()
```

**Returns**:

* `inMenuMode` (boolean)

***

### `tes3.messageBox`

Displays a message box. This may be a simple toast-style message, or a box with choice buttons.

```lua
local element = tes3.messageBox({ message = ..., buttons = ..., callback = ..., showInDialog = ..., duration = ... }, formatAdditions)
```

**Parameters**:

* `messageOrParams` (string, table)
	* `message` (string)
	* `buttons` (table): *Optional*. An array of strings to use for buttons.
	* `callback` (function)
	* `showInDialog` (boolean): *Default*: `true`. Specifying showInDialog = false forces the toast-style message, which is not shown in the dialog menu.
	* `duration` (number): *Optional*. Overrides how long the toast-style message remains visible.
* `formatAdditions` (variadic): *Optional*. Only used if messageOrParams is a string.

**Returns**:

* `element` ([tes3uiElement](../../types/tes3uiElement), nil): The UI menu created for the notification, if any.

***

### `tes3.modStatistic`

Modifies a statistic on a given actor. This should be used instead of manually setting values on the game structures, to ensure that events and GUI elements are properly handled. Either skill, attribute, or name must be provided.

```lua
tes3.modStatistic({ reference = ..., name = ..., attribute = ..., skill = ..., base = ..., current = ..., value = ..., limit = ..., limitToBase = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3mobileActor](../../types/tes3mobileActor), [tes3reference](../../types/tes3reference), string)
	* `name` (string): *Optional*. A generic name of an attribute to set.
	* `attribute` (number): *Optional*. The attribute to set.
	* `skill` (number): *Optional*. The skill to set.
	* `base` (number): *Optional*. If set, the base value will be modified.
	* `current` (number): *Optional*. If set, the current value will be modified.
	* `value` (number): *Optional*. If set, both the base and current value will be modified.
	* `limit` (boolean): If set, the attribute won't rise above 100 or fall below 0.
	* `limitToBase` (boolean): If set, the attribute's current value won't rise above its base value. Useful for health, magicka, and fatigue.

??? example "Example: Decrease Health of an Actor"

	```lua
	tes3.modStatistic({
		reference = tes3.mobilePlayer,
		name = "health",
		current = -10
	})

	```

??? example "Example: Restore Magicka without Overflowing"

	```lua
	tes3.modStatistic({
		reference = tes3.mobilePlayer,
		name = "magicka",
		current = 20,
		limitToBase = true
	})

	```

***

### `tes3.newGame`

Starts a new game.

```lua
tes3.newGame()
```

***

### `tes3.onMainMenu`

Returns true if the player is on the main menu, and hasn't loaded a game yet.

```lua
local onMainMenu = tes3.onMainMenu()
```

**Returns**:

* `onMainMenu` (boolean)

***

### `tes3.persuade`

Attempts a persuasion attempt on an actor, potentially adjusting their disposition. Returns true if the attempt was a success.

```lua
local success = tes3.persuade({ actor = ..., index = ..., modifier = ... })
```

**Parameters**:

* `params` (table)
	* `actor` ([tes3mobileActor](../../types/tes3mobileActor), [tes3reference](../../types/tes3reference), string): The actor to try to persuade.
	* `index` (number): *Optional*. If an index is provided, 0-indexed with the following results: admire, intimidate, taunt, bribe (10), bribe (100), bribe (1000).
	* `modifier` (number): *Optional*. If no index is provided, this is the direct modifier to try.

**Returns**:

* `success` (boolean)

***

### `tes3.playAnimation`

Plays a given animation group. Optional flags can be used to define how the group starts.

When 'group' is specified, the actor AI is paused while playing the animation, as if in an idle state. When one or more of 'lower', 'upper', or 'shield' are specified without 'group', the actor AI retains control, and the animations are layered. e.g. `tes3.playAnimation{reference = ..., upper = tes3.animationGroup.idle3, loopCount = 0}` will play the idle3 animation once (without looping) on the upper body, while the player or NPC is still able to walk around. Using 'upper' defers combat actions until the animation is done. Using 'shield' still allows combat actions.

As a special case, `tes3.playAnimation{reference = ..., group = 0}` returns control to the AI, as the AI knows that is the actor's neutral idle state.

```lua
tes3.playAnimation({ reference = ..., group = ..., lower = ..., upper = ..., shield = ..., startFlag = ..., loopCount = ..., mesh = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3mobileActor](../../types/tes3mobileActor), [tes3reference](../../types/tes3reference), string): The reference that will play the animation.
	* `group` (number): *Optional*. The animation group id to start playing -- a value from 0 to 149. Applies the animation to the whole body. Maps to [`tes3.animationGroup`](https://mwse.github.io/MWSE/references/animation-groups/) constants.
	* `lower` (number): *Optional*. Sets the animation group id for the lower body. This is used to combine different animations for each body section. Maps to [`tes3.animationGroup`](https://mwse.github.io/MWSE/references/animation-groups/) constants.
	* `upper` (number): *Optional*. Sets the animation group id for the upper body. This is used to combine different animations for each body section. Maps to [`tes3.animationGroup`](https://mwse.github.io/MWSE/references/animation-groups/) constants.
	* `shield` (number): *Optional*. Sets the animation group id for the shield arm. This is used to combine different animations for each body section. Maps to [`tes3.animationGroup`](https://mwse.github.io/MWSE/references/animation-groups/) constants.
	* `startFlag` (number): *Default*: `tes3.animationStartFlag.immediate`. A flag for starting the group with, using [`tes3.animationStartFlag`](https://mwse.github.io/MWSE/references/animation-start-flags/) constants.
	* `loopCount` (number): *Default*: `-1`. If provided, the animation will repeat its loop section a given number of times. To make an animation play through once, set loopCount = 0. Defaults to infinite looping.
	* `mesh` (string): *Optional*. Deprecated. Please use [`tes3.loadAnimation`](https://mwse.github.io/MWSE/apis/tes3/#tes3loadanimation) (check its documentation) before calling `playAnimation`. You can also use `loadAnimation` to reset loaded animations to default.

***

### `tes3.playItemPickupSound`

Plays the sound responsible for picking up or putting down an item.

```lua
local executed = tes3.playItemPickupSound({ reference = ..., item = ..., pickup = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): *Optional*. The reference to attach the sound to.
	* `item` ([tes3item](../../types/tes3item))
	* `pickup` (boolean): *Default*: `true`. If false, the place down item will be used.

**Returns**:

* `executed` (boolean)

***

### `tes3.playSound`

Plays a sound on a given reference. Provides control over volume (including volume channel), pitch, and loop control.

**Note**: MP3 sound files can only be played if they are inside \\Vo\\ folder. The files must conform to the MPEG Layer-3, 64 Kbps 44100 kHz, 16-bit mono specification.

```lua
local executed = tes3.playSound({ sound = ..., reference = ..., loop = ..., mixChannel = ..., volume = ..., pitch = ..., soundPath = ... })
```

**Parameters**:

* `params` (table)
	* `sound` ([tes3sound](../../types/tes3sound), string): The sound object, or id of the sound to look for.
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): *Optional*. The reference to attach the sound to.
	* `loop` (boolean): If true, the sound will loop.
	* `mixChannel` (number): *Default*: `tes3.soundMix.effects`. The channel to base volume off of. Maps to [`tes3.soundMix`](https://mwse.github.io/MWSE/references/sound-mix-types/) constants.
	* `volume` (number): *Default*: `1.0`. A value between 0.0 and 1.0 to scale the volume off of.
	* `pitch` (number): *Default*: `1.0`. The pitch-shift multiplier. For 22kHz audio (most typical) it can have the range [0.005, 4.5]; for 44kHz audio it can have the range [0.0025, 2.25].
	* `soundPath` (string): *Optional*. The path to a custom soundfile (useful for playing sounds that are not registered in the Construction Set). Starts in Data Files\Sound.

**Returns**:

* `executed` (boolean)

***

### `tes3.playVoiceover`

Causes a target actor to play a voiceover.

```lua
local played = tes3.playVoiceover({ actor = ..., voiceover = ... })
```

**Parameters**:

* `params` (table)
	* `actor` ([tes3mobileActor](../../types/tes3mobileActor), [tes3reference](../../types/tes3reference), string): The actor to play a voiceover.
	* `voiceover` (number): Maps to [`tes3.voiceover`](https://mwse.github.io/MWSE/references/voiceovers/) constants.

**Returns**:

* `played` (boolean)

***

### `tes3.positionCell`

Positions a reference to another place.

```lua
local executed = tes3.positionCell({ reference = ..., cell = ..., position = ..., orientation = ..., forceCellChange = ..., suppressFader = ..., teleportCompanions = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): *Default*: `tes3.mobilePlayer`. The reference to reposition.
	* `cell` ([tes3cell](../../types/tes3cell)): *Optional*. The cell to move the reference to. If not provided, the reference will be moved to a cell in the exterior worldspace at the position provided.
	* `position` ([tes3vector3](../../types/tes3vector3), table): The position to move the reference to.
	* `orientation` ([tes3vector3](../../types/tes3vector3), table): *Optional*. The new orientation of the reference.
	* `forceCellChange` (boolean): *Optional*. When true, forces the game to update a reference that has moved within a single cell, as if it was moved into a new cell.
	* `suppressFader` (boolean): *Optional*. When moving the player, can be used to prevent the fade in and out visual effect.
	* `teleportCompanions` (boolean): *Default*: `true`. If used on the player, determines if companions should also be teleported.

**Returns**:

* `executed` (boolean)

***

### `tes3.pushKey`

Simulates pushing a keyboard key.

```lua
tes3.pushKey(keyCode)
```

**Parameters**:

* `keyCode` (number): Maps to values in [`tes3.scanCode`](https://mwse.github.io/MWSE/references/scan-codes/) namespace.

***

### `tes3.random`

Returns a value from Morrowind's random number generator. This is not preferrable to lua's math.random function, but may be necessary for reproducing Morrowind's generation.

```lua
tes3.random(seed)
```

**Parameters**:

* `seed` (number): *Optional*. If provided, it the number generator is seeded with this value. Pointers to objects may be used, such as a reference's sceneNode, to create a consistent if less than random seed.

***

### `tes3.rayTest`

Performs a ray test and returns various information related to the result(s). If `findAll` is set, the result will be a table of results, otherwise only the first result is returned.

```lua
local result = tes3.rayTest({ position = ..., direction = ..., findAll = ..., maxDistance = ..., sort = ..., useModelBounds = ..., useModelCoordinates = ..., useBackTriangles = ..., observeAppCullFlag = ..., root = ..., ignoreSkinned = ..., returnColor = ..., returnNormal = ..., returnSmoothNormal = ..., returnTexture = ..., ignore = ... })
```

**Parameters**:

* `params` (table)
	* `position` ([tes3vector3](../../types/tes3vector3), table): Position of the ray origin.
	* `direction` ([tes3vector3](../../types/tes3vector3), table): Direction of the ray. Does not have to be unit length.
	* `findAll` (boolean): If true, the ray test won't stop after the first result.
	* `maxDistance` (number): *Optional*. The maximum distance that the test will run.
	* `sort` (boolean): *Default*: `true`. If true, the results will be sorted by distance from the origin position.
	* `useModelBounds` (boolean): If true, model bounds will be tested for intersection. Otherwise triangles will be used.
	* `useModelCoordinates` (boolean): If true, model coordinates will be used instead of world coordinates.
	* `useBackTriangles` (boolean): Include intersections with back-facing triangles.
	* `observeAppCullFlag` (boolean): *Default*: `true`. Ignore intersections with culled (hidden) models.
	* `root` (node*): *Default*: `tes3.game.worldSceneGraphRoot`. Node pointer to node scene.
	* `ignoreSkinned` (boolean): Ignore results from skinned objects.
	* `returnColor` (boolean): Calculate and return the vertex color at intersections.
	* `returnNormal` (boolean): *Default*: `true`. Calculate and return the vertex normal at intersections.
	* `returnSmoothNormal` (boolean): Use normal interpolation for calculating vertex normals.
	* `returnTexture` (boolean): Calculate and return the texture coordinate at intersections.
	* `ignore` (table): *Optional*. An array of references and/or scene graph nodes to cull from the result(s).

**Returns**:

* `result` ([niPickRecord](../../types/niPickRecord), table)

??? example "Example: Get Activation Target"

	```lua
	local hitResult = tes3.rayTest({ position = tes3.getPlayerEyePosition(), direction = tes3.getPlayerEyeVector() })
	local hitReference = hitResult and hitResult.reference
	if (hitReference == nil) then
		return
	end
	
	tes3.messageBox("The player is looking at a '%s'", hitReference.object.name or hitReference.object.id)

	```

??? example "Example: Get Camera Target"

	```lua
	local hitResult = tes3.rayTest({ position = tes3.getCameraPosition(), direction = tes3.getCameraVector() })
	local hitReference = hitResult and hitResult.reference
	if (hitReference == nil) then
		return
	end
	
	tes3.messageBox("The camera is looking at a '%s'", hitReference.object.name or hitReference.object.id)

	```

??? example "Example: Multiple Results"

	```lua
	local results = tes3.rayTest{ tes3.getCameraPosition(), direction = tes3.getCameraVector(), findAll = true }
	if results then
		for i, hit in pairs(results) do
			mwse.log("Ray hit #%d: %s", i, hit.reference or "<non-reference>");
		end
	end

	```

??? example "Example: Save rayTest result for use at a later point"

	```lua
	local result = tes3.rayTest{ -- result can get invalidated
		position = tes3.getPlayerEyePosition(),
		direction = tes3.getPlayerEyeVector(),
		ignore = { tes3.player }
	}
	
	local ref
	
	if result then
		ref = tes3.makeSafeObjectHandle(result.reference)
	end
	
	-- Before using ref, now we can chack if it is valid
	if ref:valid() then
		-- Now we can safely do something with ref
	
	end

	```

***

### `tes3.releaseKey`

Simulates releasing a keyboard key.

```lua
tes3.releaseKey(keyCode)
```

**Parameters**:

* `keyCode` (number): Maps to values in [`tes3.scanCode`](https://mwse.github.io/MWSE/references/scan-codes/) namespace.

***

### `tes3.removeEffects`

Removes magic effects from a given reference. Requires that either the `effect` or `castType` parameter be provided.

```lua
tes3.removeEffects(reference, effect, castType, chance, removeSpell)
```

**Parameters**:

* `reference` ([tes3reference](../../types/tes3reference)): Target reference to remove effects from.
* `effect` (number): *Optional*. Maps to [`tes3.effect`](https://mwse.github.io/MWSE/references/magic-effects/) constants.
* `castType` (number): *Optional*. Maps to [`tes3.spellType`](https://mwse.github.io/MWSE/references/spell-types/) constants.
* `chance` (number): *Default*: `100`. The chance for the effect to be removed.
* `removeSpell` (boolean): *Optional*. If removing by cast type, determines if the spell should be removed from the target's spell list. Defaults to true if `castType` is not `tes3.spellType.spell.` This causes diseases and curses to be removed when dispelled.

??? example "Example: Simulating a Dispel"

	```lua
	local function example(e)
			-- We only care about the player
		if (e.mobile.objectType ~= tes3.objectType.mobilePlayer) then
			return
		end
	
		local cell = tes3.mobilePlayer.cell
	
		if (cell.isInterior and not cell.hasWater) then
			return
		end
	
		local waterLevel = cell.waterLevel
		local headPosition = tes3.mobilePlayer.position.z + tes3.mobilePlayer.height
	
		local underwater = headPosition < waterLevel
	
		if underwater then
			-- There is a 50 % chance that any Water Breathing effect will be removed from the player
			tes3.removeEffects({
				reference = tes3.player,
				chance = 50,
				effect = tes3.effect.waterBreathing,
			})
		end
	end
	
	event.register(tes3.event.initialized, function ()
		event.register(tes3.event.calcMoveSpeed, example)
	end)

	```

***

### `tes3.removeItem`

Removes an item from a given reference's inventory.

```lua
local removedCount = tes3.removeItem({ reference = ..., item = ..., itemData = ..., deleteItemData = ..., count = ..., playSound = ..., reevaluateEquipment = ..., updateGUI = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): Who to remove items from.
	* `item` ([tes3item](../../types/tes3item), string): The item to remove.
	* `itemData` ([tes3itemData](../../types/tes3itemData)): *Optional*. The item data for the exact item to remove.
	* `deleteItemData` ([tes3itemData](../../types/tes3itemData)): *Optional*. Whether to delete the item data after remove succeeds. Automatically set if itemData is used. Does not need to be specified for normal usage.
	* `count` (number): *Default*: `1`. The maximum number of items to remove.
	* `playSound` (boolean): *Default*: `true`. If false, the up/down sound for the item won't be played.
	* `reevaluateEquipment` (boolean): *Default*: `true`. If true, and the item removed is armor, clothing, or a weapon, the actor will reevaluate its equipment choices to see if it needs to equip a new item. This does not affect the player.
	* `updateGUI` (boolean): *Default*: `true`. If false, the function won't manually resync the player's GUI state. This can result in some optimizations, though [`tes3ui.forcePlayerInventoryUpdate()`](https://mwse.github.io/MWSE/apis/tes3ui/#tes3uiforceplayerinventoryupdate) must manually be called after all inventory updates are finished.

**Returns**:

* `removedCount` (number)

***

### `tes3.removeItemData`

Removes and deletes item data from a given reference, or from their inventory. If no `itemData` is provided, it will be removed from the reference itself.

```lua
local wasRemoved = tes3.removeItemData({ from = ..., item = ..., itemData = ..., force = ..., ignoreOwnership = ..., updateGUI = ... })
```

**Parameters**:

* `params` (table)
	* `from` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): The reference or mobile whose inventory will be modified.
	* `item` ([tes3item](../../types/tes3item), string): The item to remove item data for.
	* `itemData` ([tes3itemData](../../types/tes3itemData)): *Optional*. The exact item data to remove. If no itemData is provided, the itemData from the reference itself will be removed.
	* `force` (boolean): If true, no checks are made to see if the item data should be deleted. It will always be purged.
	* `ignoreOwnership` (boolean): *Default*: `true`. If `force` is false, a check will be made to see if the item data is empty and can be deleted. By default this ignores any ownership data. Setting this to false will override that behavior.
	* `updateGUI` (boolean): *Default*: `true`. If false, the player or contents menu won't be updated.

**Returns**:

* `wasRemoved` (boolean)

***

### `tes3.removeSound`

Stops a sound playing. Without a reference, it will match unattached sounds. With a reference, it will only match a sound playing on that specific reference.

```lua
tes3.removeSound({ sound = ..., reference = ... })
```

**Parameters**:

* `params` (table)
	* `sound` ([tes3sound](../../types/tes3sound), string): The sound object, or id of the sound to look for.
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): *Optional*. The reference the sound is attached to.

***

### `tes3.removeSpell`

Removes a spell from an actor's spell list. If the spell is passive, any active effects from that spell are retired.

```lua
local wasRemoved = tes3.removeSpell({ reference = ..., actor = ..., spell = ..., updateGUI = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): Who to remove the spell from. To manipulate an actor without specifying any particular reference, use `actor` instead.
	* `actor` ([tes3actor](../../types/tes3actor), string): Who to remove the spell from. Providing a base actor can be done before a save has been loaded, but may not correctly update effects for instanced versions of that actor in an active save.
	* `spell` ([tes3spell](../../types/tes3spell), string): The spell to remove.
	* `updateGUI` (boolean): *Default*: `true`. If true, the GUI will be updated respecting the removal of the spell. This can be useful to disable when batch-removing many spells. The batch should be ended with [`tes3.updateMagicGUI`](https://mwse.github.io/MWSE/apis/tes3/#tes3updatemagicgui) to reflect the changes.

**Returns**:

* `wasRemoved` (boolean): True if the spell was successfully removed. This can be false if the spell comes from a race or birthsign.

***

### `tes3.runLegacyScript`

This function will compile and run a mwscript chunk of code. This is not ideal to use, but can be used for features not yet exposed to lua.

```lua
local executed = tes3.runLegacyScript({ script = ..., source = ..., command = ..., variables = ..., reference = ..., dialogue = ..., info = ... })
```

**Parameters**:

* `params` (table)
	* `script` ([tes3script](../../types/tes3script)): *Default*: `tes3.worldController.scriptGlobals`. The base script to base the execution from.
	* `source` (number): The compilation source to use. Defaults to tes3.scriptSource.default
	* `command` (string): The script text to compile and run.
	* `variables` (tes3scriptVariables): *Optional*. If a reference is provided, the reference's variables will be used.
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): The reference to target for execution.
	* `dialogue` ([tes3dialogue](../../types/tes3dialogue), string): *Optional*. If compiling for dialogue context, the dialogue associated with the script.
	* `info` ([tes3dialogueInfo](../../types/tes3dialogueInfo)): *Optional*. The info associated with the dialogue.

**Returns**:

* `executed` (boolean)

***

### `tes3.saveGame`

Saves the game.

```lua
local saved = tes3.saveGame({ file = ..., name = ... })
```

**Parameters**:

* `params` (table)
	* `file` (string): *Default*: `"quiksave"`. The filename of the save that will be created, without extension.
	* `name` (string): *Default*: `"Quicksave"`. The display name of the save.

**Returns**:

* `saved` (boolean)

***

### `tes3.say`

Plays a sound file, with an optional alteration and subtitle.

**Note**: MP3 voice files must conform to the MPEG Layer-3, 64 Kbps 44100 kHz, 16-bit mono specification.

```lua
tes3.say({ reference = ..., soundPath = ..., pitch = ..., volume = ..., forceSubtitle = ..., subtitle = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): The reference to make say something.
	* `soundPath` (string): A path to a valid sound file.
	* `pitch` (number): *Default*: `1`. A pitch shift to adjust the sound with.
	* `volume` (number): *Default*: `1`. The volume to play the sound at, relative to the voice mix channel.
	* `forceSubtitle` (boolean): If true a subtitle will be shown, even if subtitles are disabled.
	* `subtitle` (string): *Optional*. The subtitle to show if subtitles are enabled, or if forceSubtitle is set.

***

### `tes3.set3rdPersonCameraOffset`

Changes the 3rd person camera's offset from the player's head.

Note this function can be used once WorldController and MobilePlayer have finished initializing.

```lua
tes3.set3rdPersonCameraOffset(offset)
```

**Parameters**:

* `offset` ([tes3vector3](../../types/tes3vector3)): The offset vector.

***

### `tes3.setAIActivate`

Configures a mobile actor to activate an object.

```lua
tes3.setAIActivate({ reference = ..., target = ..., reset = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3mobileActor](../../types/tes3mobileActor), [tes3reference](../../types/tes3reference))
	* `target` ([tes3reference](../../types/tes3reference))
	* `reset` (boolean): *Default*: `true`.

***

### `tes3.setAIEscort`

Configures a mobile actor to escort another actor to a destination.

```lua
tes3.setAIEscort({ reference = ..., target = ..., destination = ..., duration = ..., cell = ..., reset = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3mobileActor](../../types/tes3mobileActor), [tes3reference](../../types/tes3reference))
	* `target` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor))
	* `destination` ([tes3vector3](../../types/tes3vector3), table)
	* `duration` (number): *Optional*.
	* `cell` ([tes3cell](../../types/tes3cell), string): *Optional*.
	* `reset` (boolean): *Default*: `true`.

***

### `tes3.setAIFollow`

Configures a mobile actor to follow another actor to a destination.

```lua
tes3.setAIFollow({ reference = ..., target = ..., destination = ..., duration = ..., cell = ..., reset = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3mobileActor](../../types/tes3mobileActor), [tes3reference](../../types/tes3reference))
	* `target` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor))
	* `destination` ([tes3vector3](../../types/tes3vector3), table): *Optional*.
	* `duration` (number): *Optional*.
	* `cell` ([tes3cell](../../types/tes3cell), string): *Optional*.
	* `reset` (boolean): *Default*: `true`.

***

### `tes3.setAITravel`

Configures a mobile actor to travel to a destination.

```lua
tes3.setAITravel({ reference = ..., destination = ..., reset = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3mobileActor](../../types/tes3mobileActor), [tes3reference](../../types/tes3reference))
	* `destination` ([tes3vector3](../../types/tes3vector3), table)
	* `reset` (boolean): *Default*: `true`.

***

### `tes3.setAIWander`

Configures a mobile actor to wander around a cell.

```lua
tes3.setAIWander({ reference = ..., idles = ..., range = ..., duration = ..., time = ..., reset = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3mobileActor](../../types/tes3mobileActor), [tes3reference](../../types/tes3reference))
	* `idles` (table)
	* `range` (number): *Optional*.
	* `duration` (number): *Optional*.
	* `time` (number): *Optional*.
	* `reset` (boolean): *Default*: `true`.

***

### `tes3.setAnimationTiming`

This function sets a reference's animation groups' timings to a specified value.

```lua
tes3.setAnimationTiming({ reference = ..., timing = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): A reference whose animation groups' timings to set.
	* `timing` (number, table): If one parameter is provided, all animation data timings will be set to the timing provided. If a table with 3 timings is provided, animation data timings will be set accordingly.

***

### `tes3.setDestination`

Sets or changes the destination of a door to a new location.

```lua
tes3.setDestination({ reference = ..., position = ..., orientation = ..., cell = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference)): The door reference that will be updated.
	* `position` ([tes3vector3](../../types/tes3vector3), table): The new coordinates of the transition.
	* `orientation` ([tes3vector3](../../types/tes3vector3), table): The new rotation to use after transition.
	* `cell` ([tes3cell](../../types/tes3cell), string): *Optional*. The cell to transition to, if transitioning to an interior.

***

### `tes3.setEnabled`

Enables or disables a reference.

```lua
local success = tes3.setEnabled({ reference = ..., toggle = ..., enabled = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): The reference to enable/disable.
	* `toggle` (boolean): If true, the enabled state will be toggled.
	* `enabled` (boolean): *Default*: `true`. If not toggling, setting `enabled` to true will enable the reference or to false will disable the reference.

**Returns**:

* `success` (boolean)

***

### `tes3.setGlobal`

Sets the value of a global value. If the global could not be found, the function returns false.

```lua
local value = tes3.setGlobal(id, value)
```

**Parameters**:

* `id` (string)
* `value` (number)

**Returns**:

* `value` (boolean)

***

### `tes3.setItemIsStolen`

This function changes an item's stolen flag. Morrowind handles stealing by marking the base item (not the inventory stack) with NPCs that you have stolen that item from. The NPC will recognize an item as stolen if they are marked as stolen on the base item.

```lua
tes3.setItemIsStolen(item, from, stolen)
```

**Parameters**:

* `item` ([tes3item](../../types/tes3item)): The item whose stolen flag to modify.
* `from` ([tes3baseObject](../../types/tes3baseObject)): The location the item is stolen from.
* `stolen` (boolean): *Default*: `true`. If this parameter is set to true, the item will be flagged as stolen. Otherwise, the item's stolen flag will be removed.

***

### `tes3.setJournalIndex`

Sets the index of a given journal in a way similar to the mwscript function SetJournalIndex.

```lua
local wasSet = tes3.setJournalIndex({ id = ..., index = ..., speaker = ..., showMessage = ... })
```

**Parameters**:

* `params` (table)
	* `id` ([tes3dialogue](../../types/tes3dialogue), string)
	* `index` (number)
	* `speaker` ([tes3mobileActor](../../types/tes3mobileActor), [tes3reference](../../types/tes3reference), string)
	* `showMessage` (boolean): If set, a message may be shown to the player.

**Returns**:

* `wasSet` (boolean)

***

### `tes3.setKillCount`

Sets player's kill count of a certain type of actor.

```lua
tes3.setKillCount({ actor = ..., count = ... })
```

**Parameters**:

* `params` (table)
	* `actor` ([tes3actor](../../types/tes3actor), string): The actor (or their ID) for whom to set player's kill count.
	* `count` (number): Number of kills that will be set.

***

### `tes3.setLockLevel`

Sets a locked reference's lock level. This does not lock the object.

```lua
local set = tes3.setLockLevel({ reference = ..., level = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string)
	* `level` (number)

**Returns**:

* `set` (boolean)

***

### `tes3.setMarkLocation`

This function sets the player's mark location to the one specified.

```lua
tes3.setMarkLocation({ position = ..., rotation = ..., cell = ... })
```

**Parameters**:

* `params` (table)
	* `position` ([tes3vector3](../../types/tes3vector3)): Coordinates of the mark's position.
	* `rotation` (number): *Default*: `Player's current rotation.`. This argument controls which direction the player's mark location will be facing.
	* `cell` ([tes3cell](../../types/tes3cell)): *Optional*. A cell in which the mark should be placed.

***

### `tes3.setOwner`

This function sets the owner of a reference.

```lua
tes3.setOwner({ reference = ..., remove = ..., owner = ..., requiredGlobal = ..., requiredRank = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): A reference whose owner to set.
	* `remove` (boolean): *Optional*. If this parameter is set to true, reference's owner field will be removed.
	* `owner` ([tes3npc](../../types/tes3npc), [tes3faction](../../types/tes3faction), string): Assigns this NPC or a faction as the owner of the reference.
	* `requiredGlobal` ([tes3globalVariable](../../types/tes3globalVariable)): *Optional*. If `owner` is set to NPC, `requiredGlobal` variable can be set.
	* `requiredRank` (number): *Default*: `0`. If `owner` is set to faction, `requitedRank` variable controls minimal rank in faction the player has to have to be able to freely take the reference.

***

### `tes3.setPlayerControlState`

Enables or disables player's controls state.

```lua
local changedControlState = tes3.setPlayerControlState({ enabled = ..., attack = ..., jumping = ..., magic = ..., vanity = ..., viewSwitch = ... })
```

**Parameters**:

* `params` (table)
	* `enabled` (boolean): *Optional*. Setting this to false will disable any kind of control.
	* `attack` (boolean): *Optional*. If this is false, it will block player from attacking.
	* `jumping` (boolean): *Optional*. If this is false, it will block player from jumping.
	* `magic` (boolean): *Optional*. If this is false, it will block player from using magic.
	* `vanity` (boolean): *Optional*. If this is false, it will block player from going to vanity mode.
	* `viewSwitch` (boolean): *Optional*. If this is false, it will block player changing view mod from 1st to 3rd person camera and vice versa.

**Returns**:

* `changedControlState` (boolean)

***

### `tes3.setSourceless`

Sets an object (of any kind) to be sourceless, which are objects the game does not store in savegames. This can be useful for mod-created temporary objects which are not necessary to save.

```lua
tes3.setSourceless({ object = ..., sourceless = ... })
```

**Parameters**:

* `params` (table)
	* `object` ([tes3baseObject](../../types/tes3baseObject)): The object whose sourceless flag to modify.
	* `sourceless` (boolean): *Default*: `true`. Allows flagging an object as sourceless or undoing that action.

***

### `tes3.setStatistic`

Sets a statistic on a given actor. This should be used instead of manually setting values on the game structures, to ensure that events and GUI elements are properly handled. Either skill, attribute, or name must be provided.

```lua
tes3.setStatistic({ attribute = ..., base = ..., current = ..., limit = ..., name = ..., reference = ..., skill = ..., value = ... })
```

**Parameters**:

* `params` (table)
	* `attribute` (number): *Optional*. The attribute to set.
	* `base` (number): *Optional*. If set, the base value will be set.
	* `current` (number): *Optional*. If set, the current value will be set.
	* `limit` (boolean): If set, the attribute won't rise above 100 or fall below 0.
	* `name` (string): *Optional*. A generic name of an attribute to set.
	* `reference` ([tes3mobileActor](../../types/tes3mobileActor), [tes3reference](../../types/tes3reference), string)
	* `skill` (number): *Optional*. The skill to set.
	* `value` (number): *Optional*. If set, both the base and current value will be set.

***

### `tes3.setTrap`

Sets the trap on a given reference.

```lua
local trapped = tes3.setTrap({ reference = ..., spell = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string)
	* `spell` ([tes3spell](../../types/tes3spell), string)

**Returns**:

* `trapped` (boolean)

***

### `tes3.setVanityMode`

Toggles the camera into vanity mode. In vanity mode the camera is in third person and it is orbiting slowly around the player character. Returns true if changed to vanity mode.

Note that unlike the vanity mode caused by not doing anything for a while, this vanity mode must be toggled to go off.

```lua
local changedVanityMode = tes3.setVanityMode({ enabled = ..., checkVanityDisabled = ..., toggle = ... })
```

**Parameters**:

* `params` (table)
	* `enabled` (boolean): *Default*: `true`. This flag sets the vanity mode as enabled or disabled.
	* `checkVanityDisabled` (boolean): *Default*: `true`. This will prevent changing vanity mode according to vanityDisabled flag on tes3.mobilePlayer.
	* `toggle` (boolean): *Optional*. When this flag is set to true. The vanity mode will be toggled. If the player was in vanity mode, this will make the player leave vanity mode. Conversly, if the player wasn't in the vanity mode, this will turn on the vanity mode.

**Returns**:

* `changedVanityMode` (boolean)

***

### `tes3.setWerewolfKillCount`

Sets player's kill count as a werewolf.

```lua
tes3.setWerewolfKillCount({ count = ... })
```

**Parameters**:

* `params` (table)
	* `count` (number): Number of kills.

***

### `tes3.showAlchemyMenu`

This function opens alchemy menu.

```lua
tes3.showAlchemyMenu()
```

***

### `tes3.showRepairServiceMenu`

Opens the service repair menu.

```lua
tes3.showRepairServiceMenu()
```

***

### `tes3.showRestMenu`

This function opens the resting menu and returns true on success. If the player can't rest currently, it returns false.

Various parameters can be used to allow resting in situations not normally possible.

```lua
local success = tes3.showRestMenu({ checkForEnemies = ..., checkForSolidGround = ..., checkSleepingIllegal = ..., checkIsWerewolf = ..., showMessage = ..., resting = ..., waiting = ... })
```

**Parameters**:

* `params` (table)
	* `checkForEnemies` (boolean): *Default*: `true`. Perform a check whether there are enemies nearby before opening rest menu. If there are, false is returned.
	* `checkForSolidGround` (boolean): *Default*: `true`. Perform a check if the player is underwater. If underwater, false is returned.
	* `checkSleepingIllegal` (boolean): *Default*: `true`. Perform a check if the sleeping in the current cell is illegal. If illegal, then the player will be prompted to wait instead of rest.
	* `checkIsWerewolf` (boolean): *Default*: `true`. Perform a check if the player is Werewolf. If they are, then the player will be prompted to wait instead of rest.
	* `showMessage` (boolean): *Default*: `true`. Should a messagebox be shown if the player can't open resting menu because some condition isn't met.
	* `resting` (boolean): *Default*: `true`. Should this be a rest?
	* `waiting` (boolean): *Optional*. Or, is this a wait?

**Returns**:

* `success` (boolean)

***

### `tes3.skipAnimationFrame`

Skips a given reference's animation for a single frame.

```lua
tes3.skipAnimationFrame({ reference = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3mobileActor](../../types/tes3mobileActor), [tes3reference](../../types/tes3reference), string): The reference whose animation frame will be skipped.

***

### `tes3.streamMusic`

This function interrupts the current music to play the specified music track.

```lua
local executed = tes3.streamMusic({ path = ..., situation = ..., crossfade = ... })
```

**Parameters**:

* `params` (table)
	* `path` (string): Path to the music file, relative to Data Files/music/.
	* `situation` (number): *Default*: `tes3.musicSituation.uninterruptible`. Determines what kind of gameplay situation the music should stay active for. Explore music plays during non-combat, and ends when combat starts. Combat music starts during combat, and ends when combat ends. Uninterruptible music always plays, ending only when the track does. This value maps to [`tes3.musicSituation`](https://mwse.github.io/MWSE/references/music-situations/) constants.
	* `crossfade` (number): *Default*: `1.0`. The duration in seconds of the crossfade from the old to the new track. The default is 1.0.

**Returns**:

* `executed` (boolean)

***

### `tes3.tapKey`

Simulates tapping a keyboard key.

```lua
tes3.tapKey(keyCode)
```

**Parameters**:

* `keyCode` (number): Maps to values in [`tes3.scanCode`](https://mwse.github.io/MWSE/references/scan-codes/) namespace.

***

### `tes3.testLineOfSight`

Checks if there is a clear line of sight between two references, or two points in space, in the same method that the game uses for actor vision. You should pass two references, or two positions and heights.

Only certain object types count as blocking for the purposes of the test:
Statics, activators, containers, doors, and lights with non-zero weight.

The collision root node is used for testing, if present in the model.

```lua
local hasLineOfSight = tes3.testLineOfSight({ reference1 = ..., reference2 = ..., position1 = ..., height1 = ..., position2 = ..., height2 = ... })
```

**Parameters**:

* `params` (table)
	* `reference1` ([tes3reference](../../types/tes3reference)): Position of the starting point of the LoS check. For actors, this point is set to position of this reference's head. For other objects the starting point is at the top of its bounding box.
	* `reference2` ([tes3reference](../../types/tes3reference)): Position of the ending point of the LoS check. For actors, this point is set to position of this reference's head. For other objects the ending point is at the top of its bounding box.
	* `position1` ([tes3vector3](../../types/tes3vector3), table): Position of the starting point of the LoS check. Modified by height1.
	* `height1` ([tes3vector3](../../types/tes3vector3), table): *Optional*. Moves the starting point upwards (+Z direction) by this amount. Normally used to simulate head height from a position that is on the ground. Defaults to 0.
	* `position2` ([tes3vector3](../../types/tes3vector3), table): Position of the ending point of the LoS check. Modified by height2.
	* `height2` ([tes3vector3](../../types/tes3vector3), table): *Optional*. Moves the starting point upwards (+Z direction) by this amount. Normally used to simulate head height from a position that is on the ground. Defaults to 0.

**Returns**:

* `hasLineOfSight` (boolean)

***

### `tes3.togglePOV`

Forces a toggle of the player's POV the next simulation frame, and returns if the player was previously in 3rd person. Multiple calls in the same frame will not stack.

```lua
local was3rdPerson = tes3.togglePOV()
```

**Returns**:

* `was3rdPerson` (boolean)

***

### `tes3.transferItem`

Moves one or more items from one reference to another. Returns the actual amount of items successfully transferred.

```lua
local transferredCount = tes3.transferItem({ from = ..., to = ..., item = ..., itemData = ..., count = ..., playSound = ..., limitCapacity = ..., reevaluateEquipment = ..., updateGUI = ... })
```

**Parameters**:

* `params` (table)
	* `from` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): Who to take items from.
	* `to` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): Who to give items to.
	* `item` ([tes3item](../../types/tes3item), string): The item to transfer.
	* `itemData` ([tes3itemData](../../types/tes3itemData)): *Optional*. The specific item data to transfer if, for example, you want to transfer a specific player item.
	* `count` (number): *Default*: `1`. The maximum number of items to transfer.
	* `playSound` (boolean): *Default*: `true`. If false, the up/down sound for the item won't be played.
	* `limitCapacity` (boolean): *Default*: `true`. If false, items can be placed into containers that shouldn't normally be allowed. This includes organic containers, and containers that are full.
	* `reevaluateEquipment` (boolean): *Default*: `true`. If true, and the item transferred is armor, clothing, or a weapon, the actors will reevaluate their equipment choices to see if the new item is worth equipping. This does not affect the player.
	* `updateGUI` (boolean): *Default*: `true`. If false, the function won't manually resync the player's GUI state. This can result in some optimizations, though [`tes3ui.forcePlayerInventoryUpdate()`](https://mwse.github.io/MWSE/apis/tes3ui/#tes3uiforceplayerinventoryupdate) must manually be called after all inventory updates are finished.

**Returns**:

* `transferredCount` (number)

***

### `tes3.triggerCrime`

Emulates the player committing a crime.

```lua
local executed = tes3.triggerCrime({ criminal = ..., forceDetection = ..., type = ..., value = ..., victim = ... })
```

**Parameters**:

* `params` (table)
	* `criminal` ([tes3mobileActor](../../types/tes3mobileActor), [tes3reference](../../types/tes3reference), string): *Default*: `tes3.mobilePlayer`.
	* `forceDetection` (boolean): Can be set to true to ignore normal detection checks.
	* `type` (number): *Default*: `tes3.crimeType.stealing`. Maps to [`tes3.crimeType`](https://mwse.github.io/MWSE/references/crime-types/) constants.
	* `value` (number): Penalty for the crime. Defaults to 25 for pickpocketing.
	* `victim` ([tes3mobileActor](../../types/tes3mobileActor), [tes3reference](../../types/tes3reference), string): *Default*: `tes3.mobilePlayer`.

**Returns**:

* `executed` (boolean)

***

### `tes3.undoTransform`

Changes a reference back from werewolf form to human. This function works only on a reference infected with Lycanthropy, be it the player or any other reference. Returns true if successful.

```lua
local success = tes3.undoTransform({ reference = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference)): A reference to change back to human.

**Returns**:

* `success` (boolean)

***

### `tes3.unhammerKey`

Stops simulating hammering a keyboard key.

```lua
tes3.unhammerKey(keyCode)
```

**Parameters**:

* `keyCode` (number): Maps to values in [`tes3.scanCode`](https://mwse.github.io/MWSE/references/scan-codes/) namespace.

***

### `tes3.unlock`

Unlocks an object. Returns true if the object can be and wasn't already unlocked.

```lua
local unlocked = tes3.unlock({ reference = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string)

**Returns**:

* `unlocked` (boolean)

***

### `tes3.updateInventoryGUI`

Forces the GUI to update inventory-relevant elements for a given reference. This can be used after many calls to inventory-manipulating functions while passing updateGUI as false to resync inventory tiles, container weights, and companion data.

```lua
tes3.updateInventoryGUI({ reference = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): The reference to update GUI elements for.

***

### `tes3.updateJournal`

Updates the journal index in a way similar to the mwscript function Journal.

```lua
local wasSet = tes3.updateJournal({ id = ..., index = ..., showMessage = ... })
```

**Parameters**:

* `params` (table)
	* `id` ([tes3dialogue](../../types/tes3dialogue), string)
	* `index` (number)
	* `showMessage` (boolean): If set, a message may be shown to the player.

**Returns**:

* `wasSet` (boolean)

***

### `tes3.updateMagicGUI`

Forces the GUI to update magic-relevant elements for a given reference. This can be used after many calls to magic- or magic item-manipulating functions while passing updateGUI as false to resync inventory tiles, container weights, and companion data.

```lua
tes3.updateMagicGUI({ reference = ..., updateSpells = ..., updateEnchantments = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): The reference to update GUI elements for.
	* `updateSpells` (boolean): *Default*: `true`. Determines if the spell and power lists are refreshed.
	* `updateEnchantments` (boolean): *Default*: `true`. Determines if the enchanted items list is refreshed.

***

### `tes3.wakeUp`

This function wakes player up and returns true if successful.

Note this function returns false if WorldController or MobilePlayer aren't initialized, and if the player is not sleeping or waiting

```lua
local wokeUp = tes3.wakeUp()
```

**Returns**:

* `wokeUp` (boolean)

***

