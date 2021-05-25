return{
    description = "This event can be used to prevent player from resting by returning false.",
    eventData = {
        ["mobile"] = {
            type = "tes3mobileActor",
            readonly = true,
            description = "Mobile actor which is preventing the player from resting", -- chech this
        },
        ["reference"] = {
            type = "tes3reference",
            readonly = true,
            description = "Mobile’s associated reference.",
        },
    },
    filter = "mobile",
}
