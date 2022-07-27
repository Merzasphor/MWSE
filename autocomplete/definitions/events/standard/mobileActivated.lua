return {
	type = "event",
	description = "This event is called when a mobile object is activated. This includes NPCs, creatures and projectiles, but not the player. This may be the first time that a given reference has an associated mobile object attached to it. Typically this happens when a projectile gets fired, a creature gets summoned or when the player transitions from one cell to another, causing actors in newly loaded cells to get activated.",
	related = { "mobileActivated", "mobileDeactivated" },
	eventData = {
		["reference"] = {
			type = "tes3reference",
			readOnly = true,
			description = "The reference that the mobile object has been activated for.",
		},
		["mobile"] = {
			type = "tes3mobileObject",
			readOnly = true,
			description = "The activated mobile object.",
		},
	},
}