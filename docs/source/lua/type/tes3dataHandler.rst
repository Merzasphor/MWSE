tes3dataHandler
====================================================================================================

A core game object used for storing both active and non-dynamic gameplay data.

Properties
----------------------------------------------------------------------------------------------------

`backgroundThread`_ (`number`_)
    A Windows handle to the background processing thread.

`backgroundThreadId`_ (`number`_)
    The thread ID for the background processing thread.

`backgroundThreadRunning`_ (`boolean`_)
    Access to the running state for the background processing thread.

`cellChanged`_ (`boolean`_)
    A flag set for the frame that the player has changed cells.

`centralGridX`_ (`boolean`_)
    The position of the origin horizontal grid coordinate.

`centralGridY`_ (`boolean`_)
    The position of the origin longitudinal grid coordinate.

`currentCell`_ (`tes3cell`_)
    Access to the cell that the player is currently in.

`currentInteriorCell`_ (`tes3cell`_)
    Access to the current interior cell, if the player is in an interior.

`exteriorCells`_ (`table`_)
    A table of nine tes3cellExteriorData objects for any loaded exterior cells.

`lastExteriorCell`_ (`tes3cell`_)
    Access to the last visited exterior cell.

`mainThread`_ (`number`_)
    A Windows handle to the main execution thread.

`mainThreadId`_ (`number`_)
    The thread ID for the main execution thread.

`nonDynamicData`_ (`tes3nonDynamicData`_)
    A child structure where core game objects are held.

`threadSleepTime`_ (`number`_)
    No description available.

`worldObjectRoot`_ (`niNode`_)
    One of the core parent scene graph nodes.

`worldPickLandscapeRoot`_ (`niNode`_)
    One of the core parent scene graph nodes.

`worldPickObjectRoot`_ (`niNode`_)
    One of the core parent scene graph nodes.

.. toctree::
    :hidden:

    tes3dataHandler/backgroundThread
    tes3dataHandler/backgroundThreadId
    tes3dataHandler/backgroundThreadRunning
    tes3dataHandler/cellChanged
    tes3dataHandler/centralGridX
    tes3dataHandler/centralGridY
    tes3dataHandler/currentCell
    tes3dataHandler/currentInteriorCell
    tes3dataHandler/exteriorCells
    tes3dataHandler/lastExteriorCell
    tes3dataHandler/mainThread
    tes3dataHandler/mainThreadId
    tes3dataHandler/nonDynamicData
    tes3dataHandler/threadSleepTime
    tes3dataHandler/worldObjectRoot
    tes3dataHandler/worldPickLandscapeRoot
    tes3dataHandler/worldPickObjectRoot

.. _`backgroundThread`: tes3dataHandler/backgroundThread.html
.. _`backgroundThreadId`: tes3dataHandler/backgroundThreadId.html
.. _`backgroundThreadRunning`: tes3dataHandler/backgroundThreadRunning.html
.. _`cellChanged`: tes3dataHandler/cellChanged.html
.. _`centralGridX`: tes3dataHandler/centralGridX.html
.. _`centralGridY`: tes3dataHandler/centralGridY.html
.. _`currentCell`: tes3dataHandler/currentCell.html
.. _`currentInteriorCell`: tes3dataHandler/currentInteriorCell.html
.. _`exteriorCells`: tes3dataHandler/exteriorCells.html
.. _`lastExteriorCell`: tes3dataHandler/lastExteriorCell.html
.. _`mainThread`: tes3dataHandler/mainThread.html
.. _`mainThreadId`: tes3dataHandler/mainThreadId.html
.. _`nonDynamicData`: tes3dataHandler/nonDynamicData.html
.. _`threadSleepTime`: tes3dataHandler/threadSleepTime.html
.. _`worldObjectRoot`: tes3dataHandler/worldObjectRoot.html
.. _`worldPickLandscapeRoot`: tes3dataHandler/worldPickLandscapeRoot.html
.. _`worldPickObjectRoot`: tes3dataHandler/worldPickObjectRoot.html

.. _`tes3creature`: ../../lua/type/tes3creature.html
.. _`niObject`: ../../lua/type/niObject.html
.. _`tes3book`: ../../lua/type/tes3book.html
.. _`tes3matrix33`: ../../lua/type/tes3matrix33.html
.. _`tes3actor`: ../../lua/type/tes3actor.html
.. _`tes3inputConfig`: ../../lua/type/tes3inputConfig.html
.. _`tes3itemStack`: ../../lua/type/tes3itemStack.html
.. _`tes3globalVariable`: ../../lua/type/tes3globalVariable.html
.. _`tes3containerInstance`: ../../lua/type/tes3containerInstance.html
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
.. _`tes3combatSession`: ../../lua/type/tes3combatSession.html
.. _`boolean`: ../../lua/type/boolean.html
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
.. _`tes3creatureInstance`: ../../lua/type/tes3creatureInstance.html
.. _`tes3cell`: ../../lua/type/tes3cell.html
.. _`tes3game`: ../../lua/type/tes3game.html
.. _`tes3object`: ../../lua/type/tes3object.html
.. _`number`: ../../lua/type/number.html
.. _`tes3wearablePart`: ../../lua/type/tes3wearablePart.html
.. _`function`: ../../lua/type/function.html
.. _`tes3vector4`: ../../lua/type/tes3vector4.html
.. _`tes3baseObject`: ../../lua/type/tes3baseObject.html
.. _`tes3vector2`: ../../lua/type/tes3vector2.html
.. _`tes3factionRank`: ../../lua/type/tes3factionRank.html
.. _`tes3travelDestinationNode`: ../../lua/type/tes3travelDestinationNode.html
.. _`tes3transform`: ../../lua/type/tes3transform.html
.. _`tes3packedColor`: ../../lua/type/tes3packedColor.html
.. _`bool`: ../../lua/type/boolean.html
.. _`tes3equipmentStack`: ../../lua/type/tes3equipmentStack.html
.. _`tes3bodyPart`: ../../lua/type/tes3bodyPart.html
.. _`mwseTimerController`: ../../lua/type/mwseTimerController.html
.. _`mwseTimer`: ../../lua/type/mwseTimer.html
.. _`tes3factionReaction`: ../../lua/type/tes3factionReaction.html
.. _`nil`: ../../lua/type/nil.html
.. _`tes3cellExteriorData`: ../../lua/type/tes3cellExteriorData.html
.. _`tes3clothing`: ../../lua/type/tes3clothing.html
.. _`tes3physicalObject`: ../../lua/type/tes3physicalObject.html
.. _`tes3lockNode`: ../../lua/type/tes3lockNode.html
.. _`tes3enchantment`: ../../lua/type/tes3enchantment.html
.. _`tes3itemData`: ../../lua/type/tes3itemData.html
.. _`tes3actionData`: ../../lua/type/tes3actionData.html
.. _`tes3container`: ../../lua/type/tes3container.html
.. _`tes3alchemy`: ../../lua/type/tes3alchemy.html
