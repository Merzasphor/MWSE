return{
    description = "This event is triggered when player presses Offer button in Bartering menu.",
    eventData = {
        ["mobile"] = {
            type = "tes3mobileActor",
            readonly = true,
            description = "",
        },
        ["success"] = {
            type = "boolean",
            description = "True if bartering is successful. e.sucess = false, will make player fail the bartering event.",
        },
        ["value"] = {
            type = "number",
            readonly = true,
            description = "Total value in gold of items being traded.",
        },
        ["offer"] = {
            type = "number",
            readonly = true,
            description = "Offered gold amount.",
        },
        ["selling"] = {
            type = "table",
            readonly = true,
            description = "Table of tes3what being sold. These items will be transfered to bartender's inventory on a successful bartering event.",
        },
        ["buying"] = {
            type = "table",
            readonly = true,
            description = "Table of tes3what being sold These items will be transfered to player's inventory on a successful bartering event.",
        },
    },
}
