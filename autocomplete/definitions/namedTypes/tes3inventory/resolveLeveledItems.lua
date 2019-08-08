return {
	type = "method",
	description = [[Resolves all contained leveled lists and adds the randomized items to the inventory. This should generally not be called directly.]],
	arguments = {
		{ name = "mobile", type = "tes3mobileActor", optional = true, description = "The mobile actor whose stats will be updated." },
	},
}