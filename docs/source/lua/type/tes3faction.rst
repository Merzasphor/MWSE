tes3faction
====================================================================================================

A faction game object.

Properties
----------------------------------------------------------------------------------------------------

`actorFlags`_ (`number`_)
    A number representing the actor flags. Truly a bit field.

`attributes`_ (`table`_)
    An array-style table holding the two attributes that govern advancement.

`barterGold`_ (`number`_)
    The amount of gold that the actor has to trade with.

`boundingBox`_ (`tes3boundingBox`_)
    The bounding box for the object.

`cloneCount`_ (`number`_)
    The number of clones that exist of this actor.

`deleted`_ (`boolean`_)
    The deleted state of the object.

`disabled`_ (`boolean`_)
    The disabled state of the object.

`equipment`_ (`tes3iterator`_)
    The items currently equipped to the actor.

`id`_ (`string`_)
    The unique identifier for the object.

`inventory`_ (`tes3iterator`_)
    The items currently carried by the actor.

`modified`_ (`boolean`_)
    The modification state of the object since the last save.

`name`_ (`string`_)
    The faction's player-facing name.

`nextInCollection`_ (`tes3object`_)
    The next object in parent collection's list.

`objectFlags`_ (`number`_)
    The raw flags of the object.

`objectType`_ (`number`_)
    The type of object. Maps to values in tes3.objectType.

`owningCollection`_ (`tes3referenceList`_)
    The collection responsible for holding this object.

`playerExpelled`_ (`boolean`_)
    The player's expelled state in the faction.

`playerJoined`_ (`boolean`_)
    The player's join state for the faction.

`playerRank`_ (`number`_)
    The player's current rank in the faction.

`playerReputation`_ (`number`_)
    The player's current reputation in the faction.

`previousInCollection`_ (`tes3object`_)
    The previous object in parent collection's list.

`ranks`_ (`table`_)
    An array-style table holding the ten related tes3factionRanks.

`reactions`_ (`tes3iterator`_)
    A collection of tes3factionReactions.

`scale`_ (`number`_)
    The object's scale.

`sceneNode`_ (`niNode`_)
    The scene graph node for this object.

`sceneReference`_ (`niNode`_)
    The scene graph reference node for this object.

`skills`_ (`table`_)
    An array-style table holding the seven skills that govern advancement.

`sourceMod`_ (`string`_)
    The filename of the mod that owns this object.

`stolenList`_ (`tes3iterator`_)
    A list of actors that the object has been stolen from.

.. toctree::
    :hidden:

    tes3faction/actorFlags
    tes3faction/attributes
    tes3faction/barterGold
    tes3faction/boundingBox
    tes3faction/cloneCount
    tes3faction/deleted
    tes3faction/disabled
    tes3faction/equipment
    tes3faction/id
    tes3faction/inventory
    tes3faction/modified
    tes3faction/name
    tes3faction/nextInCollection
    tes3faction/objectFlags
    tes3faction/objectType
    tes3faction/owningCollection
    tes3faction/playerExpelled
    tes3faction/playerJoined
    tes3faction/playerRank
    tes3faction/playerReputation
    tes3faction/previousInCollection
    tes3faction/ranks
    tes3faction/reactions
    tes3faction/scale
    tes3faction/sceneNode
    tes3faction/sceneReference
    tes3faction/skills
    tes3faction/sourceMod
    tes3faction/stolenList

.. _`actorFlags`: tes3faction/actorFlags.html
.. _`attributes`: tes3faction/attributes.html
.. _`barterGold`: tes3faction/barterGold.html
.. _`boundingBox`: tes3faction/boundingBox.html
.. _`cloneCount`: tes3faction/cloneCount.html
.. _`deleted`: tes3faction/deleted.html
.. _`disabled`: tes3faction/disabled.html
.. _`equipment`: tes3faction/equipment.html
.. _`id`: tes3faction/id.html
.. _`inventory`: tes3faction/inventory.html
.. _`modified`: tes3faction/modified.html
.. _`name`: tes3faction/name.html
.. _`nextInCollection`: tes3faction/nextInCollection.html
.. _`objectFlags`: tes3faction/objectFlags.html
.. _`objectType`: tes3faction/objectType.html
.. _`owningCollection`: tes3faction/owningCollection.html
.. _`playerExpelled`: tes3faction/playerExpelled.html
.. _`playerJoined`: tes3faction/playerJoined.html
.. _`playerRank`: tes3faction/playerRank.html
.. _`playerReputation`: tes3faction/playerReputation.html
.. _`previousInCollection`: tes3faction/previousInCollection.html
.. _`ranks`: tes3faction/ranks.html
.. _`reactions`: tes3faction/reactions.html
.. _`scale`: tes3faction/scale.html
.. _`sceneNode`: tes3faction/sceneNode.html
.. _`sceneReference`: tes3faction/sceneReference.html
.. _`skills`: tes3faction/skills.html
.. _`sourceMod`: tes3faction/sourceMod.html
.. _`stolenList`: tes3faction/stolenList.html

Methods
----------------------------------------------------------------------------------------------------

`onInventoryClose`_
    A callback function invoked when an inventory is closed. Typically not used outside of specific purposes.

.. toctree::
    :hidden:

    tes3faction/onInventoryClose

.. _`onInventoryClose`: tes3faction/onInventoryClose.html

.. _`tes3creature`: ../../lua/type/tes3creature.html
.. _`niObject`: ../../lua/type/niObject.html
.. _`tes3book`: ../../lua/type/tes3book.html
.. _`tes3matrix33`: ../../lua/type/tes3matrix33.html
.. _`tes3actor`: ../../lua/type/tes3actor.html
.. _`tes3inputConfig`: ../../lua/type/tes3inputConfig.html
.. _`tes3itemStack`: ../../lua/type/tes3itemStack.html
.. _`tes3globalVariable`: ../../lua/type/tes3globalVariable.html
.. _`tes3containerInstance`: ../../lua/type/tes3containerInstance.html
.. _`tes3magicSourceInstance`: ../../lua/type/tes3magicSourceInstance.html
.. _`niAVObject`: ../../lua/type/niAVObject.html
.. _`tes3iterator`: ../../lua/type/tes3iterator.html
.. _`tes3class`: ../../lua/type/tes3class.html
.. _`tes3mobileProjectile`: ../../lua/type/tes3mobileProjectile.html
.. _`tes3apparatus`: ../../lua/type/tes3apparatus.html
.. _`tes3door`: ../../lua/type/tes3door.html
.. _`tes3directInputMouseState`: ../../lua/type/tes3directInputMouseState.html
.. _`niRTTI`: ../../lua/type/niRTTI.html
.. _`niObjectNET`: ../../lua/type/niObjectNET.html
.. _`tes3armor`: ../../lua/type/tes3armor.html
.. _`tes3reference`: ../../lua/type/tes3reference.html
.. _`tes3dataHandler`: ../../lua/type/tes3dataHandler.html
.. _`tes3rangeInt`: ../../lua/type/tes3rangeInt.html
.. _`tes3dialogueInfo`: ../../lua/type/tes3dialogueInfo.html
.. _`tes3dialogue`: ../../lua/type/tes3dialogue.html
.. _`tes3gameFile`: ../../lua/type/tes3gameFile.html
.. _`tes3faction`: ../../lua/type/tes3faction.html
.. _`tes3inputController`: ../../lua/type/tes3inputController.html
.. _`tes3lockpick`: ../../lua/type/tes3lockpick.html
.. _`tes3combatSession`: ../../lua/type/tes3combatSession.html
.. _`boolean`: ../../lua/type/boolean.html
.. _`tes3magicEffect`: ../../lua/type/tes3magicEffect.html
.. _`string`: ../../lua/type/string.html
.. _`tes3iteratorNode`: ../../lua/type/tes3iteratorNode.html
.. _`tes3fader`: ../../lua/type/tes3fader.html
.. _`tes3quest`: ../../lua/type/tes3quest.html
.. _`tes3nonDynamicData`: ../../lua/type/tes3nonDynamicData.html
.. _`tes3ingredient`: ../../lua/type/tes3ingredient.html
.. _`tes3gameSetting`: ../../lua/type/tes3gameSetting.html
.. _`table`: ../../lua/type/table.html
.. _`tes3mobileNPC`: ../../lua/type/tes3mobileNPC.html
.. _`tes3wearablePart`: ../../lua/type/tes3wearablePart.html
.. _`tes3vector3`: ../../lua/type/tes3vector3.html
.. _`tes3vector4`: ../../lua/type/tes3vector4.html
.. _`tes3vector2`: ../../lua/type/tes3vector2.html
.. _`tes3activator`: ../../lua/type/tes3activator.html
.. _`tes3travelDestinationNode`: ../../lua/type/tes3travelDestinationNode.html
.. _`tes3inventory`: ../../lua/type/tes3inventory.html
.. _`tes3boundingBox`: ../../lua/type/tes3boundingBox.html
.. _`tes3markData`: ../../lua/type/tes3markData.html
.. _`tes3transform`: ../../lua/type/tes3transform.html
.. _`tes3creatureInstance`: ../../lua/type/tes3creatureInstance.html
.. _`tes3effect`: ../../lua/type/tes3effect.html
.. _`tes3game`: ../../lua/type/tes3game.html
.. _`tes3soulGemData`: ../../lua/type/tes3soulGemData.html
.. _`tes3probe`: ../../lua/type/tes3probe.html
.. _`tes3object`: ../../lua/type/tes3object.html
.. _`tes3physicalObject`: ../../lua/type/tes3physicalObject.html
.. _`number`: ../../lua/type/number.html
.. _`nil`: ../../lua/type/nil.html
.. _`tes3mobilePlayer`: ../../lua/type/tes3mobilePlayer.html
.. _`tes3mobileObject`: ../../lua/type/tes3mobileObject.html
.. _`tes3misc`: ../../lua/type/tes3misc.html
.. _`tes3leveledListNode`: ../../lua/type/tes3leveledListNode.html
.. _`tes3mobileCreature`: ../../lua/type/tes3mobileCreature.html
.. _`tes3mobileActor`: ../../lua/type/tes3mobileActor.html
.. _`function`: ../../lua/type/function.html
.. _`tes3magicEffectInstance`: ../../lua/type/tes3magicEffectInstance.html
.. _`tes3baseObject`: ../../lua/type/tes3baseObject.html
.. _`tes3bodyPart`: ../../lua/type/tes3bodyPart.html
.. _`tes3factionRank`: ../../lua/type/tes3factionRank.html
.. _`mwseTimer`: ../../lua/type/mwseTimer.html
.. _`tes3container`: ../../lua/type/tes3container.html
.. _`tes3packedColor`: ../../lua/type/tes3packedColor.html
.. _`bool`: ../../lua/type/boolean.html
.. _`tes3equipmentStack`: ../../lua/type/tes3equipmentStack.html
.. _`tes3clothing`: ../../lua/type/tes3clothing.html
.. _`mwseTimerController`: ../../lua/type/mwseTimerController.html
.. _`tes3leveledCreature`: ../../lua/type/tes3leveledCreature.html
.. _`tes3lockNode`: ../../lua/type/tes3lockNode.html
.. _`tes3activeMagicEffect`: ../../lua/type/tes3activeMagicEffect.html
.. _`tes3cellExteriorData`: ../../lua/type/tes3cellExteriorData.html
.. _`tes3light`: ../../lua/type/tes3light.html
.. _`tes3leveledItem`: ../../lua/type/tes3leveledItem.html
.. _`tes3alchemy`: ../../lua/type/tes3alchemy.html
.. _`tes3enchantment`: ../../lua/type/tes3enchantment.html
.. _`tes3cell`: ../../lua/type/tes3cell.html
.. _`tes3actionData`: ../../lua/type/tes3actionData.html
.. _`tes3itemData`: ../../lua/type/tes3itemData.html
.. _`tes3factionReaction`: ../../lua/type/tes3factionReaction.html
