
mwscript.getDistance
====================================================================================================

**Parameters:**

All parameters are passed via a table.

- ``tes3reference`` **reference**: The calling reference.
- ``tes3reference`` **target**: The target reference.

**Returned:**

- ``number`` **distance**: The distance between reference and target.


This functions wraps around the vanilla ``GetDistance`` function.

.. note:: ``mwscript`` functions can also accept ``string`` parameters.

Examples
----------------------------------------------------------------------------------------------------

.. code-block:: lua

    mwscript.getDistance({reference = "player", target = "fargoth"})
