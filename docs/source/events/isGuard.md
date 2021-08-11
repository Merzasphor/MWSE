# isGuard

The isGuard event triggers whenever the game engine checks if an NPC object is a guard. The guard status can be modified. This alone will not make an NPC behave like a guard, though.

```lua
--- @param e isGuardEventData
local function isGuardCallback(e)
end
event.register("isGuard", isGuardCallback)
```

## Event Data

* `npc` ([tes3npc](../../types/tes3npc)): The NPC that the guard status is being checked for.
* `isGuard` (boolean): The previously calculated guard status.

