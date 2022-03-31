# activeMagicEffectIconsUpdated

This event is called when the active magic effect icons in the magic menu and the HUD have been updated. Each update fully destroys the previously created active magic effect icons and recreates them.

```lua
--- @param e activeMagicEffectIconsUpdatedEventData
local function activeMagicEffectIconsUpdatedCallback(e)
end
event.register(tes3.event.activeMagicEffectIconsUpdated, activeMagicEffectIconsUpdatedCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

