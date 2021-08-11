# potionBrewed

The potionBrewed event is raised when the player brews a new potion.

```lua
--- @param e potionBrewedEventData
local function potionBrewedCallback(e)
end
event.register("potionBrewed", potionBrewedCallback)
```

## Event Data

* `object` ([tes3alchemy](../../types/tes3alchemy)): The potion created by the player.
* `ingredients` (table): An array of up to 4 tes3ingredient objects, which were used to create the potion.
* `alembic` ([tes3apparatus](../../types/tes3apparatus)): The alembic apparatus used to create the potion.
* `retort` ([tes3apparatus](../../types/tes3apparatus)): The retort apparatus used to create the potion.
* `mortar` ([tes3apparatus](../../types/tes3apparatus)): The mortar apparatus used to create the potion.
* `calcinator` ([tes3apparatus](../../types/tes3apparatus)): The calcinator apparatus used to create the potion.

## Examples

!!! example "Example: Replace a brewed potion with a modified version"

	```lua
	event.register("potionBrewed", function(e)
	    local p = {
	        ["name"] = "[*]" .. e.object.name,
	        ["mesh"] = e.object.mesh,
	        ["icon"] = e.object.icon,
	        ["weight"] = e.object.weight * 2,
	        ["value"] = e.object.value * 50,
	        ["effects"] = {},
	    }
	    for i = 1, 8 do
	        p.effects[i] = e.object.effects[i]
	    end
	
	    local newPotion = tes3alchemy.create(p)
	    tes3.removeItem{reference = tes3.player, item = e.object, playSound = false}
	    tes3.addItem{reference = tes3.player, item = newPotion, playSound = false}
	end)

	```

