return {
	type = "method",
	description = [[Gets the item associated with the given quick key. If the quick key is not marked as an item, this will return `nil`. This is equivalent to fetching the `item` and `itemData` properties, after checking to make sure the `type` is set to item.]],
	returns = {
		{ name = "source", type = "tes3item|nil", description = "The item bound to the quick key." },
		{ name = "data", type = "tes3itemData|nil", description = "Any associated item data bound to the quick key" },
	},
}