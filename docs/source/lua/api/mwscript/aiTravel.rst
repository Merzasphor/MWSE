
mwscript.aiTravel
====================================================================================================

**Parameters:**

All parameters are passed via a table.

- ``tes3reference`` **reference**: The reference that will begin travelling.
- ``number`` **x**: The X coordinate to be travelled to.
- ``number`` **y**: The Y coordinate to be travelled to.
- ``number`` **z**: The Z coordinate to be travelled to.

**Returned:**

- ``nil``


This functions wraps around the vanilla ``AITravel`` function.

.. note:: ``mwscript`` functions can also accept ``string`` parameters.

Examples
----------------------------------------------------------------------------------------------------

.. code-block:: lua

    mwscript.aiTravel({reference = "adaves therayn", x = 10199, y = 1945, z = 100})
