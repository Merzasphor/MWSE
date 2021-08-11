# infoResponse

This event fires when a dialogue response is triggered.

```lua
--- @param e infoResponseEventData
local function infoResponseCallback(e)
end
event.register("infoResponse", infoResponseCallback)
```

## Event Data

* `command` (string): The command.
* `info` ([tes3dialogueInfo](../../types/tes3dialogueInfo)): The dialogue info object.
* `dialogue` ([tes3dialogue](../../types/tes3dialogue)): The dialogue object.
* `reference` ([tes3reference](../../types/tes3reference)): The reference.
* `variables` (tes3scriptVariables): The script variables.

