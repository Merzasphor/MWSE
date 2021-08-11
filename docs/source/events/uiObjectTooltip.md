# uiObjectTooltip

The uiObjectTooltip event triggers when a new tooltip is displayed for all in-world objects and items, and inventory tiles in all dialogues. The tooltip will be already be built. Tooltips for inventory tiles are built on mouseover, while tooltips for in-world objects are rebuilt every frame.

```lua
--- @param e uiObjectTooltipEventData
local function uiObjectTooltipCallback(e)
end
event.register("uiObjectTooltip", uiObjectTooltipCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `tooltip` ([tes3uiElement](../../types/tes3uiElement)): The newly created tooltip element. Due to timeouts and target changes, it may be destroyed at any time.
* `reference` ([tes3reference](../../types/tes3reference)): The reference being examined. Only valid for in-world objects. For inventory tiles it will always be nil.
* `itemData` ([tes3itemData](../../types/tes3itemData)): The item data of object, if any.
* `count` (number): The number of items in the stack.
* `object` ([tes3physicalObject](../../types/tes3physicalObject)): The object being examined.

