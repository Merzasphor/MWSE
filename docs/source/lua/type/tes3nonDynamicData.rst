tes3nonDynamicData
====================================================================================================

A child container from tes3dataHandler, where game data is stored.

Properties
----------------------------------------------------------------------------------------------------

`cells`_ (`tes3stlList`_)
    A collection of all cell objects.

`classes`_ (`tes3iterator`_)
    A collection of all class objects.

`dialogues`_ (`tes3iterator`_)
    A collection of all dialogue objects.

`factions`_ (`tes3iterator`_)
    A collection of all faction objects.

`globals`_ (`tes3iterator`_)
    A collection of all global variable objects.

`magicEffects`_ (`table`_)
    A table of references to all 143 magic effects.

`objects`_ (`tes3linkedList`_)
    A collection of all other game objects.

`races`_ (`tes3iterator`_)
    A collection of all race objects.

`regions`_ (`tes3iterator`_)
    A collection of all region objects.

`scripts`_ (`tes3iterator`_)
    A collection of all script objects.

`skills`_ (`table`_)
    A table of references to all 27 skills.

`soundGenerators`_ (`tes3iterator`_)
    A collection of all sound generator objects.

`sounds`_ (`tes3iterator`_)
    A collection of all sound objects.

`spells`_ (`tes3linkedList`_)
    A collection of all spell objects.

`startScripts`_ (`tes3iterator`_)
    A collection of all tes3startScript objects.

.. toctree::
    :hidden:

    tes3nonDynamicData/cells
    tes3nonDynamicData/classes
    tes3nonDynamicData/dialogues
    tes3nonDynamicData/factions
    tes3nonDynamicData/globals
    tes3nonDynamicData/magicEffects
    tes3nonDynamicData/objects
    tes3nonDynamicData/races
    tes3nonDynamicData/regions
    tes3nonDynamicData/scripts
    tes3nonDynamicData/skills
    tes3nonDynamicData/soundGenerators
    tes3nonDynamicData/sounds
    tes3nonDynamicData/spells
    tes3nonDynamicData/startScripts

.. _`cells`: tes3nonDynamicData/cells.html
.. _`classes`: tes3nonDynamicData/classes.html
.. _`dialogues`: tes3nonDynamicData/dialogues.html
.. _`factions`: tes3nonDynamicData/factions.html
.. _`globals`: tes3nonDynamicData/globals.html
.. _`magicEffects`: tes3nonDynamicData/magicEffects.html
.. _`objects`: tes3nonDynamicData/objects.html
.. _`races`: tes3nonDynamicData/races.html
.. _`regions`: tes3nonDynamicData/regions.html
.. _`scripts`: tes3nonDynamicData/scripts.html
.. _`skills`: tes3nonDynamicData/skills.html
.. _`soundGenerators`: tes3nonDynamicData/soundGenerators.html
.. _`sounds`: tes3nonDynamicData/sounds.html
.. _`spells`: tes3nonDynamicData/spells.html
.. _`startScripts`: tes3nonDynamicData/startScripts.html

Methods
----------------------------------------------------------------------------------------------------

`addNewObject`_ (`boolean`_)
    Inserts a newly created object into the proper collections.

`deleteObject`_
    Removes an object from the proper collections.

`findDialogue`_ (`tes3dialogue`_)
    Locates a dialogue for a given ID.

`findFirstCloneOfActor`_ (`tes3reference`_)
    Locates the first reference for a given object ID.

`findGlobalVariable`_ (`tes3globalVariable`_)
    Locates a global variable for a given ID.

`findScript`_ (`tes3script`_)
    Locates a script for a given ID.

`findSound`_ (`tes3sound`_)
    Locates a sound for a given ID.

`resolveObject`_ (`tes3baseObject`_)
    Locates a general object for a given ID.

.. toctree::
    :hidden:

    tes3nonDynamicData/addNewObject
    tes3nonDynamicData/deleteObject
    tes3nonDynamicData/findDialogue
    tes3nonDynamicData/findFirstCloneOfActor
    tes3nonDynamicData/findGlobalVariable
    tes3nonDynamicData/findScript
    tes3nonDynamicData/findSound
    tes3nonDynamicData/resolveObject

.. _`addNewObject`: tes3nonDynamicData/addNewObject.html
.. _`deleteObject`: tes3nonDynamicData/deleteObject.html
.. _`findDialogue`: tes3nonDynamicData/findDialogue.html
.. _`findFirstCloneOfActor`: tes3nonDynamicData/findFirstCloneOfActor.html
.. _`findGlobalVariable`: tes3nonDynamicData/findGlobalVariable.html
.. _`findScript`: tes3nonDynamicData/findScript.html
.. _`findSound`: tes3nonDynamicData/findSound.html
.. _`resolveObject`: tes3nonDynamicData/resolveObject.html

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
