--- @meta

--- This event fires when a trap is being disarmed.
--- @class trapDisarmEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field toolItemData tes3itemData The item data for the tool.
--- @field chance number The chance the trap disarm will be successful.
--- @field tool tes3alchemy|tes3apparatus|tes3armor|tes3book|tes3clothing|tes3ingredient|tes3light|tes3lockpick|tes3misc|tes3probe|tes3repairTool|tes3weapon The item the disarmer is using to disarm the trap.
--- @field reference tes3reference The reference that triggered the event (container, door, etc.).
--- @field disarmer tes3mobileNpc The Mobile NPC doing the disarming.
--- @field trapPresent boolean Indicates if a trap is present on the reference.
--- @field lockData tes3lockAttachmentNode The lock data of the reference.
trapDisarm = {}

