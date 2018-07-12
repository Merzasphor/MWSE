
mwscript.stopSound
====================================================================================================

**Parameters:**

All parameters are passed via a table.

- ``tes3reference`` **reference**: The reference for which the sound will be stopped.
- ``tes3sound`` **sound**: The sound that will be stopped.

**Returned:**

- ``nil``


This functions wraps around the vanilla ``Stopsound`` function.

.. note:: ``mwscript`` functions can also accept ``string`` parameters.

Examples
----------------------------------------------------------------------------------------------------

.. code-block:: lua

    mwscript.stopSound({reference = "player", sound = "weapon swish"})
