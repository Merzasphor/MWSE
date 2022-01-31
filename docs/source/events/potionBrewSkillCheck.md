# potionBrewSkillCheck

This event is triggered when the player attempts to brew a potion. It controls both the strength of the potion's effects, and if the brew is successful. These both use the player's stats, so the game combines them into one function. Because the potion effects are not determined yet, the potion data is not available. When using this event, use the example as a template for your own code.

```lua
--- @param e potionBrewSkillCheckEventData
local function potionBrewSkillCheckCallback(e)
end
event.register(tes3.event.potionBrewSkillCheck, potionBrewSkillCheckCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `alembic` ([tes3apparatus](../../types/tes3apparatus)): *Read-only*. The alembic apparatus used to create the potion.
* `calcinator` ([tes3apparatus](../../types/tes3apparatus)): *Read-only*. The calcinator apparatus used to create the potion.
* `ingredients` (table): *Read-only*. An array of up to 4 [`tes3ingredient`](https://mwse.github.io/MWSE/types/tes3ingredient/) objects, which were used to create the potion.
* `mortar` ([tes3apparatus](../../types/tes3apparatus)): *Read-only*. The mortar apparatus used to create the potion.
* `potionStrength` (number): Can be modified. The strength multiplier used to scale the potion effects. For each different effect, it can modify magnitude, duration, or both. This is initially equal to -1 if the potion failed to brew.
* `retort` ([tes3apparatus](../../types/tes3apparatus)): *Read-only*. The retort apparatus used to create the potion.
* `success` (boolean): Can be modified. Whether the brewing is successful.

## Examples

!!! example "Example: Vanilla potion skill check function"

	```lua
	local function brewSkillCheck(e)
		local player = tes3.mobilePlayer
		local x = player.alchemy.current + 0.1 * player.intelligence.current + 0.1 * player.luck.current
	
		local roll = math.floor(100 * math.random())
		if (roll <= x) then
			local fPotionStrengthMult = tes3.findGMST(tes3.gmst.fPotionStrengthMult).value
			e.potionStrength = fPotionStrengthMult * e.mortar.quality * x
			e.success = true
		else
			e.potionStrength = -1
			e.success = false
		end
	end
	
	event.register(tes3.event.potionBrewSkillCheck, brewSkillCheck)

	```

