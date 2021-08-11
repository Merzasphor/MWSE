# skillRaised

This event is invoked whenever the player naturally gains a new level a skill. This is typically through exercise, training, or reading books.

```lua
--- @type e event.skillRaised
local function skillRaisedCallback(e)
end
event.register("skillRaised", skillRaisedCallback)
```

This event can be filtered based on the **`skill`** event data.

## Event Data

* `level` (number): The new level of the skill.
* `skill` (number): The skill that gained a new level experience.
* `source` (): 

