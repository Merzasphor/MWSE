
Mobile Object
========================================================

A **Mobile Object** is a game structure for holding active simulation data. If a reference has AI, motion, or combat simulation data, it is controlled by the associated mobile object.

This makes for a complex relationship. A scrib, for example, might be composed of `tes3creature`_ (the object created in the Construction Set), a `tes3creatureInstance`_ (a *specific* copy of that base object), and a `tes3mobileCreature`_ (current effects, AI choices, and statistics for that unique scrib). All of this will be packaged directly or indirectly inside of a `tes3reference`_.

Inheriting structures: `tes3mobileActor`_ (`tes3mobileNPC`_, `tes3mobilePlayer`_, `tes3mobileCreature`_) and `tes3mobileProjectile`_.


Properties
--------------------------------------------------------

**boundSize** (`tes3vector3`_, read-only)
    The bounding size for the object, used for physics calculations.

**cellX** (`number`_, read-only)
    The X position of the object's current cell.

**cellY** (`number`_, read-only)
    The Y position of the object's current cell.

**flags** (`number`_, read-only)
    The general mobile object flags.

**height** (`number`_, read-only)
    The vertical position of the object.

**impulseVelocity** (`tes3vector3`_)
    The object's impulse velocity.

**movementFlags** (`number`_, read-only)
    The object's current movement flags.

**position** (`tes3vector3`_)
    The object's position.

**preMovementFlags** (`number`_, read-only)
    The object's movement flags from the previous check.

**reference** (`tes3reference`_)
    The reference associated with this object.

**velocity** (`tes3vector3`_)
    The object's velocity.


.. _`boolean`: ../lua/boolean.html
.. _`number`: ../lua/number.html
.. _`string`: ../lua/string.html
.. _`table`: ../lua/table.html
.. _`userdata`: ../lua/userdata.html

.. _`tes3creature`: creature.html
.. _`tes3creatureInstance`: creatureInstance.html
.. _`tes3mobileActor`: mobileActor.html
.. _`tes3mobileCreature`: mobileCreature.html
.. _`tes3mobileNPC`: mobileNPC.html
.. _`tes3mobilePlayer`: mobilePlayer.html
.. _`tes3mobileProjectile`: mobileProjectile.html
.. _`tes3reference`: reference.html
.. _`tes3vector3`: vector3.html
