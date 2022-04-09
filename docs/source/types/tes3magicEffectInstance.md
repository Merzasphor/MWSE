# tes3magicEffectInstance

Represents an individual instance of a magic effect being applied to a reference.

## Properties

### `createdData`

*Read-only*. The bound or summoned data associated with the instance, for summoned creatures or items. The stack's object will be a reference in the case of summoned creatures.

**Returns**:

* `result` ([tes3equipmentStack](../../types/tes3equipmentStack))

***

### `cumulativeMagnitude`

No description yet available.

**Returns**:

* `result` (number)

***

### `effectiveMagnitude`

The effective magnitude of the effect, after all resistances are applied.

**Returns**:

* `result` (number)

***

### `lastUsedArmor`

*Read-only*. No description yet available.

**Returns**:

* `result` ([tes3armor](../../types/tes3armor))

***

### `lastUsedEnchItem`

*Read-only*. No description yet available.

**Returns**:

* `result` ([tes3item](../../types/tes3item))

***

### `lastUsedLight`

*Read-only*. No description yet available.

**Returns**:

* `result` ([tes3light](../../types/tes3light))

***

### `lastUsedShield`

*Read-only*. No description yet available.

**Returns**:

* `result` ([tes3armor](../../types/tes3armor))

***

### `lastUsedWeapon`

*Read-only*. No description yet available.

**Returns**:

* `result` ([tes3weapon](../../types/tes3weapon))

***

### `magnitude`

The magnitude of the effect, before any resistances are applied.

**Returns**:

* `result` (number)

***

### `resistedPercent`

The percentage of the magic effect that has been resisted. A value of `100` indicates that the magic effect has been completely resisted, whereas a value of `0` indicates it has not been resisted and is applied with its full magnitude. Values over `100` cause the magic effect to heal the actor instead of harming it, if it is a damaging magic effect.

**Returns**:

* `result` (number)

***

### `state`

The state of this magic effect instance. Maps to [`tes3.spellState`](https://mwse.github.io/MWSE/references/spell-states/) constants.

**Returns**:

* `result` (number)

***

### `target`

No description yet available.

**Returns**:

* `result` ([tes3reference](../../types/tes3reference))

***

### `timeActive`

No description yet available.

**Returns**:

* `result` (number)

***

### `visual`

No description yet available.

**Returns**:

* `result` (number)

***

