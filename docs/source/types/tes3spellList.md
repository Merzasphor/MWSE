# tes3spellList

A list of spells. Used by actors, birthsigns, and races.

## Properties

### `iterator`

*Read-only*. Deprecated. Use `for index, spell in pairs(spellList)` to iterate over spells.
	
Direct access to the spells in this list.

**Returns**:

* `result` ([tes3iterator](../../types/tes3iterator))

***

## Methods

### `add`

Adds a spell to the list.

```lua
local result = myObject:add(spell)
```

**Parameters**:

* `spell` (string, [tes3spell](../../types/tes3spell)): The spell.

**Returns**:

* `result` (boolean)

***

### `contains`

Checks if the specified spell is contained in the spell list.

```lua
local result = myObject:contains(spell)
```

**Parameters**:

* `spell` (string, [tes3spell](../../types/tes3spell)): The spell.

**Returns**:

* `result` (boolean)

***

### `containsType`

Finds the first spell with the type provided.

```lua
local result = myObject:containsType(spellType)
```

**Parameters**:

* `spellType` (number): A value from [`tes3.spellType`](https://mwse.github.io/MWSE/references/spell-types/) enumeration.

**Returns**:

* `result` ([tes3spell](../../types/tes3spell))

***

### `getCheapest`

Finds the castable spell in the list with the lowest casting cost.

```lua
local result = myObject:getCheapest()
```

**Returns**:

* `result` ([tes3spell](../../types/tes3spell))

***

### `remove`

Removes a spell from the list.

```lua
local result = myObject:remove(spell)
```

**Parameters**:

* `spell` (string, [tes3spell](../../types/tes3spell)): The spell.

**Returns**:

* `result` (boolean)

***

