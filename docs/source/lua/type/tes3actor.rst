tes3actor
====================================================================================================

An Actor (not to be confused with a Mobile Actor) is an object that can be cloned and that has an inventory. Creatures, NPCs, and containers are all considered actors.

It is standard for creatures and NPCs to be composed of an actor and a mobile actor, linked together with a reference.

Properties
----------------------------------------------------------------------------------------------------

`actorFlags`_ (`number`_)
    A number representing the actor flags. Truly a bit field.

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

`stolenList`_ (`tes3iterator`_)
    A list of actors that the object has been stolen from.

.. toctree::
    :hidden:

    tes3actor/actorFlags
    tes3actor/barterGold
    tes3actor/boundingBox
    tes3actor/cloneCount
    tes3actor/deleted
    tes3actor/disabled
    tes3actor/equipment
    tes3actor/id
    tes3actor/inventory
    tes3actor/modified
    tes3actor/nextInCollection
    tes3actor/objectFlags
    tes3actor/objectType
    tes3actor/owningCollection
    tes3actor/previousInCollection
    tes3actor/scale
    tes3actor/sceneNode
    tes3actor/sceneReference
    tes3actor/sourceMod
    tes3actor/stolenList

.. _`actorFlags`: tes3actor/actorFlags.html
.. _`barterGold`: tes3actor/barterGold.html
.. _`boundingBox`: tes3actor/boundingBox.html
.. _`cloneCount`: tes3actor/cloneCount.html
.. _`deleted`: tes3actor/deleted.html
.. _`disabled`: tes3actor/disabled.html
.. _`equipment`: tes3actor/equipment.html
.. _`id`: tes3actor/id.html
.. _`inventory`: tes3actor/inventory.html
.. _`modified`: tes3actor/modified.html
.. _`nextInCollection`: tes3actor/nextInCollection.html
.. _`objectFlags`: tes3actor/objectFlags.html
.. _`objectType`: tes3actor/objectType.html
.. _`owningCollection`: tes3actor/owningCollection.html
.. _`previousInCollection`: tes3actor/previousInCollection.html
.. _`scale`: tes3actor/scale.html
.. _`sceneNode`: tes3actor/sceneNode.html
.. _`sceneReference`: tes3actor/sceneReference.html
.. _`sourceMod`: tes3actor/sourceMod.html
.. _`stolenList`: tes3actor/stolenList.html

Methods
----------------------------------------------------------------------------------------------------

`onInventoryClose`_
    A callback function invoked when an inventory is closed. Typically not used outside of specific purposes.

.. toctree::
    :hidden:

    tes3actor/onInventoryClose

.. _`onInventoryClose`: tes3actor/onInventoryClose.html

.. _`tes3bodyPart`: ../../lua/type/tes3bodyPart.html
.. _`string`: ../../lua/type/string.html
.. _`mwseTimer`: ../../lua/type/mwseTimer.html
.. _`tes3book`: ../../lua/type/tes3book.html
.. _`tes3matrix33`: ../../lua/type/tes3matrix33.html
.. _`nil`: ../../lua/type/nil.html
.. _`tes3actor`: ../../lua/type/tes3actor.html
.. _`tes3clothing`: ../../lua/type/tes3clothing.html
.. _`tes3vector3`: ../../lua/type/tes3vector3.html
.. _`tes3activator`: ../../lua/type/tes3activator.html
.. _`niAVObject`: ../../lua/type/niAVObject.html
.. _`tes3boundingBox`: ../../lua/type/tes3boundingBox.html
.. _`tes3lockNode`: ../../lua/type/tes3lockNode.html
.. _`tes3cell`: ../../lua/type/tes3cell.html
.. _`tes3class`: ../../lua/type/tes3class.html
.. _`tes3apparatus`: ../../lua/type/tes3apparatus.html
.. _`number`: ../../lua/type/number.html
.. _`tes3actionData`: ../../lua/type/tes3actionData.html
.. _`niRTTI`: ../../lua/type/niRTTI.html
.. _`niObjectNET`: ../../lua/type/niObjectNET.html
.. _`function`: ../../lua/type/function.html
.. _`tes3baseObject`: ../../lua/type/tes3baseObject.html
.. _`tes3armor`: ../../lua/type/tes3armor.html
.. _`tes3reference`: ../../lua/type/tes3reference.html
.. _`tes3packedColor`: ../../lua/type/tes3packedColor.html
.. _`bool`: ../../lua/type/boolean.html
.. _`tes3rangeInt`: ../../lua/type/tes3rangeInt.html
.. _`mwseTimerController`: ../../lua/type/mwseTimerController.html
.. _`tes3wearablePart`: ../../lua/type/tes3wearablePart.html
.. _`tes3vector4`: ../../lua/type/tes3vector4.html
.. _`tes3vector2`: ../../lua/type/tes3vector2.html
.. _`tes3cellExteriorData`: ../../lua/type/tes3cellExteriorData.html
.. _`tes3travelDestinationNode`: ../../lua/type/tes3travelDestinationNode.html
.. _`tes3transform`: ../../lua/type/tes3transform.html
.. _`niObject`: ../../lua/type/niObject.html
.. _`tes3physicalObject`: ../../lua/type/tes3physicalObject.html
.. _`tes3alchemy`: ../../lua/type/tes3alchemy.html
.. _`table`: ../../lua/type/table.html
.. _`boolean`: ../../lua/type/boolean.html
.. _`tes3object`: ../../lua/type/tes3object.html
