# tes3combatSession

A structure that keeps track of combat session data.

## Properties

### `alchemyPriority`

No description yet available.

**Returns**:

* `result` (number)

***

### `data`

No description yet available.

***

### `distance`

No description yet available.

**Returns**:

* `result` (number)

***

### `lastUseTimestamp`

No description yet available.

**Returns**:

* `result` (number)

***

### `mobile`

*Read-only*. No description yet available.

**Returns**:

* `result` ([tes3mobileActor](../../types/tes3mobileActor))

***

### `potionUseFlag`

No description yet available.

**Returns**:

* `result` (number)

***

### `selectedAction`

No description yet available.

**Returns**:

* `result` (number)

***

### `selectedAlchemy`

No description yet available.

**Returns**:

* `result` ([tes3alchemy](../../types/tes3alchemy))

***

### `selectedItem`

No description yet available.

**Returns**:

* `result` ([tes3itemStack](../../types/tes3itemStack))

***

### `selectedShield`

*Read-only*. No description yet available.

**Returns**:

* `result` ([tes3equipmentStack](../../types/tes3equipmentStack))

***

### `selectedSpell`

No description yet available.

**Returns**:

* `result` ([tes3spell](../../types/tes3spell))

***

### `selectedWeapon`

*Read-only*. No description yet available.

**Returns**:

* `result` ([tes3equipmentStack](../../types/tes3equipmentStack))

***

### `selectionPriority`

No description yet available.

**Returns**:

* `result` (number)

***

## Methods

### `changeEquipment`

This method equips an item to the mobile in this combat sesion.

```lua
tes3combatSession:changeEquipment(equipmentStack)
```

**Parameters**:

* `equipmentStack` ([tes3equipmentStack](../../types/tes3equipmentStack)): An item to equip.

***

### `selectAlchemyWithEffect`

Selects the alchemy item with the greatest value, for a given effect ID and loads it into the selectedAlchemy property.

```lua
local result = tes3combatSession:selectAlchemyWithEffect(id)
```

**Parameters**:

* `id` (number)

**Returns**:

* `result` (number)

***

