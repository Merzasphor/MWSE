tes3dialogue
====================================================================================================

A parent-level dialogue, such as a topic, voice, greeting, persuasion response, or journal.

Properties
----------------------------------------------------------------------------------------------------

`deleted`_ (`boolean`_)
    The deleted state of the object.

`disabled`_ (`boolean`_)
    The disabled state of the object.

`id`_ (`string`_)
    The unique identifier for the object.

`info`_ (`tes3iterator`_)
    A collection of individual entries in the dialogue.

`journalIndex`_ (`number`_)
    For journal dialogues, the currently active journal index.

`modified`_ (`boolean`_)
    The modification state of the object since the last save.

`objectFlags`_ (`number`_)
    The raw flags of the object.

`objectType`_ (`number`_)
    The type of object. Maps to values in tes3.objectType.

`sourceMod`_ (`string`_)
    The filename of the mod that owns this object.

`type`_ (`number`_)
    The type of the dialogue.

.. toctree::
    :hidden:

    tes3dialogue/deleted
    tes3dialogue/disabled
    tes3dialogue/id
    tes3dialogue/info
    tes3dialogue/journalIndex
    tes3dialogue/modified
    tes3dialogue/objectFlags
    tes3dialogue/objectType
    tes3dialogue/sourceMod
    tes3dialogue/type

.. _`deleted`: tes3dialogue/deleted.html
.. _`disabled`: tes3dialogue/disabled.html
.. _`id`: tes3dialogue/id.html
.. _`info`: tes3dialogue/info.html
.. _`journalIndex`: tes3dialogue/journalIndex.html
.. _`modified`: tes3dialogue/modified.html
.. _`objectFlags`: tes3dialogue/objectFlags.html
.. _`objectType`: tes3dialogue/objectType.html
.. _`sourceMod`: tes3dialogue/sourceMod.html
.. _`type`: tes3dialogue/type.html

Methods
----------------------------------------------------------------------------------------------------

`addToJournal`_ (`boolean`_)
    Adds the dialogue to the player's journal, if applicable, at a given index.

`getInfo`_ (`tes3dialogueInfo`_)
    Fetches the info that a given actor would produce for the dialogue.

.. toctree::
    :hidden:

    tes3dialogue/addToJournal
    tes3dialogue/getInfo

.. _`addToJournal`: tes3dialogue/addToJournal.html
.. _`getInfo`: tes3dialogue/getInfo.html

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
