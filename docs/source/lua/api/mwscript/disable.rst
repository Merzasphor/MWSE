
mwscript.disable
====================================================================================================

**Parameters:**

All parameters are passed via a table.

- ``tes3reference`` **reference**: The reference to be disabled.
- ``bool`` **modify**: Whether to flag the reference as modified.

**Returned:**

- ``nil``


This functions wraps around the vanilla ``Disable`` function.

.. note:: ``mwscript`` functions can also accept ``string`` parameters.

Examples
----------------------------------------------------------------------------------------------------

.. code-block:: lua

    mwscript.disable({reference = "fargoth"})
