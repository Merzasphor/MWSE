return {
	type = "function",
	description = [[This function opens the inventory select menu which lets the player select items from an inventory. These items can be selected from any actor's inventory and can be filtered with the `filter` callback. The selected item can be retrieved in the function assigned to `callback`.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{
				name = "reference",
				type = "tes3reference",
				optional = true,
				default = "tes3player",
				description = "The reference of a `tes3actor` whose inventory will be used."
			},
			{
				name = "title",
				type = "string",
				description = "The text used for the title of the inventory select menu."
			},
			{
				name = "leaveMenuMode",
				type = "boolean",
				optional = true,
				description = "Determines if menu mode should be exited after closing the inventory select menu. By default, it will be in the state it was in before this function was called."
			},
			{
				name = "noResultsText",
				type = "string",
				optional = true,
				description = "The text used for the message that gets shown to the player if no items have been found in the inventory. The default text is equivalent to the `sInventorySelectNoItems` GMST value, unless `\"ingredients\"` or `\"soulgemFilled\"` has been assigned to `filter`, in which case the default text is equivalent to either the `sInventorySelectNoIngredients` or `sInventorySelectNoSoul` GMST value respectively."
			},
			{
				name = "noResultsCallback",
				type = "function",
				optional = true,
				description = "A function which is called when no items have been found in the inventory, right before the message containing `noResultsText` is shown."
			},
			{
				name = "filter",
				type = "function|string",
				optional = true,
				description = [[This determines which items should be shown in the inventory select menu. Accepts either a string or a function.

		If assigning a string, the available values are present in [`tes3.inventorySelectFilter`](https://mwse.github.io/MWSE/references/inventory-select-filters/) namespace. The available filters are:

		- `alembic`: Only [tes3apparatus](https://mwse.github.io/MWSE/types/tes3apparatus/) items of type `tes3.apparatusType.alembic` will be shown.
		- `calcinator`: Only [tes3apparatus](https://mwse.github.io/MWSE/types/tes3apparatus/) items of type `tes3.apparatusType.calcinator` will be shown.
		- `enchanted`: Only enchanted items will be shown.
		- `ingredients`: Only [tes3ingredient](https://mwse.github.io/MWSE/types/tes3ingredient/) items will be shown.
		- `mortar`: Only [tes3apparatus](https://mwse.github.io/MWSE/types/tes3apparatus/) items of type `tes3.apparatusType.mortarAndPestle` will be shown.
		- `quickUse`: Only items available for quick use will be shown.
		- `retort`: Only [tes3apparatus](https://mwse.github.io/MWSE/types/tes3apparatus/) items of type `tes3.apparatusType.retort` will be shown.
		- `soulgemFilled`: Only filled soulgems will be shown.

		If assigning a function it will be called when determining if an item should be added to the inventory select menu. A table `filterParams` will be passed to this function. Returning `true` from this function will add the item to the inventory select menu, whereas returning `false` will prevent it from being added.

		- `filterParams` (table)
			- `item` ([tes3item](https://mwse.github.io/MWSE/types/tes3item/)): The item that is being filtered.
			- `itemData` ([tes3itemData](https://mwse.github.io/MWSE/types/tes3itemData/)): The item data of the item that is being filtered. Can be `nil`.
]],
			},
			{
				name = "callback",
				type = "function",
				optional = true,
				description = [[A function which will be called once the inventory select menu has been closed, including when no item has been selected. A table `callbackParams` will be passed to this function.
		- `callbackParams` (table)
			- `item` ([tes3item](https://mwse.github.io/MWSE/types/tes3item/)): The item that has been selected. Can be `nil`.
			- `itemData` ([tes3itemData](https://mwse.github.io/MWSE/types/tes3itemData/)): The item data of the item that has been selected. Can be `nil`.
			- `count` (number): The number of items that have been selected. Only valid if `item` is not `nil`.
			- `inventory` ([tes3inventory](https://mwse.github.io/MWSE/types/tes3inventory/)): The inventory containing the items.
			- `actor` ([tes3actor](https://mwse.github.io/MWSE/types/tes3actor/)): The actor containing the inventory.
]],
			},
		},
	}},
}
