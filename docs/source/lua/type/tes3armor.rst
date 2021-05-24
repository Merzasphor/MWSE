tes3armor
====================================================================================================

An armor game object.

Properties
----------------------------------------------------------------------------------------------------

`armorRating`_ (`number`_)
    The armor's defensive rating.

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

`maxCondition`_ (`number`_)
    The object's maximum condition.

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

`weightClass`_ (`number`_)
    The weight class of the armor.

.. toctree::
    :hidden:

    tes3armor/armorRating
    tes3armor/boundingBox
    tes3armor/deleted
    tes3armor/disabled
    tes3armor/enchantCapacity
    tes3armor/enchantment
    tes3armor/icon
    tes3armor/id
    tes3armor/isLeftPart
    tes3armor/maxCondition
    tes3armor/mesh
    tes3armor/modified
    tes3armor/name
    tes3armor/nextInCollection
    tes3armor/objectFlags
    tes3armor/objectType
    tes3armor/owningCollection
    tes3armor/parts
    tes3armor/previousInCollection
    tes3armor/scale
    tes3armor/sceneNode
    tes3armor/sceneReference
    tes3armor/script
    tes3armor/slot
    tes3armor/slotName
    tes3armor/sourceMod
    tes3armor/stolenList
    tes3armor/value
    tes3armor/weight
    tes3armor/weightClass

.. _`armorRating`: tes3armor/armorRating.html
.. _`boundingBox`: tes3armor/boundingBox.html
.. _`deleted`: tes3armor/deleted.html
.. _`disabled`: tes3armor/disabled.html
.. _`enchantCapacity`: tes3armor/enchantCapacity.html
.. _`enchantment`: tes3armor/enchantment.html
.. _`icon`: tes3armor/icon.html
.. _`id`: tes3armor/id.html
.. _`isLeftPart`: tes3armor/isLeftPart.html
.. _`maxCondition`: tes3armor/maxCondition.html
.. _`mesh`: tes3armor/mesh.html
.. _`modified`: tes3armor/modified.html
.. _`name`: tes3armor/name.html
.. _`nextInCollection`: tes3armor/nextInCollection.html
.. _`objectFlags`: tes3armor/objectFlags.html
.. _`objectType`: tes3armor/objectType.html
.. _`owningCollection`: tes3armor/owningCollection.html
.. _`parts`: tes3armor/parts.html
.. _`previousInCollection`: tes3armor/previousInCollection.html
.. _`scale`: tes3armor/scale.html
.. _`sceneNode`: tes3armor/sceneNode.html
.. _`sceneReference`: tes3armor/sceneReference.html
.. _`script`: tes3armor/script.html
.. _`slot`: tes3armor/slot.html
.. _`slotName`: tes3armor/slotName.html
.. _`sourceMod`: tes3armor/sourceMod.html
.. _`stolenList`: tes3armor/stolenList.html
.. _`value`: tes3armor/value.html
.. _`weight`: tes3armor/weight.html
.. _`weightClass`: tes3armor/weightClass.html

Methods
----------------------------------------------------------------------------------------------------

`calculateArmorRating`_
    Calculates what armor rating is provided for a given mobile actor.

.. toctree::
    :hidden:

    tes3armor/calculateArmorRating

.. _`calculateArmorRating`: tes3armor/calculateArmorRating.html

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
