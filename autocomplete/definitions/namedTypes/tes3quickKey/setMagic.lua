return {
	type = "method",
	description = [[Sets the binding of the quick key to a given magic source. This must be a spell, or an item with an on-use enchantment.]],
	arguments = {
		{ name = "source", type = "tes3spell|tes3item", description = "The castable source to be bound to the quick key." },
		{ name = "data", type = "tes3itemData|nil", description = "If given an item as the source, the optional item data to be paired with the binding." },
	},
}