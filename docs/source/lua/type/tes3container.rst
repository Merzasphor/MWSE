tes3container
====================================================================================================

A container object that has not been cloned. Typically represents the raw information edited in the construction set.

Properties
----------------------------------------------------------------------------------------------------

`actorFlags`_ (`number`_)
    A number representing the actor flags. Truly a bit field.

`barterGold`_ (`number`_)
    The amount of gold that the actor has to trade with.

`boundingBox`_ (`tes3boundingBox`_)
    The bounding box for the object.

`capacity`_ (`number`_)
    The amount of weight, in pounds, that the container can hold.

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

`isInstance`_ (`boolean`_)
    Always returns false.

`mesh`_ (`string`_)
    The path to the object's mesh.

`modified`_ (`boolean`_)
    The modification state of the object since the last save.

`name`_ (`string`_)
    The player-facing name for the object.

`nextInCollection`_ (`tes3object`_)
    The next object in parent collection's list.

`objectFlags`_ (`number`_)
    The raw flags of the object.

`objectType`_ (`number`_)
    The type of object. Maps to values in tes3.objectType.

`organic`_ (`boolean`_)
    Determines if the container's organic flag is enabled.

`owningCollection`_ (`tes3referenceList`_)
    The collection responsible for holding this object.

`previousInCollection`_ (`tes3object`_)
    The previous object in parent collection's list.

`respawns`_ (`boolean`_)
    Determines if the container's respawn flag is enabled.

`scale`_ (`number`_)
    The object's scale.

`sceneNode`_ (`niNode`_)
    The scene graph node for this object.

`sceneReference`_ (`niNode`_)
    The scene graph reference node for this object.

`script`_ (`tes3script`_)
    The script that runs on the object.

`sourceMod`_ (`string`_)
    The filename of the mod that owns this object.

`stolenList`_ (`tes3iterator`_)
    A list of actors that the object has been stolen from.

.. toctree::
    :hidden:

    tes3container/actorFlags
    tes3container/barterGold
    tes3container/boundingBox
    tes3container/capacity
    tes3container/cloneCount
    tes3container/deleted
    tes3container/disabled
    tes3container/equipment
    tes3container/id
    tes3container/inventory
    tes3container/isInstance
    tes3container/mesh
    tes3container/modified
    tes3container/name
    tes3container/nextInCollection
    tes3container/objectFlags
    tes3container/objectType
    tes3container/organic
    tes3container/owningCollection
    tes3container/previousInCollection
    tes3container/respawns
    tes3container/scale
    tes3container/sceneNode
    tes3container/sceneReference
    tes3container/script
    tes3container/sourceMod
    tes3container/stolenList

.. _`actorFlags`: tes3container/actorFlags.html
.. _`barterGold`: tes3container/barterGold.html
.. _`boundingBox`: tes3container/boundingBox.html
.. _`capacity`: tes3container/capacity.html
.. _`cloneCount`: tes3container/cloneCount.html
.. _`deleted`: tes3container/deleted.html
.. _`disabled`: tes3container/disabled.html
.. _`equipment`: tes3container/equipment.html
.. _`id`: tes3container/id.html
.. _`inventory`: tes3container/inventory.html
.. _`isInstance`: tes3container/isInstance.html
.. _`mesh`: tes3container/mesh.html
.. _`modified`: tes3container/modified.html
.. _`name`: tes3container/name.html
.. _`nextInCollection`: tes3container/nextInCollection.html
.. _`objectFlags`: tes3container/objectFlags.html
.. _`objectType`: tes3container/objectType.html
.. _`organic`: tes3container/organic.html
.. _`owningCollection`: tes3container/owningCollection.html
.. _`previousInCollection`: tes3container/previousInCollection.html
.. _`respawns`: tes3container/respawns.html
.. _`scale`: tes3container/scale.html
.. _`sceneNode`: tes3container/sceneNode.html
.. _`sceneReference`: tes3container/sceneReference.html
.. _`script`: tes3container/script.html
.. _`sourceMod`: tes3container/sourceMod.html
.. _`stolenList`: tes3container/stolenList.html

Methods
----------------------------------------------------------------------------------------------------

`onInventoryClose`_
    A callback function invoked when an inventory is closed. Typically not used outside of specific purposes.

.. toctree::
    :hidden:

    tes3container/onInventoryClose

.. _`onInventoryClose`: tes3container/onInventoryClose.html

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
.. _`tes3vector3`: ../../lua/type/tes3vector3.html
.. _`tes3activator`: ../../lua/type/tes3activator.html
.. _`tes3inventory`: ../../lua/type/tes3inventory.html
.. _`tes3boundingBox`: ../../lua/type/tes3boundingBox.html
.. _`tes3wearablePart`: ../../lua/type/tes3wearablePart.html
.. _`tes3creatureInstance`: ../../lua/type/tes3creatureInstance.html
.. _`tes3effect`: ../../lua/type/tes3effect.html
.. _`tes3game`: ../../lua/type/tes3game.html
.. _`tes3vector4`: ../../lua/type/tes3vector4.html
.. _`tes3vector2`: ../../lua/type/tes3vector2.html
.. _`tes3object`: ../../lua/type/tes3object.html
.. _`tes3travelDestinationNode`: ../../lua/type/tes3travelDestinationNode.html
.. _`number`: ../../lua/type/number.html
.. _`tes3transform`: ../../lua/type/tes3transform.html
.. _`tes3soulGemData`: ../../lua/type/tes3soulGemData.html
.. _`tes3probe`: ../../lua/type/tes3probe.html
.. _`tes3misc`: ../../lua/type/tes3misc.html
.. _`tes3leveledListNode`: ../../lua/type/tes3leveledListNode.html
.. _`tes3physicalObject`: ../../lua/type/tes3physicalObject.html
.. _`nil`: ../../lua/type/nil.html
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
