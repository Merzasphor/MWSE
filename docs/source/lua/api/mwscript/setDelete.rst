
mwscript.setDelete
====================================================================================================

**Parameters:**

All parameters are passed via a table.

- ``tes3reference`` **reference**: The reference to be modified.
- ``bool`` **delete**: The new value for the delete flag. Defaults to ``true``.

**Returned:**

- ``nil``


This functions wraps around the vanilla ``SetDelete`` function.

.. note:: ``mwscript`` functions can also accept ``string`` parameters.

Examples
----------------------------------------------------------------------------------------------------

.. code-block:: lua

    mwscript.setDelete({reference = "fargoth", delete = true})

