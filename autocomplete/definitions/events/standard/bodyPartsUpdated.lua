return {
	type = "event",
	description = "This event is triggered when an actor's body parts have finished updating. This typically triggers when an actor is first rendered, or when their equipment changes.",
	related = { "bodyPartAssigned", "bodyPartsUpdated" },
	eventData = {
		["mobile"] = {
			type = "tes3mobileActor",
			readOnly = true,
			description = "The mobile actor whose body parts were updated.",
		},
		["reference"] = {
			type = "tes3reference",
			readOnly = true,
			description = "The reference for the actor whose body parts were updated.",
		},
	},
	examples = {
		["ripLefties"] = {
			title = "In this example all the scene graph nodes that make up left arm are culled. That will effectively make all the left arms in the game disappear.",
		}
	}
}
