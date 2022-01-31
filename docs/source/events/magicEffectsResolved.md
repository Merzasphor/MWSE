# magicEffectsResolved

This event triggers after all magic effect links have been resolved. This event is used to add new spell effect by using [`tes3.addSpellEffect()`](https://mwse.github.io/MWSE/apis/tes3/#tes3addmagiceffect) function. For examples of this event in practice see [`tes3.addMagicEffect()`](https://mwse.github.io/MWSE/apis/tes3/#tes3addmagiceffect) example.

```lua
--- @param e magicEffectsResolvedEventData
local function magicEffectsResolvedCallback(e)
end
event.register(tes3.event.magicEffectsResolved, magicEffectsResolvedCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

