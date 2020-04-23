tes3reference
====================================================================================================

A reference is a sort of container structure for objects. It holds a base object, as well as various variables associated with that object that make it unique.

For example, many doors may share the same base object. However, each door reference might have a different owner, different lock/trap statuses, etc. that make the object unique.

Properties
----------------------------------------------------------------------------------------------------

`activationReference`_ (`tes3reference`_)
    The current reference, if any, that this reference will activate.

`attachments`_ (`table`_)
    A table with friendly named access to all supported attachments.

`cell`_ (`tes3cell`_)
    The cell that the reference is currently in.

`context`_ (`tes3scriptContext`_)
    Access to the script context for this reference and its associated script.

`data`_ (`table`_)
    A generic lua table that data can be written to, and synced to/from the save. All information stored must be valid for serialization to json. For item references, this is the same table as on the tes3itemData structure.

`deleted`_ (`boolean`_)
    The deleted state of the object.

`disabled`_ (`boolean`_)
    The disabled state of the object.

`id`_ (`string`_)
    The unique identifier for the object.

`isEmpty`_ (`boolean`_)
    Friendly access onto the reference's empty inventory flag.

`isRespawn`_ (`boolean`_)
    If true, the references respawn flag is set.

`light`_ (`niPointLight`_)
    Direct access to the scene graph light, if a dynamic light is set.

`lockNode`_ (`tes3lockNode`_)
    Quick access to the reference's lock node, if any.

`mobile`_ (`tes3mobileObject`_)
    Access to the attached mobile object, if applicable.

`modified`_ (`boolean`_)
    The modification state of the object since the last save.

`nextInCollection`_ (`tes3object`_)
    The next object in parent collection's list.

`nextNode`_ (`tes3reference`_)
    The next reference in the parent reference list.

`nodeData`_ (`tes3reference`_)
    Redundant access to this object, for iterating over a tes3referenceList.

`object`_ (`tes3physicalObject`_)
    The object that the reference is for, such as a weapon, armor, or actor.

`objectFlags`_ (`number`_)
    The raw flags of the object.

`objectType`_ (`number`_)
    The type of object. Maps to values in tes3.objectType.

`orientation`_ (`tes3vector3`_)
    Access to the reference's orientation.

`owningCollection`_ (`tes3referenceList`_)
    The collection responsible for holding this object.

`position`_ (`tes3vector3`_)
    Access to the reference's position.

`previousInCollection`_ (`tes3object`_)
    The previous object in parent collection's list.

`previousNode`_ (`tes3reference`_)
    The previous reference in the parent reference list.

`scale`_ (`number`_)
    The object's scale.

`sceneNode`_ (`niNode`_)
    The scene graph node for this object.

`sceneNode`_ (`niNode`_)
    The scene graph node that the reference uses for rendering.

`sceneReference`_ (`niNode`_)
    The scene graph reference node for this object.

`sourceMod`_ (`string`_)
    The filename of the mod that owns this object.

`stackSize`_ (`number`_)
    Access to the size of a stack, if the reference represents one or more items.

.. toctree::
    :hidden:

    tes3reference/activationReference
    tes3reference/attachments
    tes3reference/cell
    tes3reference/context
    tes3reference/data
    tes3reference/deleted
    tes3reference/disabled
    tes3reference/id
    tes3reference/isEmpty
    tes3reference/isRespawn
    tes3reference/light
    tes3reference/lockNode
    tes3reference/mobile
    tes3reference/modified
    tes3reference/nextInCollection
    tes3reference/nextNode
    tes3reference/nodeData
    tes3reference/object
    tes3reference/objectFlags
    tes3reference/objectType
    tes3reference/orientation
    tes3reference/owningCollection
    tes3reference/position
    tes3reference/previousInCollection
    tes3reference/previousNode
    tes3reference/scale
    tes3reference/sceneNode
    tes3reference/sceneNode
    tes3reference/sceneReference
    tes3reference/sourceMod
    tes3reference/stackSize

.. _`activationReference`: tes3reference/activationReference.html
.. _`attachments`: tes3reference/attachments.html
.. _`cell`: tes3reference/cell.html
.. _`context`: tes3reference/context.html
.. _`data`: tes3reference/data.html
.. _`deleted`: tes3reference/deleted.html
.. _`disabled`: tes3reference/disabled.html
.. _`id`: tes3reference/id.html
.. _`isEmpty`: tes3reference/isEmpty.html
.. _`isRespawn`: tes3reference/isRespawn.html
.. _`light`: tes3reference/light.html
.. _`lockNode`: tes3reference/lockNode.html
.. _`mobile`: tes3reference/mobile.html
.. _`modified`: tes3reference/modified.html
.. _`nextInCollection`: tes3reference/nextInCollection.html
.. _`nextNode`: tes3reference/nextNode.html
.. _`nodeData`: tes3reference/nodeData.html
.. _`object`: tes3reference/object.html
.. _`objectFlags`: tes3reference/objectFlags.html
.. _`objectType`: tes3reference/objectType.html
.. _`orientation`: tes3reference/orientation.html
.. _`owningCollection`: tes3reference/owningCollection.html
.. _`position`: tes3reference/position.html
.. _`previousInCollection`: tes3reference/previousInCollection.html
.. _`previousNode`: tes3reference/previousNode.html
.. _`scale`: tes3reference/scale.html
.. _`sceneNode`: tes3reference/sceneNode.html
.. _`sceneNode`: tes3reference/sceneNode.html
.. _`sceneReference`: tes3reference/sceneReference.html
.. _`sourceMod`: tes3reference/sourceMod.html
.. _`stackSize`: tes3reference/stackSize.html

Methods
----------------------------------------------------------------------------------------------------

`activate`_
    Causes this reference to activate another. This will lead them to go through doors, pick up items, etc.

`clearActionFlag`_
    Unsets a bit in the reference's action data attachment

`clone`_ (`boolean`_)
    Clones a reference for a base actor into a reference to an instance of that actor. For example, this will force a container to resolve its leveled items and have its own unique inventory.

`deleteDynamicLightAttachment`_
    Deletes the dynamic light attachment, if it exists. This will automatically detach the dynamic light from affected nodes.

`detachDynamicLightFromAffectedNodes`_
    Removes the dynamic light from any affected scene graph nodes, but will not delete the associated attachment.

`getAttachedDynamicLight`_ (`tes3lightNode`_)
    Fetches the dynamic light attachment.

`getOrCreateAttachedDynamicLight`_ (`tes3lightNode`_)
    Fetches the dynamic light attachment. If there isn't one, a new one will be created with the given light and value.

`setActionFlag`_
    Sets a bit in the reference's action data attachment

`setDynamicLighting`_
    Sets the dynamic lighting state of the reference using the global data handler.

`testActionFlag`_ (`boolean`_)
    Returns the flag's value in the reference's action data attachment

`updateEquipment`_
    Causes the reference, if of an actor, to reevaluate its equipment choices and equip items it should.

`updateLighting`_
    Updates the lighting of the reference using the global data handler.

`updateSceneGraph`_
    Updates the reference's local rotation matrix, propagates position changes to the scene graph, and sets the reference's modified flag.

.. toctree::
    :hidden:

    tes3reference/activate
    tes3reference/clearActionFlag
    tes3reference/clone
    tes3reference/deleteDynamicLightAttachment
    tes3reference/detachDynamicLightFromAffectedNodes
    tes3reference/getAttachedDynamicLight
    tes3reference/getOrCreateAttachedDynamicLight
    tes3reference/setActionFlag
    tes3reference/setDynamicLighting
    tes3reference/testActionFlag
    tes3reference/updateEquipment
    tes3reference/updateLighting
    tes3reference/updateSceneGraph

.. _`activate`: tes3reference/activate.html
.. _`clearActionFlag`: tes3reference/clearActionFlag.html
.. _`clone`: tes3reference/clone.html
.. _`deleteDynamicLightAttachment`: tes3reference/deleteDynamicLightAttachment.html
.. _`detachDynamicLightFromAffectedNodes`: tes3reference/detachDynamicLightFromAffectedNodes.html
.. _`getAttachedDynamicLight`: tes3reference/getAttachedDynamicLight.html
.. _`getOrCreateAttachedDynamicLight`: tes3reference/getOrCreateAttachedDynamicLight.html
.. _`setActionFlag`: tes3reference/setActionFlag.html
.. _`setDynamicLighting`: tes3reference/setDynamicLighting.html
.. _`testActionFlag`: tes3reference/testActionFlag.html
.. _`updateEquipment`: tes3reference/updateEquipment.html
.. _`updateLighting`: tes3reference/updateLighting.html
.. _`updateSceneGraph`: tes3reference/updateSceneGraph.html

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
.. _`tes3weatherThunder`: ../../lua/type/tes3weatherThunder.html
.. _`tes3directInputMouseState`: ../../lua/type/tes3directInputMouseState.html
.. _`tes3weatherSnow`: ../../lua/type/tes3weatherSnow.html
.. _`niRTTI`: ../../lua/type/niRTTI.html
.. _`tes3weatherRain`: ../../lua/type/tes3weatherRain.html
.. _`niObjectNET`: ../../lua/type/niObjectNET.html
.. _`tes3light`: ../../lua/type/tes3light.html
.. _`tes3clothing`: ../../lua/type/tes3clothing.html
.. _`tes3weatherController`: ../../lua/type/tes3weatherController.html
.. _`tes3mobilePlayer`: ../../lua/type/tes3mobilePlayer.html
.. _`tes3armor`: ../../lua/type/tes3armor.html
.. _`nil`: ../../lua/type/nil.html
.. _`tes3npcInstance`: ../../lua/type/tes3npcInstance.html
.. _`tes3weatherBlizzard`: ../../lua/type/tes3weatherBlizzard.html
.. _`tes3container`: ../../lua/type/tes3container.html
.. _`tes3dataHandler`: ../../lua/type/tes3dataHandler.html
.. _`tes3rangeInt`: ../../lua/type/tes3rangeInt.html
.. _`tes3dialogueInfo`: ../../lua/type/tes3dialogueInfo.html
.. _`tes3weather`: ../../lua/type/tes3weather.html
.. _`tes3weatherAsh`: ../../lua/type/tes3weatherAsh.html
.. _`tes3wearablePart`: ../../lua/type/tes3wearablePart.html
.. _`tes3vector4`: ../../lua/type/tes3vector4.html
.. _`tes3dialogue`: ../../lua/type/tes3dialogue.html
.. _`tes3gameFile`: ../../lua/type/tes3gameFile.html
.. _`tes3faction`: ../../lua/type/tes3faction.html
.. _`tes3referenceList`: ../../lua/type/tes3referenceList.html
.. _`tes3inputController`: ../../lua/type/tes3inputController.html
.. _`tes3lockpick`: ../../lua/type/tes3lockpick.html
.. _`tes3combatSession`: ../../lua/type/tes3combatSession.html
.. _`boolean`: ../../lua/type/boolean.html
.. _`tes3vector2`: ../../lua/type/tes3vector2.html
.. _`tes3magicEffect`: ../../lua/type/tes3magicEffect.html
.. _`string`: ../../lua/type/string.html
.. _`tes3travelDestinationNode`: ../../lua/type/tes3travelDestinationNode.html
.. _`tes3iteratorNode`: ../../lua/type/tes3iteratorNode.html
.. _`tes3fader`: ../../lua/type/tes3fader.html
.. _`tes3quest`: ../../lua/type/tes3quest.html
.. _`tes3nonDynamicData`: ../../lua/type/tes3nonDynamicData.html
.. _`tes3ingredient`: ../../lua/type/tes3ingredient.html
.. _`tes3race`: ../../lua/type/tes3race.html
.. _`tes3gameSetting`: ../../lua/type/tes3gameSetting.html
.. _`tes3transform`: ../../lua/type/tes3transform.html
.. _`table`: ../../lua/type/table.html
.. _`tes3soulGemData`: ../../lua/type/tes3soulGemData.html
.. _`tes3mobileObject`: ../../lua/type/tes3mobileObject.html
.. _`tes3mobileNPC`: ../../lua/type/tes3mobileNPC.html
.. _`tes3regionSound`: ../../lua/type/tes3regionSound.html
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
.. _`tes3region`: ../../lua/type/tes3region.html
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
