# filterSoulGemTarget

This event fires when a soul gem target is filtered

```lua
--- @param e filterSoulGemTargetEventData
local function filterSoulGemTargetCallback(e)
end
event.register(tes3.event.filterSoulGemTarget, filterSoulGemTargetCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `filter` (boolean): Setting this to `false` or `nil` will prevent the `mobile`'s soul to end up in the `soulGem`. Setting this to `true` will make the opposite.
* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile actor whose soul is to be soultrapped.
* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. The reference.
* `soulGem` ([tes3misc](../../types/tes3misc)): *Read-only*. The soul gem object.

## Examples

!!! example "Example: Example"

	```lua
	local function onInitialized()
		tes3.addSoulGem({ item = "vivec_soul_container" })
	end
	event.register(tes3.event.initialized, onInitialized)
	
	local function onFilterSoulGemTarget(e)
		-- Make it so Vivec can only be trapped by a special container.
		if (e.reference.baseObject.id:lower() == "vivec") then
			return e.soulGem.id == "vivec_soul_container"
		end
	end
	event.register(tes3.event.filterSoulGemTarget, onFilterSoulGemTarget)

	```

