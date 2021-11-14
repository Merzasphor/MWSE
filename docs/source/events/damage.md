# damage

The damage event triggers before an actor is damaged. The damage value can be modified, or the damage can be prevented completely by blocking the event.

```lua
--- @param e damageEventData
local function damageCallback(e)
end
event.register("damage", damageCallback)
```

!!! tip
	This event supports blocking by setting `e.block` to `true` or returning `false`. Blocking the event prevents vanilla behavior from happening. For example, blocking an `equip` event prevents the item from being equipped.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `activeMagicEffect` ([tes3magicEffect](../../types/tes3magicEffect)): *Read-only*. tes3magicEffect which caused damage. Can be nil.
* `attacker` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile actor dealing the damage. Can be nil.
* `attackerReference` ([tes3reference](../../types/tes3reference)): *Read-only*. The attacker mobile's associated reference. Can be nil.
* `damage` (number): The amount of damage done.
* `magicSourceInstance` ([tes3magicSourceInstance](../../types/tes3magicSourceInstance)): tes3magicSourceInstance of a spell that caused damage. Can be nil.
* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile actor that is taking damage.
* `projectile` ([tes3mobileProjectile](../../types/tes3mobileProjectile)): *Read-only*. Projectile that dealt the damage. Can be nil.
* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. The mobile’s associated reference.
* `source` (tes3.damageSource constants): *Read-only*. The origin of damage. Values of this variable can be: "script", "fall", "suffocation", "attack", "magic", "shield" or nil. These damage sources are present as tes3.damageSource.* constants, and those should be used instead. See the example. Damage with "shield" source comes from magic shields. Other sources are self-explanatory.

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
	    if e.source ~= tes3.damageSource.fall then
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

