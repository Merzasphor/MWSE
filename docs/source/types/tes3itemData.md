# tes3itemData

A set of variables that differentiates one item from another.

## Properties

### `charge`

The charge of the item. Provides incorrect values on misc items, which instead have a soul actor.

**Returns**:

* `result` (number)

***

### `condition`

The condition/health of the item. Provides incorrect values on light items, which instead have a timeLeft property.

**Returns**:

* `result` (number)

***

### `context`

Returns an ease of use script context for variable access.

**Returns**:

* `result` ([tes3scriptContext](../../types/tes3scriptContext))

***

### `count`

The total number of identical items represented by this data. Reserved for use by in-world references. It should always be 1 for items in inventories. Inventories utilize the stack count in tes3itemStack.

**Returns**:

* `result` (number)

***

### `data`

A generic lua table that data can be written to, and synced to/from the save. All information stored must be valid for serialization to json. For data that doesn't persist, use tempData.

**Returns**:

* `result` (table)

***

### `owner`

The script associated with the scriptVariables.

**Returns**:

* `result` ([tes3npc](../../types/tes3npc), [tes3faction](../../types/tes3faction), nil)

***

### `requirement`

A requirement, typically associated with ownership and when the player may freely interact with an object. The type depends on the owner. Faction owners provide a required rank as a number, while NPCs provide a global variable to check.

**Returns**:

* `result` ([tes3globalVariable](../../types/tes3globalVariable), number, nil)

***

### `script`

*Read-only*. The script associated with the scriptVariables.

**Returns**:

* `result` ([tes3script](../../types/tes3script))

***

### `scriptVariables`

Access to the structure where individual mwscript data is stored.

**Returns**:

* `result` (tes3scriptVariables)

***

### `soul`

Only available on misc items. The actor that is stored inside the soul gem.

**Returns**:

* `result` ([tes3actor](../../types/tes3actor))

***

### `tempData`

A generic lua table that data can be written to, but is not synced to/from a save.

**Returns**:

* `result` (table)

***

### `timeLeft`

The time remaining on a light. Provides incorrect values on non-light items, which instead have a condition property.

**Returns**:

* `result` (number)

***

