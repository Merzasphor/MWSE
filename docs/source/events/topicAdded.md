# topicAdded

This event is raised when the player gains access to a new dialogue topic.

```lua
--- @type e event.topicAdded
local function topicAddedCallback(e)
end
event.register("topicAdded", topicAddedCallback)
```

## Event Data

* `topic` ([tes3dialogue](../../types/tes3dialogue)): The topic that was newly added to the player's list of topics.

