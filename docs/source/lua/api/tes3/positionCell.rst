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
    No description available.

orientation (`tes3vector3`_, `table`_)
    No description available.

position (`tes3vector3`_, `table`_)
    No description available.

reference (`tes3reference`_, `tes3mobileActor`_, `string`_)
    Default: ``tes3.mobilePlayer``. The reference to attach the sound to.

teleportCompanions (`boolean`_)
    Default: ``true``. If used on the player, determines if companions should also be teleported.

.. _`boolean`: ../../../lua/type/boolean.html
.. _`string`: ../../../lua/type/string.html
.. _`table`: ../../../lua/type/table.html
.. _`tes3mobileActor`: ../../../lua/type/tes3mobileActor.html
.. _`tes3reference`: ../../../lua/type/tes3reference.html
.. _`tes3vector3`: ../../../lua/type/tes3vector3.html
.. _`tes3cell`: ../../../lua/type/tes3cell.html
