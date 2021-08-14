--- @meta

--- This event fires when a dialogue response is triggered.
--- @class itemTileUpdatedEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field element tes3uiElement *Read-only*. The command.
--- @field item tes3alchemy|tes3apparatus|tes3armor|tes3book|tes3clothing|tes3ingredient|tes3light|tes3lockpick|tes3misc|tes3probe|tes3repairTool|tes3weapon *Read-only*. The reference.
--- @field itemData tesitemData *Read-only*. The script variables.
--- @field menu tes3uiElement *Read-only*. The dialogue object.
--- @field tile tes3inventoryTile *Read-only*. The dialogue info object.
