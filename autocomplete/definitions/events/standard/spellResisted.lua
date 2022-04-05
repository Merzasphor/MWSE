return {
	type = "event",
	description = "This event triggers when a magic effect has been resisted by an actor, including magic effects from sources like spells, enchantments and potions. This event can trigger multiple times per source, once for each resisted effect.",
	eventData = {
		["mobile"] = {
			type = "tes3mobileActor",
			readOnly = true,
			description = "The mobile actor that resisted the magic effect.",
		},
		["reference"] = {
			type = "tes3reference",
			readOnly = true,
			description = "The reference of the mobile actor that resisted the magic effect.",
		},
		["caster"] = {
			type = "tes3reference",
			readOnly = true,
			description = "The caster of the magic source that contained the magic effect. Can be `nil`.",
		},
		["target"] = {
			type = "tes3reference",
			readOnly = true,
			description = "The target of the magic source that contained the magic effect. Can be `nil`.",
		},
		["source"] = {
			type = "tes3alchemy|tes3enchantment|tes3spell",
			readOnly = true,
			description = "The magic source that contains the effect.",
		},
		["sourceInstance"] = {
			type = "tes3magicSourceInstance",
			readOnly = true,
			description = "The unique instance of the magic source that contains the effect.",
		},
		["effect"] = {
			type = "tes3effect",
			readOnly = true,
			description = "The specific effect that triggered the event. This is equal to `e.source.effects[e.effectIndex]`.",
		},
		["effectIndex"] = {
			type = "number",
			readOnly = true,
			description = "The index of the effect in the magic source's effects list.",
		},
	},
	filter = "reference",
	examples = {
		["learnResistedSpells"] = {
			title = "Learn resisted spells",
			description = "Makes actors learn the spell they resisted.",
		}
	}
}