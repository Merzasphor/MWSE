# tes3inventory

An inventory composes of an iterator, and flags caching the state of the inventory.

## Properties

### `flags`

*Read-only*. Raw bit-based flags.

**Returns**:

* `result` (number)

***

### `items`

*Read-only*. Direct acces to the container that holds the inventory's items.

**Returns**:

* `result` ([tes3iterator](../../types/tes3iterator))

***

### `iterator`

*Read-only*. Deprecated. Use `for index, stack in pairs(inventory)` to iterate over inventory stacks.
	
Direct access to the container that holds the inventory's items.

**Returns**:

* `result` ([tes3iterator](../../types/tes3iterator))

***

## Methods

### `addItem`

Adds an item into the inventory directly. This should not be used, in favor of the [`tes3.addItem()`](https://mwse.github.io/MWSE/apis/tes3/#tes3additem) function.

```lua
tes3inventory:addItem({ mobile = ..., item = ..., itemData = ..., count = ... })
```

**Parameters**:

* `params` (table)
	* `mobile` ([tes3mobileActor](../../types/tes3mobileActor), [tes3reference](../../types/tes3reference), string): *Optional*. The mobile actor whose stats will be updated.
	* `item` ([tes3item](../../types/tes3item)): The item to add.
	* `itemData` ([tes3itemData](../../types/tes3itemData)): *Optional*. Any associated item data to add.
	* `count` (number): *Default*: `1`. The number of items to add.

***

### `calculateWeight`

Calculates the weight of all items in the container.

```lua
local result = tes3inventory:calculateWeight()
```

**Returns**:

* `result` (number)

***

### `contains`

Checks to see if the inventory contains an item.

```lua
local result = tes3inventory:contains(item, itemData)
```

**Parameters**:

* `item` ([tes3item](../../types/tes3item), string): The item to check for.
* `itemData` ([tes3itemData](../../types/tes3itemData)): *Optional*. If provided, it will check for the specific data as well.

**Returns**:

* `result` (boolean)

***

### `dropItem`

Checks to see if the inventory contains an item. This should not be used, instead use the [`tes3.dropItem()`](https://mwse.github.io/MWSE/apis/tes3/#tes3dropitem) function.

```lua
tes3inventory:dropItem(mobile, item, itemData, count, position, orientation, ignoreItemData)
```

**Parameters**:

* `mobile` ([tes3mobileActor](../../types/tes3mobileActor), [tes3reference](../../types/tes3reference), string): The mobile actor whose stats will be updated.
* `item` ([tes3item](../../types/tes3item), string): The item to drop.
* `itemData` ([tes3itemData](../../types/tes3itemData)): If provided, it will check for the specific data to drop it.
* `count` (number): The number of items to drop.
* `position` ([tes3vector3](../../types/tes3vector3)): A vector determining placement location.
* `orientation` ([tes3vector3](../../types/tes3vector3)): A vector determining placement rotation.
* `ignoreItemData` (boolean)

***

### `findItemStack`

Searches for an item stack in the inventory.

```lua
local result = tes3inventory:findItemStack(item)
```

**Parameters**:

* `item` ([tes3item](../../types/tes3item)): The item to search for.

**Returns**:

* `result` ([tes3itemStack](../../types/tes3itemStack))

***

### `removeItem`

Removes an item from the inventory directly. This should not be used, in favor of the [`tes3.removeItem()`](https://mwse.github.io/MWSE/apis/tes3/#tes3removeitem) function.

```lua
tes3inventory:removeItem({ mobile = ..., item = ..., itemData = ..., count = ..., deleteItemData = ... })
```

**Parameters**:

* `params` (table)
	* `mobile` ([tes3mobileActor](../../types/tes3mobileActor), [tes3reference](../../types/tes3reference), string): *Optional*. The mobile actor whose stats will be updated.
	* `item` ([tes3item](../../types/tes3item)): The item to add.
	* `itemData` ([tes3itemData](../../types/tes3itemData)): *Optional*. Any associated item data to add.
	* `count` (number): *Default*: `1`. The number of items to add.
	* `deleteItemData` (boolean): If set, the itemData will be deleted after being removed.

***

### `resolveLeveledItems`

Resolves all contained leveled lists and adds the randomized items to the inventory. This should generally not be called directly.

```lua
tes3inventory:resolveLeveledItems(mobile)
```

**Parameters**:

* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): *Optional*. The mobile actor whose stats will be updated.

***

