tes3light
====================================================================================================

A core light object. This isn't actually a light in the rendering engine, but something like a lamp or torch.

Properties
----------------------------------------------------------------------------------------------------

`boundingBox`_ (`tes3boundingBox`_)
    The bounding box for the object.

`canCarry`_ (`boolean`_)
    Access to the light's flags, determining if the light can be carried.

`color`_ (`table`_)
    Access to the light's base colors, in an array-style table of four values. The values can range from 0 to 255.

`deleted`_ (`boolean`_)
    The deleted state of the object.

`disabled`_ (`boolean`_)
    The disabled state of the object.

`flickers`_ (`boolean`_)
    Access to the light's flags, determining if the light attenuation flickers.

`flickersSlowly`_ (`boolean`_)
    Access to the light's flags, determining if the light attenuation flickers slowly.

`icon`_ (`string`_)
    The path to the object's icon.

`id`_ (`string`_)
    The unique identifier for the object.

`isDynamic`_ (`boolean`_)
    Access to the light's flags, determining if the light affects dynamically moving objects.

`isFire`_ (`boolean`_)
    Access to the light's flags, determining if the light represents flame.

`isNegative`_ (`boolean`_)
    Access to the light's flags, determining if the object creates darkness.

`isOffByDefault`_ (`boolean`_)
    Access to the light's flags, determining if the light won't be active initially.

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

`pulses`_ (`boolean`_)
    Access to the light's flags, determining if the light attenuation pulses.

`pulsesSlowly`_ (`boolean`_)
    Access to the light's flags, determining if the light attenuation pulses slowly.

`radius`_ (`number`_)
    The base radius of the light.

`scale`_ (`number`_)
    The object's scale.

`sceneNode`_ (`niNode`_)
    The scene graph node for this object.

`sceneReference`_ (`niNode`_)
    The scene graph reference node for this object.

`script`_ (`tes3script`_)
    The script that runs on the object.

`sound`_ (`tes3sound`_)
    The sound that runs on the object.

`sourceMod`_ (`string`_)
    The filename of the mod that owns this object.

`stolenList`_ (`tes3iterator`_)
    A list of actors that the object has been stolen from.

`time`_ (`number`_)
    The amount of time that the light will last.

`value`_ (`number`_)
    The value of the object.

`weight`_ (`number`_)
    The weight, in pounds, of the object.

.. toctree::
    :hidden:

    tes3light/boundingBox
    tes3light/canCarry
    tes3light/color
    tes3light/deleted
    tes3light/disabled
    tes3light/flickers
    tes3light/flickersSlowly
    tes3light/icon
    tes3light/id
    tes3light/isDynamic
    tes3light/isFire
    tes3light/isNegative
    tes3light/isOffByDefault
    tes3light/mesh
    tes3light/modified
    tes3light/name
    tes3light/nextInCollection
    tes3light/objectFlags
    tes3light/objectType
    tes3light/owningCollection
    tes3light/previousInCollection
    tes3light/pulses
    tes3light/pulsesSlowly
    tes3light/radius
    tes3light/scale
    tes3light/sceneNode
    tes3light/sceneReference
    tes3light/script
    tes3light/sound
    tes3light/sourceMod
    tes3light/stolenList
    tes3light/time
    tes3light/value
    tes3light/weight

.. _`boundingBox`: tes3light/boundingBox.html
.. _`canCarry`: tes3light/canCarry.html
.. _`color`: tes3light/color.html
.. _`deleted`: tes3light/deleted.html
.. _`disabled`: tes3light/disabled.html
.. _`flickers`: tes3light/flickers.html
.. _`flickersSlowly`: tes3light/flickersSlowly.html
.. _`icon`: tes3light/icon.html
.. _`id`: tes3light/id.html
.. _`isDynamic`: tes3light/isDynamic.html
.. _`isFire`: tes3light/isFire.html
.. _`isNegative`: tes3light/isNegative.html
.. _`isOffByDefault`: tes3light/isOffByDefault.html
.. _`mesh`: tes3light/mesh.html
.. _`modified`: tes3light/modified.html
.. _`name`: tes3light/name.html
.. _`nextInCollection`: tes3light/nextInCollection.html
.. _`objectFlags`: tes3light/objectFlags.html
.. _`objectType`: tes3light/objectType.html
.. _`owningCollection`: tes3light/owningCollection.html
.. _`previousInCollection`: tes3light/previousInCollection.html
.. _`pulses`: tes3light/pulses.html
.. _`pulsesSlowly`: tes3light/pulsesSlowly.html
.. _`radius`: tes3light/radius.html
.. _`scale`: tes3light/scale.html
.. _`sceneNode`: tes3light/sceneNode.html
.. _`sceneReference`: tes3light/sceneReference.html
.. _`script`: tes3light/script.html
.. _`sound`: tes3light/sound.html
.. _`sourceMod`: tes3light/sourceMod.html
.. _`stolenList`: tes3light/stolenList.html
.. _`time`: tes3light/time.html
.. _`value`: tes3light/value.html
.. _`weight`: tes3light/weight.html

Methods
----------------------------------------------------------------------------------------------------

`getTimeLeft`_ (`number`_)
    Gets the time remaining for a light, given a tes3itemData, tes3reference, or tes3equipmentStack.

.. toctree::
    :hidden:

    tes3light/getTimeLeft

.. _`getTimeLeft`: tes3light/getTimeLeft.html

.. _`tes3creature`: ../../lua/type/tes3creature.html
.. _`niObject`: ../../lua/type/niObject.html
.. _`tes3book`: ../../lua/type/tes3book.html
.. _`niAlphaProperty`: ../../lua/type/niAlphaProperty.html
.. _`tes3spell`: ../../lua/type/tes3spell.html
.. _`tes3inputConfig`: ../../lua/type/tes3inputConfig.html
.. _`tes3itemStack`: ../../lua/type/tes3itemStack.html
.. _`niTexturingPropertyMap`: ../../lua/type/niTexturingPropertyMap.html
.. _`tes3globalVariable`: ../../lua/type/tes3globalVariable.html
.. _`tes3probe`: ../../lua/type/tes3probe.html
.. _`tes3iterator`: ../../lua/type/tes3iterator.html
.. _`tes3uiElement`: ../../lua/type/tes3uiElement.html
.. _`tes3class`: ../../lua/type/tes3class.html
.. _`niTriShapeData`: ../../lua/type/niTriShapeData.html
.. _`niObjectNET`: ../../lua/type/niObjectNET.html
.. _`tes3armor`: ../../lua/type/tes3armor.html
.. _`niPointLight`: ../../lua/type/niPointLight.html
.. _`niLight`: ../../lua/type/niLight.html
.. _`tes3dataHandler`: ../../lua/type/tes3dataHandler.html
.. _`tes3rangeInt`: ../../lua/type/tes3rangeInt.html
.. _`tes3dialogueInfo`: ../../lua/type/tes3dialogueInfo.html
.. _`tes3weatherAsh`: ../../lua/type/tes3weatherAsh.html
.. _`niSpotLight`: ../../lua/type/niSpotLight.html
.. _`tes3dialogue`: ../../lua/type/tes3dialogue.html
.. _`tes3gameFile`: ../../lua/type/tes3gameFile.html
.. _`tes3inputController`: ../../lua/type/tes3inputController.html
.. _`tes3lockpick`: ../../lua/type/tes3lockpick.html
.. _`boolean`: ../../lua/type/boolean.html
.. _`tes3magicEffect`: ../../lua/type/tes3magicEffect.html
.. _`string`: ../../lua/type/string.html
.. _`niTimeController`: ../../lua/type/niTimeController.html
.. _`tes3iteratorNode`: ../../lua/type/tes3iteratorNode.html
.. _`tes3fader`: ../../lua/type/tes3fader.html
.. _`tes3quest`: ../../lua/type/tes3quest.html
.. _`tes3nonDynamicData`: ../../lua/type/tes3nonDynamicData.html
.. _`tes3travelDestinationNode`: ../../lua/type/tes3travelDestinationNode.html
.. _`tes3race`: ../../lua/type/tes3race.html
.. _`tes3static`: ../../lua/type/tes3static.html
.. _`table`: ../../lua/type/table.html
.. _`tes3weatherBlizzard`: ../../lua/type/tes3weatherBlizzard.html
.. _`tes3weather`: ../../lua/type/tes3weather.html
.. _`tes3activator`: ../../lua/type/tes3activator.html
.. _`tes3inventory`: ../../lua/type/tes3inventory.html
.. _`tes3boundingBox`: ../../lua/type/tes3boundingBox.html
.. _`tes3birthsign`: ../../lua/type/tes3birthsign.html
.. _`tes3creatureInstance`: ../../lua/type/tes3creatureInstance.html
.. _`tes3effect`: ../../lua/type/tes3effect.html
.. _`tes3object`: ../../lua/type/tes3object.html
.. _`tes3weatherClear`: ../../lua/type/tes3weatherClear.html
.. _`number`: ../../lua/type/number.html
.. _`tes3misc`: ../../lua/type/tes3misc.html
.. _`tes3leveledListNode`: ../../lua/type/tes3leveledListNode.html
.. _`niNode`: ../../lua/type/niNode.html
.. _`function`: ../../lua/type/function.html
.. _`niVertexColorProperty`: ../../lua/type/niVertexColorProperty.html
.. _`tes3baseObject`: ../../lua/type/tes3baseObject.html
.. _`niGeometryData`: ../../lua/type/niGeometryData.html
.. _`niAmbientLight`: ../../lua/type/niAmbientLight.html
.. _`bool`: ../../lua/type/boolean.html
.. _`tes3weatherFoggy`: ../../lua/type/tes3weatherFoggy.html
.. _`mwseTimerController`: ../../lua/type/mwseTimerController.html
.. _`tes3leveledCreature`: ../../lua/type/tes3leveledCreature.html
.. _`tes3activeMagicEffect`: ../../lua/type/tes3activeMagicEffect.html
.. _`tes3cellExteriorData`: ../../lua/type/tes3cellExteriorData.html
.. _`tes3enchantment`: ../../lua/type/tes3enchantment.html
.. _`tes3container`: ../../lua/type/tes3container.html
.. _`tes3factionReaction`: ../../lua/type/tes3factionReaction.html
.. _`mwseTimer`: ../../lua/type/mwseTimer.html
.. _`tes3npc`: ../../lua/type/tes3npc.html
.. _`niTriShape`: ../../lua/type/niTriShape.html
.. _`tes3matrix33`: ../../lua/type/tes3matrix33.html
.. _`tes3actor`: ../../lua/type/tes3actor.html
.. _`tes3playerAnimationController`: ../../lua/type/tes3playerAnimationController.html
.. _`tes3containerInstance`: ../../lua/type/tes3containerInstance.html
.. _`tes3magicSourceInstance`: ../../lua/type/tes3magicSourceInstance.html
.. _`niAVObject`: ../../lua/type/niAVObject.html
.. _`tes3mobileActor`: ../../lua/type/tes3mobileActor.html
.. _`tes3raceHeightWeight`: ../../lua/type/tes3raceHeightWeight.html
.. _`tes3mobileProjectile`: ../../lua/type/tes3mobileProjectile.html
.. _`tes3mobileObject`: ../../lua/type/tes3mobileObject.html
.. _`tes3door`: ../../lua/type/tes3door.html
.. _`tes3actionData`: ../../lua/type/tes3actionData.html
.. _`niPixelData`: ../../lua/type/niPixelData.html
.. _`niRTTI`: ../../lua/type/niRTTI.html
.. _`tes3alchemy`: ../../lua/type/tes3alchemy.html
.. _`tes3leveledItem`: ../../lua/type/tes3leveledItem.html
.. _`tes3reference`: ../../lua/type/tes3reference.html
.. _`niPropertyLinkedList`: ../../lua/type/niPropertyLinkedList.html
.. _`niStencilProperty`: ../../lua/type/niStencilProperty.html
.. _`tes3raceSkillBonus`: ../../lua/type/tes3raceSkillBonus.html
.. _`tes3faction`: ../../lua/type/tes3faction.html
.. _`tes3combatSession`: ../../lua/type/tes3combatSession.html
.. _`tes3weatherThunder`: ../../lua/type/tes3weatherThunder.html
.. _`tes3weatherSnow`: ../../lua/type/tes3weatherSnow.html
.. _`niProperty`: ../../lua/type/niProperty.html
.. _`tes3moon`: ../../lua/type/tes3moon.html
.. _`tes3statistic`: ../../lua/type/tes3statistic.html
.. _`tes3ingredient`: ../../lua/type/tes3ingredient.html
.. _`niSwitchNode`: ../../lua/type/niSwitchNode.html
.. _`nil`: ../../lua/type/nil.html
.. _`tes3weatherController`: ../../lua/type/tes3weatherController.html
.. _`tes3directInputMouseState`: ../../lua/type/tes3directInputMouseState.html
.. _`tes3weatherBlight`: ../../lua/type/tes3weatherBlight.html
.. _`tes3wearablePart`: ../../lua/type/tes3wearablePart.html
.. _`tes3mobileNPC`: ../../lua/type/tes3mobileNPC.html
.. _`tes3regionSound`: ../../lua/type/tes3regionSound.html
.. _`tes3vector3`: ../../lua/type/tes3vector3.html
.. _`tes3vector4`: ../../lua/type/tes3vector4.html
.. _`tes3vector2`: ../../lua/type/tes3vector2.html
.. _`tes3transform`: ../../lua/type/tes3transform.html
.. _`tes3soulGemData`: ../../lua/type/tes3soulGemData.html
.. _`tes3region`: ../../lua/type/tes3region.html
.. _`tes3referenceList`: ../../lua/type/tes3referenceList.html
.. _`tes3bodyPart`: ../../lua/type/tes3bodyPart.html
.. _`niPickRecord`: ../../lua/type/niPickRecord.html
.. _`tes3lockNode`: ../../lua/type/tes3lockNode.html
.. _`tes3cell`: ../../lua/type/tes3cell.html
.. _`tes3game`: ../../lua/type/tes3game.html
.. _`niDirectionalLight`: ../../lua/type/niDirectionalLight.html
.. _`tes3physicalObject`: ../../lua/type/tes3physicalObject.html
.. _`tes3raceBodyParts`: ../../lua/type/tes3raceBodyParts.html
.. _`tes3raceBaseAttribute`: ../../lua/type/tes3raceBaseAttribute.html
.. _`tes3clothing`: ../../lua/type/tes3clothing.html
.. _`tes3packedColor`: ../../lua/type/tes3packedColor.html
.. _`tes3weatherCloudy`: ../../lua/type/tes3weatherCloudy.html
.. _`niTriBasedGeometry`: ../../lua/type/niTriBasedGeometry.html
.. _`niMaterialProperty`: ../../lua/type/niMaterialProperty.html
.. _`tes3npcInstance`: ../../lua/type/tes3npcInstance.html
.. _`tes3apparatus`: ../../lua/type/tes3apparatus.html
.. _`niColor`: ../../lua/type/niColor.html
.. _`niFormatPrefs`: ../../lua/type/niFormatPrefs.html
.. _`tes3light`: ../../lua/type/tes3light.html
.. _`tes3weatherRain`: ../../lua/type/tes3weatherRain.html
.. _`tes3mobilePlayer`: ../../lua/type/tes3mobilePlayer.html
.. _`tes3factionRank`: ../../lua/type/tes3factionRank.html
.. _`tes3item`: ../../lua/type/tes3item.html
.. _`tes3mobileCreature`: ../../lua/type/tes3mobileCreature.html
.. _`tes3actorAnimationController`: ../../lua/type/tes3actorAnimationController.html
.. _`niDynamicEffect`: ../../lua/type/niDynamicEffect.html
.. _`niPick`: ../../lua/type/niPick.html
.. _`niCollisionSwitch`: ../../lua/type/niCollisionSwitch.html
.. _`tes3markData`: ../../lua/type/tes3markData.html
.. _`niDynamicEffectLinkedList`: ../../lua/type/niDynamicEffectLinkedList.html
.. _`niCamera`: ../../lua/type/niCamera.html
.. _`niTriBasedGeometryData`: ../../lua/type/niTriBasedGeometryData.html
.. _`tes3magicEffectInstance`: ../../lua/type/tes3magicEffectInstance.html
.. _`tes3weatherOvercast`: ../../lua/type/tes3weatherOvercast.html
.. _`tes3gameSetting`: ../../lua/type/tes3gameSetting.html
.. _`niFogProperty`: ../../lua/type/niFogProperty.html
.. _`niSourceTexture`: ../../lua/type/niSourceTexture.html
.. _`tes3equipmentStack`: ../../lua/type/tes3equipmentStack.html
.. _`niGeometry`: ../../lua/type/niGeometry.html
.. _`tes3itemData`: ../../lua/type/tes3itemData.html
.. _`niTexturingProperty`: ../../lua/type/niTexturingProperty.html
