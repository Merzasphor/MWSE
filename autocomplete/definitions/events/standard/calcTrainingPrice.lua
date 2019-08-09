return {
	description = "This event is called when determining the cost of training, and can be used to modify the given price.",
	eventData = {
		["mobile"] = {
			type = "tes3mobileActor",
			readonly = true,
			description = "The mobile actor of the trainer the player is interacting with.",
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
			description = "The adjusted price of the training.",
		},
		["skill"] = {
			type = "tes3statisticSkill",
			readonly = true,
			description = "The ID of the skill to be trained.",
		},
		["skillId"] = {
			type = "number",
			readonly = true,
			description = "The ID of the skill to be trained.",
		},
	},
}