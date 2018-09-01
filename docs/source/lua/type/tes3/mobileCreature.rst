
Mobile Creature
========================================================

A **Mobile Creature** is an extended `tes3mobileActor`_ specific for creatures. See the `tes3mobileObject`_ page for more information on mobile objects.


Properties
--------------------------------------------------------

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

**animationData** (`tes3animationData`_, read-only)
    Current animation data for the object.

**attackBonus** (`number`_)
    Easy access into **effectAttributes**.

**attacked** (`boolean`_, read-only)
    Easy access to **flags**. If ``true``, the actor has been attacked.

**attributes** (`table`_ array of 8 `tes3statistic`_)
    The attributes related to the actor, including strength, intelligence, etc.

**barterGold** (`number`_)
    The amount of gold the actor currently has to barter with.

**blind** (`number`_)
    Easy access into **effectAttributes**.

**boundSize** (`tes3vector3`_, read-only)
    The bounding size for the object, used for physics calculations.

**cell** (`tes3cell`_, read-only)
    The cell that the actor is currently in.

**cellX** (`number`_, read-only)
    The X position of the object's current cell.

**cellY** (`number`_, read-only)
    The Y position of the object's current cell.

**chameleon** (`number`_)
    Easy access into **effectAttributes**.

**collidingReference** (`tes3reference`_, read-only)
    The most recent reference to collide with this one.

**combat** (`tes3statistic`_, read-only)
    The creature's combat statistic.

**corpseHourstamp** (`number`_, read-only)
    This property relates to the hour that the actor was inflicted with corprus, but more research needs to be done.

**currentEnchantedItem** (`tes3equipmentStack`_, read-only)
    The equipment stack associated with the item currently in the enchanted item slot.

**currentSpell** (`tes3spell`_)
    The spell that the actor has readied.

**effectAttributes** (`table`_ array of 8 `number`_)
    Various attributes including current resistances and other spell effect magnitudes.

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

**friendlyActors** (`tes3iterator`_ of **tes3mobileActor**)
    A list of actors currently friendly to the actor, which might aid them in combat.

**greetDuration** (`number`_)
    Relates NPC greetings, but more research needs to be done.

**greetTimer** (`number`_)
    Relates NPC greetings, but more research needs to be done.

**hasFreeAction** (`boolean`_, read-only)
    Returns ``true`` if the actor can act. This is ``false`` if the actor is currently attacking, knocked down/out, or is out of stamina.

**health** (`tes3statistic`_, read-only)
    The current/max health of the actor.

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

**impulseVelocity** (`tes3vector3`_)
    The object's impulse velocity.

**inCombat** (`boolean`_, read-only)
    Easy access to **flags**. If ``true``, the actor is in combat.

**intelligence** (`tes3statistic`_, read-only)
    Easy access to **attributes**, specifically providing access to the intelligence attribute.

**invisibility** (`number`_)
    Easy access into **effectAttributes**.

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

**lastGroundZ** (`number`_)
    The vertical position that the actor was last on solid ground.

**levitate** (`number`_)
    Easy access into **effectAttributes**.

**luck** (`tes3statistic`_, read-only)
    Easy access to **attributes**, specifically providing access to the luck attribute.

**magic** (`tes3statistic`_, read-only)
    The creature's magic statistic.

**magicka** (`tes3statistic`_, read-only)
    The current/max magicka of the actor.

**magickaMultiplier** (`tes3statistic`_, read-only)
    The current/max magickaMultiplier of the actor.

**movementFlags** (`number`_, read-only)
    The object's current movement flags.

**moveSpeed** (`number`_, read-only)
    The actor's movement speed, subject to the `calcMoveSpeed`_ event.

**nextActionWeight** (`number`_)
    How important the actor's next action is in their AI decision making.

**object** (`tes3creature`_ or `tes3creatureInstance`_, read-only)
    The creature associated with this mobile actor.

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

**runSpeed** (`number`_, read-only)
    The actor's run speed, subject to the `calcRunSpeed`_ event.

**sanctuary** (`number`_)
    Easy access into **effectAttributes**.

**scanInterval** (`number`_, read-only)
    Unresearched. Possibly the rate at which the actor scans for new targets.

**silence** (`number`_)
    Easy access into **effectAttributes**.

**sound** (`number`_)
    Easy access into **effectAttributes**.

**speed** (`tes3statistic`_, read-only)
    Easy access to **attributes**, specifically providing access to the speed attribute.

**spellReadied** (`boolean`_, read-only)
    Easy access to **flags**. If ``true``, actor has a spell prepared.

**stealth** (`tes3statistic`_, read-only)
    The creature's stealth statistic.

**strength** (`tes3statistic`_, read-only)
    Easy access to **attributes**, specifically providing access to the strength attribute.

**swiftSwim** (`number`_)
    Easy access into **effectAttributes**.

**swimSpeed** (`number`_, read-only)
    The actor's run speed, subject to the `calcSwimSpeed`_ event.

**swimRunSpeed** (`number`_, read-only)
    The actor's run speed, subject to the `calcSwimRunSpeed`_ event.

**torchSlot** (`tes3equipmentStack`_)
    The currently equipped torch.

**underwater** (`boolean`_, read-only)
    Easy access to **flags**. If ``true``, the actor is underwater.

**velocity** (`tes3vector3`_)
    The object's velocity.

**walkSpeed** (`number`_, read-only)
    The actor's walk speed, subject to the `calcWalkSpeed`_ event.

**waterBreathing** (`number`_)
    Easy access into **effectAttributes**.

**waterWalking** (`number`_)
    Easy access into **effectAttributes**.

**weaponDrawn** (`boolean`_, read-only)
    Easy access to **flags**. If ``true``, actor has a weapon drawn.

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
.. _`tes3animationData`: animationData.html
.. _`tes3cell`: cell.html
.. _`tes3creature`: creature.html
.. _`tes3creatureInstance`: creatureInstance.html
.. _`tes3equipmentStack`: equipmentStack.html
.. _`tes3iterator`: iterator.html
.. _`tes3mobileActor`: mobileActor.html
.. _`tes3mobileNPC`: mobileNPC.html
.. _`tes3mobileObject`: mobileObject.html
.. _`tes3mobilePlayer`: mobilePlayer.html
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
.. _`damage`: ../../event/damage.html
.. _`damaged`: ../../event/damaged.html

.. _`applyHealthDamage`: mobileActor/applyHealthDamage.html
.. _`startCombat`: mobileActor/startCombat.html
.. _`stopCombat`: mobileActor/stopCombat.html
