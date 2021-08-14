--- @meta

--- A faction game object.
--- @class tes3faction : tes3baseObject
--- @field attributes table *Read-only*. An array-style table holding the two attributes that govern advancement.
--- @field name string The faction's player-facing name.
--- @field playerExpelled boolean The player's expelled state in the faction.
--- @field playerJoined boolean The player's join state for the faction.
--- @field playerRank number The player's current rank in the faction.
--- @field playerReputation number The player's current reputation in the faction.
--- @field ranks table *Read-only*. An array-style table holding the ten related tes3factionRanks.
--- @field reactions tes3iterator *Read-only*. A collection of tes3factionReactions.
--- @field skills table *Read-only*. An array-style table holding the seven skills that govern advancement.
tes3faction = {}

--- This function fetches the player-facing name of a rank in the faction.
--- @param rank number A rank number in range [0, 9] inclusive.
--- @return string result No description yet available.
function tes3faction:getRankName(rank) end

--- This function changes the player-facing name of a given rank in the faction.
--- @param rank number A rank number in range [0, 9] inclusive.
--- @param name string A new name to set.
function tes3faction:setRankName(rank, name) end

