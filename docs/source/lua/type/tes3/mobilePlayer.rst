
Mobile Player
========================================================

The **Mobile Player** is an extended `tes3mobileNPC`_ specificly for the player. See the `tes3mobileObject`_ page for more information on mobile objects.


Properties
--------------------------------------------------------

**acrobatics** (`tes3statistic`_, read-only)
    Easy access into **skills**.

**actionBeforeCombat** (`tes3actionData`_, read-only)
    Preserved Action Data from before the current combat session.

**actionData** (`tes3actionData`_, read-only)
    Information about the current action being taken.

**activeAI** (`boolean`_)
    Easy access to **flags**. Allows getting/setting if actor's AI is active.

**activeMagicEffectCount** (`number`_, read-only)
    The number of active effects on the actor.

**actorType** (`number`_, read-only)
    A number distinguishing NPCs from the player from creatures.

**agility** (`tes3statistic`_, read-only)
    Easy access to **attributes**, specifically providing access to the agility attribute.

**alarm** (`number`_)
    The actor's current alarm AI threshold.

**alchemy** (`tes3statistic`_, read-only)
    Easy access into **skills**.

**alteration** (`tes3statistic`_, read-only)
    Easy access into **skills**.

**alwaysRun** (`boolean`_)
    Determines if the player is set to always run.

**animationData** (`tes3playerAnimationData`_, read-only)
    Current animation data for the player.

**armorer** (`tes3statistic`_, read-only)
    Easy access into **skills**.

**athletics** (`tes3statistic`_, read-only)
    Easy access into **skills**.

**attackBonus** (`number`_)
    Easy access into **effectAttributes**.

**attackDisabled** (`boolean`_)
    Determines if the player is allowed to attack.

**attacked** (`boolean`_, read-only)
    Easy access to **flags**. If ``true``, the actor has been attacked.

**attributes** (`table`_ array of 8 `tes3statistic`_)
    The attributes related to the actor, including strength, intelligence, etc.

**autoRun** (`boolean`_)
    Determines if the player is to automatically move forward.

**axe** (`tes3statistic`_, read-only)
    Easy access into **skills**.

**barterGold** (`number`_)
    The amount of gold the actor currently has to barter with.

**blind** (`number`_)
    Easy access into **effectAttributes**.

**block** (`tes3statistic`_, read-only)
    Easy access into **skills**.

**bluntWeapon** (`tes3statistic`_, read-only)
    Easy access into **skills**.

**boundSize** (`tes3vector3`_, read-only)
    The bounding size for the object, used for physics calculations.

**castReady** (`boolean`_)
    Determines if the player has magic readied.

**cell** (`tes3cell`_, read-only)
    The cell that the actor is currently in.

**cellX** (`number`_, read-only)
    The X position of the object's current cell.

**cellY** (`number`_, read-only)
    The Y position of the object's current cell.

**chameleon** (`number`_)
    Easy access into **effectAttributes**.

**clawMultiplier** (`tes3globalVariable`_, read-only)
    Quick access to the WerewolfClawMult global variable.

**collidingReference** (`tes3reference`_, read-only)
    The most recent reference to collide with this one.

**conjuration** (`tes3statistic`_, read-only)
    Easy access into **skills**.

**controlsDisabled** (`boolean`_)
    Determines if the player controls are disabled.

**corpseHourstamp** (`number`_, read-only)
    This property relates to the hour that the actor was inflicted with corprus, but more research needs to be done.

**currentEnchantedItem** (`tes3equipmentStack`_, read-only)
    The equipment stack associated with the item currently in the enchanted item slot.

**currentSpell** (`tes3spell`_)
    The spell that the actor has readied.

**destruction** (`tes3statistic`_, read-only)
    Easy access into **skills**.

**dialogueList** (`tes3iterator`_ of `tes3dialogue`_, read-only)
    A list of dialogue topics currently known by the player.

**effectAttributes** (`table`_ array of 8 `number`_)
    Various attributes including current resistances and other spell effect magnitudes.

**enchant** (`tes3statistic`_, read-only)
    Easy access into **skills**.

**encumbrance** (`tes3statistic`_, read-only)
    The current/max encumbrance of the actor.

**endurance** (`tes3statistic`_, read-only)
    Easy access to **attributes**, specifically providing access to the endurance attribute.

**fatigue** (`tes3statistic`_, read-only)
    The current/max fatigue of the actor.

**fight** (`number`_)
    The actor's current fight AI threshold.

**flags** (`number`_, read-only)
    The general mobile object flags.

**flee** (`number`_)
    The actor's current flee AI threshold.

**flySpeed** (`number`_, read-only)
    The actor's run speed, subject to the `calcFlySpeed`_ event.

**forceJump** (`boolean`_)
    A flag that determines if the actor is forced to jump.

**forceMoveJump** (`boolean`_)
    A flag that determines if the actor is forced to move-jump.

**forceRun** (`boolean`_)
    A flag that determines if the actor is forced to run.

**forceSneak** (`boolean`_)
    A flag that determines if the actor is forced to sneak. For the player, this sets the sneak state, but allows them to change their sneak state normally.

**friendlyActors** (`tes3iterator`_ of **tes3mobileActor**)
    A list of actors currently friendly to the actor, which might aid them in combat.

**greetDuration** (`number`_)
    Relates NPC greetings, but more research needs to be done.

**greetTimer** (`number`_)
    Relates NPC greetings, but more research needs to be done.

**handToHand** (`tes3statistic`_, read-only)
    Easy access into **skills**.

**hasFreeAction** (`boolean`_, read-only)
    Returns ``true`` if the actor can act. This is ``false`` if the actor is currently attacking, knocked down/out, or is out of stamina.

**health** (`tes3statistic`_, read-only)
    The current/max health of the actor.

**heavyArmor** (`tes3statistic`_, read-only)
    Easy access into **skills**.

**height** (`number`_, read-only)
    The vertical position of the object.

**hello** (`number`_)
    The actor's current hello AI threshold.

**holdBreathTime** (`number`_)
    The time when the actor started to hold their breath.

**hostileActors** (`tes3iterator`_ of **tes3mobileActor**)
    A list of actors currently hostile to the actor, which are likely engaged in combat with them.

**idleAnim** (`boolean`_, read-only)
    Easy access to **flags**. Research needed. Relates to the idle animation.

**illusion** (`tes3statistic`_, read-only)
    Easy access into **skills**.

**impulseVelocity** (`tes3vector3`_)
    The object's impulse velocity.

**inactivityTime** (`number`_)
    A timer showing how long the player has been idle.

**inCombat** (`boolean`_, read-only)
    Easy access to **flags**. If ``true``, the actor is in combat.

**inJail** (`boolean`_)
    Determines if the player is in jail.

**intelligence** (`tes3statistic`_, read-only)
    Easy access to **attributes**, specifically providing access to the intelligence attribute.

**invisibility** (`number`_)
    Easy access into **effectAttributes**.

**is3rdPerson** (`boolean`_, read-only)
    Determines if the player is currently in third person.

**isCrittable** (`boolean`_, read-only)
    Easy access to **flags**. If ``true``, the actor is subject to critical hits.

**isFlying** (`boolean`_, read-only)
    Easy access to **movementFlags**.

**isJumping** (`boolean`_, read-only)
    Easy access to **movementFlags**.

**isMovingBack** (`boolean`_, read-only)
    Easy access to **movementFlags**.

**isMovingForward** (`boolean`_, read-only)
    Easy access to **movementFlags**.

**isMovingLeft** (`boolean`_, read-only)
    Easy access to **movementFlags**.

**isMovingRight** (`boolean`_, read-only)
    Easy access to **movementFlags**.

**isRunning** (`boolean`_, read-only)
    Easy access to **movementFlags**.

**isSneaking** (`boolean`_, read-only)
    Easy access to **movementFlags**.

**isStartingJump** (`boolean`_, read-only)
    Easy access to **movementFlags**.

**isSwimming** (`boolean`_, read-only)
    Easy access to **movementFlags**.

**isTurningLeft** (`boolean`_, read-only)
    Easy access to **movementFlags**.

**isTurningRight** (`boolean`_, read-only)
    Easy access to **movementFlags**.

**isWalking** (`boolean`_, read-only)
    Easy access to **movementFlags**.

**jump** (`number`_)
    Easy access into **effectAttributes**.

**jumpingDisabled** (`boolean`_)
    Determines if the player can jump.

**knownWerewolf** (`tes3globalVariable`_, read-only)
    Quick access to the pcknownWerewolf global variable.

**lastGroundZ** (`number`_)
    The vertical position that the actor was last on solid ground.

**lastUsedAlembic** (`tes3apparatus`_, read-only)
    One of the last used apparatus items when performing alchemy.

**lastUsedAmmoCount** (`number`_)
    The number of ammo used.

**lastUsedCalcinator** (`tes3apparatus`_, read-only)
    One of the last used apparatus items when performing alchemy.

**lastUsedMortar** (`tes3apparatus`_, read-only)
    One of the last used apparatus items when performing alchemy.

**lastUsedRetort** (`tes3apparatus`_, read-only)
    One of the last used apparatus items when performing alchemy.

**levelUpProgress** (`number`_)
    The current progress towards the next level.

**levelupsPerAttribute** (`table`_ array of 8 `number`_)
    The number of skill leveups obtained for each governing attribute.

**levelupsPerSpecialization** (`table`_ array of 3 `number`_)
    The number of skill leveups obtained for each governing specialization.

**levitate** (`number`_)
    Easy access into **effectAttributes**.

**lightArmor** (`tes3statistic`_, read-only)
    Easy access into **skills**.

**longBlade** (`tes3statistic`_, read-only)
    Easy access into **skills**.

**luck** (`tes3statistic`_, read-only)
    Easy access to **attributes**, specifically providing access to the luck attribute.

**magicDisabled** (`boolean`_)
    Determines if the player can use magic.

**magicka** (`tes3statistic`_, read-only)
    The current/max magicka of the actor.

**magickaMultiplier** (`tes3statistic`_, read-only)
    The current/max magickaMultiplier of the actor.

**marksman** (`tes3statistic`_, read-only)
    Easy access into **skills**.

**markLocation** (`tes3markData`_, read-only)
    Provides information about where the player's mark location is, including its position, facing, and cell.

**mediumArmor** (`tes3statistic`_, read-only)
    Easy access into **skills**.

**mercantile** (`tes3statistic`_, read-only)
    Easy access into **skills**.

**mouseLookDisabled** (`boolean`_)
    Determines if the player can look around using the mouse.

**movementFlags** (`number`_, read-only)
    The object's current movement flags.

**moveSpeed** (`number`_, read-only)
    The actor's movement speed, subject to the `calcMoveSpeed`_ event.

**mysticism** (`tes3statistic`_, read-only)
    Easy access into **skills**.

**nextActionWeight** (`number`_)
    How important the actor's next action is in their AI decision making.

**object** (`tes3npc`_ or `tes3npcInstance`_, read-only)
    The NPC associated with this mobile actor.

**paralyze** (`number`_)
    Easy access into **effectAttributes**.

**personality** (`tes3statistic`_, read-only)
    Easy access to **attributes**, specifically providing access to the personality attribute.

**position** (`tes3vector3`_)
    The object's position.

**preMovementFlags** (`number`_, read-only)
    The object's movement flags from the previous check.

**readiedAmmo** (`tes3equipmentStack`_)
    The currently equipped ammunition.

**readiedAmmoCount** (`number`_)
    The stack count of ammunition equipped.

**readiedShield** (`tes3equipmentStack`_)
    The currently equipped shield.

**readiedWeapon** (`tes3equipmentStack`_)
    The currently equipped weapon.

**reference** (`tes3reference`_)
    The reference associated with this object.

**resistBlightDisease** (`number`_)
    Easy access into **effectAttributes**.

**resistCommonDisease** (`number`_)
    Easy access into **effectAttributes**.

**resistCorprus** (`number`_)
    Easy access into **effectAttributes**.

**resistFire** (`number`_)
    Easy access into **effectAttributes**.

**resistFrost** (`number`_)
    Easy access into **effectAttributes**.

**resistMagicka** (`number`_)
    Easy access into **effectAttributes**.

**resistNormalWeapons** (`number`_)
    Easy access into **effectAttributes**.

**resistParalysis** (`number`_)
    Easy access into **effectAttributes**.

**resistPoison** (`number`_)
    Easy access into **effectAttributes**.

**resistShock** (`number`_)
    Easy access into **effectAttributes**.

**restHoursRemaining** (`number`_)
    The number of hours left when resting or waiting.

**restoration** (`tes3statistic`_, read-only)
    Easy access into **skills**.

**runSpeed** (`number`_, read-only)
    The actor's run speed, subject to the `calcRunSpeed`_ event.

**sanctuary** (`number`_)
    Easy access into **effectAttributes**.

**scanInterval** (`number`_, read-only)
    Unresearched. Possibly the rate at which the actor scans for new targets.

**security** (`tes3statistic`_, read-only)
    Easy access into **skills**.

**shortBlade** (`tes3statistic`_, read-only)
    Easy access into **skills**.

**silence** (`number`_)
    Easy access into **effectAttributes**.

**skillProgress** (`table`_ array of 27 `number`_)
    The progress of leveling each of the player's skills.

**skills** (`table`_ array of 27 `tes3statistic`_)
    The skills the NPC has.

**sleeping** (`boolean`_)
    Determines if the player is currently sleeping, as opposed to **waiting**.

**sneak** (`tes3statistic`_, read-only)
    Easy access into **skills**.

**sound** (`number`_)
    Easy access into **effectAttributes**.

**spear** (`tes3statistic`_, read-only)
    Easy access into **skills**.

**speechcraft** (`tes3statistic`_, read-only)
    Easy access into **skills**.

**speed** (`tes3statistic`_, read-only)
    Easy access to **attributes**, specifically providing access to the speed attribute.

**spellReadied** (`boolean`_, read-only)
    Easy access to **flags**. If ``true``, actor has a spell prepared.

**strength** (`tes3statistic`_, read-only)
    Easy access to **attributes**, specifically providing access to the strength attribute.

**swiftSwim** (`number`_)
    Easy access into **effectAttributes**.

**swimSpeed** (`number`_, read-only)
    The actor's run speed, subject to the `calcSwimSpeed`_ event.

**swimRunSpeed** (`number`_, read-only)
    The actor's run speed, subject to the `calcSwimRunSpeed`_ event.

**telekinesis** (`number`_)
    The current magnitude of the telekinesis effect of the player.

**torchSlot** (`tes3equipmentStack`_)
    The currently equipped torch.

**travelling** (`boolean`_)
    Determines if the player is currently travelling.

**unarmored** (`tes3statistic`_, read-only)
    Easy access into **skills**.

**underwater** (`boolean`_, read-only)
    Easy access to **flags**. If ``true``, the actor is underwater.

**vanityDisabled** (`boolean`_)
    Determines if the player can use the vanity camera.

**velocity** (`tes3vector3`_)
    The object's velocity.

**walkSpeed** (`number`_, read-only)
    The actor's walk speed, subject to the `calcWalkSpeed`_ event.

**viewSwitchDisabled** (`boolean`_)
    Determines if the player can use switch between third and first person.

**visionBonus** (`number`_)
    The current magnitude of the night eye effect of the player.

**waiting** (`boolean`_)
    Determines if the player is currently waiting, as opposed to **sleeping**.

**waterBreathing** (`number`_)
    Easy access into **effectAttributes**.

**waterWalking** (`number`_)
    Easy access into **effectAttributes**.

**weaponDrawn** (`boolean`_, read-only)
    Easy access to **flags**. If ``true``, actor has a weapon drawn.

**weaponReady** (`boolean`_)
    Determines if the player has a weapon readied.

**werewolf** (`boolean`_, read-only)
    Easy access to **flags**. If ``true``, actor is a werewolf.

**width** (`number`_, read-only)
    The width of the actor.

**willpower** (`tes3statistic`_, read-only)
    Easy access to **attributes**, specifically providing access to the willpower attribute.


Functions
--------------------------------------------------------

`applyHealthDamage`_
    Causes damage to the actor, invoking the associated `damage`_ and `damaged`_ events.

`exerciseSkill`_
    Provides experience to a specific skill. This fires the `exerciseSkill event`_.

`startCombat`_
    Begins combat with a specified actor, triggering the `combatStart`_ and `combatStarted`_ events.

`stopCombat`_
    Ends combat with a specified actor, triggering the `combatStop`_ and `combatStopped`_ events.


.. _`boolean`: ../lua/boolean.html
.. _`number`: ../lua/number.html
.. _`string`: ../lua/string.html
.. _`table`: ../lua/table.html
.. _`userdata`: ../lua/userdata.html

.. _`tes3actionData`: actionData.html
.. _`tes3apparatus`: apparatus.html
.. _`tes3cell`: cell.html
.. _`tes3dialogue`: dialogue.html
.. _`tes3equipmentStack`: equipmentStack.html
.. _`tes3globalvariable`: globalvariable.html
.. _`tes3iterator`: iterator.html
.. _`tes3mobileActor`: mobileActor.html
.. _`tes3mobileCreature`: mobileCreature.html
.. _`tes3mobileNPC`: mobileNPC.html
.. _`tes3mobileObject`: mobileObject.html
.. _`tes3npc`: npc.html
.. _`tes3npcInstance`: npcInstance.html
.. _`tes3playerAnimationData`: playerAnimationData.html
.. _`tes3reference`: reference.html
.. _`tes3spell`: spell.html
.. _`tes3statistic`: statistic.html
.. _`tes3vector3`: vector3.html

.. _`calcFlySpeed`: ../../event/calcFlySpeed.html
.. _`calcMoveSpeed`: ../../event/calcMoveSpeed.html
.. _`calcRunSpeed`: ../../event/calcRunSpeed.html
.. _`calcSwimRunSpeed`: ../../event/calcSwimRunSpeed.html
.. _`calcSwimSpeed`: ../../event/calcSwimSpeed.html
.. _`calcWalkSpeed`: ../../event/calcWalkSpeed.html
.. _`combatStart`: ../../event/combatStart.html
.. _`combatStarted`: ../../event/combatStarted.html
.. _`combatStop`: ../../event/combatStop.html
.. _`combatStopped`: ../../event/combatStopped.html
.. _`damage`: ../../event/damage.html
.. _`damaged`: ../../event/damaged.html
.. _`exerciseSkill event`: ../../event/exerciseSkill.html

.. _`applyHealthDamage`: mobileActor/applyHealthDamage.html
.. _`exerciseSkill`: mobilePlayer/exerciseSkill.html
.. _`startCombat`: mobileActor/startCombat.html
.. _`stopCombat`: mobileActor/stopCombat.html
