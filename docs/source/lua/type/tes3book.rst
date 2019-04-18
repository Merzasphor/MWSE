tes3book
====================================================================================================

A book game object.

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

`skill`_ (`number`_)
    The skill learned from the book, or -1 if the book doesn't have one, or has already been read.

`sourceMod`_ (`string`_)
    The filename of the mod that owns this object.

`stolenList`_ (`tes3iterator`_)
    A list of actors that the object has been stolen from.

`text`_ (`string`_)
    Loads and displays the text of the book.

`type`_ (`number`_)
    The book type, where 0 is book and 1 is scroll.

`value`_ (`number`_)
    The value of the object.

`weight`_ (`number`_)
    The weight, in pounds, of the object.

.. toctree::
    :hidden:

    tes3book/boundingBox
    tes3book/deleted
    tes3book/disabled
    tes3book/enchantCapacity
    tes3book/enchantment
    tes3book/icon
    tes3book/id
    tes3book/mesh
    tes3book/modified
    tes3book/name
    tes3book/nextInCollection
    tes3book/objectFlags
    tes3book/objectType
    tes3book/owningCollection
    tes3book/previousInCollection
    tes3book/scale
    tes3book/sceneNode
    tes3book/sceneReference
    tes3book/script
    tes3book/skill
    tes3book/sourceMod
    tes3book/stolenList
    tes3book/text
    tes3book/type
    tes3book/value
    tes3book/weight

.. _`boundingBox`: tes3book/boundingBox.html
.. _`deleted`: tes3book/deleted.html
.. _`disabled`: tes3book/disabled.html
.. _`enchantCapacity`: tes3book/enchantCapacity.html
.. _`enchantment`: tes3book/enchantment.html
.. _`icon`: tes3book/icon.html
.. _`id`: tes3book/id.html
.. _`mesh`: tes3book/mesh.html
.. _`modified`: tes3book/modified.html
.. _`name`: tes3book/name.html
.. _`nextInCollection`: tes3book/nextInCollection.html
.. _`objectFlags`: tes3book/objectFlags.html
.. _`objectType`: tes3book/objectType.html
.. _`owningCollection`: tes3book/owningCollection.html
.. _`previousInCollection`: tes3book/previousInCollection.html
.. _`scale`: tes3book/scale.html
.. _`sceneNode`: tes3book/sceneNode.html
.. _`sceneReference`: tes3book/sceneReference.html
.. _`script`: tes3book/script.html
.. _`skill`: tes3book/skill.html
.. _`sourceMod`: tes3book/sourceMod.html
.. _`stolenList`: tes3book/stolenList.html
.. _`text`: tes3book/text.html
.. _`type`: tes3book/type.html
.. _`value`: tes3book/value.html
.. _`weight`: tes3book/weight.html

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
