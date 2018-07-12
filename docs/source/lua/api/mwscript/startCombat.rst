
mwscript.startCombat
====================================================================================================

**Parameters:**

All parameters are passed via a table.

- ``tes3reference`` **reference**: The reference who's level will be modified.
- ``tes3reference`` **target**: The reference who's level will be modified.

**Returned:**

- ``nil``


This functions wraps around the vanilla ``StartCombat`` function.

.. note:: ``mwscript`` functions can also accept ``string`` parameters.

Examples
----------------------------------------------------------------------------------------------------

.. code-block:: lua

    mwscript.startCombat({reference = "fargoth", target = "player"})
