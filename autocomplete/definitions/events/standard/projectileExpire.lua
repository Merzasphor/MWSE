return {
	description = "The projectileExpire event fires just prior to a fired projectile expiring.",
	eventData = {
		["mobile"] = {
			type = "tes3mobileProjectile",
			readonly = true,
			description = "The mobile projectile that is expiring.",
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