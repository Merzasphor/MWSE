# tes3weapon

A weapon game object.

This type inherits the following: [tes3item](../../types/tes3item), [tes3physicalObject](../../types/tes3physicalObject), [tes3object](../../types/tes3object), [tes3baseObject](../../types/tes3baseObject)
## Properties

### `blocked`

The blocked state of the object.

**Returns**:

* `result` (boolean)

***

### `boundingBox`

The bounding box for the object.

**Returns**:

* `result` ([tes3boundingBox](../../types/tes3boundingBox))

***

### `chopMax`

Chop damage inflicted at maximum weapon swing.

**Returns**:

* `result` (number)

***

### `chopMin`

Chop damage inflicted at minimum weapon swing.

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

### `enchantCapacity`

The object's enchantment capacity.

**Returns**:

* `result` (number)

***

### `enchantment`

The enchantment used by the object.

**Returns**:

* `result` ([tes3enchantment](../../types/tes3enchantment))

***

### `flags`

Access to the weapon flag bitfield. Known flags can be accessed via other weapon properties.

**Returns**:

* `result` (number)

***

### `hasDurability`

*Read-only*. Whether the weapon type has durability. Thrown weapons and ammunition are used once fired, and therefore do not use durability.

**Returns**:

* `result` (boolean)

***

### `icon`

The path to the object's icon.

**Returns**:

* `result` (string)

***

### `id`

*Read-only*. The unique identifier for the object.

**Returns**:

* `result` (string)

***

### `ignoresNormalWeaponResistance`

Access to the flag that controls if this weapon bypasses the "Resist normal weapons" magic effect.

**Returns**:

* `result` (boolean)

***

### `isAmmo`

*Read-only*. If true, the weapon is a type of ammunition.

**Returns**:

* `result` (boolean)

***

### `isLocationMarker`

True if this object is an editor marker for a gameplay location. These include travel, intervention, prison, door, and interior north markers. Markers are invisible in-game.

**Returns**:

* `result` (boolean)

***

### `isMelee`

*Read-only*. If true, the weapon has a melee weapon type.

**Returns**:

* `result` (boolean)

***

### `isOneHanded`

*Read-only*. If true, the weapon is a one-handed weapon.

**Returns**:

* `result` (boolean)

***

### `isProjectile`

*Read-only*. If true, the weapon is a projectile.

**Returns**:

* `result` (boolean)

***

### `isRanged`

*Read-only*. If true, the weapon is a ranged weapon.

**Returns**:

* `result` (boolean)

***

### `isSilver`

If true, the weapon has a silver material flag.

**Returns**:

* `result` (boolean)

***

### `isTwoHanded`

*Read-only*. If true, the weapon is a two-handed melee weapon.

**Returns**:

* `result` (boolean)

***

### `maxCondition`

The object's maximum condition.

**Returns**:

* `result` (number)

***

### `mesh`

The path to the object's mesh.

**Returns**:

* `result` (string)

***

### `modified`

The modification state of the object since the last save.

**Returns**:

* `result` (boolean)

***

### `name`

The player-facing name for the object.

**Returns**:

* `result` (string)

***

### `nextInCollection`

The next object in parent collection's list.

**Returns**:

* `result` ([tes3object](../../types/tes3object))

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

### `owningCollection`

The collection responsible for holding this object.

**Returns**:

* `result` ([tes3referenceList](../../types/tes3referenceList))

***

### `persistent`

The persistent flag of the object.

**Returns**:

* `result` (boolean)

***

### `previousInCollection`

The previous object in parent collection's list.

**Returns**:

* `result` ([tes3object](../../types/tes3object))

***

### `reach`

The weapon's relative reach. A value of `1.0` is the standard reach. It is multiplied by the GMST `fCombatDistance` to find the attack reach in world units.

**Returns**:

* `result` (number)

***

### `scale`

The object's scale.

**Returns**:

* `result` (number)

***

### `sceneCollisionRoot`

The scene graph node for this object's physics collision, if its mesh has a root collision node.

**Returns**:

* `result` ([niNode](../../types/niNode))

***

### `sceneNode`

The scene graph node for this object.

**Returns**:

* `result` ([niNode](../../types/niNode))

***

### `sceneReference`

The scene graph reference node for this object.

**Returns**:

* `result` ([niNode](../../types/niNode))

***

### `script`

*Read-only*. The script that runs on the object.

**Returns**:

* `result` ([tes3script](../../types/tes3script))

***

### `skill`

Gets the skill data for the attack skill used by the weapon.

**Returns**:

* `result` ([tes3skill](../../types/tes3skill))

***

### `skillId`

Gets the skill ID for the attack skill used by the weapon. Maps to values in [`tes3.skill`](https://mwse.github.io/MWSE/references/skills/) namespace.

**Returns**:

* `result` (number)

??? example "Example: Print the name of the skill the attacker's weapon uses"

	```lua
	
	local function showMessage(e)
		if e.mobile.readiedWeapon then
			local id = e.mobile.readiedWeapon.object.skillId
			local name = tes3.getSkillName(id)
	
			tes3.messageBox(name)
		end
	end
	
	event.register(tes3.event.attackStart, showMessage)

	```

***

### `slashMax`

Slash damage inflicted at maximum weapon swing.

**Returns**:

* `result` (number)

***

### `slashMin`

Slash damage inflicted at minimum weapon swing.

**Returns**:

* `result` (number)

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

### `speed`

The relative attack speed of the weapon. Controls attack timing and animation speed. Standard speed is `1.0`.

**Returns**:

* `result` (number)

***

### `stolenList`

A list of actors that the object has been stolen from.

**Returns**:

* `result` ([tes3iterator](../../types/tes3iterator))

***

### `supportsLuaData`

If true, references of this object can store temporary or persistent lua data.

**Returns**:

* `result` (boolean)

***

### `thrustMax`

Thrust damage inflicted at maximum weapon swing.

**Returns**:

* `result` (number)

***

### `thrustMin`

Thrust damage inflicted at minimum weapon swing.

**Returns**:

* `result` (number)

***

### `type`

*Read-only*. A number representing the weapon type. Matches values from the [`tes3.weaponType`](https://mwse.github.io/MWSE/references/weapon-types/) table.

**Returns**:

* `result` (number)

***

### `typeName`

*Read-only*. The player-facing name for the weapon type.

**Returns**:

* `result` (string)

***

### `value`

The value of the object.

**Returns**:

* `result` (number)

***

### `weight`

The weight of the object.

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

### `getMaterialFlag`

Access to the material flag bitfield. Known material flags can be accessed via other weapon properties.

```lua
local result = tes3weapon:getMaterialFlag(flagBit)
```

**Parameters**:

* `flagBit` (number)

**Returns**:

* `result` (number)

***

### `setMaterialFlag`

Access to the material flag bitfield. Known material flags can be accessed via other weapon properties.

```lua
tes3weapon:setMaterialFlag(flagBit, value)
```

**Parameters**:

* `flagBit` (number)
* `value` (boolean)

***

