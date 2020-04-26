tes3npcInstance
====================================================================================================

An NPC object that has been cloned. Typically represents an NPC that has been instanced in the world.

Properties
----------------------------------------------------------------------------------------------------

`actorFlags`_ (`number`_)
    A number representing the actor flags. Truly a bit field.

`aiConfig`_ (`tes3aiConfig`_)
    A substructure off of actors that contains information on the current AI configuration.

`attributes`_ (`table`_)
    Quick access to the base NPC's attributes.

`barterGold`_ (`number`_)
    Quick access to the base NPC's base amount of barter gold.

`baseObject`_ (`tes3npc`_)
    Access to the base NPC object.

`boundingBox`_ (`tes3boundingBox`_)
    The bounding box for the object.

`class`_ (`tes3class`_)
    Quick access to the base NPC's class.

`cloneCount`_ (`number`_)
    The number of clones that exist of this actor.

`deleted`_ (`boolean`_)
    The deleted state of the object.

`disabled`_ (`boolean`_)
    The disabled state of the object.

`disposition`_ (`number`_)
    The actor's base disposition.

`equipment`_ (`tes3iterator`_)
    The items currently equipped to the actor.

`faction`_ (`tes3faction`_)
    Quick access to the base NPC's faction.

`factionIndex`_ (`number`_)
    No description available.

`fatigue`_ (`number`_)
    Quick access to the base NPC's fatigue.

`health`_ (`number`_)
    Quick access to the base NPC's health.

`id`_ (`string`_)
    The unique identifier for the object.

`inventory`_ (`tes3iterator`_)
    The items currently carried by the actor.

`isAttacked`_ (`boolean`_)
    If true, the actor's attacked flag is set.

`isEssential`_ (`boolean`_)
    If true, the actor's essential flag is set.

`isInstance`_ (`boolean`_)
    Always returns true.

`isRespawn`_ (`boolean`_)
    If true, the actor's respawn flag is set.

`level`_ (`number`_)
    Quick access to the base NPC's level.

`magicka`_ (`number`_)
    Quick access to the base NPC's magicka.

`modified`_ (`boolean`_)
    The modification state of the object since the last save.

`name`_ (`number`_)
    Quick access to the base NPC's name.

`nextInCollection`_ (`tes3object`_)
    The next object in parent collection's list.

`objectFlags`_ (`number`_)
    The raw flags of the object.

`objectType`_ (`number`_)
    The type of object. Maps to values in tes3.objectType.

`owningCollection`_ (`tes3referenceList`_)
    The collection responsible for holding this object.

`previousInCollection`_ (`tes3object`_)
    The previous object in parent collection's list.

`race`_ (`tes3race`_)
    Quick access to the base NPC's race.

`scale`_ (`number`_)
    The object's scale.

`sceneNode`_ (`niNode`_)
    The scene graph node for this object.

`sceneReference`_ (`niNode`_)
    The scene graph reference node for this object.

`script`_ (`tes3script`_)
    Quick access to the base NPC's script.

`skills`_ (`table`_)
    Quick access to the base NPC's skills.

`sourceMod`_ (`string`_)
    The filename of the mod that owns this object.

`spells`_ (`tes3spellList`_)
    Quick access to the base NPC's spell list.

`stolenList`_ (`tes3iterator`_)
    A list of actors that the object has been stolen from.

.. toctree::
    :hidden:

    tes3npcInstance/actorFlags
    tes3npcInstance/aiConfig
    tes3npcInstance/attributes
    tes3npcInstance/barterGold
    tes3npcInstance/baseObject
    tes3npcInstance/boundingBox
    tes3npcInstance/class
    tes3npcInstance/cloneCount
    tes3npcInstance/deleted
    tes3npcInstance/disabled
    tes3npcInstance/disposition
    tes3npcInstance/equipment
    tes3npcInstance/faction
    tes3npcInstance/factionIndex
    tes3npcInstance/fatigue
    tes3npcInstance/health
    tes3npcInstance/id
    tes3npcInstance/inventory
    tes3npcInstance/isAttacked
    tes3npcInstance/isEssential
    tes3npcInstance/isInstance
    tes3npcInstance/isRespawn
    tes3npcInstance/level
    tes3npcInstance/magicka
    tes3npcInstance/modified
    tes3npcInstance/name
    tes3npcInstance/nextInCollection
    tes3npcInstance/objectFlags
    tes3npcInstance/objectType
    tes3npcInstance/owningCollection
    tes3npcInstance/previousInCollection
    tes3npcInstance/race
    tes3npcInstance/scale
    tes3npcInstance/sceneNode
    tes3npcInstance/sceneReference
    tes3npcInstance/script
    tes3npcInstance/skills
    tes3npcInstance/sourceMod
    tes3npcInstance/spells
    tes3npcInstance/stolenList

.. _`actorFlags`: tes3npcInstance/actorFlags.html
.. _`aiConfig`: tes3npcInstance/aiConfig.html
.. _`attributes`: tes3npcInstance/attributes.html
.. _`barterGold`: tes3npcInstance/barterGold.html
.. _`baseObject`: tes3npcInstance/baseObject.html
.. _`boundingBox`: tes3npcInstance/boundingBox.html
.. _`class`: tes3npcInstance/class.html
.. _`cloneCount`: tes3npcInstance/cloneCount.html
.. _`deleted`: tes3npcInstance/deleted.html
.. _`disabled`: tes3npcInstance/disabled.html
.. _`disposition`: tes3npcInstance/disposition.html
.. _`equipment`: tes3npcInstance/equipment.html
.. _`faction`: tes3npcInstance/faction.html
.. _`factionIndex`: tes3npcInstance/factionIndex.html
.. _`fatigue`: tes3npcInstance/fatigue.html
.. _`health`: tes3npcInstance/health.html
.. _`id`: tes3npcInstance/id.html
.. _`inventory`: tes3npcInstance/inventory.html
.. _`isAttacked`: tes3npcInstance/isAttacked.html
.. _`isEssential`: tes3npcInstance/isEssential.html
.. _`isInstance`: tes3npcInstance/isInstance.html
.. _`isRespawn`: tes3npcInstance/isRespawn.html
.. _`level`: tes3npcInstance/level.html
.. _`magicka`: tes3npcInstance/magicka.html
.. _`modified`: tes3npcInstance/modified.html
.. _`name`: tes3npcInstance/name.html
.. _`nextInCollection`: tes3npcInstance/nextInCollection.html
.. _`objectFlags`: tes3npcInstance/objectFlags.html
.. _`objectType`: tes3npcInstance/objectType.html
.. _`owningCollection`: tes3npcInstance/owningCollection.html
.. _`previousInCollection`: tes3npcInstance/previousInCollection.html
.. _`race`: tes3npcInstance/race.html
.. _`scale`: tes3npcInstance/scale.html
.. _`sceneNode`: tes3npcInstance/sceneNode.html
.. _`sceneReference`: tes3npcInstance/sceneReference.html
.. _`script`: tes3npcInstance/script.html
.. _`skills`: tes3npcInstance/skills.html
.. _`sourceMod`: tes3npcInstance/sourceMod.html
.. _`spells`: tes3npcInstance/spells.html
.. _`stolenList`: tes3npcInstance/stolenList.html

Methods
----------------------------------------------------------------------------------------------------

`onInventoryClose`_
    A callback function invoked when an inventory is closed. Typically not used outside of specific purposes.

.. toctree::
    :hidden:

    tes3npcInstance/onInventoryClose

.. _`onInventoryClose`: tes3npcInstance/onInventoryClose.html

.. _`tes3factionReaction`: ../../lua/type/tes3factionReaction.html
.. _`niObject`: ../../lua/type/niObject.html
.. _`tes3npc`: ../../lua/type/tes3npc.html
.. _`tes3book`: ../../lua/type/tes3book.html
.. _`tes3matrix33`: ../../lua/type/tes3matrix33.html
.. _`tes3actor`: ../../lua/type/tes3actor.html
.. _`tes3spell`: ../../lua/type/tes3spell.html
.. _`tes3inputConfig`: ../../lua/type/tes3inputConfig.html
.. _`tes3itemStack`: ../../lua/type/tes3itemStack.html
.. _`tes3globalVariable`: ../../lua/type/tes3globalVariable.html
.. _`tes3containerInstance`: ../../lua/type/tes3containerInstance.html
.. _`tes3magicSourceInstance`: ../../lua/type/tes3magicSourceInstance.html
.. _`niAVObject`: ../../lua/type/niAVObject.html
.. _`tes3iterator`: ../../lua/type/tes3iterator.html
.. _`tes3raceHeightWeight`: ../../lua/type/tes3raceHeightWeight.html
.. _`tes3weatherThunder`: ../../lua/type/tes3weatherThunder.html
.. _`tes3weatherSnow`: ../../lua/type/tes3weatherSnow.html
.. _`tes3class`: ../../lua/type/tes3class.html
.. _`tes3mobileProjectile`: ../../lua/type/tes3mobileProjectile.html
.. _`tes3weatherRain`: ../../lua/type/tes3weatherRain.html
.. _`tes3apparatus`: ../../lua/type/tes3apparatus.html
.. _`tes3door`: ../../lua/type/tes3door.html
.. _`tes3leveledItem`: ../../lua/type/tes3leveledItem.html
.. _`nil`: ../../lua/type/nil.html
.. _`tes3directInputMouseState`: ../../lua/type/tes3directInputMouseState.html
.. _`tes3weatherController`: ../../lua/type/tes3weatherController.html
.. _`niRTTI`: ../../lua/type/niRTTI.html
.. _`tes3mobileCreature`: ../../lua/type/tes3mobileCreature.html
.. _`niObjectNET`: ../../lua/type/niObjectNET.html
.. _`tes3mobilePlayer`: ../../lua/type/tes3mobilePlayer.html
.. _`tes3weatherBlizzard`: ../../lua/type/tes3weatherBlizzard.html
.. _`tes3lockNode`: ../../lua/type/tes3lockNode.html
.. _`tes3vector2`: ../../lua/type/tes3vector2.html
.. _`tes3armor`: ../../lua/type/tes3armor.html
.. _`tes3weather`: ../../lua/type/tes3weather.html
.. _`tes3npcInstance`: ../../lua/type/tes3npcInstance.html
.. _`tes3wearablePart`: ../../lua/type/tes3wearablePart.html
.. _`tes3vector4`: ../../lua/type/tes3vector4.html
.. _`tes3dataHandler`: ../../lua/type/tes3dataHandler.html
.. _`tes3rangeInt`: ../../lua/type/tes3rangeInt.html
.. _`tes3dialogueInfo`: ../../lua/type/tes3dialogueInfo.html
.. _`tes3raceSkillBonus`: ../../lua/type/tes3raceSkillBonus.html
.. _`tes3weatherAsh`: ../../lua/type/tes3weatherAsh.html
.. _`tes3travelDestinationNode`: ../../lua/type/tes3travelDestinationNode.html
.. _`tes3transform`: ../../lua/type/tes3transform.html
.. _`tes3dialogue`: ../../lua/type/tes3dialogue.html
.. _`tes3gameFile`: ../../lua/type/tes3gameFile.html
.. _`tes3faction`: ../../lua/type/tes3faction.html
.. _`tes3statistic`: ../../lua/type/tes3statistic.html
.. _`tes3inputController`: ../../lua/type/tes3inputController.html
.. _`tes3lockpick`: ../../lua/type/tes3lockpick.html
.. _`tes3combatSession`: ../../lua/type/tes3combatSession.html
.. _`boolean`: ../../lua/type/boolean.html
.. _`tes3static`: ../../lua/type/tes3static.html
.. _`tes3magicEffect`: ../../lua/type/tes3magicEffect.html
.. _`string`: ../../lua/type/string.html
.. _`tes3soulGemData`: ../../lua/type/tes3soulGemData.html
.. _`tes3iteratorNode`: ../../lua/type/tes3iteratorNode.html
.. _`tes3item`: ../../lua/type/tes3item.html
.. _`tes3quest`: ../../lua/type/tes3quest.html
.. _`tes3nonDynamicData`: ../../lua/type/tes3nonDynamicData.html
.. _`tes3ingredient`: ../../lua/type/tes3ingredient.html
.. _`tes3race`: ../../lua/type/tes3race.html
.. _`tes3gameSetting`: ../../lua/type/tes3gameSetting.html
.. _`tes3reference`: ../../lua/type/tes3reference.html
.. _`table`: ../../lua/type/table.html
.. _`tes3mobileActor`: ../../lua/type/tes3mobileActor.html
.. _`tes3referenceList`: ../../lua/type/tes3referenceList.html
.. _`tes3mobileNPC`: ../../lua/type/tes3mobileNPC.html
.. _`tes3regionSound`: ../../lua/type/tes3regionSound.html
.. _`tes3vector3`: ../../lua/type/tes3vector3.html
.. _`tes3raceBodyParts`: ../../lua/type/tes3raceBodyParts.html
.. _`tes3raceBaseAttribute`: ../../lua/type/tes3raceBaseAttribute.html
.. _`tes3activator`: ../../lua/type/tes3activator.html
.. _`tes3probe`: ../../lua/type/tes3probe.html
.. _`tes3inventory`: ../../lua/type/tes3inventory.html
.. _`tes3boundingBox`: ../../lua/type/tes3boundingBox.html
.. _`tes3birthsign`: ../../lua/type/tes3birthsign.html
.. _`tes3physicalObject`: ../../lua/type/tes3physicalObject.html
.. _`tes3creatureInstance`: ../../lua/type/tes3creatureInstance.html
.. _`tes3effect`: ../../lua/type/tes3effect.html
.. _`tes3game`: ../../lua/type/tes3game.html
.. _`tes3light`: ../../lua/type/tes3light.html
.. _`tes3moon`: ../../lua/type/tes3moon.html
.. _`tes3object`: ../../lua/type/tes3object.html
.. _`tes3weatherClear`: ../../lua/type/tes3weatherClear.html
.. _`number`: ../../lua/type/number.html
.. _`tes3mobileObject`: ../../lua/type/tes3mobileObject.html
.. _`tes3weatherCloudy`: ../../lua/type/tes3weatherCloudy.html
.. _`tes3region`: ../../lua/type/tes3region.html
.. _`tes3misc`: ../../lua/type/tes3misc.html
.. _`tes3leveledListNode`: ../../lua/type/tes3leveledListNode.html
.. _`tes3markData`: ../../lua/type/tes3markData.html
.. _`tes3magicEffectInstance`: ../../lua/type/tes3magicEffectInstance.html
.. _`function`: ../../lua/type/function.html
.. _`tes3bodyPart`: ../../lua/type/tes3bodyPart.html
.. _`tes3baseObject`: ../../lua/type/tes3baseObject.html
.. _`mwseTimer`: ../../lua/type/mwseTimer.html
.. _`tes3factionRank`: ../../lua/type/tes3factionRank.html
.. _`tes3fader`: ../../lua/type/tes3fader.html
.. _`tes3weatherBlight`: ../../lua/type/tes3weatherBlight.html
.. _`tes3packedColor`: ../../lua/type/tes3packedColor.html
.. _`bool`: ../../lua/type/boolean.html
.. _`tes3equipmentStack`: ../../lua/type/tes3equipmentStack.html
.. _`tes3weatherFoggy`: ../../lua/type/tes3weatherFoggy.html
.. _`mwseTimerController`: ../../lua/type/mwseTimerController.html
.. _`tes3leveledCreature`: ../../lua/type/tes3leveledCreature.html
.. _`tes3clothing`: ../../lua/type/tes3clothing.html
.. _`tes3activeMagicEffect`: ../../lua/type/tes3activeMagicEffect.html
.. _`tes3cellExteriorData`: ../../lua/type/tes3cellExteriorData.html
.. _`tes3weatherOvercast`: ../../lua/type/tes3weatherOvercast.html
.. _`tes3itemData`: ../../lua/type/tes3itemData.html
.. _`tes3cell`: ../../lua/type/tes3cell.html
.. _`tes3enchantment`: ../../lua/type/tes3enchantment.html
.. _`tes3actionData`: ../../lua/type/tes3actionData.html
.. _`tes3creature`: ../../lua/type/tes3creature.html
.. _`tes3container`: ../../lua/type/tes3container.html
.. _`tes3alchemy`: ../../lua/type/tes3alchemy.html
