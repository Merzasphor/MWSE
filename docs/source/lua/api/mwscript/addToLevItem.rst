
mwscript.addToLevItem
====================================================================================================

**Parameters:**

All parameters are passed via a table.

- ``tes3levelledlist`` **list**: The levelled item list that will be added to.
- ``tes3physicalobject`` **item**: The item that will be added.
- ``number`` **level**: The minimum player level to trigger the item.

**Returned:**

- ``nil``


This functions wraps around the vanilla ``AddToLevItem`` function.

.. note:: ``mwscript`` functions can also accept ``string`` parameters.

Examples
----------------------------------------------------------------------------------------------------

.. code-block:: lua

    mwscript.addToLevItem({list = "l_m_amulets", item = "amulet of 6th house", level = 15})
