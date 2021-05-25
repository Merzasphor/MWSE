return{
    description = "",
    eventData = {
        ["power"] = {
            type = "tes3spell",
            readonly = true,
            description = "",
        },
        ["mobile"] = {
            type = "tes3mobileActor",
            readonly = true,
            description = "",
        },
        ["reference"] = {
            type = "tes3reference",
            readonly = true,
            description = "Mobile’s associated reference.",
        },
    },
    filter = { "power", "mobile" }, -- Is this line ok?
}
