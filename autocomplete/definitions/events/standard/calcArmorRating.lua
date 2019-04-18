return {
	brief = "This event is raised when a book's text is about to be displayed. By providing your own text, you can overwrite what is going to be displayed.",
	eventData = {
		armor = {
			type = "tes3armor",
			readonly = true,
			description = "The armor piece whose AR is being calculated.",
		},
		mobile = {
			type = "tes3mobileActor",
			readonly = true,
			description = "The mobile whose AR is being calculated. May not always be available.",
		},
		reference = {
			type = "tes3reference",
			readonly = true,
			description = "A shortcut to the mobile's reference. May not always be available.",
		},
		npc = {
			type = "tes3npc",
			readonly = true,
			description = "The NPC object whose AR is being calculated. May not always be available.",
		},
	},
	filter = "armor",
}