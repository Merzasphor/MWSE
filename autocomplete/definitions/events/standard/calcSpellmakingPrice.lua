return {
	type = "event",
	description = "This event is called when determining the cost of making a spell. The price can be modified.",
	eventData = {
		["mobile"] = {
			type = "tes3mobileActor",
			readOnly = true,
			description = "The mobile actor of the spellmaking service npc the player is interacting with.",
		},
		["reference"] = {
			type = "tes3reference",
			readOnly = true,
			description = "Mobile's related reference.",
		},
		["price"] = {
			type = "number",
			description = "The price of the spell.",
		},
	},
}