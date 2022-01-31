# topicAdded

This event is raised when the player gains access to a new dialogue topic.

```lua
--- @param e topicAddedEventData
local function topicAddedCallback(e)
end
event.register(tes3.event.topicAdded, topicAddedCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `topic` ([tes3dialogue](../../types/tes3dialogue)): *Read-only*. The topic that was newly added to the player's list of topics.

