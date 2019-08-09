return {
	description = "This event is called when determining the cost of purchasing a spell. The price can be modified.",
	eventData = {
		["mobile"] = {
			type = "tes3mobileActor",
			readonly = true,
			description = "The mobile actor of the merchant the player is interacting with.",
		},
		["reference"] = {
			type = "tes3reference",
			readonly = true,
			description = "mobile’s related reference.",
		},
		["basePrice"] = {
			type = "number",
			readonly = true,
			description = "The price before adjustment.",
		},
		["price"] = {
			type = "number",
			description = "The adjusted price of spell.",
		},
		["spell"] = {
			type = "tes3spell",
			readonly = true,
			description = "The spell currently being purchased.",
		},
	},
}