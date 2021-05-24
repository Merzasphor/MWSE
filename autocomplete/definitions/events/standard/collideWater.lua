return{
    description = "This event is triggered when a mobile object collides with water.",
    eventData = {
        ["mobile"] = {
            type = "tes3mobileObject",
            readonly = true,
            description = "Mobile object which collided.",
        },
        ["inWater"] = {
            type = "boolean",
            readonly = true,
            description = "",
        },
    },
    filter = { "mobile", "inWater" },
}
