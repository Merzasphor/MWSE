return {
	description = "The spellTick event happens every frame that an effect is active on a target. This can be used to aid in scripted spells, cancel active spells, or otherwise monitor spell activity on actors.",
	eventData = {
		["caster"] = {
			type = "tes3reference",
			readonly = true,
			description = "The caster of the spell.",
		},
		["deltaTime"] = {
			type = "number",
			readonly = true,
			description = "The number of seconds since the last spell tick.",
		},
		["effect"] = {
			type = "tes3magicEffect",
			readonly = true,
			description = "The individual effect structure on source.",
		},
		["effectId"] = {
			type = "number",
			readonly = true,
			description = "The magic effect ID that is being ticked.",
		},
		["effectIndex"] = {
			type = "number",
			readonly = true,
			description = "The index of the effect in source’s effects list.",
		},
		["effectInstance"] = {
			type = "tes3magicEffectInstance",
			readonly = true,
			description = "The unique instance of the magic effect.",
		},
		["source"] = {
			type = "tes3alchemy|tes3enchantment|tes3spell",
			readonly = true,
			description = "The magic source.",
		},
		["sourceInstance"] = {
			type = "tes3magicSourceInstance",
			readonly = true,
			description = "The unique instance of the magic source.",
		},
		["target"] = {
			type = "tes3reference",
			readonly = true,
			description = "The target of the spell. For self-targeted spells, this matches caster.",
		},
	},
	filter = "source",
}