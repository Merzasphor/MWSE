return {
	type = "method",
	description = [[Sets the binding of the quick key to a given item source.]],
	arguments = {
		{ name = "source", type = "tes3item", description = "The item to be bound to the quick key." },
		{ name = "data", type = "tes3itemData|nil", description = "The optional item data to be paired with the binding." },
	},
}