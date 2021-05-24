return{
    description = "",
    eventData = {
        ["item"] = {
            type = "tes3baseObject",
            --readonly = true,
            description = "",
        },
        ["state"] = {
            type = "number",
            --readonly = true,
            description = "",
        },
        ["reference"] = {
            type = "tes3reference",
            --readonly = true,
            description = "",
        },
    },
    filter = { "item", "state", "reference" }, -- Is this line ok?
}
