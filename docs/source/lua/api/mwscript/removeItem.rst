
mwscript.removeItem
====================================================================================================

**Parameters:**

All parameters are passed via a table.

- ``tes3reference`` **reference**: The reference that the item will be removed from.
- ``tes3physicalobject`` **item**: The item that will be removed from the reference.
- ``number`` **count**: The number of item copies that will be removed

**Returned:**

- ``nil``


This functions wraps around the vanilla ``RemoveItem`` function.

.. note:: ``mwscript`` functions can also accept ``string`` parameters.

Examples
----------------------------------------------------------------------------------------------------

.. code-block:: lua

    mwscript.removeItem({reference = "player", item = "gold_001", count = 20000})
