
mwscript.playSound
====================================================================================================

**Parameters:**

All parameters are passed via a table.

- ``tes3reference`` **reference**: The reference from which the sound will originate.
- ``tes3sound`` **sound**: The sound that will be played.

**Returned:**

- ``nil``


This functions wraps around the vanilla ``PlaySound`` function.

.. note:: ``mwscript`` functions can also accept ``string`` parameters.

Examples
----------------------------------------------------------------------------------------------------

.. code-block:: lua

  mwscript.playSound({reference = "player, sound = "bell3"})

