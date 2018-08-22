
Leveled Item
========================================================

A leveled item is a core game object responsible for holding a list of potential options, one of which might be picked at runtime.


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
    Contains each item in the leveled list.


Functions
--------------------------------------------------------

`Object`_ **pickFrom()**
    Returns:
        The object randomly chosen from the leveled list. This may be ``nil``, or altered from the `leveledItemPicked`_ event.

    Randomly chooses an item from the leveled list.


.. _`boolean`: ../lua/boolean.html
.. _`number`: ../lua/number.html
.. _`string`: ../lua/string.html
.. _`table`: ../lua/table.html
.. _`userdata`: ../lua/userdata.html

.. _`leveledItemPicked`: ../../event/leveledItemPicked.html

.. _`Iterator`: iterator.html
.. _`Leveled List Nodes`: leveledListNode.html
.. _`Object Type`: baseObject/objectType.html
.. _`Object`: object.html
