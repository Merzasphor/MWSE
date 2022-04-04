return {
	type = "event",
	description = "This event triggers when a magic effect has been removed from an actor. This includes magic effects that have been resisted.",
	eventData = {
		["mobile"] = {
			type = "tes3mobileActor",
			readOnly = true,
			description = "The mobile actor the magic effect is removed from.",
		},
		["reference"] = {
			type = "tes3reference",
			readOnly = true,
			description = "The reference of the mobile actor the magic effect is removed from.",
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
			description = "The specific magic effect that triggered the event. This is equal to `e.source.effects[effectIndex]`. Can be `nil`.",
		},
		["effectIndex"] = {
			type = "number",
			readOnly = true,
			description = "The index of the magic effect in the magic source's effects list.",
		},
	},
	filter = "reference"
}