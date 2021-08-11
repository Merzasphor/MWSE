# uiEvent

uiEvent is triggered through various UI events. This includes scrolling through panes, clicking buttons, selecting icons, or a host of other UI-related activities.

```lua
--- @param e uiEventEventData
local function uiEventCallback(e)
end
event.register("uiEvent", uiEventCallback)
```

## Event Data

* `property` (number): The property identifier that is being triggered.
* `block` ([tes3uiElement](../../types/tes3uiElement)): The UI element that is firing this event.
* `var2` (number): One of two undefined variables related to the event.
* `parent` ([tes3uiElement](../../types/tes3uiElement)): The calling element's parent.
* `var1` (number): One of two undefined variables related to the event.

