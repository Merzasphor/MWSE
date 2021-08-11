--- @meta

--- This event fires when a dialogue response is triggered.
--- @class itemTileUpdatedEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field tile tes3uiInventoryTile The dialogue info object.
--- @field menu tesuiElement The dialogue object.
--- @field item tes3alchemy|tes3apparatus|tes3armor|tes3book|tes3clothing|tes3ingredient|tes3light|tes3lockpick|tes3misc|tes3probe|tes3repairTool|tes3weapon The reference.
--- @field element tesuiElement The command.
--- @field itemData tesitemData The script variables.
itemTileUpdated = {}

