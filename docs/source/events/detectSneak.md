# detectSneak

This event is invoked whenever an actor is checking if they can detect another actor sneaking.

```lua
--- @param e detectSneakEventData
local function detectSneakCallback(e)
end
event.register(tes3.event.detectSneak, detectSneakCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `detector` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile actor that is doing the detecting.
* `isDetected` (boolean): The previous detection calculated, starting with the base engine result.
* `target` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile actor that is possibly being detected.

