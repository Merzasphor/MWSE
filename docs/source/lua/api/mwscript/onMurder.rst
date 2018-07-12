
mwscript.onMurder
====================================================================================================

**Parameters:**

All parameters are passed via a table.

- ``tes3reference`` **reference**: The reference to detect if was murdered on this frame.

**Returned:**

- ``boolean`` **result**: ``true`` if the reference was was murdered on this frame.


This functions wraps around the vanilla ``OnMurder`` function.

.. note:: ``mwscript`` functions can also accept ``string`` parameters.

Examples
----------------------------------------------------------------------------------------------------

.. code-block:: lua

    mwscript.onMurder({reference = "fargoth"})
