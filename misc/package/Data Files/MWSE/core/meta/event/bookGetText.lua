--- @meta

--- This event is raised when a book's text is about to be displayed. By providing your own text, you can overwrite what is going to be displayed.
--- @class bookGetTextEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field book tes3book *Read-only*. The book whose text is being retrieved.
--- @field text string If set, the book's text will be overwritten with this value.
