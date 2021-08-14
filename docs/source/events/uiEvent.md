# uiEvent

uiEvent is triggered through various UI events. This includes scrolling through panes, clicking buttons, selecting icons, or a host of other UI-related activities.

```lua
--- @param e uiEventEventData
local function uiEventCallback(e)
end
event.register("uiEvent", uiEventCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `block` ([tes3uiElement](../../types/tes3uiElement)): *Read-only*. The UI element that is firing this event.
* `parent` ([tes3uiElement](../../types/tes3uiElement)): *Read-only*. The calling element's parent.
* `property` (number): *Read-only*. The property identifier that is being triggered.
* `var1` (number): *Read-only*. One of two undefined variables related to the event.
* `var2` (number): *Read-only*. One of two undefined variables related to the event.

