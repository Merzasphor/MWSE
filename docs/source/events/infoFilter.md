# infoFilter

This event fires when a dialogue info object is filtered.

```lua
--- @type e event.infoFilter
local function infoFilterCallback(e)
end
event.register("infoFilter", infoFilterCallback)
```

## Event Data

* `source` (number): The source.
* `dialogue` ([tes3dialogue](../../types/tes3dialogue)): The dialogue object.
* `reference` ([tes3reference](../../types/tes3reference)): The reference.
* `info` ([tes3dialogueInfo](../../types/tes3dialogueInfo)): The dialogue info object.
* `passes` (boolean): Indicates if the filter passes.
* `actor` ([tes3object](../../types/tes3object)): The actor.

