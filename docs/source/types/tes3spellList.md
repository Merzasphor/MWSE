# tes3spellList

A list of spells. Used by actors, birthsigns, and races.

## Properties

### `iterator`

*Read-only*. A collection of spells. Can be iterated over using *pairs*.

**Returns**:

* `result` ([tes3iterator](../../types/tes3iterator))

***

## Methods

### `add`

Adds a spell to the list.

```lua
local result = tes3spellList:add(spell)
```

**Parameters**:

* `spell` (string, [tes3spell](../../types/tes3spell)): The spell.

**Returns**:

* `result` (boolean)

***

### `contains`

Checks if the specified spell is contained in the spell list.

```lua
local result = tes3spellList:contains(spell)
```

**Parameters**:

* `spell` (string, [tes3spell](../../types/tes3spell)): The spell.

**Returns**:

* `result` (boolean)

***

### `containsType`

Finds the first spell with the type provided.

```lua
local result = tes3spellList:containsType(spellType)
```

**Parameters**:

* `spellType` (number): A value from tes3.spellType.

**Returns**:

* `result` ([tes3spell](../../types/tes3spell))

***

### `getCheapest`

Finds the castable spell in the list with the lowest casting cost.

```lua
local result = tes3spellList:getCheapest()
```

**Returns**:

* `result` ([tes3spell](../../types/tes3spell))

***

### `remove`

Removes a spell from the list.

```lua
local result = tes3spellList:remove(spell)
```

**Parameters**:

* `spell` (string, [tes3spell](../../types/tes3spell)): The spell.

**Returns**:

* `result` (boolean)

***

