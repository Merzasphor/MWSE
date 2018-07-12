
mwscript.getDisabled
====================================================================================================

**Parameters:**

All parameters are passed via a table.

- ``tes3reference`` **reference**: The reference to check for disabled.

**Returned:**

- ``boolean`` **result**: ``true`` if the reference is disabled.


This functions wraps around the vanilla ``GetDisabled`` function.

.. note:: ``mwscript`` functions can also accept ``string`` parameters.

Examples
----------------------------------------------------------------------------------------------------

.. code-block:: lua

    mwscript.getDisabled({reference = "fargoth"})
