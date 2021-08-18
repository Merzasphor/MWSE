return {
	type = "function",
	description = [[Returns the amount of a certain item that can be found in a reference's inventory.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3reference|tes3mobileActor|string", description = "The reference to get the item count for. Must be a reference that has an inventory." },
			{ name = "item", type = "tes3item|string", description = "The item to get the count of." },
		},
	}},
	returns = {
		{ name = "count", type = "number", description = "The absolute value of the stack count in the reference's inventory." },
	},
}
