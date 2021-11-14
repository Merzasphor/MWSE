return {
	type = "event",
	description = "The damaged event triggers after an actor has been damaged.",
	related = { "damage", "damaged", "damageHandToHand", "damagedHandToHand" },
	eventData = {
		damage = {
			type = "number",
			readOnly = true,
			description = "The amount of damage done.",
		},
		mobile = {
			type = "tes3mobileActor",
			readOnly = true,
			description = "The mobile actor that took damage.",
		},
		reference = {
			type = "tes3reference",
			readOnly = true,
			description = "The mobile’s associated reference.",
		},
        attacker = {
			type = "tes3mobileActor",
			readOnly = true,
			description = "The mobile actor dealing the damage. Can be nil.",
		},
		attackerReference = {
			type = "tes3reference",
			readOnly = true,
			description = "The attacker mobile's associated reference. Can be nil.",
		},
		projectile = {
			type = "tes3mobileProjectile",
			readOnly = true,
			description = "Projectile that dealt the damage. Can be nil.",
		},
		activeMagicEffect = {
			type = "tes3magicEffect",
			readOnly = true,
			description = "tes3magicEffect which caused damage. Can be nil.",
		},
		magicSourceInstance = {
			type = "tes3magicSourceInstance",
			readonly = true ,
			description = "tes3magicSourceInstance of a spell that caused damage. Can be nil.",
		},
		source = {
			type ="tes3.damageSource constants",
			readOnly = true,
			description = "The origin of damage. Values of this variable can be: \"script\", \"fall\", \"suffocation\", \"attack\", \"magic\", \"shield\" or nil. These damage sources are present as tes3.damageSource.* constants, and those should be used instead. See the example. Damage with \"shield\" source comes from magic shields. Other sources are self-explanatory.",
		},
		killingBlow = {
			type ="boolean",
			readOnly = true,
			description = "If true, the damage killed the target.",
		},
	},
	examples = {
		["killingBlow"] = {
			title = "Notify the player that their arrow/bolt killed their opponent"
		},
		["suffocation"] = {
			title = "Detect that the player died from drowning"
		}
	},
}
