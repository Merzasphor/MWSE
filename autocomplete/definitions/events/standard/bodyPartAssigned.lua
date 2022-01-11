return {
	type = "event",
	description = "Allows reading and overwriting body part assignments.",
	related = { "bodyPartAssigned", "bodyPartsUpdated" },
	eventData = {
		["manager"] = {
			type = "tes3bodyPartManager",
			readOnly = true,
			description = "The access to the body part manager that is associated with the reference that had a body part assigned.",
		},
		["reference"] = {
			type = "tes3reference",
			readOnly = true,
			description = "The reference for the actor whose body part was assigned.",
		},
		["object"] = {
			type = "tes3physicalObject",
			readOnly = true,
			description = "Access to the physical object for the assigned body part.",
		},
		["index"] = {
			type = "number",
			readOnly = true,
			description = "The body slot index of the newly assigned body part. Maps to values in [`tes3.activeBodyPart`](https://mwse.github.io/MWSE/references/active-body-parts/) constants.",
		},
		["bodyPart"] = {
			type = "tes3bodyPart",
			description = "The body part object assigned.",
		},
		["isFirstPerson"] = {
			type = "boolean",
			readOnly = true,
			description = "A flag that controls whether the newly assigned body part is used while the camera is in the first person.",
		},
	},
	blockable = true,
}
