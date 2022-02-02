# tes3magicSourceInstance

A game structure that keeps track of a magic source on an object.

This type inherits the following: [tes3baseObject](../../types/tes3baseObject)
## Properties

### `blocked`

The blocked state of the object.

**Returns**:

* `result` (boolean)

***

### `castChanceOverride`

No description yet available.

**Returns**:

* `result` (number)

***

### `caster`

*Read-only*. No description yet available.

**Returns**:

* `result` ([tes3reference](../../types/tes3reference))

***

### `corprusHoursSinceLastWorsen`

The number of hours passed since the player's corprus state last worsened.

**Returns**:

* `result` (number)

***

### `deleted`

*Read-only*. The deleted state of the object.

**Returns**:

* `result` (boolean)

***

### `disabled`

*Read-only*. The disabled state of the object.

**Returns**:

* `result` (boolean)

***

### `id`

*Read-only*. The unique identifier for the object.

**Returns**:

* `result` (string)

***

### `item`

*Read-only*. No description yet available.

**Returns**:

* `result` ([tes3item](../../types/tes3item))

***

### `itemData`

*Read-only*. No description yet available.

**Returns**:

* `result` ([tes3itemData](../../types/tes3itemData))

***

### `itemID`

*Read-only*. No description yet available.

**Returns**:

* `result` (string)

***

### `magicID`

*Read-only*. No description yet available.

**Returns**:

* `result` (string)

***

### `modified`

The modification state of the object since the last save.

**Returns**:

* `result` (boolean)

***

### `objectFlags`

*Read-only*. The raw flags of the object.

**Returns**:

* `result` (number)

***

### `objectType`

*Read-only*. The type of object. Maps to values in [`tes3.objectType`](https://mwse.github.io/MWSE/references/object-types/).

**Returns**:

* `result` (number)

***

### `persistent`

The persistent flag of the object.

**Returns**:

* `result` (boolean)

***

### `projectile`

*Read-only*. No description yet available.

**Returns**:

* `result` ([tes3mobileProjectile](../../types/tes3mobileProjectile))

***

### `serialNumber`

*Read-only*. Unique indentifier for just this magic source.

**Returns**:

* `result` (number)

***

### `source`

*Read-only*. No description yet available.

**Returns**:

* `result` ([tes3alchemy](../../types/tes3alchemy), [tes3enchantment](../../types/tes3enchantment), [tes3spell](../../types/tes3spell))

***

### `sourceEffects`

*Read-only*. An array-style table holding spell effects this magic source has.

**Returns**:

* `result` (table)

***

### `sourceless`

The soruceless flag of the object.

**Returns**:

* `result` (boolean)

***

### `sourceMod`

*Read-only*. The filename of the mod that owns this object.

**Returns**:

* `result` (string)

***

### `sourceType`

*Read-only*. The type of this magic source. Maps to [`tes3.magicSourceType`](https://mwse.github.io/MWSE/references/magic-source-types/) constants.

**Returns**:

* `result` (number)

***

### `state`

Shows if the state is pre-cast, cast, beginning, working, ending, retired, etc. Maps to [`tes3.spellState`](https://mwse.github.io/MWSE/references/spell-states/) constants.

**Returns**:

* `result` (number)

***

### `supportsLuaData`

If true, references of this object can store temporary or persistent lua data.

**Returns**:

* `result` (boolean)

***

### `target`

*Read-only*. No description yet available.

**Returns**:

* `result` ([tes3reference](../../types/tes3reference))

***

### `timestampCastBegin`

No description yet available.

**Returns**:

* `result` (number)

***

## Methods

### `__tojson`

Serializes the object to json.

```lua
local string = tes3baseObject:__tojson()
```

**Returns**:

* `string` (string)

***

### `getEffectInstance`

Gets the magic effect instance for a given effect index and target reference. Effect instances may not all be active on a target, due to reflect, absorption, dispels, different durations and other factors.

```lua
local result = tes3magicSourceInstance:getEffectInstance(index, target)
```

**Parameters**:

* `index` (number): The index in the effect list to fetch, between `0` and `7`.
* `target` ([tes3reference](../../types/tes3reference)): The target actor for the effect.

**Returns**:

* `result` ([tes3magicEffectInstance](../../types/tes3magicEffectInstance))

***

### `getMagnitudeForIndex`

Gets the magnitude from the casting source for a given effect index.

```lua
local result = tes3magicSourceInstance:getMagnitudeForIndex(index)
```

**Parameters**:

* `index` (number): The index in the effect list to fetch, between `0` and `7`.

**Returns**:

* `result` (number)

***

### `playVisualEffect`

This function plays an animation for an effect from the `tes3magicSourceInstance` object.

```lua
tes3magicSourceInstance:playVisualEffect({ effectIndex = ..., position = ..., visual = ..., scale = ..., reference = ... })
```

**Parameters**:

* `params` (table)
	* `effectIndex` (number): The index in the effect whose visual will be played, a number in range [0, 7].
	* `position` ([tes3vector3](../../types/tes3vector3), table): A table or a `tes3vector3` holding `x`, `y` and `z` coordinates at which the visual effect will be played.
	* `visual` ([tes3physicalObject](../../types/tes3physicalObject), string): The visual effect to be played.
	* `scale` (number): *Default*: `1`. The scale of the effect. Only applies to effects that are designed to be scaled.
	* `reference` ([tes3reference](../../types/tes3reference), string): A reference on which the visual effect will be played.

??? example "Example: Plays the soul trap effect if the player kills a target that is affected by vampirism."

	```lua
	local function onDamaged(e)
		-- Check if we killed our target with this damage.
		if e.killingBlow then
			-- Iterate through the killed target's active magic effects.
			for _, activeMagicEffect in pairs(e.mobile.activeMagicEffectList) do
				-- Check if the target is a vampire.
				if activeMagicEffect.effectId == tes3.effect.vampirism then
					-- Play the soul trap visual effect at the position of the target.
					activeMagicEffect.instance:playVisualEffect{
						effectIndex = 0,
						position = e.mobile.position,
						visual = "VFX_Soul_Trap"
					}
					break
				end
			end
		end
	end
	
	event.register("damaged", onDamaged)

	```

***

