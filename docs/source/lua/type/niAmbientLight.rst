niAmbientLight
====================================================================================================

An object that represents an ambient light. This object is fairly simple, and has no location, direction, or attenuation.

Properties
----------------------------------------------------------------------------------------------------

`affectedNodes`_ (`niNodeLinkedList`_)
    The list of nodes that a given dynamic effect will affect.

`ambient`_ (`niColor`_)
    The ambient settings for the light.

`appCulled`_ (`boolean`_)
    A flag indicating if this object is culled. When culled, it will not render, and raycasts ignore it.

`diffuse`_ (`niColor`_)
    The defuse settings for the light.

`dimmer`_ (`niColor`_)
    The dimmer settings for the light.

`enabled`_ (`boolean`_)
    The enabled state of a given dynamic effect.

`flags`_ (`number`_)
    Flags, dependent on the specific object type.

`name`_ (`string`_)
    The human-facing name of the given object.

`properties`_ (`niPropertyLinkedList`_)
    The list of properties attached to this niAVObject.

`references`_ (`string`_)
    The number of references that exist for the given object. When this value hits zero, the object's memory is freed.

`rotation`_ (`tes3matrix33`_)
    The object's local rotation matrix.

`runTimeTypeInformation`_ (`niRTTI`_)
    The runtime type information for this object.

`scale`_ (`number`_)
    The object's local uniform scaling factor.

`specular`_ (`niColor`_)
    The specular settings for the light.

`translation`_ (`tes3vector3`_)
    The object's local translation vector.

`type`_ (`number`_)
    The enumerated type of a given dynamic effect. Types: `0 - niAmbientLight`, `1 - niDirectionalLight`, `2 - niPointLight`, `3 - niSpotLight`, `4 - niTextureEffect`.

.. toctree::
    :hidden:

    niAmbientLight/affectedNodes
    niAmbientLight/ambient
    niAmbientLight/appCulled
    niAmbientLight/diffuse
    niAmbientLight/dimmer
    niAmbientLight/enabled
    niAmbientLight/flags
    niAmbientLight/name
    niAmbientLight/properties
    niAmbientLight/references
    niAmbientLight/rotation
    niAmbientLight/runTimeTypeInformation
    niAmbientLight/scale
    niAmbientLight/specular
    niAmbientLight/translation
    niAmbientLight/type

.. _`affectedNodes`: niAmbientLight/affectedNodes.html
.. _`ambient`: niAmbientLight/ambient.html
.. _`appCulled`: niAmbientLight/appCulled.html
.. _`diffuse`: niAmbientLight/diffuse.html
.. _`dimmer`: niAmbientLight/dimmer.html
.. _`enabled`: niAmbientLight/enabled.html
.. _`flags`: niAmbientLight/flags.html
.. _`name`: niAmbientLight/name.html
.. _`properties`: niAmbientLight/properties.html
.. _`references`: niAmbientLight/references.html
.. _`rotation`: niAmbientLight/rotation.html
.. _`runTimeTypeInformation`: niAmbientLight/runTimeTypeInformation.html
.. _`scale`: niAmbientLight/scale.html
.. _`specular`: niAmbientLight/specular.html
.. _`translation`: niAmbientLight/translation.html
.. _`type`: niAmbientLight/type.html

Methods
----------------------------------------------------------------------------------------------------

`attachProperty`_
    Attach a property to this object.

`clearTransforms`_
    Resets the object's local transform.

`clone`_ (`niObject`_)
    Creates a copy of this object.

`detachProperty`_ (`niProperty`_)
    Detaches and returns a property from the object which matches the given property type.

`getObjectByName`_ (`niAVObject`_)
    Searches this node and all child nodes recursively for a node with a name that matches the argument.

`getProperty`_ (`niProperty`_)
    Gets an attached property by property type.

`isInstanceOfType`_ (`boolean`_)
    Determines if the object is of a given type, or of a type derived from the given type. Types can be found in the tes3.niType table.

`isOfType`_ (`boolean`_)
    Determines if the object is of a given type. Types can be found in the tes3.niType table.

`prependController`_
    Add a controller to the object as the first controller.

`removeAllControllers`_
    Removes all controllers.

`removeController`_
    Removes a controller from the object.

`update`_
    Updates the world transforms of this node and its children, which makes changes visible for rendering. Use after changing any local rotation, translation, scale, or bounds.

`updateEffects`_
    Update all attached effects.

`updateProperties`_
    Update all attached properties.

.. toctree::
    :hidden:

    niAmbientLight/attachProperty
    niAmbientLight/clearTransforms
    niAmbientLight/clone
    niAmbientLight/detachProperty
    niAmbientLight/getObjectByName
    niAmbientLight/getProperty
    niAmbientLight/isInstanceOfType
    niAmbientLight/isOfType
    niAmbientLight/prependController
    niAmbientLight/removeAllControllers
    niAmbientLight/removeController
    niAmbientLight/update
    niAmbientLight/updateEffects
    niAmbientLight/updateProperties

.. _`attachProperty`: niAmbientLight/attachProperty.html
.. _`clearTransforms`: niAmbientLight/clearTransforms.html
.. _`clone`: niAmbientLight/clone.html
.. _`detachProperty`: niAmbientLight/detachProperty.html
.. _`getObjectByName`: niAmbientLight/getObjectByName.html
.. _`getProperty`: niAmbientLight/getProperty.html
.. _`isInstanceOfType`: niAmbientLight/isInstanceOfType.html
.. _`isOfType`: niAmbientLight/isOfType.html
.. _`prependController`: niAmbientLight/prependController.html
.. _`removeAllControllers`: niAmbientLight/removeAllControllers.html
.. _`removeController`: niAmbientLight/removeController.html
.. _`update`: niAmbientLight/update.html
.. _`updateEffects`: niAmbientLight/updateEffects.html
.. _`updateProperties`: niAmbientLight/updateProperties.html

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
