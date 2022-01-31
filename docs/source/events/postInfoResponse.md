# postInfoResponse

This event fires immediately after a dialogue response is processed.

```lua
--- @param e postInfoResponseEventData
local function postInfoResponseCallback(e)
end
event.register(tes3.event.postInfoResponse, postInfoResponseCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `command` (string): *Read-only*. The command.
* `dialogue` ([tes3dialogue](../../types/tes3dialogue)): *Read-only*. The dialogue object.
* `info` ([tes3dialogueInfo](../../types/tes3dialogueInfo)): *Read-only*. The dialogue info object.
* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. The reference.
* `variables` (tes3scriptVariables): *Read-only*. The script variables.

