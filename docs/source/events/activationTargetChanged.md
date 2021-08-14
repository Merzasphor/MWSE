# activationTargetChanged

This event is raised when the potential activation target for the player changes.

```lua
--- @param e activationTargetChangedEventData
local function activationTargetChangedCallback(e)
end
event.register("activationTargetChanged", activationTargetChangedCallback)
```

!!! tip
	This event can be filtered based on the **`current`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `current` ([tes3reference](../../types/tes3reference)): *Read-only*. The activation target for the player, should they press the activation key.
* `previous` ([tes3reference](../../types/tes3reference)): *Read-only*. The previous activation target.

