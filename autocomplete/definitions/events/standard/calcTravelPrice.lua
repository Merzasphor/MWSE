return {
	description = "This event is called when determining the price of traveling, and can be used to modify the given price.",
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
			description = "The adjusted price of travelling.",
		},
		["destination"] = {
			type = "tes3reference",
			readonly = true,
			description = "The travel marker that marks the destination.",
		},
		["companions"] = {
			type = "table",
			readonly = true,
			description = "A table of companions (tes3references) that will travel with the player, or nil if no companions are present."
		},
	},
}