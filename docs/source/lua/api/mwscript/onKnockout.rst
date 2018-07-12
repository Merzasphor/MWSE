
mwscript.onKnockout
====================================================================================================

**Parameters:**

All parameters are passed via a table.

- ``tes3reference`` **reference**: The reference to detect if knocked out on this frame.

**Returned:**

- ``boolean`` **result**: ``true`` if the reference was knocked out on this frame.


This functions wraps around the vanilla ``OnKnockout`` function.

.. note:: ``mwscript`` functions can also accept ``string`` parameters.

Examples
----------------------------------------------------------------------------------------------------

.. code-block:: lua

    mwscript.onKnockout({reference = "fargoth"})

