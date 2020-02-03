tes3cell
====================================================================================================

An exterior or interior game area.

Properties
----------------------------------------------------------------------------------------------------

`activators`_ (`tes3referenceList`_)
    One of the three reference collections for a cell.

`actors`_ (`tes3referenceList`_)
    One of the three reference collections for a cell.

`ambientColor`_ (`tes3packedColor`_)
    The cell's ambient color. Only available on interior cells.

`behavesAsExterior`_ (`boolean`_)
    If true, the cell behaves as an exterior instead of an interior for certain properties. Only available on interior cells.

`cellFlags`_ (`number`_)
    A numeric representation of the packed bit flags for the cell, typically accessed from other properties.

`deleted`_ (`boolean`_)
    The deleted state of the object.

`disabled`_ (`boolean`_)
    The disabled state of the object.

`fogColor`_ (`tes3packedColor`_)
    The cell's fog color. Only available on interior cells.

`fogDensity`_ (`number`_)
    The cell's fog density. Only available on interior cells.

`gridX`_ (`number`_)
    The cell's X grid coordinate. Only available on exterior cells.

`gridY`_ (`number`_)
    The cell's Y grid coordinate. Only available on exterior cells.

`hasWater`_ (`boolean`_)
    If true, the cell has water. Only applies to interior cells.

`id`_ (`string`_)
    The unique identifier for the object.

`isInterior`_ (`boolean`_)
    If true, the cell is an interior.

`modified`_ (`boolean`_)
    The modification state of the object since the last save.

`name`_ (`string`_)
    The name and id of the cell.

`objectFlags`_ (`number`_)
    The raw flags of the object.

`objectType`_ (`number`_)
    The type of object. Maps to values in tes3.objectType.

`region`_ (`tes3region`_)
    The region associated with the cell. Only available on exterior cells, or interior cells that behave as exterior cells.

`restingIsIllegal`_ (`boolean`_)
    If true, the player may not rest in the cell.

`sourceMod`_ (`string`_)
    The filename of the mod that owns this object.

`statics`_ (`tes3referenceList`_)
    One of the three reference collections for a cell.

`sunColor`_ (`tes3packedColor`_)
    The cell's sun color. Only available on interior cells.

`waterLevel`_ (`number`_)
    The water level in the cell. Only available on interior cells.

.. toctree::
    :hidden:

    tes3cell/activators
    tes3cell/actors
    tes3cell/ambientColor
    tes3cell/behavesAsExterior
    tes3cell/cellFlags
    tes3cell/deleted
    tes3cell/disabled
    tes3cell/fogColor
    tes3cell/fogDensity
    tes3cell/gridX
    tes3cell/gridY
    tes3cell/hasWater
    tes3cell/id
    tes3cell/isInterior
    tes3cell/modified
    tes3cell/name
    tes3cell/objectFlags
    tes3cell/objectType
    tes3cell/region
    tes3cell/restingIsIllegal
    tes3cell/sourceMod
    tes3cell/statics
    tes3cell/sunColor
    tes3cell/waterLevel

.. _`activators`: tes3cell/activators.html
.. _`actors`: tes3cell/actors.html
.. _`ambientColor`: tes3cell/ambientColor.html
.. _`behavesAsExterior`: tes3cell/behavesAsExterior.html
.. _`cellFlags`: tes3cell/cellFlags.html
.. _`deleted`: tes3cell/deleted.html
.. _`disabled`: tes3cell/disabled.html
.. _`fogColor`: tes3cell/fogColor.html
.. _`fogDensity`: tes3cell/fogDensity.html
.. _`gridX`: tes3cell/gridX.html
.. _`gridY`: tes3cell/gridY.html
.. _`hasWater`: tes3cell/hasWater.html
.. _`id`: tes3cell/id.html
.. _`isInterior`: tes3cell/isInterior.html
.. _`modified`: tes3cell/modified.html
.. _`name`: tes3cell/name.html
.. _`objectFlags`: tes3cell/objectFlags.html
.. _`objectType`: tes3cell/objectType.html
.. _`region`: tes3cell/region.html
.. _`restingIsIllegal`: tes3cell/restingIsIllegal.html
.. _`sourceMod`: tes3cell/sourceMod.html
.. _`statics`: tes3cell/statics.html
.. _`sunColor`: tes3cell/sunColor.html
.. _`waterLevel`: tes3cell/waterLevel.html

Methods
----------------------------------------------------------------------------------------------------

`iterateReferences`_
    Used in a for loop, iterates over objects in the cell.

.. toctree::
    :hidden:

    tes3cell/iterateReferences

.. _`iterateReferences`: tes3cell/iterateReferences.html

.. _`tes3creature`: ../../lua/type/tes3creature.html
.. _`niObject`: ../../lua/type/niObject.html
.. _`tes3npc`: ../../lua/type/tes3npc.html
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
.. _`tes3raceHeightWeight`: ../../lua/type/tes3raceHeightWeight.html
.. _`tes3class`: ../../lua/type/tes3class.html
.. _`tes3mobileProjectile`: ../../lua/type/tes3mobileProjectile.html
.. _`tes3apparatus`: ../../lua/type/tes3apparatus.html
.. _`tes3door`: ../../lua/type/tes3door.html
.. _`tes3directInputMouseState`: ../../lua/type/tes3directInputMouseState.html
.. _`niRTTI`: ../../lua/type/niRTTI.html
.. _`tes3weatherThunder`: ../../lua/type/tes3weatherThunder.html
.. _`niObjectNET`: ../../lua/type/niObjectNET.html
.. _`tes3weatherSnow`: ../../lua/type/tes3weatherSnow.html
.. _`tes3weatherRain`: ../../lua/type/tes3weatherRain.html
.. _`tes3light`: ../../lua/type/tes3light.html
.. _`tes3clothing`: ../../lua/type/tes3clothing.html
.. _`tes3armor`: ../../lua/type/tes3armor.html
.. _`tes3weatherController`: ../../lua/type/tes3weatherController.html
.. _`tes3npcInstance`: ../../lua/type/tes3npcInstance.html
.. _`tes3mobilePlayer`: ../../lua/type/tes3mobilePlayer.html
.. _`nil`: ../../lua/type/nil.html
.. _`tes3dataHandler`: ../../lua/type/tes3dataHandler.html
.. _`tes3rangeInt`: ../../lua/type/tes3rangeInt.html
.. _`tes3dialogueInfo`: ../../lua/type/tes3dialogueInfo.html
.. _`tes3weatherBlizzard`: ../../lua/type/tes3weatherBlizzard.html
.. _`tes3weatherAsh`: ../../lua/type/tes3weatherAsh.html
.. _`tes3container`: ../../lua/type/tes3container.html
.. _`tes3weather`: ../../lua/type/tes3weather.html
.. _`tes3dialogue`: ../../lua/type/tes3dialogue.html
.. _`tes3gameFile`: ../../lua/type/tes3gameFile.html
.. _`tes3faction`: ../../lua/type/tes3faction.html
.. _`tes3wearablePart`: ../../lua/type/tes3wearablePart.html
.. _`tes3inputController`: ../../lua/type/tes3inputController.html
.. _`tes3lockpick`: ../../lua/type/tes3lockpick.html
.. _`tes3combatSession`: ../../lua/type/tes3combatSession.html
.. _`boolean`: ../../lua/type/boolean.html
.. _`tes3vector4`: ../../lua/type/tes3vector4.html
.. _`tes3magicEffect`: ../../lua/type/tes3magicEffect.html
.. _`string`: ../../lua/type/string.html
.. _`tes3referenceList`: ../../lua/type/tes3referenceList.html
.. _`tes3iteratorNode`: ../../lua/type/tes3iteratorNode.html
.. _`tes3fader`: ../../lua/type/tes3fader.html
.. _`tes3quest`: ../../lua/type/tes3quest.html
.. _`tes3nonDynamicData`: ../../lua/type/tes3nonDynamicData.html
.. _`tes3ingredient`: ../../lua/type/tes3ingredient.html
.. _`tes3race`: ../../lua/type/tes3race.html
.. _`tes3gameSetting`: ../../lua/type/tes3gameSetting.html
.. _`tes3vector2`: ../../lua/type/tes3vector2.html
.. _`table`: ../../lua/type/table.html
.. _`tes3travelDestinationNode`: ../../lua/type/tes3travelDestinationNode.html
.. _`tes3transform`: ../../lua/type/tes3transform.html
.. _`tes3mobileNPC`: ../../lua/type/tes3mobileNPC.html
.. _`tes3soulGemData`: ../../lua/type/tes3soulGemData.html
.. _`tes3vector3`: ../../lua/type/tes3vector3.html
.. _`tes3reference`: ../../lua/type/tes3reference.html
.. _`tes3raceSkillBonus`: ../../lua/type/tes3raceSkillBonus.html
.. _`tes3activator`: ../../lua/type/tes3activator.html
.. _`tes3raceBodyParts`: ../../lua/type/tes3raceBodyParts.html
.. _`tes3inventory`: ../../lua/type/tes3inventory.html
.. _`tes3boundingBox`: ../../lua/type/tes3boundingBox.html
.. _`tes3markData`: ../../lua/type/tes3markData.html
.. _`tes3raceBaseAttribute`: ../../lua/type/tes3raceBaseAttribute.html
.. _`tes3creatureInstance`: ../../lua/type/tes3creatureInstance.html
.. _`tes3effect`: ../../lua/type/tes3effect.html
.. _`tes3game`: ../../lua/type/tes3game.html
.. _`tes3probe`: ../../lua/type/tes3probe.html
.. _`tes3physicalObject`: ../../lua/type/tes3physicalObject.html
.. _`tes3object`: ../../lua/type/tes3object.html
.. _`tes3weatherClear`: ../../lua/type/tes3weatherClear.html
.. _`number`: ../../lua/type/number.html
.. _`tes3moon`: ../../lua/type/tes3moon.html
.. _`tes3weatherCloudy`: ../../lua/type/tes3weatherCloudy.html
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
.. _`tes3weatherBlight`: ../../lua/type/tes3weatherBlight.html
.. _`tes3packedColor`: ../../lua/type/tes3packedColor.html
.. _`bool`: ../../lua/type/boolean.html
.. _`tes3equipmentStack`: ../../lua/type/tes3equipmentStack.html
.. _`tes3weatherFoggy`: ../../lua/type/tes3weatherFoggy.html
.. _`mwseTimerController`: ../../lua/type/mwseTimerController.html
.. _`tes3leveledCreature`: ../../lua/type/tes3leveledCreature.html
.. _`tes3lockNode`: ../../lua/type/tes3lockNode.html
.. _`tes3activeMagicEffect`: ../../lua/type/tes3activeMagicEffect.html
.. _`tes3cellExteriorData`: ../../lua/type/tes3cellExteriorData.html
.. _`tes3weatherOvercast`: ../../lua/type/tes3weatherOvercast.html
.. _`tes3leveledItem`: ../../lua/type/tes3leveledItem.html
.. _`tes3alchemy`: ../../lua/type/tes3alchemy.html
.. _`tes3enchantment`: ../../lua/type/tes3enchantment.html
.. _`tes3cell`: ../../lua/type/tes3cell.html
.. _`tes3actionData`: ../../lua/type/tes3actionData.html
.. _`tes3itemData`: ../../lua/type/tes3itemData.html
.. _`tes3factionReaction`: ../../lua/type/tes3factionReaction.html
