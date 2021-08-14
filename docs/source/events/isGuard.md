# isGuard

The isGuard event triggers whenever the game engine checks if an NPC object is a guard. The guard status can be modified. This alone will not make an NPC behave like a guard, though.

```lua
--- @param e isGuardEventData
local function isGuardCallback(e)
end
event.register("isGuard", isGuardCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `isGuard` (boolean): The previously calculated guard status.
* `npc` ([tes3npc](../../types/tes3npc)): *Read-only*. The NPC that the guard status is being checked for.

