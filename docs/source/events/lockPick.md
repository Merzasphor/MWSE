# lockPick

This event fires when a lock is being picked.

```lua
--- @type e event.lockPick
local function lockPickCallback(e)
end
event.register("lockPick", lockPickCallback)
```

## Event Data

* `picker` (tes3mobileNpc): The Mobile NPC doing the disarming.
* `chance` (number): The chance the lockpick will be successful.
* `tool` ([tes3item](../../types/tes3item)): The item the picker is using to pick the lock.
* `reference` ([tes3reference](../../types/tes3reference)): The reference that triggered the event (container, door, etc.).
* `lockPresent` (boolean): Indicates if a lock is present on the reference.
* `toolItemData` ([tes3itemData](../../types/tes3itemData)): The item data for the tool.
* `lockData` (tes3lockAttachmentNode): The lock data of the reference.

