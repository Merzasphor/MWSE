
Class
========================================================

This interface represents a class. Classes are assigned to an `NPC`_ and the player.


Properties
--------------------------------------------------------

**attributes** (`table`_ of `number`_)
    The minor **skills** for this class.

**id** (`string`_)
    The object's unique id.

**majorSkills** (`table`_ of `number`_)
    The major **skills** for this class.

**minorSkills** (`table`_ of `number`_)
    The minor **skills** for this class.

**objectType** (`number`_, read-only)
    The object's `objectType`_.

**playable** (`boolean`_)
    A flag that determines if the player can choose this class.

**skills** (`table`_ of `number`_)
    A list of skills that the class has assigned to it. Odd-indexed skills are major, while even-indexed skills are major.

**sourceMod** (`string`_)
    The object's originating plugin filename.

**specialization** (`number`_)
    The specialization of the class, be it combat, stealth, or magic.


.. _`boolean`: ../lua/boolean.html
.. _`number`: ../lua/number.html
.. _`string`: ../lua/string.html
.. _`table`: ../lua/table.html
.. _`userdata`: ../lua/userdata.html

.. _`boundingBox`: physicalObject/boundingBox.html
.. _`NPC`: npc.html
.. _`objectType`: baseObject/objectType.html
