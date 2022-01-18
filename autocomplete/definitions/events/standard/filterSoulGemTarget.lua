return {
	type = "event",
	description = "This event fires when a soul gem target is filtered",
	eventData = {
		["soulGem"] = {
			type = "tes3misc",
			readOnly = true,
			description = "The soul gem object.",
		},
		["mobile"] = {
			type = "tes3mobileActor",
			readOnly = true,
			description = "The mobile actor whose soul is to be soultrapped.",
		},
		["reference"] = {
			type = "tes3reference",
			readOnly = true,
			description = "The reference.",
		},
		["filter"] = {
			type = "boolean",
			description = "Setting this to `false` or `nil` will prevent the `mobile`'s soul to end up in the `soulGem`. Setting this to `true` will make the opposite."
		}
	},
	examples = {
		["example"] = {
			title = "Example"
		},
	},
}