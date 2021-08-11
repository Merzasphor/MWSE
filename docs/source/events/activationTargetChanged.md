# activationTargetChanged

This event is raised when the potential activation target for the player changes.

```lua
--- @type e event.activationTargetChanged
local function activationTargetChangedCallback(e)
end
event.register("activationTargetChanged", activationTargetChangedCallback)
```

This event can be filtered based on the **`current`** event data.

## Event Data

* `previous` ([tes3reference](../../types/tes3reference)): The previous activation target.
* `current` ([tes3reference](../../types/tes3reference)): The activation target for the player, should they press the activation key.

