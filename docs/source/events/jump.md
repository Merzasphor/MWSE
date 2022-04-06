# jump

This event is called when an actor tries to jump. The velocity can be modified.

```lua
--- @param e jumpEventData
local function jumpCallback(e)
end
event.register(tes3.event.jump, jumpCallback)
```

!!! tip
	This event can be filtered based on the **`reference`** event data.

!!! tip
	This event supports blocking by setting `e.block` to `true` or returning `false`. Blocking the event prevents vanilla behavior from happening. For example, blocking an `equip` event prevents the item from being equipped.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile actor that is trying to jump.
* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. Mobile's related reference.
* `velocity` ([tes3vector3](../../types/tes3vector3)): The velocity of the jump.

## Examples

!!! example "Example: Disable jumping while encumbered"

	Disables jumping for the player if their current encumbrance is over 50%.

	```lua
	local function onJump(e)
		-- Check if the actor that is trying to jump is the player.
		if e.mobile == tes3.mobilePlayer then
			-- Define the threshold at which we no longer want to be able to jump.
			-- This is set to 50% of the player's maximum encumbrance.
			local encumbranceThreshold = e.mobile.encumbrance.base * 0.5
	
			-- Check if the current encumbrance is higher than our defined threshold and prevent jumping.
			if e.mobile.encumbrance.current > encumbranceThreshold then
				-- Show a message to the player to inform them that jumping is not possible.
				tes3.messageBox("You are unable to jump.")
	
				-- Block the vanilla jump logic and prevent other jump events from being triggered.
				return false
			end
		end
	end
	event.register(tes3.event.jump, onJump)

	```

!!! example "Example: Double jump height"

	Double the height of every jump.

	```lua
	local function onJump(e)
		-- Multiply the velocity on the Z-Axis (Up/Down) by 2.
		e.velocity.z = e.velocity.z * 2
	end
	event.register(tes3.event.jump, onJump)

	```

!!! example "Example: Force player jump height"

	Forces the jump height of the player to a fixed value, not taking into account attributes, skills, fatigue, encumbrance and other factors.

	```lua
	local function onJump(e)
		-- Check if the actor that is trying to jump is the player.
		if e.mobile == tes3.mobilePlayer then
			-- Define the fixed height of the jump.
			local jumpHeight = 300
	
			-- Multiply the normalized direction vector of the jump by the fixed jump height.
			-- This will make jumps initiated during movement behave like they normally do.
			e.velocity = e.velocity:normalized() * jumpHeight
		end
	end
	event.register(tes3.event.jump, onJump)

	```

