return{
    description = "This event is called when a potentially successful barter offer is made by the player. Potentially successful means both parties have the required funds to make the trade.",
    eventData = {
        ["mobile"] = {
            type = "tes3mobileActor",
            readonly = true,
            description = "The mobile actor of the merchant the player is interacting with.",
        },
        ["success"] = {
            type = "boolean",
            --readonly = true,
            description = "Whether the trade was accepted or not.",
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
            description = "Table of tes3what being bought. These items will be transfered to player's inventory on a successful bartering event.",
        },
    },
}
