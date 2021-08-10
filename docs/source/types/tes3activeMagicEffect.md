# tes3activeMagicEffect

An active magic effect.

## Properties

### `attributeId`

The attribute ID (note that this may be the skill ID if the effect affects skills).

**Returns**:

* `result` (number)

***

### `duration`

The total duration of this specific effect.

**Returns**:

* `result` (number)

***

### `effectId`

The magic effect ID.

**Returns**:

* `result` (number)

***

### `effectIndex`

The index of the effect inside the magic source instance.

**Returns**:

* `result` (number)

***

### `effectInstance`

The magic effect instance for this effect.

**Returns**:

* `result` ([tes3magicEffectInstance](../../types/tes3magicEffectInstance))

***

### `harmful`

This flag that determines if this effect is counted as a hostile action.

**Returns**:

* `result` (boolean)

***

### `instance`

The magic source instance for this effect.

**Returns**:

* `result` ([tes3magicSourceInstance](../../types/tes3magicSourceInstance))

***

### `isSummon`

No description yet available.

**Returns**:

* `result` (boolean)

***

### `magnitude`

The unresisted magnitude of the magic effect, that is the magnitude before resistance attributes are applied. This is always an integer number. To find the actual applied magnitude, you must check the magic effect instance.

**Returns**:

* `result` (number)

***

### `magnitudeMin`

Deprecated.

**Returns**:

* `result` (number)

***

### `mobile`

The mobile affected by the magic effect.

**Returns**:

* `result` ([tes3magicSourceInstance](../../types/tes3magicSourceInstance))

***

### `next`

Deprecated.

**Returns**:

* `result` ([tes3activeMagicEffect](../../types/tes3activeMagicEffect))

***

### `previous`

Deprecated.

**Returns**:

* `result` ([tes3activeMagicEffect](../../types/tes3activeMagicEffect))

***

### `serial`

The magic source instance serial number. See the ``instance`` and ``effectInstance`` properties to easily access the magic and effect instances.

**Returns**:

* `result` (number)

***

### `skillId`

The skill ID (note that this may be the attribute ID if the effect affects attributes).

**Returns**:

* `result` (number)

***

