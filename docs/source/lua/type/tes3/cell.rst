
Cell
====================================================================================================

A cell is a container interior or exterior object representing an area in the world.


Properties
----------------------------------------------------------------------------------------------------

**activators** (`tes3referenceList`_, read-only)
    One of the containers that holds references currently in the cell.

**actors** (`tes3referenceList`_, read-only)
    One of the containers that holds references currently in the cell.

**ambientColor** (`tes3packedColor`_, read-only)
    Ambient color values. Only available for interior cells.

**behavesAsExterior** (`boolean`_)
    Friendly access into **flags**, providing access to if the cell is an interior, but should behave as an exterior.

**flags** (`number`_)
    A set of bit flags for the cell.

**fogColor** (`tes3packedColor`_, read-only)
    Fog color values. Only available for interior cells.

**fogDensity** (`number`_)
    The strength of the fog. Only available for interior cells.

**gridX** (`number`_, read-only)
    The cell's longitudinal world grid position. Only available for exterior cells.

**gridY** (`number`_, read-only)
    The cell's latitudinal world grid position. Only available for exterior cells.

**hasWater** (`boolean`_)
    Friendly access into **flags**, providing access to if the cell has water.

**isInterior** (`boolean`_)
    Friendly access into **flags**, providing access to if the cell is an interior.

**moveReferences** (`tes3iterator`_ of `tes3reference`_, read-only)
    One of the containers that holds references currently in the cell.

**region** (`tes3region`_, read-only)
    The associated region with the cell. Only available for exterior cells, or interior cells that behave as exterior cells.

**restingIsIllegal** (`boolean`_)
    Friendly access into **flags**, providing access to if the cell restricts resting.

**statics** (`tes3referenceList`_, read-only)
    One of the containers that holds references currently in the cell.

**sunColor** (`tes3packedColor`_, read-only)
    Sun color values. Only available for interior cells.

**waterLevel** (`number`_)
    The water level of the cell. Only available for interior cells that do not behave as exterior cells.


Functions
----------------------------------------------------------------------------------------------------

**iterateReferences**
    Returns values to be used in a ``for`` loop. This loops through **actors**, then **activators**, then **statics**. An optional parameter allows the objects to be filtered by their contained object's type.


.. _`boolean`: ../lua/boolean.html
.. _`number`: ../lua/number.html
.. _`string`: ../lua/string.html
.. _`table`: ../lua/table.html
.. _`userdata`: ../lua/userdata.html

.. _`tes3iterator`: iterator.html
.. _`tes3packedColor`: packedColor.html
.. _`tes3reference`: reference.html
.. _`tes3referenceList`: referenceList.html
.. _`tes3region`: region.html
