tes3mobileCreature
====================================================================================================

A mobile object for a creature.

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

`combat`_ (`tes3statistic`_)
    Direct access to the creature's combat statistic.

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

`flySpeed`_ (`number`_)
    The calculated fly movement speed.

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

`magic`_ (`tes3statistic`_)
    Direct access to the creature's magic statistic.

`magicka`_ (`tes3statistic`_)
    Access to the actor's magicka statistic.

`magickaMultiplier`_ (`tes3statistic`_)
    Access to the actor's magicka multiplier statistic.

`moveSpeed`_ (`number`_)
    The calculated base movement speed.

`movementFlags`_ (`number`_)
    Access to the root mobile object movement flags, represented as an integer. Should not be accessed directly.

`nextActionWeight`_ (`number`_)
    No description available.

`object`_ (`tes3creatureInstance`_)
    The actor object that maps to this mobile.

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

`runSpeed`_ (`number`_)
    The calculated run movement speed.

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

`skills`_ (`table`_)
    An array-style table with access to the three creature skill statistics.

`sound`_ (`number`_)
    Direct access to the actor's sound effect attribute.

`speed`_ (`tes3statistic`_)
    Direct access to the actor's speed attribute statistic.

`spellReadied`_ (`boolean`_)
    Friendly access to the actor's flag that controls if the actor has a spell readied.

`stealth`_ (`tes3statistic`_)
    Direct access to the creature's stealth statistic.

`strength`_ (`tes3statistic`_)
    Direct access to the actor's strength attribute statistic.

`swiftSwim`_ (`number`_)
    Direct access to the actor's swift swim effect attribute.

`swimRunSpeed`_ (`number`_)
    The calculated swim movement speed while running.

`swimSpeed`_ (`number`_)
    The calculated swim movement speed.

`torchSlot`_ (`tes3equipmentStack`_)
    The currently equipped light.

`underwater`_ (`boolean`_)
    Friendly access to the actor's flag that controls if the actor is under water.

`velocity`_ (`tes3vector3`_)
    A vector that represents the 3D velocity of the object.

`walkSpeed`_ (`number`_)
    The calculated walk movement speed.

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

    tes3mobileCreature/actionBeforeCombat
    tes3mobileCreature/actionData
    tes3mobileCreature/activeAI
    tes3mobileCreature/activeMagicEffectCount
    tes3mobileCreature/activeMagicEffects
    tes3mobileCreature/actorType
    tes3mobileCreature/agility
    tes3mobileCreature/aiPlanner
    tes3mobileCreature/alarm
    tes3mobileCreature/animationData
    tes3mobileCreature/attackBonus
    tes3mobileCreature/attacked
    tes3mobileCreature/attributes
    tes3mobileCreature/barterGold
    tes3mobileCreature/blind
    tes3mobileCreature/boundSize
    tes3mobileCreature/cell
    tes3mobileCreature/cellX
    tes3mobileCreature/cellY
    tes3mobileCreature/chameleon
    tes3mobileCreature/collidingReference
    tes3mobileCreature/combat
    tes3mobileCreature/corpseHourstamp
    tes3mobileCreature/currentEnchantedItem
    tes3mobileCreature/currentSpell
    tes3mobileCreature/effectAttributes
    tes3mobileCreature/encumbrance
    tes3mobileCreature/endurance
    tes3mobileCreature/fatigue
    tes3mobileCreature/fight
    tes3mobileCreature/flags
    tes3mobileCreature/flee
    tes3mobileCreature/flySpeed
    tes3mobileCreature/friendlyActors
    tes3mobileCreature/greetDuration
    tes3mobileCreature/greetTimer
    tes3mobileCreature/health
    tes3mobileCreature/height
    tes3mobileCreature/hello
    tes3mobileCreature/holdBreathTime
    tes3mobileCreature/hostileActors
    tes3mobileCreature/idleAnim
    tes3mobileCreature/impulseVelocity
    tes3mobileCreature/inCombat
    tes3mobileCreature/intelligence
    tes3mobileCreature/invisibility
    tes3mobileCreature/isCrittable
    tes3mobileCreature/isFlying
    tes3mobileCreature/isJumping
    tes3mobileCreature/isMovingBack
    tes3mobileCreature/isMovingForward
    tes3mobileCreature/isMovingLeft
    tes3mobileCreature/isMovingRight
    tes3mobileCreature/isRunning
    tes3mobileCreature/isSneaking
    tes3mobileCreature/isStartingJump
    tes3mobileCreature/isSwimming
    tes3mobileCreature/isTurningLeft
    tes3mobileCreature/isTurningRight
    tes3mobileCreature/isWalking
    tes3mobileCreature/jump
    tes3mobileCreature/lastGroundZ
    tes3mobileCreature/levitate
    tes3mobileCreature/luck
    tes3mobileCreature/magic
    tes3mobileCreature/magicka
    tes3mobileCreature/magickaMultiplier
    tes3mobileCreature/moveSpeed
    tes3mobileCreature/movementFlags
    tes3mobileCreature/nextActionWeight
    tes3mobileCreature/object
    tes3mobileCreature/objectType
    tes3mobileCreature/paralyze
    tes3mobileCreature/personality
    tes3mobileCreature/position
    tes3mobileCreature/prevMovementFlags
    tes3mobileCreature/readiedAmmo
    tes3mobileCreature/readiedAmmoCount
    tes3mobileCreature/readiedShield
    tes3mobileCreature/readiedWeapon
    tes3mobileCreature/reference
    tes3mobileCreature/resistBlightDisease
    tes3mobileCreature/resistCommonDisease
    tes3mobileCreature/resistCorprus
    tes3mobileCreature/resistFire
    tes3mobileCreature/resistFrost
    tes3mobileCreature/resistMagicka
    tes3mobileCreature/resistNormalWeapons
    tes3mobileCreature/resistParalysis
    tes3mobileCreature/resistPoison
    tes3mobileCreature/resistShock
    tes3mobileCreature/runSpeed
    tes3mobileCreature/sanctuary
    tes3mobileCreature/scanInterval
    tes3mobileCreature/scanTimer
    tes3mobileCreature/shield
    tes3mobileCreature/silence
    tes3mobileCreature/skills
    tes3mobileCreature/sound
    tes3mobileCreature/speed
    tes3mobileCreature/spellReadied
    tes3mobileCreature/stealth
    tes3mobileCreature/strength
    tes3mobileCreature/swiftSwim
    tes3mobileCreature/swimRunSpeed
    tes3mobileCreature/swimSpeed
    tes3mobileCreature/torchSlot
    tes3mobileCreature/underwater
    tes3mobileCreature/velocity
    tes3mobileCreature/walkSpeed
    tes3mobileCreature/waterBreathing
    tes3mobileCreature/waterWalking
    tes3mobileCreature/weaponDrawn
    tes3mobileCreature/werewolf
    tes3mobileCreature/width
    tes3mobileCreature/willpower

.. _`actionBeforeCombat`: tes3mobileCreature/actionBeforeCombat.html
.. _`actionData`: tes3mobileCreature/actionData.html
.. _`activeAI`: tes3mobileCreature/activeAI.html
.. _`activeMagicEffectCount`: tes3mobileCreature/activeMagicEffectCount.html
.. _`activeMagicEffects`: tes3mobileCreature/activeMagicEffects.html
.. _`actorType`: tes3mobileCreature/actorType.html
.. _`agility`: tes3mobileCreature/agility.html
.. _`aiPlanner`: tes3mobileCreature/aiPlanner.html
.. _`alarm`: tes3mobileCreature/alarm.html
.. _`animationData`: tes3mobileCreature/animationData.html
.. _`attackBonus`: tes3mobileCreature/attackBonus.html
.. _`attacked`: tes3mobileCreature/attacked.html
.. _`attributes`: tes3mobileCreature/attributes.html
.. _`barterGold`: tes3mobileCreature/barterGold.html
.. _`blind`: tes3mobileCreature/blind.html
.. _`boundSize`: tes3mobileCreature/boundSize.html
.. _`cell`: tes3mobileCreature/cell.html
.. _`cellX`: tes3mobileCreature/cellX.html
.. _`cellY`: tes3mobileCreature/cellY.html
.. _`chameleon`: tes3mobileCreature/chameleon.html
.. _`collidingReference`: tes3mobileCreature/collidingReference.html
.. _`combat`: tes3mobileCreature/combat.html
.. _`corpseHourstamp`: tes3mobileCreature/corpseHourstamp.html
.. _`currentEnchantedItem`: tes3mobileCreature/currentEnchantedItem.html
.. _`currentSpell`: tes3mobileCreature/currentSpell.html
.. _`effectAttributes`: tes3mobileCreature/effectAttributes.html
.. _`encumbrance`: tes3mobileCreature/encumbrance.html
.. _`endurance`: tes3mobileCreature/endurance.html
.. _`fatigue`: tes3mobileCreature/fatigue.html
.. _`fight`: tes3mobileCreature/fight.html
.. _`flags`: tes3mobileCreature/flags.html
.. _`flee`: tes3mobileCreature/flee.html
.. _`flySpeed`: tes3mobileCreature/flySpeed.html
.. _`friendlyActors`: tes3mobileCreature/friendlyActors.html
.. _`greetDuration`: tes3mobileCreature/greetDuration.html
.. _`greetTimer`: tes3mobileCreature/greetTimer.html
.. _`health`: tes3mobileCreature/health.html
.. _`height`: tes3mobileCreature/height.html
.. _`hello`: tes3mobileCreature/hello.html
.. _`holdBreathTime`: tes3mobileCreature/holdBreathTime.html
.. _`hostileActors`: tes3mobileCreature/hostileActors.html
.. _`idleAnim`: tes3mobileCreature/idleAnim.html
.. _`impulseVelocity`: tes3mobileCreature/impulseVelocity.html
.. _`inCombat`: tes3mobileCreature/inCombat.html
.. _`intelligence`: tes3mobileCreature/intelligence.html
.. _`invisibility`: tes3mobileCreature/invisibility.html
.. _`isCrittable`: tes3mobileCreature/isCrittable.html
.. _`isFlying`: tes3mobileCreature/isFlying.html
.. _`isJumping`: tes3mobileCreature/isJumping.html
.. _`isMovingBack`: tes3mobileCreature/isMovingBack.html
.. _`isMovingForward`: tes3mobileCreature/isMovingForward.html
.. _`isMovingLeft`: tes3mobileCreature/isMovingLeft.html
.. _`isMovingRight`: tes3mobileCreature/isMovingRight.html
.. _`isRunning`: tes3mobileCreature/isRunning.html
.. _`isSneaking`: tes3mobileCreature/isSneaking.html
.. _`isStartingJump`: tes3mobileCreature/isStartingJump.html
.. _`isSwimming`: tes3mobileCreature/isSwimming.html
.. _`isTurningLeft`: tes3mobileCreature/isTurningLeft.html
.. _`isTurningRight`: tes3mobileCreature/isTurningRight.html
.. _`isWalking`: tes3mobileCreature/isWalking.html
.. _`jump`: tes3mobileCreature/jump.html
.. _`lastGroundZ`: tes3mobileCreature/lastGroundZ.html
.. _`levitate`: tes3mobileCreature/levitate.html
.. _`luck`: tes3mobileCreature/luck.html
.. _`magic`: tes3mobileCreature/magic.html
.. _`magicka`: tes3mobileCreature/magicka.html
.. _`magickaMultiplier`: tes3mobileCreature/magickaMultiplier.html
.. _`moveSpeed`: tes3mobileCreature/moveSpeed.html
.. _`movementFlags`: tes3mobileCreature/movementFlags.html
.. _`nextActionWeight`: tes3mobileCreature/nextActionWeight.html
.. _`object`: tes3mobileCreature/object.html
.. _`objectType`: tes3mobileCreature/objectType.html
.. _`paralyze`: tes3mobileCreature/paralyze.html
.. _`personality`: tes3mobileCreature/personality.html
.. _`position`: tes3mobileCreature/position.html
.. _`prevMovementFlags`: tes3mobileCreature/prevMovementFlags.html
.. _`readiedAmmo`: tes3mobileCreature/readiedAmmo.html
.. _`readiedAmmoCount`: tes3mobileCreature/readiedAmmoCount.html
.. _`readiedShield`: tes3mobileCreature/readiedShield.html
.. _`readiedWeapon`: tes3mobileCreature/readiedWeapon.html
.. _`reference`: tes3mobileCreature/reference.html
.. _`resistBlightDisease`: tes3mobileCreature/resistBlightDisease.html
.. _`resistCommonDisease`: tes3mobileCreature/resistCommonDisease.html
.. _`resistCorprus`: tes3mobileCreature/resistCorprus.html
.. _`resistFire`: tes3mobileCreature/resistFire.html
.. _`resistFrost`: tes3mobileCreature/resistFrost.html
.. _`resistMagicka`: tes3mobileCreature/resistMagicka.html
.. _`resistNormalWeapons`: tes3mobileCreature/resistNormalWeapons.html
.. _`resistParalysis`: tes3mobileCreature/resistParalysis.html
.. _`resistPoison`: tes3mobileCreature/resistPoison.html
.. _`resistShock`: tes3mobileCreature/resistShock.html
.. _`runSpeed`: tes3mobileCreature/runSpeed.html
.. _`sanctuary`: tes3mobileCreature/sanctuary.html
.. _`scanInterval`: tes3mobileCreature/scanInterval.html
.. _`scanTimer`: tes3mobileCreature/scanTimer.html
.. _`shield`: tes3mobileCreature/shield.html
.. _`silence`: tes3mobileCreature/silence.html
.. _`skills`: tes3mobileCreature/skills.html
.. _`sound`: tes3mobileCreature/sound.html
.. _`speed`: tes3mobileCreature/speed.html
.. _`spellReadied`: tes3mobileCreature/spellReadied.html
.. _`stealth`: tes3mobileCreature/stealth.html
.. _`strength`: tes3mobileCreature/strength.html
.. _`swiftSwim`: tes3mobileCreature/swiftSwim.html
.. _`swimRunSpeed`: tes3mobileCreature/swimRunSpeed.html
.. _`swimSpeed`: tes3mobileCreature/swimSpeed.html
.. _`torchSlot`: tes3mobileCreature/torchSlot.html
.. _`underwater`: tes3mobileCreature/underwater.html
.. _`velocity`: tes3mobileCreature/velocity.html
.. _`walkSpeed`: tes3mobileCreature/walkSpeed.html
.. _`waterBreathing`: tes3mobileCreature/waterBreathing.html
.. _`waterWalking`: tes3mobileCreature/waterWalking.html
.. _`weaponDrawn`: tes3mobileCreature/weaponDrawn.html
.. _`werewolf`: tes3mobileCreature/werewolf.html
.. _`width`: tes3mobileCreature/width.html
.. _`willpower`: tes3mobileCreature/willpower.html

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

    tes3mobileCreature/applyHealthDamage
    tes3mobileCreature/getSkillStatistic
    tes3mobileCreature/getSkillValue
    tes3mobileCreature/hasFreeAction
    tes3mobileCreature/isAffectedByObject
    tes3mobileCreature/startCombat
    tes3mobileCreature/startDialogue
    tes3mobileCreature/stopCombat

.. _`applyHealthDamage`: tes3mobileCreature/applyHealthDamage.html
.. _`getSkillStatistic`: tes3mobileCreature/getSkillStatistic.html
.. _`getSkillValue`: tes3mobileCreature/getSkillValue.html
.. _`hasFreeAction`: tes3mobileCreature/hasFreeAction.html
.. _`isAffectedByObject`: tes3mobileCreature/isAffectedByObject.html
.. _`startCombat`: tes3mobileCreature/startCombat.html
.. _`startDialogue`: tes3mobileCreature/startDialogue.html
.. _`stopCombat`: tes3mobileCreature/stopCombat.html

.. _`tes3creature`: ../../lua/type/tes3creature.html
.. _`niObject`: ../../lua/type/niObject.html
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
.. _`tes3class`: ../../lua/type/tes3class.html
.. _`tes3mobileProjectile`: ../../lua/type/tes3mobileProjectile.html
.. _`tes3apparatus`: ../../lua/type/tes3apparatus.html
.. _`tes3door`: ../../lua/type/tes3door.html
.. _`tes3directInputMouseState`: ../../lua/type/tes3directInputMouseState.html
.. _`niRTTI`: ../../lua/type/niRTTI.html
.. _`niObjectNET`: ../../lua/type/niObjectNET.html
.. _`tes3armor`: ../../lua/type/tes3armor.html
.. _`tes3reference`: ../../lua/type/tes3reference.html
.. _`tes3dataHandler`: ../../lua/type/tes3dataHandler.html
.. _`tes3rangeInt`: ../../lua/type/tes3rangeInt.html
.. _`tes3dialogueInfo`: ../../lua/type/tes3dialogueInfo.html
.. _`tes3dialogue`: ../../lua/type/tes3dialogue.html
.. _`tes3gameFile`: ../../lua/type/tes3gameFile.html
.. _`tes3faction`: ../../lua/type/tes3faction.html
.. _`tes3inputController`: ../../lua/type/tes3inputController.html
.. _`tes3lockpick`: ../../lua/type/tes3lockpick.html
.. _`tes3combatSession`: ../../lua/type/tes3combatSession.html
.. _`boolean`: ../../lua/type/boolean.html
.. _`tes3magicEffect`: ../../lua/type/tes3magicEffect.html
.. _`string`: ../../lua/type/string.html
.. _`tes3iteratorNode`: ../../lua/type/tes3iteratorNode.html
.. _`tes3fader`: ../../lua/type/tes3fader.html
.. _`tes3quest`: ../../lua/type/tes3quest.html
.. _`tes3nonDynamicData`: ../../lua/type/tes3nonDynamicData.html
.. _`tes3ingredient`: ../../lua/type/tes3ingredient.html
.. _`tes3gameSetting`: ../../lua/type/tes3gameSetting.html
.. _`table`: ../../lua/type/table.html
.. _`tes3mobileNPC`: ../../lua/type/tes3mobileNPC.html
.. _`tes3wearablePart`: ../../lua/type/tes3wearablePart.html
.. _`tes3vector3`: ../../lua/type/tes3vector3.html
.. _`tes3vector4`: ../../lua/type/tes3vector4.html
.. _`tes3vector2`: ../../lua/type/tes3vector2.html
.. _`tes3activator`: ../../lua/type/tes3activator.html
.. _`tes3travelDestinationNode`: ../../lua/type/tes3travelDestinationNode.html
.. _`tes3inventory`: ../../lua/type/tes3inventory.html
.. _`tes3boundingBox`: ../../lua/type/tes3boundingBox.html
.. _`tes3markData`: ../../lua/type/tes3markData.html
.. _`tes3transform`: ../../lua/type/tes3transform.html
.. _`tes3creatureInstance`: ../../lua/type/tes3creatureInstance.html
.. _`tes3effect`: ../../lua/type/tes3effect.html
.. _`tes3game`: ../../lua/type/tes3game.html
.. _`tes3soulGemData`: ../../lua/type/tes3soulGemData.html
.. _`tes3probe`: ../../lua/type/tes3probe.html
.. _`tes3object`: ../../lua/type/tes3object.html
.. _`tes3physicalObject`: ../../lua/type/tes3physicalObject.html
.. _`number`: ../../lua/type/number.html
.. _`nil`: ../../lua/type/nil.html
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
