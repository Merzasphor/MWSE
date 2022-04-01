--- @meta
--- @diagnostic disable:undefined-doc-name

--- This event is called when the active magic effect icons in the magic menu and the HUD have been updated. Each update fully destroys the previously created active magic effect icons and recreates them.
--- @class activeMagicEffectIconsUpdatedEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
