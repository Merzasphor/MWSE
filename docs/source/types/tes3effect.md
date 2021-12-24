# tes3effect

A structure that defines information for an effect and its associated variables, typically found on spells, alchemy, and enchantments.

## Properties

### `attribute`

The attribute associated with this effect, or `-1` if no attribute is used.

**Returns**:

* `result` (number)

***

### `cost`

The base magicka cost of this effect.

**Returns**:

* `result` (number)

***

### `duration`

How long the effect should last.

**Returns**:

* `result` (number)

***

### `id`

The base `tes3magicEffect` ID that the effect uses.

**Returns**:

* `result` (number)

***

### `max`

The maximum magnitude of the effect.

**Returns**:

* `result` (number)

***

### `min`

The minimum magnitude of the effect.

**Returns**:

* `result` (number)

***

### `object`

*Read-only*. Fetches the `tes3magicEffect` for the given id used.

**Returns**:

* `result` ([tes3magicEffect](../../types/tes3magicEffect))

***

### `radius`

The radius of the effect.

**Returns**:

* `result` (number)

***

### `rangeType`

Determines if the effect is self, touch, or target ranged. Maps to [`tes3.effectRange`](https://mwse.github.io/MWSE/references/effect-ranges/) constants.

**Returns**:

* `result` (number)

***

### `skill`

The skill associated with this effect, or `-1` if no skill is used.

**Returns**:

* `result` (number)

***

