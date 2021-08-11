# trapDisarm

This event fires when a trap is being disarmed.

```lua
--- @param e trapDisarmEventData
local function trapDisarmCallback(e)
end
event.register("trapDisarm", trapDisarmCallback)
```

## Event Data

* `toolItemData` ([tes3itemData](../../types/tes3itemData)): The item data for the tool.
* `chance` (number): The chance the trap disarm will be successful.
* `tool` ([tes3item](../../types/tes3item)): The item the disarmer is using to disarm the trap.
* `reference` ([tes3reference](../../types/tes3reference)): The reference that triggered the event (container, door, etc.).
* `disarmer` (tes3mobileNpc): The Mobile NPC doing the disarming.
* `trapPresent` (boolean): Indicates if a trap is present on the reference.
* `lockData` (tes3lockAttachmentNode): The lock data of the reference.

