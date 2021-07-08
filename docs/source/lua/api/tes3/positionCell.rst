tes3.positionCell
====================================================================================================

Positions a reference to another place.

Returns
----------------------------------------------------------------------------------------------------

`boolean`_.

Parameters
----------------------------------------------------------------------------------------------------

Accepts parameters through a table with the given keys:

cell (`tes3cell`_)
    Optional. The cell to move the reference to. If not provided, the reference will be moved to a cell in the exterior worldspace at the position provided.

position (`tes3vector3`_, `table`_)
    The position to move the reference to.

orientation (`tes3vector3`_, `table`_)
    Optional. The position to move the reference to.

forceCellChange (`boolean`_)
    Default: ``false``. When true, forces the game to update a reference that has moved within a single cell, as if it was moved into a new cell.

suppressFader (`boolean`_)
    Default: ``false``. When moving the player, can be used to prevent the fade in and out visual effect.

teleportCompanions (`boolean`_)
    Default: ``true``. If used on the player, determines if companions should also be teleported.

.. _`boolean`: ../../../lua/type/boolean.html
.. _`table`: ../../../lua/type/table.html
.. _`tes3vector3`: ../../../lua/type/tes3vector3.html
.. _`tes3cell`: ../../../lua/type/tes3cell.html
