
mwscript.getItemCount
====================================================================================================

**Parameters:**

All parameters are passed via a table.

- ``tes3reference`` **reference**: The reference to check item count for.
- ``tes3physicalobject`` **item**: The item to check for.

**Returned:**

- ``number`` **count**: The number item copies that reference is carrying.


This functions wraps around the vanilla ``Getitemcount`` function.

.. note:: ``mwscript`` functions can also accept ``string`` parameters.

Examples
----------------------------------------------------------------------------------------------------

.. code-block:: lua

    mwscript.getItemCount({reference = "player", item = "gold_001"})
