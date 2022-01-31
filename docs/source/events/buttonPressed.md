# buttonPressed

The buttonPressed event is unique in that it is invoked only when using `tes3.messageBox` to present buttons to the player.

```lua
--- @param e buttonPressedEventData
local function buttonPressedCallback(e)
end
event.register(tes3.event.buttonPressed, buttonPressedCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `button` (number): *Read-only*. The button index, 0-based, that was pressed.

