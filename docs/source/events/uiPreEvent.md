# uiPreEvent

uiPreEvent is triggered through various UI events. This includes scrolling through panes, clicking buttons, selecting icons, or a host of other UI-related activities. This event fires before uiEvent, and has the additional advantage of being able to be blocked.

```lua
--- @type e event.uiPreEvent
local function uiPreEventCallback(e)
end
event.register("uiPreEvent", uiPreEventCallback)
```

## Event Data

* `property` (number): The property identifier that is being triggered.
* `block` ([tes3uiElement](../../types/tes3uiElement)): The UI element that is firing this event.
* `var2` (number): One of two undefined variables related to the event.
* `parent` ([tes3uiElement](../../types/tes3uiElement)): The calling element's parent.
* `var1` (number): One of two undefined variables related to the event.

