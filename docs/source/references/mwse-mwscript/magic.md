# Magic Functions

--8<-- "mwse-deprecated.md"


## `xAddEffect`

**Parameters:**

- `long` **objectType**: [Object Type](../../object-types) value for the target's type.
- `string` **objectID**: Object ID of target spell, enchantment, or potion.
- `long` **effectID**: [Magic Effect](../../magic-effects) ID that will be added to the target.
- `long` **skillAttributeID**: [Skill](../../skills) or [Attribute](../../attributes) ID to be used. (Only for absorb/damage/drain/fortify/restore effects - ignored otherwise.)
- `long` **rangeType**: New range type. (0 = SELF, 1 = TOUCH, 2 = TARGET)
- `long` **area**: Area of effect.
- `long` **duration**: Duration in seconds.
- `long` **magMin**: Minimum magnitude.
- `long` **magMax**: Maximum magnitude.

**Returned:**

- `long` **success**: `1` if the effect was added, or `0` if it wasn't.

Adds a new effect to the given spell, enchantment, or potion.


??? example
	```
	begin Example_xAddEffect

	short result

	; Fire Damage (14), On Touch (1), Duration (30), Magnitude (1 to 5)
	setx result to xAddEffect 1279610963 "fire bite" 14 0 1 0 30 1 5

	if ( result != 0 )
		MessageBox "Your 'Fire Bite' spell has been upgraded!"
	endif

	StopScript Example_xAddEffect

	end
	```


***

## `xCreateSpell`

**Parameters:**

- `string` **ID**: The object ID of the spell to create.
- `string` **name**: The name of the spell to create.

**Returned:**

- `long` **wasCreated**: `1` if the spell was successfully created.

Creates a new spell with all flags cleared, origin set to spellmaker (`2`) and a single Water Breathing effect and adds it to the master spell list.

!!! note
	This function will fail if **ID** already exists or if either **ID** or **name** are longer than 31 characters.


***

## `xDeleteEffect`

**Parameters:**

- `long` **type**: The [Object Type](../../object-types) to delete an effect from. Must be an alchemy, spell, or enchantment object.
- `string` **id**: The object ID to remove an effect from.
- `long` **index**: The index of the effect to remove. Must be between (inclusive) `1` and `8`.

**Returned:**

- `long` **result**: `1` if the effect was deleted.

Removes the effect at index from the given spell or enchantment.

Other effects are reordered, e.g. if effect `1` is removed, effect `2` becomes `1`, `3` becomes `2`, etc.


***

## `xDeleteSpell`

**Parameters:**

- `long` **type**: The [Object Type](../../object-types) to delete an effect from. Must be an alchemy, spell, or enchantment object.
- `string` **id**: The object ID to remove an effect from.
- `long` **index**: The index of the effect to remove. Must be between (inclusive) `1` and `8`.

**Returned:**

- `long` **result**: `1` if the spell was deleted.

Deletes a spell from the master spell list. It will no longer persist in save games.

Notes: Be very careful using this command. The effect of deleting a spell originating from the CS is undefined. The effect of deleting a spell referenced by other entities (player, npcs, traps, etc.) in undefined. Do not attempt to add a deleted spell with AddSpell. AddSpell will succeed, but leave the game in an indeterminate state. It's not yet clear why this happens, but I hope to fix it in the future.


***

## `xGetAlchemyInfo`

**Parameters:**

- `string` **id**: ID of the alchemy item to get information for.

**Returned:**

- `long` **effectCount**: The number of effects on the alchemy item, between `1` and `8`.
- `long` **flags**: `1` = autocalc, `2` = PC Start, `4` = Always Succeeds

Provides information important to a given alchemy object. Unlike the other related functions, there is no associated ability to set this information. The effects themselves can still be retrieved and modified using `xGetEffectInfo` and `xSetEffectInfo`.

!!! tip
	Use this function to determine the state of a potion before modifying it with `xAddEffect`, `xDeleteEffect` or `xSetEffectInfo`.

??? example
	```
	begin Example_xGetAlchemyInfo

	long numEffects
	long flags

	setx numEffects flags to xGetAlchemyInfo "potion_skooma_01"

	MessageBox "flags: %g" flags
	MessageBox "numEffects: %g" numEffects
	MessageBox "potion_skooma_01"

	end
	```


***

## `xGetBaseEffectInfo`

**Parameters:**

- `long` **attributeID**: The [School](../../schools) ID to get the value of.

**Returned:**

- `long` **school**: The [School](../../schools) of the effect.
- `float` **baseCost**: The base cost of the effect.
- `long` **flags**: The flags of the effect.

Returns the properties of a magic effect.

This function only supports the player and NPCs.


***

## `xGetEffectInfo`

**Parameters:**

- `long` **type**: The [Object Type](../../object-types) to get the effect of.
- `string` **objectID**: The Object ID of the object to get the effect of.
- `long` **index**: The effect index to get the info from, from 1 to 8.

**Returned:**

- `long` **effectId**: The `Effect ID`_ of the effect.
- `long` **skillAttribId**: The [Attribute](../../attributes) or [Skill](../../skills) ID associated with the effect, if applicable.
- `long` **rangeType**: `0` = self, `1` = touch, `2` = target
- `long` **area**: Area of effect.
- `long` **duration**: Duration in seconds.
- `long` **magMin**: Minimum magnitude.
- `long` **magMax**: Maximum magnitude.

Returns the properties of an effect on the given alchemy item, spell, or enchantment.

On failure, **effectId** is set to `-1`.


***

## `xGetEnchantInfo`

**Parameters:**

- `string` **objectID**: The Object ID of the enchantment.

**Returned:**

- `short` **type**: `0` = Cast Once, `1` = Cast When Strikes, `2` = Cast When Used, `3` = Constant
- `short` **cost**: The cost of using the enchantment.
- `long` **maxCharge**: The maximum charge for the enchantment.
- `short` **numEffects**: The number of effects on the enchantment.
- `long` **autocalc**: `0` = off, `1` = on

Returns info about the given **enchantId**, or `0` if **enchantId** is invalid.


***

## `xGetIngredientEffect`

**Parameters:**

- `string` **id**: The id of the ingredient to fetch data for.
- `long` **effectIndex**: A value between 1 and 4, matching the effect index desired.

**Returned:**

- `long` **effectType**: The [Effect Type](../../effect-types) that the ingredient has at the given **effectIndex**.
- `long` **skillAttributeType**: The [Attribute Type](../../attribute-types) or [Skill Type](../../skill-types), if the **effectType** supports one. Otherwise will always be -1.

This function allows scripts to determine the effects of a given ingredient programmatically. Scripts can alter these values as well using `xSetIngredientEffect`.

??? example
	```
	begin Example_xGetIngredientEffect

	long effect
	long skillAttribute

	setx effect skillAttribute to xGetIngredientEffect "food_kwama_egg_01" 1

	MessageBox "skill / attribute: %g" skillAttribute
	MessageBox "effect: %g" effectID
	MessageBox "food_kwama_egg_01"

	end
	```


***

## `xGetSpellInfo`

**Parameters:**

- `string` **objectID**: The object ID of the spell to get information from.

**Returned:**

- `string` **name**: The spell's name.
- `short` **type**: `0` = Spell, `1` = Ability, `2` = Blight, `3` = Disease, `4` = Curse, `5` = Power.
- `short` **cost**: The cost to cast the spell.
- `short` **numEffects**: The number of effects the spell has.
- `long` **flags**: Bit array of spell flags. `1` = Auto-Calc, `2` = PC Starting Spell, `4` = Always Succeeds.

This function gets information about a spell, given its **objectID**.

The **numEffects** value is useful when looping over spell effects using `xGetEffectInfo`.


***

## `xSetBaseEffectInfo`

**Parameters:**

- `long` **effectID**: The [Magic Effect](../../magic-effects) to modify.
- `long` **school**: New spell [School](../../schools).
- `float` **cost**: New base cost in magicka.
- `long` **flags**: New [Magic Effect Flags](../../magic-effect-flags). Only spellmaking, enchanting, and negative lighting are valid here. All others are ignored.

**Returned:**

- `long` **result**: `1` on success, `0` on failure.

This function changes the properties of the effect for all magic that uses it. Changes to **school** and **flags** take effect immediately.

E.g. if you have a spell with a Fire Damage effect and you change the Fire Damage **school** to Alteration, casting that spell will raise Alteration instead of Destruction. Likewise, if you clear the Spellmaking or Enchanting flags, Fire Damage will no longer be available at the respective crafter. Changes to the base **cost** take effect on any subsequent spell or magic item creation, but don't affect any spells or items already in the game.


***

## `xSetEffectInfo`

**Parameters:**

- `long` **type**: The [Object Type](../../object-types) of the object to alter.
- `string` **id**: The object ID of the object to alter.
- `long` **index**: The index of the effect to alter.
- `long` **effectID**: The [Effect Type](../../effect-types) to change to.
- `long` **skillOrAttributeID**: The [Attribute](../../attributes) or [Skill](../../skills) ID to use, if the **effectID** uses one.
- `long` **rangeType**: `0` = self, `1` = touch, `2` = target.
- `long` **area**: Area of effect.
- `long` **duration**: Effect duration (in seconds).
- `long` **minimumMagnitude**: Minimum magnitude.
- `long` **maximumMagnitude**: Maximum magnitude.

**Returned:**

- `long` **result**: `1` on success, `0` on failure.

Modifies an existing effect on the given spell or enchantment.


***

## `xSetEnchantInfo`

**Parameters:**

- `string` **enchantID**: Object ID of the enchantment to modify.
- `long` **type**: `0` = cast once, `1` = cast when strikes, `2` = cast when used, `3` = constant.
- `long` **cost**: New cost per use.
- `long` **charge**: New maximum charge.
- `long` **autoCalc**: `0` = off, `1` = on.

**Returned:**

- `long` **result**: `1` on success, `0` on failure.

Sets the properties of the given **enchantId**.


***

## `xSetIngredientEffect`

**Parameters:**

- `string` **id**: The id of the ingredient to fetch data for.
- `long` **effectIndex**: A value between `1` and `4`, matching the effect index desired.
- `long` **effectType**: The [Effect Type](../../effect-types) that the ingredient has at the given **effectIndex**.
- `long` **skillAttributeType**: The [Attribute Type](../../attribute-types) or [Skill Type](../../skill-types), if the **effectType** supports one.

**Returned:**

- `long` **success**: If the effect was set, this value is `1`. If it failed, the value is `0`.

This function allows scripts to modify the effects of an ingredient programmatically.

To instead retrieve these values, use  `xGetIngredientEffect`.


??? example Set an ingredient's first effect.
	```
	begin WheatAllergy

	long ingred
	long index
	long effect
	long attrib

	setx ingred to xStringBuild "ingred_bread_01"
	set index to 1 ; First Slot
	set effect to 22 ; Damage Attribute
	set attrib to 0 ; Strength
	xSetIngredientEffect ingred index effect attrib

	; in this case, we could've also used literals
	xSetIngredientEffect "ingred_bread_01" 1 22 0

	; needs to run only once per session
	StopScript WheatAllergy

	end
	```


***

## `xSetSpellInfo`

**Parameters:**

- `string` **spellID**: The spell ID to modify.
- `string` **spellName**: New display name. Names longer than 31 characters will be truncated.
- `long` **type**: New spell type. (`0` = spell, `1` = ability, `2` = blight, `3` = disease, `4` = curse, `5` = power)
- `long` **cost**: New magicka cost.
- `long` **flags**: New flags. (`1` = autocalc, `2` = player start, `4` = always succeeds)
- `long` **origin**: New origin. (`1` = module, not saved in .ess; `2` = spellmaker, saved in .ess; `0` to leave unmodified)

**Returned:**

- `short` **result**: `1` if the function was successfull, other wise `0`.