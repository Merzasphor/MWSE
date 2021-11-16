return{
	type = "event",
    description = "This event is triggered when a new spell is created using spellmaking services or by a script using tes3spell.create().",
    eventData = {
        ["spell"] = {
            type = "tes3spell",
            description = "A spell which was created.",
        },
        ["source"] = {
            type = "",
            description = "This can be \"script\" or \"service\".",
        },
    },
    filter = "source",
}
