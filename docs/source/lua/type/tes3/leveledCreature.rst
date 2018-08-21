
Leveled Creature
========================================================

A leveled creature is a core game object responsible for holding a list of potential options, one of which might be picked at runtime.


Properties
--------------------------------------------------------

**id** (`string`_)
    The object's unique id.

**objectType** (`number`_)
    The object's `Object Type`_.

**sourceMod** (`string`_)
    The object's originating plugin filename.

**chanceForNothing** (`number`_)
    The chance that the list will return nothing.

**list** (`Iterator`_ of `Leveled List Nodes`_, read-only)
    Contains each creature in the leveled list.


Functions
--------------------------------------------------------

`Creature`_ **pickFrom()**
    Returns:
        The creature randomly chosen from the leveled list. This may be ``nil``, or altered from the `leveledCreaturePicked`_ event.

    Randomly chooses a creature from the leveled list.


.. _`boolean`: ../lua/boolean.html
.. _`number`: ../lua/number.html
.. _`string`: ../lua/string.html
.. _`table`: ../lua/table.html
.. _`userdata`: ../lua/userdata.html

.. _`leveledCreaturePicked`: ../../event/leveledCreaturePicked.html

.. _`Creature`: creature.html
.. _`Iterator`: iterator.html
.. _`Leveled List Nodes`: leveledListNode.html
.. _`Object Type`: baseObject/objectType.html
