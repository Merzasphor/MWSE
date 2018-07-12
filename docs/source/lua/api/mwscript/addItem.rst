
mwscript.addItem
====================================================================================================

**Parameters:**

All parameters are passed via a table.

- ``tes3reference`` **reference**: The reference that the item will be added to.
- ``tes3physicalobject`` **item**: The item that will be added to the reference.
- ``number`` **count**: The number of item copies that will be added.

**Returned:**

- ``nil``


This functions wraps around the vanilla ``AddItem`` function.

.. note:: ``mwscript`` functions can also accept ``string`` parameters.

Examples
----------------------------------------------------------------------------------------------------

.. code-block:: lua

    mwscript.addItem({reference = "player", item = "gold_001", count = 20000})
