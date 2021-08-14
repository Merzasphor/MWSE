--- @meta

--- This event fires when an inventory filter has been selected for an item.
--- @class filterInventorySelectEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field item tes3alchemy|tes3apparatus|tes3armor|tes3book|tes3clothing|tes3ingredient|tes3light|tes3lockpick|tes3misc|tes3probe|tes3repairTool|tes3weapon *Read-only*. The item being filtered.
--- @field itemData tes3itemData *Read-only*. The item data for the item being filtered.
--- @field type string *Read-only*. The inventory filter type.
