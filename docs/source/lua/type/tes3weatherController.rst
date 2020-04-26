tes3weatherController
====================================================================================================

A data structure that handles the weather.

Properties
----------------------------------------------------------------------------------------------------

`currentFogColor`_ (`tes3vector3`_)
    The current fog color.

`currentSkyColor`_ (`tes3vector3`_)
    The current sky color.

`currentWeather`_ (`tes3weather`_)
    The current weather.

`daysRemaining`_ (`number`_)
    The days remaining.

`hoursBetweenWeatherChange`_ (`number`_)
    The hours between weather changes. Stored as a float value.

`hoursRemaining`_ (`number`_)
    The hours remaining.

`lastActiveRegion`_ (`tes3region`_)
    Provides read-only access to last active region object.

`masser`_ (`tes3moon`_)
    Provides read-only access to the Masser moon object.

`nextWeather`_ (`tes3weather`_)
    The next weather.

`sceneRainRoot`_ (`niNode`_)
    Provides read-only access to the scene rain root NiNode.

`sceneSkyLight`_ (`niDirectionalLight`_)
    Provides read-only access to the scene sky light directional light.

`sceneSkyRoot`_ (`niNode`_)
    Provides read-only access to the scene sky root NiNode.

`sceneSnowRoot`_ (`niNode`_)
    Provides read-only access to the scene snow root NiNode.

`sceneStormRoot`_ (`niNode`_)
    Provides read-only access to the scene storm root NiNode.

`sceneSunBase`_ (`niNode`_)
    Provides read-only access to the scenesun base NiNode.

`sceneSunGlare`_ (`niNode`_)
    Provides read-only access to the scene sun glare NiNode.

`sceneSunVis`_ (`niNode`_)
    Provides read-only access to the scene sun vis NiNode.

`secunda`_ (`tes3moon`_)
    Provides read-only access to the Secunda moon object.

`sunglareFaderAngleMax`_ (`number`_)
    The sunglare fader maximum angle.

`sunglareFaderColor`_ (`tes3vector3`_)
    The sunglare fader color.

`sunglareFaderMax`_ (`number`_)
    The sunglare fader maximum.

`sunriseDuration`_ (`number`_)
    The sunrise duration.

`sunriseHour`_ (`number`_)
    The sunrise hour.

`sunsetDuration`_ (`number`_)
    The sunset duration.

`sunsetHour`_ (`number`_)
    The sunset hour.

`timescaleClouds`_ (`string`_)
    The timescale for clouds.

`transitionScalar`_ (`number`_)
    The scalar transition.

`underwaterColor`_ (`tes3vector3`_)
    The underwater color, represented as a vector.

`underwaterColorWeight`_ (`number`_)
    The underwater color weight.

`underwaterDayFog`_ (`number`_)
    The underwater day fog value.

`underwaterIndoorFog`_ (`number`_)
    The underwater indoor fog value.

`underwaterNightFog`_ (`number`_)
    The underwater night fog value.

`underwaterSunriseFog`_ (`number`_)
    The underwater sunrise fog value.

`underwaterSunsetFog`_ (`number`_)
    The underwater sunset fog value.

`weathers`_ (`table`_)
    Array-style table for the different weather types. Each object in the table is a tes3weather.

`windVelocityCurrWeather`_ (`tes3vector3`_)
    The wind velocity for the current weather.

`windVelocityNextWeather`_ (`tes3vector3`_)
    The wind velocity for the next weather.

.. toctree::
    :hidden:

    tes3weatherController/currentFogColor
    tes3weatherController/currentSkyColor
    tes3weatherController/currentWeather
    tes3weatherController/daysRemaining
    tes3weatherController/hoursBetweenWeatherChange
    tes3weatherController/hoursRemaining
    tes3weatherController/lastActiveRegion
    tes3weatherController/masser
    tes3weatherController/nextWeather
    tes3weatherController/sceneRainRoot
    tes3weatherController/sceneSkyLight
    tes3weatherController/sceneSkyRoot
    tes3weatherController/sceneSnowRoot
    tes3weatherController/sceneStormRoot
    tes3weatherController/sceneSunBase
    tes3weatherController/sceneSunGlare
    tes3weatherController/sceneSunVis
    tes3weatherController/secunda
    tes3weatherController/sunglareFaderAngleMax
    tes3weatherController/sunglareFaderColor
    tes3weatherController/sunglareFaderMax
    tes3weatherController/sunriseDuration
    tes3weatherController/sunriseHour
    tes3weatherController/sunsetDuration
    tes3weatherController/sunsetHour
    tes3weatherController/timescaleClouds
    tes3weatherController/transitionScalar
    tes3weatherController/underwaterColor
    tes3weatherController/underwaterColorWeight
    tes3weatherController/underwaterDayFog
    tes3weatherController/underwaterIndoorFog
    tes3weatherController/underwaterNightFog
    tes3weatherController/underwaterSunriseFog
    tes3weatherController/underwaterSunsetFog
    tes3weatherController/weathers
    tes3weatherController/windVelocityCurrWeather
    tes3weatherController/windVelocityNextWeather

.. _`currentFogColor`: tes3weatherController/currentFogColor.html
.. _`currentSkyColor`: tes3weatherController/currentSkyColor.html
.. _`currentWeather`: tes3weatherController/currentWeather.html
.. _`daysRemaining`: tes3weatherController/daysRemaining.html
.. _`hoursBetweenWeatherChange`: tes3weatherController/hoursBetweenWeatherChange.html
.. _`hoursRemaining`: tes3weatherController/hoursRemaining.html
.. _`lastActiveRegion`: tes3weatherController/lastActiveRegion.html
.. _`masser`: tes3weatherController/masser.html
.. _`nextWeather`: tes3weatherController/nextWeather.html
.. _`sceneRainRoot`: tes3weatherController/sceneRainRoot.html
.. _`sceneSkyLight`: tes3weatherController/sceneSkyLight.html
.. _`sceneSkyRoot`: tes3weatherController/sceneSkyRoot.html
.. _`sceneSnowRoot`: tes3weatherController/sceneSnowRoot.html
.. _`sceneStormRoot`: tes3weatherController/sceneStormRoot.html
.. _`sceneSunBase`: tes3weatherController/sceneSunBase.html
.. _`sceneSunGlare`: tes3weatherController/sceneSunGlare.html
.. _`sceneSunVis`: tes3weatherController/sceneSunVis.html
.. _`secunda`: tes3weatherController/secunda.html
.. _`sunglareFaderAngleMax`: tes3weatherController/sunglareFaderAngleMax.html
.. _`sunglareFaderColor`: tes3weatherController/sunglareFaderColor.html
.. _`sunglareFaderMax`: tes3weatherController/sunglareFaderMax.html
.. _`sunriseDuration`: tes3weatherController/sunriseDuration.html
.. _`sunriseHour`: tes3weatherController/sunriseHour.html
.. _`sunsetDuration`: tes3weatherController/sunsetDuration.html
.. _`sunsetHour`: tes3weatherController/sunsetHour.html
.. _`timescaleClouds`: tes3weatherController/timescaleClouds.html
.. _`transitionScalar`: tes3weatherController/transitionScalar.html
.. _`underwaterColor`: tes3weatherController/underwaterColor.html
.. _`underwaterColorWeight`: tes3weatherController/underwaterColorWeight.html
.. _`underwaterDayFog`: tes3weatherController/underwaterDayFog.html
.. _`underwaterIndoorFog`: tes3weatherController/underwaterIndoorFog.html
.. _`underwaterNightFog`: tes3weatherController/underwaterNightFog.html
.. _`underwaterSunriseFog`: tes3weatherController/underwaterSunriseFog.html
.. _`underwaterSunsetFog`: tes3weatherController/underwaterSunsetFog.html
.. _`weathers`: tes3weatherController/weathers.html
.. _`windVelocityCurrWeather`: tes3weatherController/windVelocityCurrWeather.html
.. _`windVelocityNextWeather`: tes3weatherController/windVelocityNextWeather.html

Methods
----------------------------------------------------------------------------------------------------

`calcSunDamageScalar`_ (`number`_)
    Calculates the sun damage based on the current weather.

`switchImmediate`_
    Immediately switches the weather to the provided weather parameter.

`switchTransition`_
    Transitions the weather to the provided weather parameter based on the weather controller settings.

`updateVisuals`_
    Updates the weather controller visuals. This should be called after any weather transitions.

.. toctree::
    :hidden:

    tes3weatherController/calcSunDamageScalar
    tes3weatherController/switchImmediate
    tes3weatherController/switchTransition
    tes3weatherController/updateVisuals

.. _`calcSunDamageScalar`: tes3weatherController/calcSunDamageScalar.html
.. _`switchImmediate`: tes3weatherController/switchImmediate.html
.. _`switchTransition`: tes3weatherController/switchTransition.html
.. _`updateVisuals`: tes3weatherController/updateVisuals.html

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
