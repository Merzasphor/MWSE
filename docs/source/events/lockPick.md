# lockPick

This event fires when a lock is being picked.

```lua
--- @param e lockPickEventData
local function lockPickCallback(e)
end
event.register("lockPick", lockPickCallback)
```

!!! tip
	This event supports blocking by setting `e.block` to `true` or returning `false`. Blocking the event prevents vanilla behavior from happening. For example, blocking an `equip` event prevents the item from being equipped.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `picker` (tes3mobileNpc): The Mobile NPC doing the disarming.
* `chance` (number): The chance the lockpick will be successful.
* `tool` ([tes3item](../../types/tes3item)): The item the picker is using to pick the lock.
* `reference` ([tes3reference](../../types/tes3reference)): The reference that triggered the event (container, door, etc.).
* `lockPresent` (boolean): Indicates if a lock is present on the reference.
* `toolItemData` ([tes3itemData](../../types/tes3itemData)): The item data for the tool.
* `lockData` (tes3lockAttachmentNode): The lock data of the reference.

