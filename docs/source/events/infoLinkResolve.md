# infoLinkResolve

This event fires when a dialogue hyperlink is being resolved to a topic, during UI layout (not on link activation).

```lua
--- @param e infoLinkResolveEventData
local function infoLinkResolveCallback(e)
end
event.register(tes3.event.infoLinkResolve, infoLinkResolveCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `topic` (string): The topic that activates when this hyperlink is clicked. Initially set to the link text. Set this value to change the target topic.

