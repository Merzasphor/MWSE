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
			description = "The mobile actor dealing the damage. Can be `nil`.",
		},
		attackerReference = {
			type = "tes3reference",
			readOnly = true,
			description = "The attacker mobile's associated reference. Can be `nil`.",
		},
		projectile = {
			type = "tes3mobileProjectile",
			readOnly = true,
			description = "Projectile that will deal the damage. Can be `nil`.",
		},
		activeMagicEffect = {
			type = "tes3magicEffect",
			readOnly = true,
			description = "Magic effect which will cause the damage. Can be `nil`.",
		},
		magicSourceInstance = {
			type = "tes3magicSourceInstance",
			readonly = true ,
			description = "A `tes3magicSourceInstance` object of a spell that will cause the damage. Can be `nil`.",
		},
		magicEffectInstance = {
			type = "tes3magicEffectInstance",
			readonly = true ,
			description = "An instance of the magic effect in the spell that will cause the damage. Can be `nil`.",
		},
		source = {
			type ="string",
			readOnly = true,
			description = "The origin of damage. These damage sources are present as [`tes3.damageSource`](https://mwse.github.io/MWSE/references/damage-sources/) constants. See the example. Damage with `tes3.damageSource.shield` source comes from magic shields. Other sources are self-explanatory.",
		},
	},
	blockable = true,
	examples = {
		["changeFallDamage"] = {
			title = "Change fall damage"
		},
	},
}
