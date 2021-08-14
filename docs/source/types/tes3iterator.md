# tes3iterator

A collection that can be iterated over Contains items in a simple linked list, and stores its head/tail.

## Properties

### `current`

*Read-only*. A reference for the currently iterated node. This is used by the core game engine, but should not be accessed from lua.

**Returns**:

* `result` ([tes3iteratorNode](../../types/tes3iteratorNode))

***

### `head`

*Read-only*. The first node in the collection.

**Returns**:

* `result` ([tes3iteratorNode](../../types/tes3iteratorNode))

***

### `size`

*Read-only*. The amount of items in the iterator.

**Returns**:

* `result` (number)

***

### `tail`

*Read-only*. The last node in the collection.

**Returns**:

* `result` ([tes3iteratorNode](../../types/tes3iteratorNode))

***

??? example "Example: Iterating Lists"

	```lua
	-- Check player equipment
	for _, stack in pairs(tes3.player.object.equipment) do
	    -- stack is type tes3equipmentStack, as tes3.player.object.equipment is a list of tes3equipmentStack.
	    mwse.log("Equipment object ID: %s", stack.object.id)
	end
	
	-- tes3.player.object.spells is a tes3spellList with helper functions.
	-- The actual list is spells.iterator.
	for _, spell in pairs(tes3.player.object.spells.iterator) do
	    -- spell is type tes3spell, as tes3.player.object.spells.iterator is a list of spell.
	    mwse.log("Spell %s, cost %d", spell.name, spell.magickaCost)
	end

	```

