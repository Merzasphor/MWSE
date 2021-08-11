--- @meta

--- The uiSpellTooltip event triggers when a new tooltip is displayed for a spell. The tooltip will be already be built.
--- @class uiSpellTooltipEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field tooltip tes3uiElement The newly created tooltip element. Due to timeouts and target changes, it may be destroyed at any time.
--- @field spell tes3spell The spell being examined.
