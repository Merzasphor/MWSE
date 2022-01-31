# calcSunDamageScalar

calcSunDamageScalar is used when calculating the amount of damage to apply for the Sun Damage magic effect.

```lua
--- @param e calcSunDamageScalarEventData
local function calcSunDamageScalarCallback(e)
end
event.register(tes3.event.calcSunDamageScalar, calcSunDamageScalarCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `damage` (number): The previously calculated sun damage.

