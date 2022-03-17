# tes3inventoryTile

An inventory tile, connecting an item, its data, and various related UI elements.

## Properties

### `count`

*Read-only*. The number of items that the tile represents.

**Returns**:

* `result` (number)

***

### `element`

*Read-only*. The UI element associated with the tile.

**Returns**:

* `result` ([tes3uiElement](../../types/tes3uiElement))

***

### `flags`

*Read-only*. Direct access to the tile's flags. Use `.isBartered`, `.isBoundItem`, or `.isEquipped` to access individual flags.

**Returns**:

* `result` (number)

***

### `isBartered`

If `true`, the tile represents an item being bartered.

**Returns**:

* `result` (boolean)

***

### `isBoundItem`

*Read-only*. If `true`, the tile represents a bound item.

**Returns**:

* `result` (boolean)

***

### `isEquipped`

If `true`, the tile represents an item that is equipped.

**Returns**:

* `result` (boolean)

***

### `item`

*Read-only*. The item the tile represents.

**Returns**:

* `result` ([tes3item](../../types/tes3item))

***

### `itemData`

*Read-only*. The item data associated with this tile.

**Returns**:

* `result` ([tes3itemData](../../types/tes3itemData))

***

### `type`

*Read-only*. The type of tile represented. Maps to values in [`tes3.inventoryTileType`](https://mwse.github.io/MWSE/references/inventory-tile-types/) namespace.

**Returns**:

* `result` (number)

***

