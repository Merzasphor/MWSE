# tes3quickKey

A configuration detailing a quick key.

## Properties

### `item`

*Read-only*. The raw item bound to the quick key. To change its value, use either the `setItem` or `setMagic` methods.

**Returns**:

* `result` ([tes3item](../../types/tes3item))

***

### `itemData`

*Read-only*. The raw item data bound to the quick key. To change its value, use either the `setItem` or `setMagic` methods.

**Returns**:

* `result` ([tes3itemData](../../types/tes3itemData))

***

### `spell`

*Read-only*. The raw spell bound to the quick key. To change its value, use the `setMagic` method.

**Returns**:

* `result` ([tes3spell](../../types/tes3spell))

***

### `type`

*Read-only*. The type of the quick key, with the numeric value matching [`tes3.quickKeyType`](https://mwse.github.io/MWSE/references/quick-key-types/) constants.

**Returns**:

* `result` (number)

***

## Methods

### `clear`

Unbinds the quick key, removing any data in it.

```lua
tes3quickKey:clear()
```

***

### `getItem`

Gets the item associated with the given quick key. If the quick key is not marked as an item, this will return `nil`. This is equivalent to fetching the `item` and `itemData` properties, after checking to make sure the `type` is set to item.

```lua
local source, data = tes3quickKey:getItem()
```

**Returns**:

* `source` ([tes3item](../../types/tes3item), nil): The item bound to the quick key.
* `data` ([tes3itemData](../../types/tes3itemData), nil): Any associated item data bound to the quick key

***

### `getMagic`

Gets the magic associated with the given quick key. If the quick key is not marked as magic, this will return `nil`. This is equivalent to fetching either the `spell` or `item` properties and the `itemData` property, after checking to make sure the `type` is set to magic.

```lua
local source, data = tes3quickKey:getMagic()
```

**Returns**:

* `source` ([tes3spell](../../types/tes3spell), [tes3item](../../types/tes3item), nil): The castable source bound to the quick key.
* `data` ([tes3itemData](../../types/tes3itemData), nil): Any associated item data bound to the quick key

***

### `setItem`

Sets the binding of the quick key to a given item source.

```lua
tes3quickKey:setItem(source, data)
```

**Parameters**:

* `source` ([tes3item](../../types/tes3item)): The item to be bound to the quick key.
* `data` ([tes3itemData](../../types/tes3itemData), nil): The optional item data to be paired with the binding.

***

### `setMagic`

Sets the binding of the quick key to a given magic source. This must be a spell, or an item with an on-use enchantment.

```lua
tes3quickKey:setMagic(source, data)
```

**Parameters**:

* `source` ([tes3spell](../../types/tes3spell), [tes3item](../../types/tes3item)): The castable source to be bound to the quick key.
* `data` ([tes3itemData](../../types/tes3itemData), nil): If given an item as the source, the optional item data to be paired with the binding.

***

