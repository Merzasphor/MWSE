--- @meta

--- The isGuard event triggers whenever the game engine checks if an NPC object is a guard. The guard status can be modified. This alone will not make an NPC behave like a guard, though.
--- @class isGuardEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field npc tes3npc The NPC that the guard status is being checked for.
--- @field isGuard boolean The previously calculated guard status.
isGuard = {}

