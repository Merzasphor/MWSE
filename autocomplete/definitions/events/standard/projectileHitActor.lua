return {
	description = "The projectileHitActor event fires when a projectile collides with an actor.",
	eventData = {
		["mobile"] = {
			type = "tes3mobileProjectile",
			readonly = true,
			description = "The mobile projectile that is expiring.",
		},
		["target"] = {
			type = "tes3reference",
			readonly = true,
			description = "Reference to the actor that was hit.",
		},
		["firingReference"] = {
			type = "tes3reference",
			readonly = true,
			description = "Reference to the actor that fired the projectile.",
		},
		["firingWeapon"] = {
			type = "tes3weapon",
			readonly = true,
			description = "The weapon that fired the projectile.",
		},
	},
}