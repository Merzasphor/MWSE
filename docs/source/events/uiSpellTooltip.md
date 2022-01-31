# uiSpellTooltip

The uiSpellTooltip event triggers when a new tooltip is displayed for a spell. The tooltip will be already be built.

```lua
--- @param e uiSpellTooltipEventData
local function uiSpellTooltipCallback(e)
end
event.register(tes3.event.uiSpellTooltip, uiSpellTooltipCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `spell` ([tes3spell](../../types/tes3spell)): *Read-only*. The spell being examined.
* `tooltip` ([tes3uiElement](../../types/tes3uiElement)): *Read-only*. The newly created tooltip element. Due to timeouts and target changes, it may be destroyed at any time.

