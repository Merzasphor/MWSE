
Lock Node
========================================================

Lock nodes are one of the attachments that a reference can have. This provides information on lock and trap state.


Properties
--------------------------------------------------------

**key** (`tes3miscItem`_)
    The key used to bypass the lock and trap.

**level** (`number`_)
    The lock's current level.

**locked** (`boolean`_)
    The lock state. If ``true``, the associated reference is locked.

**trap** (`tes3spell`_)
    The object's mesh path, relative to 'Data Files/Meshes'.


.. _`boolean`: ../lua/boolean.html
.. _`number`: ../lua/number.html
.. _`string`: ../lua/string.html
.. _`table`: ../lua/table.html
.. _`userdata`: ../lua/userdata.html

.. _`tes3miscItem`: miscItem.html
.. _`tes3spell`: spell.html
