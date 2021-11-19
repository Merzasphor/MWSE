--- @meta

--- A game object which contains AI configuration inforamtion for an actor. This includes: alarm, fight, flee, hello values, which services the actor provides, goods types the actor trades in, and possible destinations this actor can take the player to.
--- @class tes3aiConfig
--- @field alarm number Friendly access to actor's alarm value.
--- @field bartersAlchemy boolean Friendly access to a flag that controls whether the actor barters in potions.
--- @field bartersApparatus boolean Friendly access to a flag that controls whether the actor barters in alchemical apparati.
--- @field bartersArmor boolean Friendly access to a flag that controls whether the actor barters in armor.
--- @field bartersBooks boolean Friendly access to a flag that controls whether the actor barters in books.
--- @field bartersClothing boolean Friendly access to a flag that controls whether the actor barters in clothing.
--- @field bartersEnchantedItems boolean Friendly access to a flag that controls whether the actor barters in enchanted items.
--- @field bartersIngredients boolean Friendly access to a flag that controls whether the actor barters in alchemical ingredients.
--- @field bartersLights boolean Friendly access to a flag that controls whether the actor barters in lights.
--- @field bartersLockpicks boolean Friendly access to a flag that controls whether the actor barters in lockpicks.
--- @field bartersMiscItems boolean Friendly access to a flag that controls whether the actor barters in miscellaneous items.
--- @field bartersProbes boolean Friendly access to a flag that controls whether the actor barters in probes.
--- @field bartersRepairTools boolean Friendly access to a flag that controls whether the actor barters in repair hammers and prongs.
--- @field bartersWeapons boolean Friendly access to a flag that controls whether the actor barters in weapons.
--- @field fight number Friendly access to actor's fight value.
--- @field flee number Friendly access to actor's flee value.
--- @field hello number Friendly access to actor's hello value.
--- @field merchantFlags table A table access to all merchant flags. Shouldn't be used directly.
--- @field offersEnchanting boolean Friendly access to a flag that controls whether the actor offers enchanting services.
--- @field offersRepairs boolean Friendly access to a flag that controls whether the actor offers item repairs service.
--- @field offersSpellmaking boolean Friendly access to a flag that controls whether the actor offers spellmaking service.
--- @field offersSpells boolean Friendly access to a flag that controls whether the actor sells spells.
--- @field offersTraining boolean Friendly access to a flag that controls whether the actor offers training services.
--- @field travelDestinations table A table access to all tes3travelDestinationNode objects this actor can take the player to.
tes3aiConfig = {}

