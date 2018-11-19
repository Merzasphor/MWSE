return {
	type = "function",
	description = [[Determines if a merchant trades in a given item.]],
	arguments = {
		{ name = "item", type = "tes3item|string" },
		{ name = "reference", type = "tes3reference|tes3mobileActor|string" },
	},
	returns = "trades",
	valuetype = "boolean",
}