# attack

This event is invoked whenever an actor makes an attack with their fists or a weapon, or a creature makes any attack. It occurs at the release time of the attack, such as the downstroke of a melee weapon or when an arrow is shot. Lockpicks and probes do not invoke this event.

```lua
--- @param e attackEventData
local function attackCallback(e)
end
event.register("attack", attackCallback)
```

!!! tip
	This event can be filtered based on the **`reference`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile actor making the attack.
* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. A shortcut to the reference that is attacking.
* `targetMobile` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile actor being attacked.
* `targetReference` ([tes3reference](../../types/tes3reference)): *Read-only*. A shortcut to the reference being attacked.

## Examples

!!! example "Example: Show a Message when the Player Attacks"

	```lua
	local function myOnAttackCallback(e)
	    -- Someone other than the player is attacking.
	    if (e.reference ~= tes3.player) then
	        return
	    end
	
	    -- We hit someone!
	    if (e.targetReference ~= nil) then
	        tes3.messageBox("You hit %s!", e.targetReference.object.name or e.targetReference.object.id)
	    end
	end
	event.register("attack", myOnAttackCallback)

	```

