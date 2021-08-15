# damaged

The damaged event triggers after an actor has been damaged.

```lua
--- @param e damagedEventData
local function damagedCallback(e)
end
event.register("damaged", damagedCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `activeMagicEffect` ([tes3magicEffect](../../types/tes3magicEffect)): *Read-only*. tes3magicEffect which caused damage. Can be nil.
* `attacker` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile actor dealing the damage. Can be nil.
* `attackerReference` ([tes3reference](../../types/tes3reference)): *Read-only*. attacker mobile's associated reference. Can be nil.
* `damage` (number): *Read-only*. The amount of damage done.
* `killingBlow` (boolean): *Read-only*. If true, the damage killed the target.
* `magicSourceInstance` ([tes3magicSourceInstance](../../types/tes3magicSourceInstance)): tes3magicSourceInstance of a spell that caused damage. Can be nil.
* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile actor that took damage.
* `projectile` ([tes3mobileProjectile](../../types/tes3mobileProjectile)): *Read-only*. Projectile that dealt the damage. Can be nil.
* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. mobile’s associated reference.
* `source` (damageSourceType): *Read-only*. The origin of damage. Values of this variable can be: "script", "fall", "suffocation", "attack", "magic", "shield" or nil.

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

