return {
    description = "This event triggers when a derived statistic of the mobile is updated. This includes any attribute, any skill (or creature skill, if mobile is a creature), health, magicka, fatigue, and magickaMultiplier.",
    eventData = {
        ["mobile"] = {
            type = "tes3mobileActor",
            readonly = true,
            description = "The mobile actor whose derived statistics are being updated.",
        },
        ["reference"] = {
            type = "",
            readonly = true,
            description = "Mobile’s associated reference.",
        },
        ["statistic"] = {
            type = "tes3statistic",
            readonly = true,
            description = "The statistic being updated.",
        },
        ["name"] = {
            type = "string",
            readonly = true,
            description = "The name of the statistic.",
        },
    },
    filter = "name",
    examples = {
		["overEncumberedNotification"] = {
			title = "Notify the player that they can't carry more stuff"
		},
	},
}