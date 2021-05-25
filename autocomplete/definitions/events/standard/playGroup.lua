return{
    description = "",
    eventData = {
        ["animationData"] = {
            type = "tes3animationData",
            --readonly = true,
            description = "",
        },
        ["reference"] = {
            type = "tes3reference",
            --readonly = true,
            description = "",
        },
        ["group"] = {
            type = "number",
            --readonly = true,
            description = "",
        },
        ["index"] = {
            type = "number",
            --readonly = true,
            description = "",
        },
        ["flags"] = {
            type = "number",
            --readonly = true,
            description = "",
        },
        ["loopCount"] = {
            type = "number",
            --readonly = true,
            description = "",
        },
    },
    filter = { "animationData", "group", "index", "flags", "loopCount" }, -- Is this ok?
}
