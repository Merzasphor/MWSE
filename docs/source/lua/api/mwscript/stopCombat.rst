
mwscript.stopCombat
====================================================================================================

**Parameters:**

All parameters are passed via a table.

- ``tes3reference`` **reference**: The that will cease combat.

**Returned:**

- ``nil``


This functions wraps around the vanilla ``StopCombat`` function.

.. note:: ``mwscript`` functions can also accept ``string`` parameters.

Examples
----------------------------------------------------------------------------------------------------

.. code-block:: lua

    mwscript.stopCombat({TODO = tes3.player})
