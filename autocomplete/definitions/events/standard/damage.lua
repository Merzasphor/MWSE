return {
	type = "event",
	description = "The damage event triggers before an actor is damaged. The damage value can be modified, or the damage can be prevented completely by blocking the event.",
	related = { "damage", "damaged", "damageHandToHand", "damagedHandToHand" },
	eventData = {
		damage = {
			type = "number",
			description = "The amount of damage done.",
		},
		mobile = {
			type = "tes3mobileActor",
			readOnly = true,
			description = "The mobile actor that is taking damage.",
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
	},
	blockable = true,
	examples = {
		["changeFallDamage"] = {
			title = "Change fall damage"
		},
	},
}
