tes3reference
====================================================================================================

A reference is a sort of container structure for objects. It holds a base object, as well as various variables associated with that object that make it unique.

For example, many doors may share the same base object. However, each door reference might have a different owner, different lock/trap statuses, etc. that make the object unique.

Properties
----------------------------------------------------------------------------------------------------

`cell`_ (`tes3cell`_)
    The cell that the reference is currently in.

`deleted`_ (`boolean`_)
    The deleted state of the object.

`disabled`_ (`boolean`_)
    The disabled state of the object.

`id`_ (`string`_)
    The unique identifier for the object.

`modified`_ (`boolean`_)
    The modification state of the object since the last save.

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

`scale`_ (`number`_)
    The object's scale.

`sceneNode`_ (`niNode`_)
    The scene graph node for this object.

`sceneReference`_ (`niNode`_)
    The scene graph reference node for this object.

`sourceMod`_ (`string`_)
    The filename of the mod that owns this object.

.. toctree::
    :hidden:

    tes3reference/cell
    tes3reference/deleted
    tes3reference/disabled
    tes3reference/id
    tes3reference/modified
    tes3reference/nextInCollection
    tes3reference/objectFlags
    tes3reference/objectType
    tes3reference/owningCollection
    tes3reference/previousInCollection
    tes3reference/scale
    tes3reference/sceneNode
    tes3reference/sceneReference
    tes3reference/sourceMod

.. _`cell`: tes3reference/cell.html
.. _`deleted`: tes3reference/deleted.html
.. _`disabled`: tes3reference/disabled.html
.. _`id`: tes3reference/id.html
.. _`modified`: tes3reference/modified.html
.. _`nextInCollection`: tes3reference/nextInCollection.html
.. _`objectFlags`: tes3reference/objectFlags.html
.. _`objectType`: tes3reference/objectType.html
.. _`owningCollection`: tes3reference/owningCollection.html
.. _`previousInCollection`: tes3reference/previousInCollection.html
.. _`scale`: tes3reference/scale.html
.. _`sceneNode`: tes3reference/sceneNode.html
.. _`sceneReference`: tes3reference/sceneReference.html
.. _`sourceMod`: tes3reference/sourceMod.html

.. _`tes3bodyPart`: ../../lua/type/tes3bodyPart.html
.. _`string`: ../../lua/type/string.html
.. _`mwseTimer`: ../../lua/type/mwseTimer.html
.. _`tes3iteratorNode`: ../../lua/type/tes3iteratorNode.html
.. _`tes3fader`: ../../lua/type/tes3fader.html
.. _`tes3quest`: ../../lua/type/tes3quest.html
.. _`tes3book`: ../../lua/type/tes3book.html
.. _`tes3matrix33`: ../../lua/type/tes3matrix33.html
.. _`nil`: ../../lua/type/nil.html
.. _`tes3actor`: ../../lua/type/tes3actor.html
.. _`tes3clothing`: ../../lua/type/tes3clothing.html
.. _`tes3wearablePart`: ../../lua/type/tes3wearablePart.html
.. _`tes3vector4`: ../../lua/type/tes3vector4.html
.. _`tes3vector3`: ../../lua/type/tes3vector3.html
.. _`tes3vector2`: ../../lua/type/tes3vector2.html
.. _`tes3travelDestinationNode`: ../../lua/type/tes3travelDestinationNode.html
.. _`tes3activator`: ../../lua/type/tes3activator.html
.. _`tes3transform`: ../../lua/type/tes3transform.html
.. _`niAVObject`: ../../lua/type/niAVObject.html
.. _`tes3boundingBox`: ../../lua/type/tes3boundingBox.html
.. _`niObject`: ../../lua/type/niObject.html
.. _`tes3creature`: ../../lua/type/tes3creature.html
.. _`tes3creatureInstance`: ../../lua/type/tes3creatureInstance.html
.. _`tes3cell`: ../../lua/type/tes3cell.html
.. _`tes3class`: ../../lua/type/tes3class.html
.. _`tes3physicalObject`: ../../lua/type/tes3physicalObject.html
.. _`tes3factionReaction`: ../../lua/type/tes3factionReaction.html
.. _`tes3apparatus`: ../../lua/type/tes3apparatus.html
.. _`tes3door`: ../../lua/type/tes3door.html
.. _`number`: ../../lua/type/number.html
.. _`tes3object`: ../../lua/type/tes3object.html
.. _`tes3actionData`: ../../lua/type/tes3actionData.html
.. _`tes3nonDynamicData`: ../../lua/type/tes3nonDynamicData.html
.. _`niRTTI`: ../../lua/type/niRTTI.html
.. _`tes3lockNode`: ../../lua/type/tes3lockNode.html
.. _`tes3alchemy`: ../../lua/type/tes3alchemy.html
.. _`tes3iterator`: ../../lua/type/tes3iterator.html
.. _`function`: ../../lua/type/function.html
.. _`tes3gameSetting`: ../../lua/type/tes3gameSetting.html
.. _`tes3baseObject`: ../../lua/type/tes3baseObject.html
.. _`tes3armor`: ../../lua/type/tes3armor.html
.. _`tes3factionRank`: ../../lua/type/tes3factionRank.html
.. _`tes3reference`: ../../lua/type/tes3reference.html
.. _`tes3game`: ../../lua/type/tes3game.html
.. _`tes3packedColor`: ../../lua/type/tes3packedColor.html
.. _`bool`: ../../lua/type/boolean.html
.. _`tes3rangeInt`: ../../lua/type/tes3rangeInt.html
.. _`tes3dialogueInfo`: ../../lua/type/tes3dialogueInfo.html
.. _`mwseTimerController`: ../../lua/type/mwseTimerController.html
.. _`tes3containerInstance`: ../../lua/type/tes3containerInstance.html
.. _`tes3dialogue`: ../../lua/type/tes3dialogue.html
.. _`tes3dataHandler`: ../../lua/type/tes3dataHandler.html
.. _`tes3cellExteriorData`: ../../lua/type/tes3cellExteriorData.html
.. _`tes3gameFile`: ../../lua/type/tes3gameFile.html
.. _`tes3faction`: ../../lua/type/tes3faction.html
.. _`niObjectNET`: ../../lua/type/niObjectNET.html
.. _`tes3enchantment`: ../../lua/type/tes3enchantment.html
.. _`table`: ../../lua/type/table.html
.. _`tes3combatSession`: ../../lua/type/tes3combatSession.html
.. _`boolean`: ../../lua/type/boolean.html
.. _`tes3container`: ../../lua/type/tes3container.html
