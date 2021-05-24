return{
    description = "",
    eventData = {
        ["sound"] = {
            type = "tes3sound",
            --readonly = true,
            description = "",
        },
        ["flags"] = {
            type = "number",
            --readonly = true,
            description = "",
        },
        ["volume"] = {
            type = "number",
            --readonly = true,
            description = "",
        },
        ["pitch"] = {
            type = "number",
            --readonly = true,
            description = "",
        },
        ["isNot3D"] = {
            type = "boolean",
            --readonly = true,
            description = "",
        },
    },
    filter = { "sound", "flags", "volume", "pitch", "isNot3D" }, -- Is this line ok?,
}
