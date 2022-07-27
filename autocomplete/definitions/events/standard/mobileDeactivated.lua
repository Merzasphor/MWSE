return {
	type = "event",
	description = "This event is called when a mobile object is deactivated. This includes NPCs, creatures and projectiles, but not the player. Typically this happens when an actor dies, a creature gets unsummoned, a projectile collides with something or expires or when the player transitions from one cell to another, causing actors in previously visited cells to get deactivated.",
	related = { "mobileActivated", "mobileDeactivated" },
	eventData = {
		["reference"] = {
			type = "tes3reference",
			readOnly = true,
			description = "The reference that the mobile object has been deactivated for.",
		},
		["mobile"] = {
			type = "tes3mobileObject",
			readOnly = true,
			description = "The deactivated mobile object.",
		},
	},
}