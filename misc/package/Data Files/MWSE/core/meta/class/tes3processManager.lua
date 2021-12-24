--- @meta

--- 
--- @class tes3processManager
--- @field aiDistance number A value which controls how far the game AI is processed, measured in game distance units. Corresponds to AI Distance slider in Options menu.
--- @field aiDistanceScale number A value which controls how far the game AI is processed. Corresponds to AI Distance slider in Options menu. This scale is in range [0, 1]. Where `0` means the minimal AI processing range, while `1` means maximal AI processing range.
tes3processManager = {}

--- 
--- @param params tes3processManager.checkAlarmRadius.params This table accepts the following values:
--- 
--- `actor`: tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer — 
--- 
--- `container`: tes3aiPlanner — 
function tes3processManager.checkAlarmRadius(params) end

---Table parameter definitions for `tes3processManager.checkAlarmRadius`.
--- @class tes3processManager.checkAlarmRadius.params
--- @field actor tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer 
--- @field container tes3aiPlanner 

--- Performs a check whether any potential nearby enemies allow the player to rest.
--- @return boolean result No description yet available.
function tes3processManager.checkNearbyEnemiesAllowRest() end

--- 
function tes3processManager.checkPlayerDistance() end

--- This function performs a check for presence of a given mobile actor.
--- @param params tes3processManager.detectPresence.params This table accepts the following values:
--- 
--- `actor`: tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer — The actor to perform a check for.
--- 
--- `unknown`: boolean — No description yet available.
function tes3processManager.detectPresence(params) end

---Table parameter definitions for `tes3processManager.detectPresence`.
--- @class tes3processManager.detectPresence.params
--- @field actor tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer The actor to perform a check for.
--- @field unknown boolean No description yet available.

--- This function performs a check whether a detector can detect another actor sneaking.
--- @param params tes3processManager.detectSneak.params This table accepts the following values:
--- 
--- `detector`: tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer — The detector actor to perform a check for.
--- 
--- `target`: tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer — The target actor to perform a check for.
--- 
--- `unknown`: boolean — No description yet available.
--- @return boolean isDetected No description yet available.
function tes3processManager.detectSneak(params) end

---Table parameter definitions for `tes3processManager.detectSneak`.
--- @class tes3processManager.detectSneak.params
--- @field detector tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer The detector actor to perform a check for.
--- @field target tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer The target actor to perform a check for.
--- @field unknown boolean No description yet available.

