
NPC
========================================================

An **NPC** is an `Actor`_ that covers any non-`Creature`_ character. An NPC has a race, class, and stronger diversity of equipment.


Properties
--------------------------------------------------------

**actorFlags** (`number`_, read-only)
    The actor's flags, including information on essential and respawn status.

**aiConfig** (`tes3aiConfig`_, read-only)
    Information on the actor's AI configuration, which includes base hello/fight/flee/alarm values, merchant flags, and travel destinations.

**attributes** (`table`_ of `number`_, read-only)
    Returns an array of the base 8 attributes the NPC has. These may not necessarily be the current values.

**barterGold** (`number`_)
    The base gold that the actor has to barter with.

**barterGold** (`number`_)
    The base gold that the actor has to barter with.

**boundingBox** (`tes3boundingBox`_, read-only)
    The object's bounding box.

**class** (`tes3class`_, read-only)
    The NPC's associated class.

**cloneCount** (`number`_, read-only)
    The number of clones that this actor has.

**disposition** (`number`_)
    The NPC's base disposition value.

**equipment** (`tes3iterator`_ of `tes3equipmentStack`_, read-only)
    Items currently equipped on the actor.

**faction** (`tes3faction`_, read-only)
    The NPC's associated faction.

**factionIndex** (`number`_)
    The numerical index representing the 0-based position of the NPC's faction in the global faction list.

**factionRank** (`number`_)
    The numerical index representing the 0-based position of that NPC's rank in their associated faction.

**fatigue** (`tes3statistic`_, read-only)
    The NPC's fatigue statistic.

**health** (`tes3statistic`_, read-only)
    The NPC's health statistic.

**id** (`string`_, read-only)
    The object's unique id.

**inventory** (`tes3inventory`_, read-only)
    Items the actor currently carries.

**isAttacked** (`boolean`_, read-only)
    Reveals if the NPC is marked as being attacked.

**isEssential** (`boolean`_, read-only)
    Reveals if the NPC is marked as essential.

**isInstance** (`boolean`_, read-only)
    Always return ``false``. This is useful because **objectType** is the same for both **NPC** and `NPC Instance`_, while this field allows differentiation.

**isRespawn** (`boolean`_, read-only)
    Reveals if the NPC is marked as a respawn.

**level** (`number`_, read-only)
    Access to the NPC's level.

**magicka** (`tes3statistic`_, read-only)
    The NPC's magicka statistic.

**model** (`string`_)
    The mesh used by the object.

**name** (`string`_)
    The user-friendly name shown for the container.

**objectType** (`number`_, read-only)
    The object's `objectType`_.

**race** (`tes3race`_, read-only)
    The NPC's associated race.

**reputation** (`number`_)
    The NPC's base reputation.

**script** (`tes3script`_, read-only)
    The NPC's attached script.

**skills** (`table`_ of `number`_, read-only)
    Each NPC has 27 skills. This property returns a table with the base values of these skills.

**sourceMod** (`string`_, read-only)
    The object's originating plugin filename.

**spells** (`tes3spellList`_, read-only)
    A list of spells attached to the actor.


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
.. _`tes3class`: class.html
.. _`tes3equipmentStack`: equipmentStack.html
.. _`tes3faction`: faction.html
.. _`tes3inventory`: inventory.html
.. _`tes3iterator`: iterator.html
.. _`tes3npc`: npc.html
.. _`tes3race`: race.html
.. _`tes3range`: range.html
.. _`tes3script`: script.html
.. _`tes3spellList`: spellList.html
.. _`tes3statistic`: statistic.html
