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

### `tail`

*Read-only*. The last node in the collection.

**Returns**:

* `result` ([tes3iteratorNode](../../types/tes3iteratorNode))

***

## Methods

### `size`

*Read-only*. Returns the amount of items in the iterator.

```lua
local result = tes3iterator:size()
```

**Returns**:

* `result` (number)

***

??? example "Example: Iterating Lists"

	```lua
	-- Check player equipment. Equipment list contains only equipped items.
	for _, stack in pairs(tes3.player.object.equipment) do
		-- stack is type tes3equipmentStack, as tes3.player.object.equipment is a list of tes3equipmentStack objects.
		mwse.log("Equipment object ID: %s", stack.object.id)
	end
	
	-- This will iterate over all the items in player's inventory including equipped items.
	for _, itemStack in pairs(tes3.player.object.inventory) do
		-- itemStack is of tes3itemStack type
		local item = itemStack.object
		mwse.log("The player has %s of %s in inventory.", itemStack.count, item.id)
	end
	
	-- tes3.player.object.spells is a tes3spellList with helper functions.
	-- The actual list is spells.iterator.
	for _, spell in pairs(tes3.player.object.spells.iterator) do
		-- spell is type tes3spell, as tes3.player.object.spells.iterator is a list of tes3spell objects.
		mwse.log("Spell %s, cost %d", spell.name, spell.magickaCost)
	end

	```

