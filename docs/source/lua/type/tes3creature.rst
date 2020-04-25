tes3creature
====================================================================================================

A creature object that has not been cloned. Typically represents the raw information edited in the construction set.

Properties
----------------------------------------------------------------------------------------------------

`actorFlags`_ (`number`_)
    A number representing the actor flags. Truly a bit field.

`aiConfig`_ (`tes3aiConfig`_)
    A substructure off of actors that contains information on the current AI configuration.

`attacks`_ (`table`_)
    A table of three attacks, represented by a trio of tes3rangeInt.

`attributes`_ (`table`_)
    A table of eight numbers, representing the base values for the actor's attributes.

`biped`_ (`boolean`_)
    Access to the creature's biped flag.

`boundingBox`_ (`tes3boundingBox`_)
    The bounding box for the object.

`cloneCount`_ (`number`_)
    The number of clones that exist of this actor.

`deleted`_ (`boolean`_)
    The deleted state of the object.

`disabled`_ (`boolean`_)
    The disabled state of the object.

`equipment`_ (`tes3iterator`_)
    The items currently equipped to the actor.

`fatigue`_ (`number`_)
    The actor's max fatigue.

`flies`_ (`boolean`_)
    Access to the creature's flies flag.

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
    The base level of the creature.

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

`respawns`_ (`boolean`_)
    Access to the creature's respawns flag.

`scale`_ (`number`_)
    The object's scale.

`sceneNode`_ (`niNode`_)
    The scene graph node for this object.

`sceneReference`_ (`niNode`_)
    The scene graph reference node for this object.

`script`_ (`tes3script`_)
    The script that runs on the object.

`skills`_ (`table`_)
    A table of three numbers, representing the base values for the creature's combat, magic, and stealth skills.

`soul`_ (`number`_)
    The amount of soul value that the creature provides.

`soundCreature`_ (`tes3creature`_)
    A creature to use instead of this one for sound generation.

`sourceMod`_ (`string`_)
    The filename of the mod that owns this object.

`spells`_ (`tes3spellList`_)
    A list of spells that the actor has access to.

`stolenList`_ (`tes3iterator`_)
    A list of actors that the object has been stolen from.

`swims`_ (`boolean`_)
    Access to the creature's swims flag.

`type`_ (`number`_)
    The type of the creature, represented by a number for normal, daedra, undead, or humanoid.

`usesEquipment`_ (`boolean`_)
    Access to the creature's usesEquipment flag.

`walks`_ (`boolean`_)
    Access to the creature's walks flag.

.. toctree::
    :hidden:

    tes3creature/actorFlags
    tes3creature/aiConfig
    tes3creature/attacks
    tes3creature/attributes
    tes3creature/biped
    tes3creature/boundingBox
    tes3creature/cloneCount
    tes3creature/deleted
    tes3creature/disabled
    tes3creature/equipment
    tes3creature/fatigue
    tes3creature/flies
    tes3creature/health
    tes3creature/id
    tes3creature/inventory
    tes3creature/isAttacked
    tes3creature/isEssential
    tes3creature/isInstance
    tes3creature/isRespawn
    tes3creature/level
    tes3creature/magicka
    tes3creature/mesh
    tes3creature/modified
    tes3creature/name
    tes3creature/nextInCollection
    tes3creature/objectFlags
    tes3creature/objectType
    tes3creature/owningCollection
    tes3creature/previousInCollection
    tes3creature/respawns
    tes3creature/scale
    tes3creature/sceneNode
    tes3creature/sceneReference
    tes3creature/script
    tes3creature/skills
    tes3creature/soul
    tes3creature/soundCreature
    tes3creature/sourceMod
    tes3creature/spells
    tes3creature/stolenList
    tes3creature/swims
    tes3creature/type
    tes3creature/usesEquipment
    tes3creature/walks

.. _`actorFlags`: tes3creature/actorFlags.html
.. _`aiConfig`: tes3creature/aiConfig.html
.. _`attacks`: tes3creature/attacks.html
.. _`attributes`: tes3creature/attributes.html
.. _`biped`: tes3creature/biped.html
.. _`boundingBox`: tes3creature/boundingBox.html
.. _`cloneCount`: tes3creature/cloneCount.html
.. _`deleted`: tes3creature/deleted.html
.. _`disabled`: tes3creature/disabled.html
.. _`equipment`: tes3creature/equipment.html
.. _`fatigue`: tes3creature/fatigue.html
.. _`flies`: tes3creature/flies.html
.. _`health`: tes3creature/health.html
.. _`id`: tes3creature/id.html
.. _`inventory`: tes3creature/inventory.html
.. _`isAttacked`: tes3creature/isAttacked.html
.. _`isEssential`: tes3creature/isEssential.html
.. _`isInstance`: tes3creature/isInstance.html
.. _`isRespawn`: tes3creature/isRespawn.html
.. _`level`: tes3creature/level.html
.. _`magicka`: tes3creature/magicka.html
.. _`mesh`: tes3creature/mesh.html
.. _`modified`: tes3creature/modified.html
.. _`name`: tes3creature/name.html
.. _`nextInCollection`: tes3creature/nextInCollection.html
.. _`objectFlags`: tes3creature/objectFlags.html
.. _`objectType`: tes3creature/objectType.html
.. _`owningCollection`: tes3creature/owningCollection.html
.. _`previousInCollection`: tes3creature/previousInCollection.html
.. _`respawns`: tes3creature/respawns.html
.. _`scale`: tes3creature/scale.html
.. _`sceneNode`: tes3creature/sceneNode.html
.. _`sceneReference`: tes3creature/sceneReference.html
.. _`script`: tes3creature/script.html
.. _`skills`: tes3creature/skills.html
.. _`soul`: tes3creature/soul.html
.. _`soundCreature`: tes3creature/soundCreature.html
.. _`sourceMod`: tes3creature/sourceMod.html
.. _`spells`: tes3creature/spells.html
.. _`stolenList`: tes3creature/stolenList.html
.. _`swims`: tes3creature/swims.html
.. _`type`: tes3creature/type.html
.. _`usesEquipment`: tes3creature/usesEquipment.html
.. _`walks`: tes3creature/walks.html

Methods
----------------------------------------------------------------------------------------------------

`onInventoryClose`_
    A callback function invoked when an inventory is closed. Typically not used outside of specific purposes.

.. toctree::
    :hidden:

    tes3creature/onInventoryClose

.. _`onInventoryClose`: tes3creature/onInventoryClose.html

.. _`tes3creature`: ../../lua/type/tes3creature.html
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
.. _`tes3class`: ../../lua/type/tes3class.html
.. _`tes3mobileProjectile`: ../../lua/type/tes3mobileProjectile.html
.. _`tes3weatherSnow`: ../../lua/type/tes3weatherSnow.html
.. _`tes3apparatus`: ../../lua/type/tes3apparatus.html
.. _`tes3door`: ../../lua/type/tes3door.html
.. _`tes3weatherRain`: ../../lua/type/tes3weatherRain.html
.. _`tes3light`: ../../lua/type/tes3light.html
.. _`tes3directInputMouseState`: ../../lua/type/tes3directInputMouseState.html
.. _`nil`: ../../lua/type/nil.html
.. _`niRTTI`: ../../lua/type/niRTTI.html
.. _`tes3weatherController`: ../../lua/type/tes3weatherController.html
.. _`niObjectNET`: ../../lua/type/niObjectNET.html
.. _`tes3mobileObject`: ../../lua/type/tes3mobileObject.html
.. _`tes3moon`: ../../lua/type/tes3moon.html
.. _`tes3weatherBlizzard`: ../../lua/type/tes3weatherBlizzard.html
.. _`tes3container`: ../../lua/type/tes3container.html
.. _`tes3armor`: ../../lua/type/tes3armor.html
.. _`tes3reference`: ../../lua/type/tes3reference.html
.. _`tes3npcInstance`: ../../lua/type/tes3npcInstance.html
.. _`tes3weather`: ../../lua/type/tes3weather.html
.. _`tes3wearablePart`: ../../lua/type/tes3wearablePart.html
.. _`tes3dataHandler`: ../../lua/type/tes3dataHandler.html
.. _`tes3rangeInt`: ../../lua/type/tes3rangeInt.html
.. _`tes3dialogueInfo`: ../../lua/type/tes3dialogueInfo.html
.. _`tes3vector4`: ../../lua/type/tes3vector4.html
.. _`tes3weatherAsh`: ../../lua/type/tes3weatherAsh.html
.. _`tes3vector2`: ../../lua/type/tes3vector2.html
.. _`tes3travelDestinationNode`: ../../lua/type/tes3travelDestinationNode.html
.. _`tes3dialogue`: ../../lua/type/tes3dialogue.html
.. _`tes3gameFile`: ../../lua/type/tes3gameFile.html
.. _`tes3faction`: ../../lua/type/tes3faction.html
.. _`tes3transform`: ../../lua/type/tes3transform.html
.. _`tes3inputController`: ../../lua/type/tes3inputController.html
.. _`tes3lockpick`: ../../lua/type/tes3lockpick.html
.. _`tes3combatSession`: ../../lua/type/tes3combatSession.html
.. _`boolean`: ../../lua/type/boolean.html
.. _`tes3statistic`: ../../lua/type/tes3statistic.html
.. _`tes3magicEffect`: ../../lua/type/tes3magicEffect.html
.. _`string`: ../../lua/type/string.html
.. _`tes3static`: ../../lua/type/tes3static.html
.. _`tes3iteratorNode`: ../../lua/type/tes3iteratorNode.html
.. _`tes3item`: ../../lua/type/tes3item.html
.. _`tes3quest`: ../../lua/type/tes3quest.html
.. _`tes3nonDynamicData`: ../../lua/type/tes3nonDynamicData.html
.. _`tes3ingredient`: ../../lua/type/tes3ingredient.html
.. _`tes3race`: ../../lua/type/tes3race.html
.. _`tes3gameSetting`: ../../lua/type/tes3gameSetting.html
.. _`tes3soulGemData`: ../../lua/type/tes3soulGemData.html
.. _`table`: ../../lua/type/table.html
.. _`tes3referenceList`: ../../lua/type/tes3referenceList.html
.. _`tes3mobileCreature`: ../../lua/type/tes3mobileCreature.html
.. _`tes3mobileNPC`: ../../lua/type/tes3mobileNPC.html
.. _`tes3regionSound`: ../../lua/type/tes3regionSound.html
.. _`tes3vector3`: ../../lua/type/tes3vector3.html
.. _`tes3raceSkillBonus`: ../../lua/type/tes3raceSkillBonus.html
.. _`tes3raceBodyParts`: ../../lua/type/tes3raceBodyParts.html
.. _`tes3activator`: ../../lua/type/tes3activator.html
.. _`tes3raceBaseAttribute`: ../../lua/type/tes3raceBaseAttribute.html
.. _`tes3inventory`: ../../lua/type/tes3inventory.html
.. _`tes3boundingBox`: ../../lua/type/tes3boundingBox.html
.. _`tes3markData`: ../../lua/type/tes3markData.html
.. _`tes3probe`: ../../lua/type/tes3probe.html
.. _`tes3creatureInstance`: ../../lua/type/tes3creatureInstance.html
.. _`tes3effect`: ../../lua/type/tes3effect.html
.. _`tes3game`: ../../lua/type/tes3game.html
.. _`tes3physicalObject`: ../../lua/type/tes3physicalObject.html
.. _`tes3lockNode`: ../../lua/type/tes3lockNode.html
.. _`tes3object`: ../../lua/type/tes3object.html
.. _`tes3weatherClear`: ../../lua/type/tes3weatherClear.html
.. _`number`: ../../lua/type/number.html
.. _`tes3mobilePlayer`: ../../lua/type/tes3mobilePlayer.html
.. _`tes3weatherCloudy`: ../../lua/type/tes3weatherCloudy.html
.. _`tes3region`: ../../lua/type/tes3region.html
.. _`tes3misc`: ../../lua/type/tes3misc.html
.. _`tes3leveledListNode`: ../../lua/type/tes3leveledListNode.html
.. _`tes3mobileActor`: ../../lua/type/tes3mobileActor.html
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
.. _`tes3leveledItem`: ../../lua/type/tes3leveledItem.html
.. _`tes3alchemy`: ../../lua/type/tes3alchemy.html
.. _`tes3enchantment`: ../../lua/type/tes3enchantment.html
.. _`tes3cell`: ../../lua/type/tes3cell.html
.. _`tes3actionData`: ../../lua/type/tes3actionData.html
.. _`tes3itemData`: ../../lua/type/tes3itemData.html
.. _`tes3factionReaction`: ../../lua/type/tes3factionReaction.html
