# activate

This event is invoked whenever something is activated, typically by the player. Activation is usually done with the associated activate/use key, but may also be forced by scripts.

```lua
--- @type e event.activate
local function activateCallback(e)
end
event.register("activate", activateCallback)
```

This event can be filtered based on the **`target`** event data.

## Event Data

* `target` ([tes3reference](../../types/tes3reference)): The reference that is being activated.
* `activator` ([tes3reference](../../types/tes3reference)): The actor attempting to trigger the event.

## Examples

!!! example "Example: Prevent the player from activating NPCs"

	```lua
	
	-- Show the id when the player activates an object.
	local function myOnActivateCallback(e)
		-- We only care if the PC is activating something.
		if (e.activator ~= tes3.player) then
			return
		end
	
		-- If the player targets an NPC, block the activation.
		if (e.target.object.objectType == tes3.objectType.npc) then
			return false
		end
	end
	event.register("activate", myOnActivateCallback)

	```

!!! example "Example: Show a message for what the player is activating"

	```lua
	-- Show the id when the player activates an object.
	local function myOnActivateCallback(e)
		if (e.activator == tes3.player) then
			tes3.messageBox({ message = "Activated " .. e.target.object.id })
		end
	end
	event.register("activate", myOnActivateCallback)

	```

