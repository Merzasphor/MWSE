# postInfoResponse

This event fires immediately after a dialogue response is processed.

```lua
--- @param e postInfoResponseEventData
local function postInfoResponseCallback(e)
end
event.register("postInfoResponse", postInfoResponseCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `command` (string): The command.
* `info` ([tes3dialogueInfo](../../types/tes3dialogueInfo)): The dialogue info object.
* `dialogue` ([tes3dialogue](../../types/tes3dialogue)): The dialogue object.
* `reference` ([tes3reference](../../types/tes3reference)): The reference.
* `variables` (tes3scriptVariables): The script variables.

