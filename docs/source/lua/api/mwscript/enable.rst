
mwscript.enable
====================================================================================================

**Parameters:**

All parameters are passed via a table.

- ``tes3reference`` **reference**: The reference to be enabled.
- ``bool`` **modify**: Whether to flag **reference** as modified.

**Returned:**

- ``nil``


This functions wraps around the vanilla ``Enable`` function.

.. note:: ``mwscript`` functions can also accept ``string`` parameters.

Examples
----------------------------------------------------------------------------------------------------

.. code-block:: lua

    mwscript.disable({reference = "fargoth"})
