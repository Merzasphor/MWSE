tes3mobileActor
====================================================================================================

A mobile object for a creature, NPC, or the player.

Properties
----------------------------------------------------------------------------------------------------

`actionBeforeCombat`_ (`tes3actionData`_)
    Action data stored before the actor entered combat.

`actionData`_ (`tes3actionData`_)
    Current action data. Pre-combat action data is stored in the actionBeforeCombat property.

`activeAI`_ (`boolean`_)
    Friendly access to the actor's flag that controls if AI is active.

`activeMagicEffectCount`_ (`number`_)
    The number of active magic effects currently operating on the actor.

`activeMagicEffects`_ (`tes3activeMagicEffect`_)
    The first active magic effect on the actor, from which all others can be accessed.

`actorType`_ (`number`_)
    The type of the mobile actor, showing if it belongs to a creature, NPC, or the player.

`agility`_ (`tes3statistic`_)
    Direct access to the actor's agility attribute statistic.

`aiPlanner`_ (`tes3aiPlanner`_)
    Access to the mobile's AI planner and AI package information.

`alarm`_ (`number`_)
    The actor's alarm AI value.

`animationData`_ (`tes3actorAnimationData`_)
    No description available.

`attackBonus`_ (`number`_)
    Direct access to the actor's attack bonus effect attribute.

`attacked`_ (`boolean`_)
    Friendly access to the actor's flag that controls if the actor has been attacked.

`attributes`_ (`table`_)
    Access to a table of 8 tes3statistic objects for the actor's attributes.

`barterGold`_ (`number`_)
    The current amount of gold that the actor has access to for bartering.

`blind`_ (`number`_)
    Direct access to the actor's blind effect attribute.

`boundSize`_ (`tes3vector3`_)
    A vector that shows the size of the bounding box in each direction.

`cell`_ (`tes3cell`_)
    Fetches the cell that the actor is in.

`cellX`_ (`number`_)
    The X grid coordinate of the cell the mobile is in.

`cellY`_ (`number`_)
    The Y grid coordinate of the cell the mobile is in.

`chameleon`_ (`number`_)
    Direct access to the actor's chameleon effect attribute.

`collidingReference`_ (`tes3reference`_)
    The reference that the mobile has collided with this frame.

`corpseHourstamp`_ (`number`_)
    No description available.

`currentEnchantedItem`_ (`tes3equipmentStack`_)
    The currently equipped enchanted item that the actor will use.

`currentSpell`_ (`tes3spell`_)
    The currently equipped spell that the actor will use.

`effectAttributes`_ (`table`_)
    Access to a table of 24 numbers for the actor's effect attributes.

`encumbrance`_ (`tes3statistic`_)
    Access to the actor's encumbrance statistic.

`endurance`_ (`tes3statistic`_)
    Direct access to the actor's endurance attribute statistic.

`fatigue`_ (`tes3statistic`_)
    Access to the actor's fatigue statistic.

`fight`_ (`number`_)
    The actor's fight AI value.

`flags`_ (`number`_)
    Access to the root mobile object flags, represented as an integer. Should not be accessed directly.

`flee`_ (`number`_)
    The actor's flee AI value.

`friendlyActors`_ (`tes3iterator`_)
    A collection of other tes3mobileActors that this actor considers friendly.

`greetDuration`_ (`number`_)
    No description available.

`greetTimer`_ (`number`_)
    No description available.

`health`_ (`tes3statistic`_)
    Access to the actor's health statistic.

`height`_ (`number`_)
    The height of the mobile above the ground.

`hello`_ (`number`_)
    The actor's hello AI value.

`holdBreathTime`_ (`number`_)
    No description available.

`hostileActors`_ (`tes3iterator`_)
    A collection of other tes3mobileActors that this actor considers hostile.

`idleAnim`_ (`boolean`_)
    Friendly access to the actor's flag that controls if the actor is using their idle animation.

`impulseVelocity`_ (`tes3vector3`_)
    A vector that represents the 3D acceleration of the object.

`inCombat`_ (`boolean`_)
    Friendly access to the actor's flag that controls if the actor is in combat.

`intelligence`_ (`tes3statistic`_)
    Direct access to the actor's intelligence attribute statistic.

`invisibility`_ (`number`_)
    Direct access to the actor's invisibility effect attribute.

`isCrittable`_ (`boolean`_)
    Friendly access to the actor's flag that controls if the actor can be crittically hit.

`isFlying`_ (`boolean`_)
    Direct access to the actor's current movement flags, showing if the actor is flying.

`isJumping`_ (`boolean`_)
    Direct access to the actor's current movement flags, showing if the actor is jumping.

`isMovingBack`_ (`boolean`_)
    Direct access to the actor's current movement flags, showing if the actor is moving backwards.

`isMovingForward`_ (`boolean`_)
    Direct access to the actor's current movement flags, showing if the actor is moving forwards.

`isMovingLeft`_ (`boolean`_)
    Direct access to the actor's current movement flags, showing if the actor is moving left.

`isMovingRight`_ (`boolean`_)
    Direct access to the actor's current movement flags, showing if the actor is moving right.

`isRunning`_ (`boolean`_)
    Direct access to the actor's current movement flags, showing if the actor is running.

`isSneaking`_ (`boolean`_)
    Direct access to the actor's current movement flags, showing if the actor is sneaking.

`isStartingJump`_ (`boolean`_)
    Direct access to the actor's current movement flags, showing if the actor has started jumping.

`isSwimming`_ (`boolean`_)
    Direct access to the actor's current movement flags, showing if the actor is swimming.

`isTurningLeft`_ (`boolean`_)
    Direct access to the actor's current movement flags, showing if the actor is turning left.

`isTurningRight`_ (`boolean`_)
    Direct access to the actor's current movement flags, showing if the actor is turning right.

`isWalking`_ (`boolean`_)
    Direct access to the actor's current movement flags, showing if the actor is walking.

`jump`_ (`number`_)
    Direct access to the actor's jump effect attribute.

`lastGroundZ`_ (`number`_)
    No description available.

`levitate`_ (`number`_)
    Direct access to the actor's levitate effect attribute.

`luck`_ (`tes3statistic`_)
    Direct access to the actor's luck attribute statistic.

`magicka`_ (`tes3statistic`_)
    Access to the actor's magicka statistic.

`magickaMultiplier`_ (`tes3statistic`_)
    Access to the actor's magicka multiplier statistic.

`movementFlags`_ (`number`_)
    Access to the root mobile object movement flags, represented as an integer. Should not be accessed directly.

`nextActionWeight`_ (`number`_)
    No description available.

`objectType`_ (`number`_)
    The type of mobile object. Maps to values in tes3.objectType.

`paralyze`_ (`number`_)
    Direct access to the actor's paralyze effect attribute.

`personality`_ (`tes3statistic`_)
    Direct access to the actor's personality attribute statistic.

`position`_ (`tes3vector3`_)
    A vector that represents the 3D position of the object.

`prevMovementFlags`_ (`number`_)
    Access to the root mobile object movement flags from the previous frame, represented as an integer. Should not be accessed directly.

`readiedAmmo`_ (`tes3equipmentStack`_)
    The currently equipped ammo.

`readiedAmmoCount`_ (`number`_)
    The number of ammo equipped for the readied ammo.

`readiedShield`_ (`tes3equipmentStack`_)
    The currently equipped shield.

`readiedWeapon`_ (`tes3equipmentStack`_)
    The currently equipped weapon.

`reference`_ (`tes3reference`_)
    Access to the reference object for the mobile, if any.

`resistBlightDisease`_ (`number`_)
    Direct access to the actor's blight disease resistance effect attribute.

`resistCommonDisease`_ (`number`_)
    Direct access to the actor's common disease resistance effect attribute.

`resistCorprus`_ (`number`_)
    Direct access to the actor's corprus disease resistance effect attribute.

`resistFire`_ (`number`_)
    Direct access to the actor's fire resistance effect attribute.

`resistFrost`_ (`number`_)
    Direct access to the actor's frost resistance effect attribute.

`resistMagicka`_ (`number`_)
    Direct access to the actor's magicka resistance effect attribute.

`resistNormalWeapons`_ (`number`_)
    Direct access to the actor's normal weapon resistance effect attribute.

`resistParalysis`_ (`number`_)
    Direct access to the actor's paralysis resistance effect attribute.

`resistPoison`_ (`number`_)
    Direct access to the actor's poison resistance effect attribute.

`resistShock`_ (`number`_)
    Direct access to the actor's shock resistance effect attribute.

`sanctuary`_ (`number`_)
    Direct access to the actor's sanctuary effect attribute.

`scanInterval`_ (`number`_)
    No description available.

`scanTimer`_ (`number`_)
    No description available.

`shield`_ (`number`_)
    Direct access to the actor's shield effect attribute.

`silence`_ (`number`_)
    Direct access to the actor's silence effect attribute.

`sound`_ (`number`_)
    Direct access to the actor's sound effect attribute.

`speed`_ (`tes3statistic`_)
    Direct access to the actor's speed attribute statistic.

`spellReadied`_ (`boolean`_)
    Friendly access to the actor's flag that controls if the actor has a spell readied.

`strength`_ (`tes3statistic`_)
    Direct access to the actor's strength attribute statistic.

`swiftSwim`_ (`number`_)
    Direct access to the actor's swift swim effect attribute.

`torchSlot`_ (`tes3equipmentStack`_)
    The currently equipped light.

`underwater`_ (`boolean`_)
    Friendly access to the actor's flag that controls if the actor is under water.

`velocity`_ (`tes3vector3`_)
    A vector that represents the 3D velocity of the object.

`waterBreathing`_ (`number`_)
    Direct access to the actor's water breathing effect attribute.

`waterWalking`_ (`number`_)
    Direct access to the actor's water walking effect attribute.

`weaponDrawn`_ (`boolean`_)
    Friendly access to the actor's flag that controls if the actor has a weapon readied.

`werewolf`_ (`boolean`_)
    Friendly access to the actor's flag that controls if the actor in werewolf form.

`width`_ (`number`_)
    No description available.

`willpower`_ (`tes3statistic`_)
    Direct access to the actor's willpower attribute statistic.

.. toctree::
    :hidden:

    tes3mobileActor/actionBeforeCombat
    tes3mobileActor/actionData
    tes3mobileActor/activeAI
    tes3mobileActor/activeMagicEffectCount
    tes3mobileActor/activeMagicEffects
    tes3mobileActor/actorType
    tes3mobileActor/agility
    tes3mobileActor/aiPlanner
    tes3mobileActor/alarm
    tes3mobileActor/animationData
    tes3mobileActor/attackBonus
    tes3mobileActor/attacked
    tes3mobileActor/attributes
    tes3mobileActor/barterGold
    tes3mobileActor/blind
    tes3mobileActor/boundSize
    tes3mobileActor/cell
    tes3mobileActor/cellX
    tes3mobileActor/cellY
    tes3mobileActor/chameleon
    tes3mobileActor/collidingReference
    tes3mobileActor/corpseHourstamp
    tes3mobileActor/currentEnchantedItem
    tes3mobileActor/currentSpell
    tes3mobileActor/effectAttributes
    tes3mobileActor/encumbrance
    tes3mobileActor/endurance
    tes3mobileActor/fatigue
    tes3mobileActor/fight
    tes3mobileActor/flags
    tes3mobileActor/flee
    tes3mobileActor/friendlyActors
    tes3mobileActor/greetDuration
    tes3mobileActor/greetTimer
    tes3mobileActor/health
    tes3mobileActor/height
    tes3mobileActor/hello
    tes3mobileActor/holdBreathTime
    tes3mobileActor/hostileActors
    tes3mobileActor/idleAnim
    tes3mobileActor/impulseVelocity
    tes3mobileActor/inCombat
    tes3mobileActor/intelligence
    tes3mobileActor/invisibility
    tes3mobileActor/isCrittable
    tes3mobileActor/isFlying
    tes3mobileActor/isJumping
    tes3mobileActor/isMovingBack
    tes3mobileActor/isMovingForward
    tes3mobileActor/isMovingLeft
    tes3mobileActor/isMovingRight
    tes3mobileActor/isRunning
    tes3mobileActor/isSneaking
    tes3mobileActor/isStartingJump
    tes3mobileActor/isSwimming
    tes3mobileActor/isTurningLeft
    tes3mobileActor/isTurningRight
    tes3mobileActor/isWalking
    tes3mobileActor/jump
    tes3mobileActor/lastGroundZ
    tes3mobileActor/levitate
    tes3mobileActor/luck
    tes3mobileActor/magicka
    tes3mobileActor/magickaMultiplier
    tes3mobileActor/movementFlags
    tes3mobileActor/nextActionWeight
    tes3mobileActor/objectType
    tes3mobileActor/paralyze
    tes3mobileActor/personality
    tes3mobileActor/position
    tes3mobileActor/prevMovementFlags
    tes3mobileActor/readiedAmmo
    tes3mobileActor/readiedAmmoCount
    tes3mobileActor/readiedShield
    tes3mobileActor/readiedWeapon
    tes3mobileActor/reference
    tes3mobileActor/resistBlightDisease
    tes3mobileActor/resistCommonDisease
    tes3mobileActor/resistCorprus
    tes3mobileActor/resistFire
    tes3mobileActor/resistFrost
    tes3mobileActor/resistMagicka
    tes3mobileActor/resistNormalWeapons
    tes3mobileActor/resistParalysis
    tes3mobileActor/resistPoison
    tes3mobileActor/resistShock
    tes3mobileActor/sanctuary
    tes3mobileActor/scanInterval
    tes3mobileActor/scanTimer
    tes3mobileActor/shield
    tes3mobileActor/silence
    tes3mobileActor/sound
    tes3mobileActor/speed
    tes3mobileActor/spellReadied
    tes3mobileActor/strength
    tes3mobileActor/swiftSwim
    tes3mobileActor/torchSlot
    tes3mobileActor/underwater
    tes3mobileActor/velocity
    tes3mobileActor/waterBreathing
    tes3mobileActor/waterWalking
    tes3mobileActor/weaponDrawn
    tes3mobileActor/werewolf
    tes3mobileActor/width
    tes3mobileActor/willpower

.. _`actionBeforeCombat`: tes3mobileActor/actionBeforeCombat.html
.. _`actionData`: tes3mobileActor/actionData.html
.. _`activeAI`: tes3mobileActor/activeAI.html
.. _`activeMagicEffectCount`: tes3mobileActor/activeMagicEffectCount.html
.. _`activeMagicEffects`: tes3mobileActor/activeMagicEffects.html
.. _`actorType`: tes3mobileActor/actorType.html
.. _`agility`: tes3mobileActor/agility.html
.. _`aiPlanner`: tes3mobileActor/aiPlanner.html
.. _`alarm`: tes3mobileActor/alarm.html
.. _`animationData`: tes3mobileActor/animationData.html
.. _`attackBonus`: tes3mobileActor/attackBonus.html
.. _`attacked`: tes3mobileActor/attacked.html
.. _`attributes`: tes3mobileActor/attributes.html
.. _`barterGold`: tes3mobileActor/barterGold.html
.. _`blind`: tes3mobileActor/blind.html
.. _`boundSize`: tes3mobileActor/boundSize.html
.. _`cell`: tes3mobileActor/cell.html
.. _`cellX`: tes3mobileActor/cellX.html
.. _`cellY`: tes3mobileActor/cellY.html
.. _`chameleon`: tes3mobileActor/chameleon.html
.. _`collidingReference`: tes3mobileActor/collidingReference.html
.. _`corpseHourstamp`: tes3mobileActor/corpseHourstamp.html
.. _`currentEnchantedItem`: tes3mobileActor/currentEnchantedItem.html
.. _`currentSpell`: tes3mobileActor/currentSpell.html
.. _`effectAttributes`: tes3mobileActor/effectAttributes.html
.. _`encumbrance`: tes3mobileActor/encumbrance.html
.. _`endurance`: tes3mobileActor/endurance.html
.. _`fatigue`: tes3mobileActor/fatigue.html
.. _`fight`: tes3mobileActor/fight.html
.. _`flags`: tes3mobileActor/flags.html
.. _`flee`: tes3mobileActor/flee.html
.. _`friendlyActors`: tes3mobileActor/friendlyActors.html
.. _`greetDuration`: tes3mobileActor/greetDuration.html
.. _`greetTimer`: tes3mobileActor/greetTimer.html
.. _`health`: tes3mobileActor/health.html
.. _`height`: tes3mobileActor/height.html
.. _`hello`: tes3mobileActor/hello.html
.. _`holdBreathTime`: tes3mobileActor/holdBreathTime.html
.. _`hostileActors`: tes3mobileActor/hostileActors.html
.. _`idleAnim`: tes3mobileActor/idleAnim.html
.. _`impulseVelocity`: tes3mobileActor/impulseVelocity.html
.. _`inCombat`: tes3mobileActor/inCombat.html
.. _`intelligence`: tes3mobileActor/intelligence.html
.. _`invisibility`: tes3mobileActor/invisibility.html
.. _`isCrittable`: tes3mobileActor/isCrittable.html
.. _`isFlying`: tes3mobileActor/isFlying.html
.. _`isJumping`: tes3mobileActor/isJumping.html
.. _`isMovingBack`: tes3mobileActor/isMovingBack.html
.. _`isMovingForward`: tes3mobileActor/isMovingForward.html
.. _`isMovingLeft`: tes3mobileActor/isMovingLeft.html
.. _`isMovingRight`: tes3mobileActor/isMovingRight.html
.. _`isRunning`: tes3mobileActor/isRunning.html
.. _`isSneaking`: tes3mobileActor/isSneaking.html
.. _`isStartingJump`: tes3mobileActor/isStartingJump.html
.. _`isSwimming`: tes3mobileActor/isSwimming.html
.. _`isTurningLeft`: tes3mobileActor/isTurningLeft.html
.. _`isTurningRight`: tes3mobileActor/isTurningRight.html
.. _`isWalking`: tes3mobileActor/isWalking.html
.. _`jump`: tes3mobileActor/jump.html
.. _`lastGroundZ`: tes3mobileActor/lastGroundZ.html
.. _`levitate`: tes3mobileActor/levitate.html
.. _`luck`: tes3mobileActor/luck.html
.. _`magicka`: tes3mobileActor/magicka.html
.. _`magickaMultiplier`: tes3mobileActor/magickaMultiplier.html
.. _`movementFlags`: tes3mobileActor/movementFlags.html
.. _`nextActionWeight`: tes3mobileActor/nextActionWeight.html
.. _`objectType`: tes3mobileActor/objectType.html
.. _`paralyze`: tes3mobileActor/paralyze.html
.. _`personality`: tes3mobileActor/personality.html
.. _`position`: tes3mobileActor/position.html
.. _`prevMovementFlags`: tes3mobileActor/prevMovementFlags.html
.. _`readiedAmmo`: tes3mobileActor/readiedAmmo.html
.. _`readiedAmmoCount`: tes3mobileActor/readiedAmmoCount.html
.. _`readiedShield`: tes3mobileActor/readiedShield.html
.. _`readiedWeapon`: tes3mobileActor/readiedWeapon.html
.. _`reference`: tes3mobileActor/reference.html
.. _`resistBlightDisease`: tes3mobileActor/resistBlightDisease.html
.. _`resistCommonDisease`: tes3mobileActor/resistCommonDisease.html
.. _`resistCorprus`: tes3mobileActor/resistCorprus.html
.. _`resistFire`: tes3mobileActor/resistFire.html
.. _`resistFrost`: tes3mobileActor/resistFrost.html
.. _`resistMagicka`: tes3mobileActor/resistMagicka.html
.. _`resistNormalWeapons`: tes3mobileActor/resistNormalWeapons.html
.. _`resistParalysis`: tes3mobileActor/resistParalysis.html
.. _`resistPoison`: tes3mobileActor/resistPoison.html
.. _`resistShock`: tes3mobileActor/resistShock.html
.. _`sanctuary`: tes3mobileActor/sanctuary.html
.. _`scanInterval`: tes3mobileActor/scanInterval.html
.. _`scanTimer`: tes3mobileActor/scanTimer.html
.. _`shield`: tes3mobileActor/shield.html
.. _`silence`: tes3mobileActor/silence.html
.. _`sound`: tes3mobileActor/sound.html
.. _`speed`: tes3mobileActor/speed.html
.. _`spellReadied`: tes3mobileActor/spellReadied.html
.. _`strength`: tes3mobileActor/strength.html
.. _`swiftSwim`: tes3mobileActor/swiftSwim.html
.. _`torchSlot`: tes3mobileActor/torchSlot.html
.. _`underwater`: tes3mobileActor/underwater.html
.. _`velocity`: tes3mobileActor/velocity.html
.. _`waterBreathing`: tes3mobileActor/waterBreathing.html
.. _`waterWalking`: tes3mobileActor/waterWalking.html
.. _`weaponDrawn`: tes3mobileActor/weaponDrawn.html
.. _`werewolf`: tes3mobileActor/werewolf.html
.. _`width`: tes3mobileActor/width.html
.. _`willpower`: tes3mobileActor/willpower.html

Methods
----------------------------------------------------------------------------------------------------

`applyHealthDamage`_ (`boolean`_)
    Damages the actor.

`getSkillStatistic`_ (`tes3skillStatistic`_)
    Fetches the statistic object of a skill with a given index. This converts to the limited options available for creatures.

`getSkillValue`_ (`number`_)
    Fetches the current value of a skill with a given index. This converts to the limited options available for creatures.

`hasFreeAction`_ (`boolean`_)
    If true, the actor isn't paralyzed, dead, stunned, or otherwise unable to take action.

`isAffectedByObject`_ (`boolean`_)
    Determines if the actor is currently being affected by a given alchemy, enchantment, or spell.

`startCombat`_
    Forces the actor into combat with another actor.

`startDialogue`_
    Starts dialogue with this actor for the player.

`stopCombat`_
    Ends combat for the actor.

.. toctree::
    :hidden:

    tes3mobileActor/applyHealthDamage
    tes3mobileActor/getSkillStatistic
    tes3mobileActor/getSkillValue
    tes3mobileActor/hasFreeAction
    tes3mobileActor/isAffectedByObject
    tes3mobileActor/startCombat
    tes3mobileActor/startDialogue
    tes3mobileActor/stopCombat

.. _`applyHealthDamage`: tes3mobileActor/applyHealthDamage.html
.. _`getSkillStatistic`: tes3mobileActor/getSkillStatistic.html
.. _`getSkillValue`: tes3mobileActor/getSkillValue.html
.. _`hasFreeAction`: tes3mobileActor/hasFreeAction.html
.. _`isAffectedByObject`: tes3mobileActor/isAffectedByObject.html
.. _`startCombat`: tes3mobileActor/startCombat.html
.. _`startDialogue`: tes3mobileActor/startDialogue.html
.. _`stopCombat`: tes3mobileActor/stopCombat.html

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
.. _`niObjectNET`: ../../lua/type/niObjectNET.html
.. _`tes3armor`: ../../lua/type/tes3armor.html
.. _`tes3npcInstance`: ../../lua/type/tes3npcInstance.html
.. _`tes3dataHandler`: ../../lua/type/tes3dataHandler.html
.. _`tes3rangeInt`: ../../lua/type/tes3rangeInt.html
.. _`tes3dialogueInfo`: ../../lua/type/tes3dialogueInfo.html
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
.. _`nil`: ../../lua/type/nil.html
.. _`number`: ../../lua/type/number.html
.. _`tes3moon`: ../../lua/type/tes3moon.html
.. _`tes3mobilePlayer`: ../../lua/type/tes3mobilePlayer.html
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
.. _`tes3container`: ../../lua/type/tes3container.html
.. _`tes3packedColor`: ../../lua/type/tes3packedColor.html
.. _`bool`: ../../lua/type/boolean.html
.. _`tes3equipmentStack`: ../../lua/type/tes3equipmentStack.html
.. _`tes3clothing`: ../../lua/type/tes3clothing.html
.. _`mwseTimerController`: ../../lua/type/mwseTimerController.html
.. _`tes3leveledCreature`: ../../lua/type/tes3leveledCreature.html
.. _`tes3lockNode`: ../../lua/type/tes3lockNode.html
.. _`tes3activeMagicEffect`: ../../lua/type/tes3activeMagicEffect.html
.. _`tes3cellExteriorData`: ../../lua/type/tes3cellExteriorData.html
.. _`tes3light`: ../../lua/type/tes3light.html
.. _`tes3leveledItem`: ../../lua/type/tes3leveledItem.html
.. _`tes3alchemy`: ../../lua/type/tes3alchemy.html
.. _`tes3enchantment`: ../../lua/type/tes3enchantment.html
.. _`tes3cell`: ../../lua/type/tes3cell.html
.. _`tes3actionData`: ../../lua/type/tes3actionData.html
.. _`tes3itemData`: ../../lua/type/tes3itemData.html
.. _`tes3factionReaction`: ../../lua/type/tes3factionReaction.html
