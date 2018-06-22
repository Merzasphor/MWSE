
Actor
========================================================

An **Actor** (not to be confused with a `Mobile Actor`_) is an object that can be cloned and that has an inventory. Creatures, NPCs, and containers are all considered actors.

It is standard for creatures and NPCs to be composed of an actor and a mobile actor, linked together with a reference.

Inheriting structures: `Container`_, `Container Instance`_, `Creature`_, `Creature Instance`_, `NPC`_, and `NPC Instance`_.


Properties
--------------------------------------------------------

**actorFlags** (`number`_, read-only)
    The actor's flags, including information on essential and respawn status.

**barterGold** (`number`_)
    The base gold that the actor has to barter with.

**boundingBox** (`tes3boundingBox`_, read-only)
    The object's bounding box.

**cloneCount** (`number`_, read-only)
    The number of clones that this actor has.

**equipment** (`tes3iterator`_ of `tes3equipmentStack`_, read-only)
    Items currently equipped on the actor.

**id** (`string`_, read-only)
    The object's unique id.

**inventory** (`tes3inventory`_, read-only)
    Items the actor currently carries.

**objectType** (`number`_, read-only)
    The object's `objectType`_.

**sourceMod** (`string`_, read-only)
    The object's originating plugin filename.


.. _`boolean`: ../lua/boolean.html
.. _`number`: ../lua/number.html
.. _`string`: ../lua/string.html
.. _`table`: ../lua/table.html
.. _`userdata`: ../lua/userdata.html

.. _`Container Instance`: containerInstance.html
.. _`Container`: container.html
.. _`Creature Instance`: creatureInstance.html
.. _`Creature`: creature.html
.. _`Mobile Actor`: mobileActor.html
.. _`NPC Instance`: npcInstance.html
.. _`NPC`: npc.html
.. _`objectType`: baseObject/objectType.html
.. _`tes3boundingBox`: boundingBox.html
.. _`tes3equipmentStack`: equipmentStack.html
.. _`tes3inventory`: inventory.html
.. _`tes3iterator`: iterator.html
