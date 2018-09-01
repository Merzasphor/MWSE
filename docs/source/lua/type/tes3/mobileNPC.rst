
Mobile NPC
========================================================

A **Mobile NPC** is an extended `tes3mobileActor`_ specific for NPCs. See the `tes3mobileObject`_ page for more information on mobile objects.


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

**animationData** (`tes3animationData`_, read-only)
    Current animation data for the object.

**armorer** (`tes3statistic`_, read-only)
    Easy access into **skills**.

**athletics** (`tes3statistic`_, read-only)
    Easy access into **skills**.

**attackBonus** (`number`_)
    Easy access into **effectAttributes**.

**attacked** (`boolean`_, read-only)
    Easy access to **flags**. If ``true``, the actor has been attacked.

**attributes** (`table`_ array of 8 `tes3statistic`_)
    The attributes related to the actor, including strength, intelligence, etc.

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

**conjuration** (`tes3statistic`_, read-only)
    Easy access into **skills**.

**corpseHourstamp** (`number`_, read-only)
    This property relates to the hour that the actor was inflicted with corprus, but more research needs to be done.

**currentEnchantedItem** (`tes3equipmentStack`_, read-only)
    The equipment stack associated with the item currently in the enchanted item slot.

**currentSpell** (`tes3spell`_)
    The spell that the actor has readied.

**destruction** (`tes3statistic`_, read-only)
    Easy access into **skills**.

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
    A flag that determines if the actor is forced to sneak.

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

**lightArmor** (`tes3statistic`_, read-only)
    Easy access into **skills**.

**longBlade** (`tes3statistic`_, read-only)
    Easy access into **skills**.

**luck** (`tes3statistic`_, read-only)
    Easy access to **attributes**, specifically providing access to the luck attribute.

**magicka** (`tes3statistic`_, read-only)
    The current/max magicka of the actor.

**magickaMultiplier** (`tes3statistic`_, read-only)
    The current/max magickaMultiplier of the actor.

**marksman** (`tes3statistic`_, read-only)
    Easy access into **skills**.

**mediumArmor** (`tes3statistic`_, read-only)
    Easy access into **skills**.

**mercantile** (`tes3statistic`_, read-only)
    Easy access into **skills**.

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

**skills** (`table`_ array of 27 `tes3statistic`_)
    The skills the NPC has.

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

**torchSlot** (`tes3equipmentStack`_)
    The currently equipped torch.

**unarmored** (`tes3statistic`_, read-only)
    Easy access into **skills**.

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

`boolean`_ **equip** (`tes3object`_ item)
    Returns:
        ``true`` if the equip was successful.
    
    Equips an item from the actor's inventory. If the item does not exist, or the the actor is currently attacking with another item that occupies the item's slot, it will fail.

`boolean`_ **unequip** {`tes3object`_ item, `armorSlot`_ armorSlot, `clothingSlot`_ clothingSlot, `objectType`_ type}  ``Uses table arguments.``
    Returns:
        ``true`` if the un-equip was successful.

    Un-equips item(s) that match the argument given. Only one argument can be used in a call.
    
    **item**:
        One equipped item matching the item given.
        
        e.g. ``mobileActor:unequip{ item = tes3.getObject("common_pants_01") }``
    
    **armorSlot**:
        One piece of armor occupying that slot. Slot numbers can be accessed through ``tes3.weaponSlot``.

        e.g. ``mobileActor:unequip{ armorSlot = tes3.weaponSlot.helmet }``
    
    **clothingSlot**:
        One piece of clothing occupying that slot. Slot numbers can be accessed through ``tes3.clothingSlot``. Rings are the only slot that can have multiple items equipped. Call the function multiple times to un-equip them all.
    
        e.g. ``mobileActor:unequip{ clothingSlot = tes3.clothingSlot.belt }``
    
    **type**:
        **All** items of that object type are un-equipped.
        
        e.g. ``mobileActor:unequip{ type = tes3.objectType.armor }``
        
        Weapons and ammunition can be un-equipped with this argument.


.. _`boolean`: ../lua/boolean.html
.. _`number`: ../lua/number.html
.. _`string`: ../lua/string.html
.. _`table`: ../lua/table.html
.. _`userdata`: ../lua/userdata.html

.. _`tes3actionData`: actionData.html
.. _`tes3animationData`: animationData.html
.. _`tes3cell`: cell.html
.. _`tes3equipmentStack`: equipmentStack.html
.. _`tes3iterator`: iterator.html
.. _`tes3mobileActor`: mobileActor.html
.. _`tes3mobileCreature`: mobileCreature.html
.. _`tes3mobileObject`: mobileObject.html
.. _`tes3mobilePlayer`: mobilePlayer.html
.. _`tes3npc`: npc.html
.. _`tes3npcInstance`: npcInstance.html
.. _`tes3object`: object.html
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

.. _`applyHealthDamage`: mobileActor/applyHealthDamage.html
.. _`startCombat`: mobileActor/startCombat.html
.. _`stopCombat`: mobileActor/stopCombat.html

.. _`armorSlot`: armor/armorSlot.html
.. _`clothingSlot`: clothing/clothingSlot.html
.. _`objectType`: baseObject/objectType.html
