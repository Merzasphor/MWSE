# bookGetText

This event is raised when a book's text is about to be displayed. By providing your own text, you can overwrite what is going to be displayed.

```lua
--- @param e bookGetTextEventData
local function bookGetTextCallback(e)
end
event.register("bookGetText", bookGetTextCallback)
```

This event can be filtered based on the **`book`** event data.

## Event Data

* `book` ([tes3book](../../types/tes3book)): The book whose text is being retrieved.
* `text` (string): If set, the book's text will be overwritten with this value.

