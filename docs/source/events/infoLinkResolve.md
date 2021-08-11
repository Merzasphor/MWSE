# infoLinkResolve

This event fires when a dialogue hyperlink is being resolved to a topic, during UI layout (not on link activation).

```lua
--- @param e infoLinkResolveEventData
local function infoLinkResolveCallback(e)
end
event.register("infoLinkResolve", infoLinkResolveCallback)
```

## Event Data

* `topic` (string): The topic that activates when this hyperlink is clicked. Initially set to the link text. Set this value to change the target topic.

