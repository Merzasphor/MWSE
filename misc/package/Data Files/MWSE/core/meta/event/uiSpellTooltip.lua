--- @meta

--- The uiSpellTooltip event triggers when a new tooltip is displayed for a spell. The tooltip will be already be built.
--- @class uiSpellTooltipEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field spell tes3spell *Read-only*. The spell being examined.
--- @field tooltip tes3uiElement *Read-only*. The newly created tooltip element. Due to timeouts and target changes, it may be destroyed at any time.
