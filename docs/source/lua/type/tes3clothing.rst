tes3clothing
====================================================================================================

A clothing game object.

Properties
----------------------------------------------------------------------------------------------------

`boundingBox`_ (`tes3boundingBox`_)
    The bounding box for the object.

`deleted`_ (`boolean`_)
    The deleted state of the object.

`disabled`_ (`boolean`_)
    The disabled state of the object.

`enchantCapacity`_ (`number`_)
    The object's enchantment capacity.

`enchantment`_ (`tes3enchantment`_)
    The enchantment used by the object.

`icon`_ (`string`_)
    The path to the object's icon.

`id`_ (`string`_)
    The unique identifier for the object.

`isLeftPart`_ (`boolean`_)
    Determines if the armor is the left part of a pair.

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

`owningCollection`_ (`tes3referenceList`_)
    The collection responsible for holding this object.

`parts`_ (`table`_)
    An array-style table of the tes3wearablePart data on the object.

`previousInCollection`_ (`tes3object`_)
    The previous object in parent collection's list.

`scale`_ (`number`_)
    The object's scale.

`sceneNode`_ (`niNode`_)
    The scene graph node for this object.

`sceneReference`_ (`niNode`_)
    The scene graph reference node for this object.

`script`_ (`tes3script`_)
    The script that runs on the object.

`slot`_ (`number`_)
    The slot used by the armor.

`slotName`_ (`string`_)
    The name of the slot used by the armor.

`sourceMod`_ (`string`_)
    The filename of the mod that owns this object.

`stolenList`_ (`tes3iterator`_)
    A list of actors that the object has been stolen from.

`value`_ (`number`_)
    The value of the object.

`weight`_ (`number`_)
    The weight, in pounds, of the object.

.. toctree::
    :hidden:

    tes3clothing/boundingBox
    tes3clothing/deleted
    tes3clothing/disabled
    tes3clothing/enchantCapacity
    tes3clothing/enchantment
    tes3clothing/icon
    tes3clothing/id
    tes3clothing/isLeftPart
    tes3clothing/mesh
    tes3clothing/modified
    tes3clothing/name
    tes3clothing/nextInCollection
    tes3clothing/objectFlags
    tes3clothing/objectType
    tes3clothing/owningCollection
    tes3clothing/parts
    tes3clothing/previousInCollection
    tes3clothing/scale
    tes3clothing/sceneNode
    tes3clothing/sceneReference
    tes3clothing/script
    tes3clothing/slot
    tes3clothing/slotName
    tes3clothing/sourceMod
    tes3clothing/stolenList
    tes3clothing/value
    tes3clothing/weight

.. _`boundingBox`: tes3clothing/boundingBox.html
.. _`deleted`: tes3clothing/deleted.html
.. _`disabled`: tes3clothing/disabled.html
.. _`enchantCapacity`: tes3clothing/enchantCapacity.html
.. _`enchantment`: tes3clothing/enchantment.html
.. _`icon`: tes3clothing/icon.html
.. _`id`: tes3clothing/id.html
.. _`isLeftPart`: tes3clothing/isLeftPart.html
.. _`mesh`: tes3clothing/mesh.html
.. _`modified`: tes3clothing/modified.html
.. _`name`: tes3clothing/name.html
.. _`nextInCollection`: tes3clothing/nextInCollection.html
.. _`objectFlags`: tes3clothing/objectFlags.html
.. _`objectType`: tes3clothing/objectType.html
.. _`owningCollection`: tes3clothing/owningCollection.html
.. _`parts`: tes3clothing/parts.html
.. _`previousInCollection`: tes3clothing/previousInCollection.html
.. _`scale`: tes3clothing/scale.html
.. _`sceneNode`: tes3clothing/sceneNode.html
.. _`sceneReference`: tes3clothing/sceneReference.html
.. _`script`: tes3clothing/script.html
.. _`slot`: tes3clothing/slot.html
.. _`slotName`: tes3clothing/slotName.html
.. _`sourceMod`: tes3clothing/sourceMod.html
.. _`stolenList`: tes3clothing/stolenList.html
.. _`value`: tes3clothing/value.html
.. _`weight`: tes3clothing/weight.html

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
