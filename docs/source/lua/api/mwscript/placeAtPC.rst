
mwscript.placeAtPC
====================================================================================================

**Parameters:**

All parameters are passed via a table.

- ``tes3physicalobject`` **object**: The object that will be placed.
- ``number`` **count**: The number of copies of the object the will be placed.
- ``number`` **distance**: The distance at which to player the object from the player.
- ``number`` **direction**: The direction in which to player the object from player.

**Returned:**

- ``tes3reference`` **reference**: The placed reference.


This functions wraps around the vanilla ``PlaceAtPC`` function.

.. note:: ``mwscript`` functions can also accept ``string`` parameters.

Examples
----------------------------------------------------------------------------------------------------

.. code-block:: lua

    local ref = mwscript.placeAtPC({object = "fargoth", count = 1, distance = 0, direction = 0})
