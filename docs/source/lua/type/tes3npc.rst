tes3npc
====================================================================================================

An NPC object that has not been cloned. Typically represents the raw information edited in the construction set.

Properties
----------------------------------------------------------------------------------------------------

`actorFlags`_ (`number`_)
    A number representing the actor flags. Truly a bit field.

`aiConfig`_ (`tes3aiConfig`_)
    A substructure off of actors that contains information on the current AI configuration.

`attributes`_ (`table`_)
    A table of eight numbers, representing the base values for the actor's attributes.

`autoCalc`_ (`boolean`_)
    Direct access to the actor autocalc flag.

`barterGold`_ (`number`_)
    The actor's max health.

`boundingBox`_ (`tes3boundingBox`_)
    The bounding box for the object.

`class`_ (`tes3class`_)
    The class that the NPC uses.

`cloneCount`_ (`number`_)
    The number of clones that exist of this actor.

`deleted`_ (`boolean`_)
    The deleted state of the object.

`disabled`_ (`boolean`_)
    The disabled state of the object.

`disposition`_ (`number`_)
    The actor's base disposition.

`equipment`_ (`tes3iterator`_)
    The items currently equipped to the actor.

`faction`_ (`tes3faction`_)
    The class that the NPC is joined to.

`factionIndex`_ (`number`_)
    No description available.

`factionRank`_ (`number`_)
    The NPC's rank in their faction.

`fatigue`_ (`number`_)
    The actor's max fatigue.

`female`_ (`boolean`_)
    Direct access to the actor female flag.

`hair`_ (`tes3bodyPart`_)
    The hair body part that the NPC will use.

`head`_ (`tes3bodyPart`_)
    The head body part that the NPC will use.

`health`_ (`number`_)
    The actor's max health.

`id`_ (`string`_)
    The unique identifier for the object.

`inventory`_ (`tes3iterator`_)
    The items currently carried by the actor.

`isAttacked`_ (`boolean`_)
    If true, the actor's attacked flag is set.

`isEssential`_ (`boolean`_)
    If true, the actor's essential flag is set.

`isInstance`_ (`boolean`_)
    Always returns false.

`isRespawn`_ (`boolean`_)
    If true, the actor's respawn flag is set.

`level`_ (`number`_)
    The actor's level.

`magicka`_ (`number`_)
    The actor's max magicka.

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

`race`_ (`tes3race`_)
    The race that the NPC uses.

`reputation`_ (`number`_)
    The actor's base reputation.

`scale`_ (`number`_)
    The object's scale.

`sceneNode`_ (`niNode`_)
    The scene graph node for this object.

`sceneReference`_ (`niNode`_)
    The scene graph reference node for this object.

`script`_ (`tes3script`_)
    The script that runs on the object.

`skills`_ (`table`_)
    A table of twenty seven numbers, representing the base values for the NPC's skills.

`sourceMod`_ (`string`_)
    The filename of the mod that owns this object.

`spells`_ (`tes3spellList`_)
    A list of spells that the actor has access to.

`stolenList`_ (`tes3iterator`_)
    A list of actors that the object has been stolen from.

.. toctree::
    :hidden:

    tes3npc/actorFlags
    tes3npc/aiConfig
    tes3npc/attributes
    tes3npc/autoCalc
    tes3npc/barterGold
    tes3npc/boundingBox
    tes3npc/class
    tes3npc/cloneCount
    tes3npc/deleted
    tes3npc/disabled
    tes3npc/disposition
    tes3npc/equipment
    tes3npc/faction
    tes3npc/factionIndex
    tes3npc/factionRank
    tes3npc/fatigue
    tes3npc/female
    tes3npc/hair
    tes3npc/head
    tes3npc/health
    tes3npc/id
    tes3npc/inventory
    tes3npc/isAttacked
    tes3npc/isEssential
    tes3npc/isInstance
    tes3npc/isRespawn
    tes3npc/level
    tes3npc/magicka
    tes3npc/mesh
    tes3npc/modified
    tes3npc/name
    tes3npc/nextInCollection
    tes3npc/objectFlags
    tes3npc/objectType
    tes3npc/owningCollection
    tes3npc/previousInCollection
    tes3npc/race
    tes3npc/reputation
    tes3npc/scale
    tes3npc/sceneNode
    tes3npc/sceneReference
    tes3npc/script
    tes3npc/skills
    tes3npc/sourceMod
    tes3npc/spells
    tes3npc/stolenList

.. _`actorFlags`: tes3npc/actorFlags.html
.. _`aiConfig`: tes3npc/aiConfig.html
.. _`attributes`: tes3npc/attributes.html
.. _`autoCalc`: tes3npc/autoCalc.html
.. _`barterGold`: tes3npc/barterGold.html
.. _`boundingBox`: tes3npc/boundingBox.html
.. _`class`: tes3npc/class.html
.. _`cloneCount`: tes3npc/cloneCount.html
.. _`deleted`: tes3npc/deleted.html
.. _`disabled`: tes3npc/disabled.html
.. _`disposition`: tes3npc/disposition.html
.. _`equipment`: tes3npc/equipment.html
.. _`faction`: tes3npc/faction.html
.. _`factionIndex`: tes3npc/factionIndex.html
.. _`factionRank`: tes3npc/factionRank.html
.. _`fatigue`: tes3npc/fatigue.html
.. _`female`: tes3npc/female.html
.. _`hair`: tes3npc/hair.html
.. _`head`: tes3npc/head.html
.. _`health`: tes3npc/health.html
.. _`id`: tes3npc/id.html
.. _`inventory`: tes3npc/inventory.html
.. _`isAttacked`: tes3npc/isAttacked.html
.. _`isEssential`: tes3npc/isEssential.html
.. _`isInstance`: tes3npc/isInstance.html
.. _`isRespawn`: tes3npc/isRespawn.html
.. _`level`: tes3npc/level.html
.. _`magicka`: tes3npc/magicka.html
.. _`mesh`: tes3npc/mesh.html
.. _`modified`: tes3npc/modified.html
.. _`name`: tes3npc/name.html
.. _`nextInCollection`: tes3npc/nextInCollection.html
.. _`objectFlags`: tes3npc/objectFlags.html
.. _`objectType`: tes3npc/objectType.html
.. _`owningCollection`: tes3npc/owningCollection.html
.. _`previousInCollection`: tes3npc/previousInCollection.html
.. _`race`: tes3npc/race.html
.. _`reputation`: tes3npc/reputation.html
.. _`scale`: tes3npc/scale.html
.. _`sceneNode`: tes3npc/sceneNode.html
.. _`sceneReference`: tes3npc/sceneReference.html
.. _`script`: tes3npc/script.html
.. _`skills`: tes3npc/skills.html
.. _`sourceMod`: tes3npc/sourceMod.html
.. _`spells`: tes3npc/spells.html
.. _`stolenList`: tes3npc/stolenList.html

Methods
----------------------------------------------------------------------------------------------------

`onInventoryClose`_
    A callback function invoked when an inventory is closed. Typically not used outside of specific purposes.

.. toctree::
    :hidden:

    tes3npc/onInventoryClose

.. _`onInventoryClose`: tes3npc/onInventoryClose.html

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
