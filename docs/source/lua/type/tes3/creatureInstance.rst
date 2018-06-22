
Creature Instance
========================================================

An **Creature Instance** is a cloned `Creature`_.


Properties
--------------------------------------------------------

**actorFlags** (`number`_, read-only)
    The actor's flags, including information on essential and respawn status.

**aiConfig** (`tes3aiConfig`_, read-only)
    Information on the actor's AI configuration, which includes base hello/fight/flee/alarm values, merchant flags, and travel destinations.

**attacks** (`table`_ of `tes3range`_, read-only)
    Each creature has 3 attacks. This returns an array of the 3 attacks, each of which has a ``.min`` and ``.max`` property.

**attributes** (`table`_ of `number`_, read-only)
    Returns an array of the base 8 attributes the creature has. These may not necessarily be the current values.

**barterGold** (`number`_)
    The base gold that the actor has to barter with.

**baseObject** (`tes3creature`_, read-only)
    The creature that this instance was cloned from.

**boundingBox** (`tes3boundingBox`_, read-only)
    The object's bounding box.

**cloneCount** (`number`_, read-only)
    The number of clones that this actor has.

**equipment** (`tes3iterator`_ of `tes3equipmentStack`_, read-only)
    Items currently equipped on the actor.

**fatigue** (`tes3statistic`_, read-only)
    The creature's fatigue statistic.

**health** (`tes3statistic`_, read-only)
    The creature's health statistic.

**id** (`string`_, read-only)
    The object's unique id.

**inventory** (`tes3inventory`_, read-only)
    Items the actor currently carries.

**isAttacked** (`boolean`_, read-only)
    Reveals if the creature is marked as being attacked.

**isEssential** (`boolean`_, read-only)
    Reveals if the creature is marked as essential.

**isInstance** (`boolean`_, read-only)
    Always return ``true``. This is useful because **objectType** is the same for both `Creature`_ and **Creature Instance**, while this field allows differentiation.

**isRespawn** (`boolean`_, read-only)
    Reveals if the creature is marked as a respawn.

**level** (`number`_, read-only)
    Access to the creature's level.

**magicka** (`tes3statistic`_, read-only)
    The creature's magicka statistic.

**model** (`string`_)
    The mesh used by the object.

**name** (`string`_)
    The user-friendly name shown for the container.

**objectType** (`number`_, read-only)
    The object's `objectType`_.

**script** (`tes3script`_, read-only)
    The script, if any, that is attached to the object.

**skills** (`table`_ of `number`_, read-only)
    Each creature has 3 skills, covering **combat**, **magic**, and **stealth**. This property returns a table with the base values of these three skills.

**soul** (`number`_)
    The amount of soul that the creature can provide to a soul gem.

**soundCreature** (**tes3creature**)
    The creature that this creature will use for sounds. For example, a summoned *Frost Atronach* will use the same sounds as the normal creature, despite them being its own unique object.

**sourceMod** (`string`_, read-only)
    The object's originating plugin filename.

**spells** (`tes3spellList`_, read-only)
    A list of spells attached to the actor.

**type** (`number`_, read-only)
    The type of the creature.

**weapon** (`tes3weapon`_, read-only)
    The equipped weapon by the creature.


.. _`boolean`: ../lua/boolean.html
.. _`number`: ../lua/number.html
.. _`string`: ../lua/string.html
.. _`table`: ../lua/table.html
.. _`userdata`: ../lua/userdata.html

.. _`Actor`: actor.html
.. _`Container Instance`: containerInstance.html
.. _`Container`: container.html
.. _`Creature Instance`: creatureInstance.html
.. _`Creature`: creature.html
.. _`Mobile Actor`: mobileActor.html
.. _`NPC Instance`: npcInstance.html
.. _`NPC`: npc.html
.. _`objectType`: baseObject/objectType.html
.. _`tes3aiConfig`: aiConfig.html
.. _`tes3boundingBox`: boundingBox.html
.. _`tes3creature`: creature.html
.. _`tes3equipmentStack`: equipmentStack.html
.. _`tes3inventory`: inventory.html
.. _`tes3iterator`: iterator.html
.. _`tes3range`: range.html
.. _`tes3script`: script.html
.. _`tes3spellList`: spellList.html
.. _`tes3statistic`: statistic.html
.. _`tes3weapon`: weapon.html
