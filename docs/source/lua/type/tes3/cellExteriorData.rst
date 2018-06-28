
Cell Exterior Data
====================================================================================================

A container object for exterior cells. Contains a reference to the cell, as well as its X/Y grid position. The player's 9 currently loaded cells are referenced by this in the `Data Handler`_ core game structure.


Properties
----------------------------------------------------------------------------------------------------

**cell** (`tes3cell`_)
    The cell's longitudinal world grid position.

**gridX** (`number`_)
    The cell's longitudinal world grid position.

**gridY** (`number`_)
    The cell's latitudinal world grid position.


.. _`boolean`: ../lua/boolean.html
.. _`number`: ../lua/number.html
.. _`string`: ../lua/string.html
.. _`table`: ../lua/table.html
.. _`userdata`: ../lua/userdata.html

.. _`Data Handler`: dataHandler.html
.. _`tes3cell`: cell.html
