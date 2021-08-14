# skillRaised

This event is invoked whenever the player naturally gains a new level a skill. This is typically through exercise, training, or reading books.

```lua
--- @param e skillRaisedEventData
local function skillRaisedCallback(e)
end
event.register("skillRaised", skillRaisedCallback)
```

!!! tip
	This event can be filtered based on the **`skill`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `level` (number): *Read-only*. The new level of the skill.
* `skill` (number): *Read-only*. The skill that gained a new level experience.
* `source` (): 

