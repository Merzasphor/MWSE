return {
	description = "The projectileHitObject event fires when a projectile collides with an object.",
	eventData = {
		["mobile"] = {
			type = "tes3mobileProjectile",
			readonly = true,
			description = "The mobile projectile that is expiring.",
		},
		["target"] = {
			type = "tes3reference",
			readonly = true,
			description = "Reference to the object that was hit.",
		},
		["collisionPoint"] = {
			type = "tes3vector3",
			readonly = true,
			description = "The collision point of the mobile projectile.",
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