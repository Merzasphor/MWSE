# infoResponse

This event fires when a dialogue response is triggered.

```lua
--- @param e infoResponseEventData
local function infoResponseCallback(e)
end
event.register("infoResponse", infoResponseCallback)
```

!!! tip
	This event supports blocking by setting `e.block` to `true` or returning `false`. Blocking the event prevents vanilla behavior from happening. For example, blocking an `equip` event prevents the item from being equipped.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `command` (string): The command.
* `info` ([tes3dialogueInfo](../../types/tes3dialogueInfo)): The dialogue info object.
* `dialogue` ([tes3dialogue](../../types/tes3dialogue)): The dialogue object.
* `reference` ([tes3reference](../../types/tes3reference)): The reference.
* `variables` (tes3scriptVariables): The script variables.

