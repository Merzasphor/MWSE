# damaged

The damaged event triggers after an actor has been damaged.

```lua
--- @param e damagedEventData
local function damagedCallback(e)
end
event.register("damaged", damagedCallback)
```

## Event Data

* `activeMagicEffect` ([tes3magicEffect](../../types/tes3magicEffect)): tes3magicEffect which caused damage. Can be nil.
* `reference` ([tes3reference](../../types/tes3reference)): mobile’s associated reference.
* `projectile` ([tes3mobileProjectile](../../types/tes3mobileProjectile)): Projectile that dealt the damage. Can be nil.
* `attackerReference` ([tes3reference](../../types/tes3reference)): attacker mobile's associated reference. Can be nil.
* `source` (damageSourceType): The origin of damage. Values of this variable can be: "script", "fall", "suffocation", "attack", "magic", "shield" or nil.
* `damage` (number): The amount of damage done.
* `magicSourceInstance` ([tes3magicSourceInstance](../../types/tes3magicSourceInstance)): tes3magicSourceInstance of a spell that caused damage. Can be nil.
* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): The mobile actor that took damage.
* `killingBlow` (boolean): If true, the damage killed the target.
* `attacker` ([tes3mobileActor](../../types/tes3mobileActor)): The mobile actor dealing the damage. Can be nil.

## Examples

!!! example "Example: Notify the player that their arrow/bolt killed their opponent"

	```lua
	
	-- Print a message if player's arrow killed its target
	local function onDamaged(e)
	    -- We only care if the player did the damage
	    if e.attackerReference ~= tes3.player then
	        return
	    end
	
	    -- Check if the damage was caused by a projectile, but not by a spell, so it must be an arrow or a bolt
	    if e.projectile ~= nil and e.magicSourceInstance == nil then
	
	        -- Did the damage kill the target?
	        if e.killingBlow == true then
	            tes3.messageBox("Your arrow felled its target!")
	        end
	    end
	end
	event.register("damaged", onDamaged)

	```

