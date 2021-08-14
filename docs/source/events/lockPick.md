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

* `chance` (number): *Read-only*. The chance the lockpick will be successful.
* `lockData` (tes3lockAttachmentNode): *Read-only*. The lock data of the reference.
* `lockPresent` (boolean): *Read-only*. Indicates if a lock is present on the reference.
* `picker` (tes3mobileNpc): *Read-only*. The Mobile NPC doing the disarming.
* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. The reference that triggered the event (container, door, etc.).
* `tool` ([tes3item](../../types/tes3item)): *Read-only*. The item the picker is using to pick the lock.
* `toolItemData` ([tes3itemData](../../types/tes3itemData)): *Read-only*. The item data for the tool.

