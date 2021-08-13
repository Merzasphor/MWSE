--- @meta

--- This event is invoked after a UI menu has been built or made visible, at the point that all menu elements contain updated data.
--- @class uiActivatedEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field element tes3uiElement The menu element that was created. The event is filtered on element.name.
--- @field newlyCreated boolean true if the menu was created for the first time or destroyed and re-created; false if it was made visible after being hidden. This can be used when adding custom elements to a menu, as elements previously added will still exist if the menu was hidden. If the menu was re-created, the elements will need to be added again.
