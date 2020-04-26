tes3region
====================================================================================================

A structure that contains region information.

Properties
----------------------------------------------------------------------------------------------------

`deleted`_ (`boolean`_)
    The deleted state of the object.

`disabled`_ (`boolean`_)
    The disabled state of the object.

`id`_ (`string`_)
    The unique identifier for the object.

`modified`_ (`boolean`_)
    The modification state of the object since the last save.

`name`_ (`string`_)
    The region's name. Must be a string less than 32 characters.

`objectFlags`_ (`number`_)
    The raw flags of the object.

`objectType`_ (`number`_)
    The type of object. Maps to values in tes3.objectType.

`sleepCreature`_ (`tes3leveledCreature`_)
    The region's leveled creature that can be spawned while the player is sleeping.

`sounds`_ (`table`_)
    Array-style table for the different region sounds. Each object in the table is a tes3regionSound.

`sourceMod`_ (`string`_)
    The filename of the mod that owns this object.

`weather`_ (`tes3weather`_)
    The region's current weather.

`weatherChanceAsh`_ (`number`_)
    The chance the Ash weather-type will be used. Must be an integer between 0 - 100.

`weatherChanceBlight`_ (`number`_)
    The chance the Blight weather-type will be used. Must be an integer between 0 - 100.

`weatherChanceBlizzard`_ (`number`_)
    The chance the Blizzard weather-type will be used. Must be an integer between 0 - 100.

`weatherChanceClear`_ (`number`_)
    The chance the Clear weather-type will be used. Must be an integer between 0 - 100.

`weatherChanceCloudy`_ (`number`_)
    The chance the Cloudy weather-type will be used. Must be an integer between 0 - 100.

`weatherChanceFoggy`_ (`number`_)
    The chance the Foggy weather-type will be used. Must be an integer between 0 - 100.

`weatherChanceOvercast`_ (`number`_)
    The chance the Overcast weather-type will be used. Must be an integer between 0 - 100.

`weatherChanceRain`_ (`number`_)
    The chance the Rain weather-type will be used. Must be an integer between 0 - 100.

`weatherChanceSnow`_ (`number`_)
    The chance the Snow weather-type will be used. Must be an integer between 0 - 100.

`weatherChanceThunder`_ (`number`_)
    The chance the Thunder weather-type will be used. Must be an integer between 0 - 100.

`weatherChances`_ (`table`_)
    Array-style table for the different weather chances. Each object in the table is a number, between 1 - 100. The index of the table is the weather type.

.. toctree::
    :hidden:

    tes3region/deleted
    tes3region/disabled
    tes3region/id
    tes3region/modified
    tes3region/name
    tes3region/objectFlags
    tes3region/objectType
    tes3region/sleepCreature
    tes3region/sounds
    tes3region/sourceMod
    tes3region/weather
    tes3region/weatherChanceAsh
    tes3region/weatherChanceBlight
    tes3region/weatherChanceBlizzard
    tes3region/weatherChanceClear
    tes3region/weatherChanceCloudy
    tes3region/weatherChanceFoggy
    tes3region/weatherChanceOvercast
    tes3region/weatherChanceRain
    tes3region/weatherChanceSnow
    tes3region/weatherChanceThunder
    tes3region/weatherChances

.. _`deleted`: tes3region/deleted.html
.. _`disabled`: tes3region/disabled.html
.. _`id`: tes3region/id.html
.. _`modified`: tes3region/modified.html
.. _`name`: tes3region/name.html
.. _`objectFlags`: tes3region/objectFlags.html
.. _`objectType`: tes3region/objectType.html
.. _`sleepCreature`: tes3region/sleepCreature.html
.. _`sounds`: tes3region/sounds.html
.. _`sourceMod`: tes3region/sourceMod.html
.. _`weather`: tes3region/weather.html
.. _`weatherChanceAsh`: tes3region/weatherChanceAsh.html
.. _`weatherChanceBlight`: tes3region/weatherChanceBlight.html
.. _`weatherChanceBlizzard`: tes3region/weatherChanceBlizzard.html
.. _`weatherChanceClear`: tes3region/weatherChanceClear.html
.. _`weatherChanceCloudy`: tes3region/weatherChanceCloudy.html
.. _`weatherChanceFoggy`: tes3region/weatherChanceFoggy.html
.. _`weatherChanceOvercast`: tes3region/weatherChanceOvercast.html
.. _`weatherChanceRain`: tes3region/weatherChanceRain.html
.. _`weatherChanceSnow`: tes3region/weatherChanceSnow.html
.. _`weatherChanceThunder`: tes3region/weatherChanceThunder.html
.. _`weatherChances`: tes3region/weatherChances.html

Methods
----------------------------------------------------------------------------------------------------

`changeWeather`_
    Changes the current weather for the region to the provided weather-type parameter.

`randomizeWeather`_
    Changes the weather to a random weather type.

.. toctree::
    :hidden:

    tes3region/changeWeather
    tes3region/randomizeWeather

.. _`changeWeather`: tes3region/changeWeather.html
.. _`randomizeWeather`: tes3region/randomizeWeather.html

.. _`tes3factionReaction`: ../../lua/type/tes3factionReaction.html
.. _`niObject`: ../../lua/type/niObject.html
.. _`tes3npc`: ../../lua/type/tes3npc.html
.. _`tes3book`: ../../lua/type/tes3book.html
.. _`tes3matrix33`: ../../lua/type/tes3matrix33.html
.. _`tes3actor`: ../../lua/type/tes3actor.html
.. _`tes3spell`: ../../lua/type/tes3spell.html
.. _`tes3inputConfig`: ../../lua/type/tes3inputConfig.html
.. _`tes3itemStack`: ../../lua/type/tes3itemStack.html
.. _`tes3globalVariable`: ../../lua/type/tes3globalVariable.html
.. _`tes3containerInstance`: ../../lua/type/tes3containerInstance.html
.. _`tes3magicSourceInstance`: ../../lua/type/tes3magicSourceInstance.html
.. _`niAVObject`: ../../lua/type/niAVObject.html
.. _`tes3iterator`: ../../lua/type/tes3iterator.html
.. _`tes3raceHeightWeight`: ../../lua/type/tes3raceHeightWeight.html
.. _`tes3weatherThunder`: ../../lua/type/tes3weatherThunder.html
.. _`tes3weatherSnow`: ../../lua/type/tes3weatherSnow.html
.. _`tes3class`: ../../lua/type/tes3class.html
.. _`tes3mobileProjectile`: ../../lua/type/tes3mobileProjectile.html
.. _`tes3weatherRain`: ../../lua/type/tes3weatherRain.html
.. _`tes3apparatus`: ../../lua/type/tes3apparatus.html
.. _`tes3door`: ../../lua/type/tes3door.html
.. _`tes3leveledItem`: ../../lua/type/tes3leveledItem.html
.. _`nil`: ../../lua/type/nil.html
.. _`tes3directInputMouseState`: ../../lua/type/tes3directInputMouseState.html
.. _`tes3weatherController`: ../../lua/type/tes3weatherController.html
.. _`niRTTI`: ../../lua/type/niRTTI.html
.. _`tes3mobileCreature`: ../../lua/type/tes3mobileCreature.html
.. _`niObjectNET`: ../../lua/type/niObjectNET.html
.. _`tes3mobilePlayer`: ../../lua/type/tes3mobilePlayer.html
.. _`tes3weatherBlizzard`: ../../lua/type/tes3weatherBlizzard.html
.. _`tes3lockNode`: ../../lua/type/tes3lockNode.html
.. _`tes3vector2`: ../../lua/type/tes3vector2.html
.. _`tes3armor`: ../../lua/type/tes3armor.html
.. _`tes3weather`: ../../lua/type/tes3weather.html
.. _`tes3npcInstance`: ../../lua/type/tes3npcInstance.html
.. _`tes3wearablePart`: ../../lua/type/tes3wearablePart.html
.. _`tes3vector4`: ../../lua/type/tes3vector4.html
.. _`tes3dataHandler`: ../../lua/type/tes3dataHandler.html
.. _`tes3rangeInt`: ../../lua/type/tes3rangeInt.html
.. _`tes3dialogueInfo`: ../../lua/type/tes3dialogueInfo.html
.. _`tes3raceSkillBonus`: ../../lua/type/tes3raceSkillBonus.html
.. _`tes3weatherAsh`: ../../lua/type/tes3weatherAsh.html
.. _`tes3travelDestinationNode`: ../../lua/type/tes3travelDestinationNode.html
.. _`tes3transform`: ../../lua/type/tes3transform.html
.. _`tes3dialogue`: ../../lua/type/tes3dialogue.html
.. _`tes3gameFile`: ../../lua/type/tes3gameFile.html
.. _`tes3faction`: ../../lua/type/tes3faction.html
.. _`tes3statistic`: ../../lua/type/tes3statistic.html
.. _`tes3inputController`: ../../lua/type/tes3inputController.html
.. _`tes3lockpick`: ../../lua/type/tes3lockpick.html
.. _`tes3combatSession`: ../../lua/type/tes3combatSession.html
.. _`boolean`: ../../lua/type/boolean.html
.. _`tes3static`: ../../lua/type/tes3static.html
.. _`tes3magicEffect`: ../../lua/type/tes3magicEffect.html
.. _`string`: ../../lua/type/string.html
.. _`tes3soulGemData`: ../../lua/type/tes3soulGemData.html
.. _`tes3iteratorNode`: ../../lua/type/tes3iteratorNode.html
.. _`tes3item`: ../../lua/type/tes3item.html
.. _`tes3quest`: ../../lua/type/tes3quest.html
.. _`tes3nonDynamicData`: ../../lua/type/tes3nonDynamicData.html
.. _`tes3ingredient`: ../../lua/type/tes3ingredient.html
.. _`tes3race`: ../../lua/type/tes3race.html
.. _`tes3gameSetting`: ../../lua/type/tes3gameSetting.html
.. _`tes3reference`: ../../lua/type/tes3reference.html
.. _`table`: ../../lua/type/table.html
.. _`tes3mobileActor`: ../../lua/type/tes3mobileActor.html
.. _`tes3referenceList`: ../../lua/type/tes3referenceList.html
.. _`tes3mobileNPC`: ../../lua/type/tes3mobileNPC.html
.. _`tes3regionSound`: ../../lua/type/tes3regionSound.html
.. _`tes3vector3`: ../../lua/type/tes3vector3.html
.. _`tes3raceBodyParts`: ../../lua/type/tes3raceBodyParts.html
.. _`tes3raceBaseAttribute`: ../../lua/type/tes3raceBaseAttribute.html
.. _`tes3activator`: ../../lua/type/tes3activator.html
.. _`tes3probe`: ../../lua/type/tes3probe.html
.. _`tes3inventory`: ../../lua/type/tes3inventory.html
.. _`tes3boundingBox`: ../../lua/type/tes3boundingBox.html
.. _`tes3birthsign`: ../../lua/type/tes3birthsign.html
.. _`tes3physicalObject`: ../../lua/type/tes3physicalObject.html
.. _`tes3creatureInstance`: ../../lua/type/tes3creatureInstance.html
.. _`tes3effect`: ../../lua/type/tes3effect.html
.. _`tes3game`: ../../lua/type/tes3game.html
.. _`tes3light`: ../../lua/type/tes3light.html
.. _`tes3moon`: ../../lua/type/tes3moon.html
.. _`tes3object`: ../../lua/type/tes3object.html
.. _`tes3weatherClear`: ../../lua/type/tes3weatherClear.html
.. _`number`: ../../lua/type/number.html
.. _`tes3mobileObject`: ../../lua/type/tes3mobileObject.html
.. _`tes3weatherCloudy`: ../../lua/type/tes3weatherCloudy.html
.. _`tes3region`: ../../lua/type/tes3region.html
.. _`tes3misc`: ../../lua/type/tes3misc.html
.. _`tes3leveledListNode`: ../../lua/type/tes3leveledListNode.html
.. _`tes3markData`: ../../lua/type/tes3markData.html
.. _`tes3magicEffectInstance`: ../../lua/type/tes3magicEffectInstance.html
.. _`function`: ../../lua/type/function.html
.. _`tes3bodyPart`: ../../lua/type/tes3bodyPart.html
.. _`tes3baseObject`: ../../lua/type/tes3baseObject.html
.. _`mwseTimer`: ../../lua/type/mwseTimer.html
.. _`tes3factionRank`: ../../lua/type/tes3factionRank.html
.. _`tes3fader`: ../../lua/type/tes3fader.html
.. _`tes3weatherBlight`: ../../lua/type/tes3weatherBlight.html
.. _`tes3packedColor`: ../../lua/type/tes3packedColor.html
.. _`bool`: ../../lua/type/boolean.html
.. _`tes3equipmentStack`: ../../lua/type/tes3equipmentStack.html
.. _`tes3weatherFoggy`: ../../lua/type/tes3weatherFoggy.html
.. _`mwseTimerController`: ../../lua/type/mwseTimerController.html
.. _`tes3leveledCreature`: ../../lua/type/tes3leveledCreature.html
.. _`tes3clothing`: ../../lua/type/tes3clothing.html
.. _`tes3activeMagicEffect`: ../../lua/type/tes3activeMagicEffect.html
.. _`tes3cellExteriorData`: ../../lua/type/tes3cellExteriorData.html
.. _`tes3weatherOvercast`: ../../lua/type/tes3weatherOvercast.html
.. _`tes3itemData`: ../../lua/type/tes3itemData.html
.. _`tes3cell`: ../../lua/type/tes3cell.html
.. _`tes3enchantment`: ../../lua/type/tes3enchantment.html
.. _`tes3actionData`: ../../lua/type/tes3actionData.html
.. _`tes3creature`: ../../lua/type/tes3creature.html
.. _`tes3container`: ../../lua/type/tes3container.html
.. _`tes3alchemy`: ../../lua/type/tes3alchemy.html
