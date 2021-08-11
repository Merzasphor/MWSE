--- @meta

--- This event fires when an item in the contents menu is filtered.
--- @class filterContentsMenuEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field tile tes3uiInventoryTile The inventory tile being filtered.
--- @field item tes3alchemy|tes3apparatus|tes3armor|tes3book|tes3clothing|tes3ingredient|tes3light|tes3lockpick|tes3misc|tes3probe|tes3repairTool|tes3weapon The item being filtered.
--- @field itemData tes3itemData The item data for the item being filtered.
filterContentsMenu = {}

