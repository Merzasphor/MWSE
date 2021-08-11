# uiSpellTooltip

The uiSpellTooltip event triggers when a new tooltip is displayed for a spell. The tooltip will be already be built.

```lua
--- @param e uiSpellTooltipEventData
local function uiSpellTooltipCallback(e)
end
event.register("uiSpellTooltip", uiSpellTooltipCallback)
```

## Event Data

* `tooltip` ([tes3uiElement](../../types/tes3uiElement)): The newly created tooltip element. Due to timeouts and target changes, it may be destroyed at any time.
* `spell` ([tes3spell](../../types/tes3spell)): The spell being examined.

