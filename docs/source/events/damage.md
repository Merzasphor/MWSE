# damage

The damage event triggers before an actor is damaged. The damage value can be modified, or the damage can be prevented completely by blocking the event.

```lua
--- @param e damageEventData
local function damageCallback(e)
end
event.register("damage", damageCallback)
```

## Event Data

* `activeMagicEffect` ([tes3magicEffect](../../types/tes3magicEffect)): tes3magicEffect which caused damage. Can be nil.
* `projectile` ([tes3mobileProjectile](../../types/tes3mobileProjectile)): Projectile that dealt the damage. Can be nil.
* `attackerReference` ([tes3reference](../../types/tes3reference)): attacker mobile's associated reference. Can be nil.
* `source` (damageSourceType): The origin of damage. Values of this variable can be: "script", "fall", "suffocation", "attack", "magic", "shield" or nil.
* `damage` (number): The amount of damage done.
* `magicSourceInstance` ([tes3magicSourceInstance](../../types/tes3magicSourceInstance)): tes3magicSourceInstance of a spell that caused damage. Can be nil.
* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): The mobile actor that is taking damage.
* `reference` ([tes3reference](../../types/tes3reference)): mobile’s associated reference.
* `attacker` ([tes3mobileActor](../../types/tes3mobileActor)): The mobile actor dealing the damage. Can be nil.

## Examples

!!! example "Example: Change fall damage"

	```lua
	
	-- Change fall damage if player is a Bosmer
	local function onDamage(e)
	    -- We only care if the player took some damage
	    if e.reference ~= tes3.player then
	        return
	    end
	
	    -- Check if the damage was caused by a fall
	    if e.source ~= "fall" then
	        return
	    end
	
	    -- Check weather the player is a Bosmer
	    if e.reference.object.race.id:lower() == "bosmer" then    -- This is the same as tes3.player.object.race.id:lower() == "bosmer"
	        -- Taunt the player
	        tes3.messageBox("Ha ha ha, you broke your leg Bosmer")
	
	        -- Double the damage. He is Fargoth's cousin after all
	        e.damage = e.damage * 2
	    end
	end
	event.register("damage", onDamage)

	```

