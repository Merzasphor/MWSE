tes3repairTool
====================================================================================================

A core repair tool object.

Properties
----------------------------------------------------------------------------------------------------

`blocked`_ (`boolean`_)
    The blocked state of the object.

`boundingBox`_ (`tes3boundingBox`_)
    The bounding box for the object.

`deleted`_ (`boolean`_)
    Read-only. The deleted state of the object.

`disabled`_ (`boolean`_)
    Read-only. The disabled state of the object.

`icon`_ (`string`_)
    The path to the object's icon.

`id`_ (`string`_)
    Read-only. The unique identifier for the object.

`maxCondition`_ (`number`_)
    The maximum condition/health of the object.

`mesh`_ (`string`_)
    The path to the object's mesh.

`modified`_ (`boolean`_)
    The modification state of the object since the last save.

`name`_ (`string`_)
    The player-facing name for the object.

`nextInCollection`_ (`tes3object`_)
    The next object in parent collection's list.

`objectFlags`_ (`number`_)
    Read-only. The raw flags of the object.

`objectType`_ (`number`_)
    Read-only. The type of object. Maps to values in tes3.objectType.

`owningCollection`_ (`tes3referenceList`_)
    The collection responsible for holding this object.

`persistent`_ (`boolean`_)
    The persistent flag of the object.

`previousInCollection`_ (`tes3object`_)
    The previous object in parent collection's list.

`quality`_ (`number`_)
    The quality of the object, with how much of a bonus it has.

`scale`_ (`number`_)
    The object's scale.

`sceneNode`_ (`niNode`_)
    The scene graph node for this object.

`sceneReference`_ (`niNode`_)
    The scene graph reference node for this object.

`script`_ (`tes3script`_)
    Read-only. The script that runs on the object.

`sourceMod`_ (`string`_)
    Read-only. The filename of the mod that owns this object.

`sourceless`_ (`boolean`_)
    The soruceless flag of the object.

`stolenList`_ (`tes3iterator`_)
    A list of actors that the object has been stolen from.

`supportsLuaData`_ (`boolean`_)
    If true, references of this object can store temporary or persistent lua data.

`value`_ (`number`_)
    The value of the object.

`weight`_ (`number`_)
    The weight of the object.

.. toctree::
    :hidden:

    tes3repairTool/blocked
    tes3repairTool/boundingBox
    tes3repairTool/deleted
    tes3repairTool/disabled
    tes3repairTool/icon
    tes3repairTool/id
    tes3repairTool/maxCondition
    tes3repairTool/mesh
    tes3repairTool/modified
    tes3repairTool/name
    tes3repairTool/nextInCollection
    tes3repairTool/objectFlags
    tes3repairTool/objectType
    tes3repairTool/owningCollection
    tes3repairTool/persistent
    tes3repairTool/previousInCollection
    tes3repairTool/quality
    tes3repairTool/scale
    tes3repairTool/sceneNode
    tes3repairTool/sceneReference
    tes3repairTool/script
    tes3repairTool/sourceMod
    tes3repairTool/sourceless
    tes3repairTool/stolenList
    tes3repairTool/supportsLuaData
    tes3repairTool/value
    tes3repairTool/weight

.. _`blocked`: tes3repairTool/blocked.html
.. _`boundingBox`: tes3repairTool/boundingBox.html
.. _`deleted`: tes3repairTool/deleted.html
.. _`disabled`: tes3repairTool/disabled.html
.. _`icon`: tes3repairTool/icon.html
.. _`id`: tes3repairTool/id.html
.. _`maxCondition`: tes3repairTool/maxCondition.html
.. _`mesh`: tes3repairTool/mesh.html
.. _`modified`: tes3repairTool/modified.html
.. _`name`: tes3repairTool/name.html
.. _`nextInCollection`: tes3repairTool/nextInCollection.html
.. _`objectFlags`: tes3repairTool/objectFlags.html
.. _`objectType`: tes3repairTool/objectType.html
.. _`owningCollection`: tes3repairTool/owningCollection.html
.. _`persistent`: tes3repairTool/persistent.html
.. _`previousInCollection`: tes3repairTool/previousInCollection.html
.. _`quality`: tes3repairTool/quality.html
.. _`scale`: tes3repairTool/scale.html
.. _`sceneNode`: tes3repairTool/sceneNode.html
.. _`sceneReference`: tes3repairTool/sceneReference.html
.. _`script`: tes3repairTool/script.html
.. _`sourceMod`: tes3repairTool/sourceMod.html
.. _`sourceless`: tes3repairTool/sourceless.html
.. _`stolenList`: tes3repairTool/stolenList.html
.. _`supportsLuaData`: tes3repairTool/supportsLuaData.html
.. _`value`: tes3repairTool/value.html
.. _`weight`: tes3repairTool/weight.html

Methods
----------------------------------------------------------------------------------------------------

`__tojson`_ (`string`_)
    Serializes the object to json.

.. toctree::
    :hidden:

    tes3repairTool/__tojson

.. _`__tojson`: tes3repairTool/__tojson.html

.. _`boolean`: ../../lua/type/boolean.html
.. _`niNode`: ../../lua/type/niNode.html
.. _`number`: ../../lua/type/number.html
.. _`string`: ../../lua/type/string.html
.. _`tes3boundingBox`: ../../lua/type/tes3boundingBox.html
.. _`tes3iterator`: ../../lua/type/tes3iterator.html
.. _`tes3object`: ../../lua/type/tes3object.html
.. _`tes3referenceList`: ../../lua/type/tes3referenceList.html
