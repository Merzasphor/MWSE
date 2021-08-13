# trapDisarm

This event fires when a trap is being disarmed.

```lua
--- @param e trapDisarmEventData
local function trapDisarmCallback(e)
end
event.register("trapDisarm", trapDisarmCallback)
```

!!! tip
	This event supports blocking by setting `e.block` to `true` or returning `false`. Blocking the event prevents vanilla behavior from happening. For example, blocking an `equip` event prevents the item from being equipped.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `chance` (number): The chance the trap disarm will be successful.
* `disarmer` (tes3mobileNpc): The Mobile NPC doing the disarming.
* `lockData` (tes3lockAttachmentNode): The lock data of the reference.
* `reference` ([tes3reference](../../types/tes3reference)): The reference that triggered the event (container, door, etc.).
* `tool` ([tes3item](../../types/tes3item)): The item the disarmer is using to disarm the trap.
* `toolItemData` ([tes3itemData](../../types/tes3itemData)): The item data for the tool.
* `trapPresent` (boolean): Indicates if a trap is present on the reference.

