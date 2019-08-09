return {
	description = "This event is called when determining the price of repairing an item. It can be used to override the repair cost.",
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
			description = "The adjusted price of repairing item.",
		},
		["item"] = {
			type = "tes3item",
			readonly = true,
			description = "The item to be repaired.",
		},
		["itemData"] = {
			type = "tes3item",
			readonly = true,
			description = "Variable node. The data associated with item. This may be nil.",
		},
	},
}