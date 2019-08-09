return {
	description = "This event is used to notify when an actor's body parts have finished updating. This typically triggers when an actor is first rendered, or when their equipment changes.",
	eventData = {
		["mobile"] = {
			type = "tes3mobileActor",
			readonly = true,
			description = "The mobile actor whose body parts have updated.",
		},
		["reference"] = {
			type = "tes3reference",
			readonly = true,
			description = "The reference for the actor whose body parts was updated.",
		},
	},
}