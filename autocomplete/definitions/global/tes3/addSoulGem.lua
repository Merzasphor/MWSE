return {
	type = "function",
	description = [[Causes a misc item to be recognized as a soul gem, so that it can be used for soul trapping.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "item", type = "tes3misc|string", description = "The item to recognize as a soul gem." },
		},
	}},
	examples = {
		["customSoulGem"] = {
			title = "Make the Dwemer Tube a Soul gem. Also, make sure Fargoth's soul alway ends up in it if the player has one avilable.",
		}
	},
	returns = {{ name = "wasAdded", type = "boolean" }},
}