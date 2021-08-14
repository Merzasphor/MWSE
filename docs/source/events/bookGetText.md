# bookGetText

This event is raised when a book's text is about to be displayed. By providing your own text, you can overwrite what is going to be displayed.

```lua
--- @param e bookGetTextEventData
local function bookGetTextCallback(e)
end
event.register("bookGetText", bookGetTextCallback)
```

!!! tip
	This event can be filtered based on the **`book`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `book` ([tes3book](../../types/tes3book)): *Read-only*. The book whose text is being retrieved.
* `text` (string): If set, the book's text will be overwritten with this value.

