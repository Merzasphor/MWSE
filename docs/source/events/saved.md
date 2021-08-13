# saved

The saved event fires after the game has successfully been saved. This event is preceded by the save event.

```lua
--- @param e savedEventData
local function savedCallback(e)
end
event.register("saved", savedCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `filename` (string): The filename of the save, not including file extension.
* `name` (string): The user facing name of the save, shown in the load/save game menu.

