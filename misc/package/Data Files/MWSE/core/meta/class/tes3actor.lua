--- @meta

--- An Actor (not to be confused with a Mobile Actor) is an object that can be cloned and that has an inventory. Creatures, NPCs, and containers are all considered actors.
--- 
--- It is standard for creatures and NPCs to be composed of an actor and a mobile actor, linked together with a reference.
--- @class tes3actor : tes3physicalObject, tes3object, tes3baseObject
--- @field actorFlags number *Read-only*. A number representing the actor flags. Truly a bit field.
--- @field barterGold number Friendly access to actor's barter gold amount.
--- @field blood number Friendly access to actor's blood type.
--- @field cloneCount number *Read-only*. The number of clones that exist of this actor.
--- @field equipment tes3iterator *Read-only*. The items currently equipped to the actor.
--- @field inventory tes3inventory *Read-only*. The items currently carried by the actor.
tes3actor = {}

--- Checks if the actor has provided item equipped.
--- @param params tes3actor.hasItemEquipped.params This table accepts the following values:
--- 
--- `item`: tes3alchemy|tes3apparatus|tes3armor|tes3book|tes3clothing|tes3ingredient|tes3light|tes3lockpick|tes3misc|tes3probe|tes3repairTool|tes3weapon|string — The item to perform a check for.
--- 
--- `itemData`: tes3itemData — *Optional*. No description yet available.
--- @return boolean result No description yet available.
function tes3actor:hasItemEquipped(params) end

---Table parameter definitions for `tes3actor.hasItemEquipped`.
--- @class tes3actor.hasItemEquipped.params
--- @field item tes3alchemy|tes3apparatus|tes3armor|tes3book|tes3clothing|tes3ingredient|tes3light|tes3lockpick|tes3misc|tes3probe|tes3repairTool|tes3weapon|string The item to perform a check for.
--- @field itemData tes3itemData *Optional*. No description yet available.

--- Checks if the actor will offer a service in dialogue. This an offer and may still be refused by dialogue checks. To also get the result of dialogue checks, use [`tes3.checkMerchantOffersService()`](https://mwse.github.io/MWSE/apis/tes3/#tes3checkmerchantoffersservice).
--- @param service number Use one of the [`tes3.merchantService.*`](https://mwse.github.io/MWSE/references/merchant-service-types/) constants.
--- @return boolean result No description yet available.
function tes3actor:offersService(service) end

--- A callback function invoked when an inventory is closed. Typically not used outside of specific purposes. You may find `tes3.reference`'s `onCloseInventory()` to be more convenient to use.
--- @param reference tes3reference No description yet available.
function tes3actor:onInventoryClose(reference) end

--- Checks if the actor will buy and sell items of a given object type. e.g. `actor:tradesItemType(tes3.objectType.repairItem)`
--- @param objectType number Accepts values from [`tes3.objectType`](https://mwse.github.io/MWSE/references/object-types/) namespace.
--- @return boolean result No description yet available.
function tes3actor:tradesItemType(objectType) end

