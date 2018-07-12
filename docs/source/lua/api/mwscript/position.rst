
mwscript.position
====================================================================================================

**Parameters:**

All parameters are passed via a table.

- ``tes3reference`` **reference**: The reference that will be positioned.
- ``number`` **x**: The new X position.
- ``number`` **y**: The new Y position.
- ``number`` **z**: The new Z position.
- ``number`` **rotation**: The new Z rotation.

**Returned:**

- ``nil``


This functions wraps around the vanilla ``Position`` function.

.. note:: ``mwscript`` functions can also accept ``string`` parameters.

Examples
----------------------------------------------------------------------------------------------------

.. code-block:: lua

  mwscript.position({reference = "player", x = 0, y = 0, z = 0, rotation = 0})
