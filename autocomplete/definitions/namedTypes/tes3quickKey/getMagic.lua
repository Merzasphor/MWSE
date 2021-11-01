return {
	type = "method",
	description = [[Gets the magic associated with the given quick key. If the quick key is not marked as magic, this will return `nil`. This is equivalent to fetching either the `spell` or `item` properties and the `itemData` property, after checking to make sure the `type` is set to magic.]],
	returns = {
		{ name = "source", type = "tes3spell|tes3item|nil", description = "The castable source bound to the quick key." },
		{ name = "data", type = "tes3itemData|nil", description = "Any associated item data bound to the quick key" },
	},
}