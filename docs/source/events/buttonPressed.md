# buttonPressed

The buttonPressed event is unique in that it is invoked only when using tes3.messageBox to present buttons to the player.

```lua
--- @type e event.buttonPressed
local function buttonPressedCallback(e)
end
event.register("buttonPressed", buttonPressedCallback)
```

## Event Data

* `button` (number): The button index, 0-based, that was pressed.

