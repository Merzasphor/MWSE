
mwscript.drop
====================================================================================================

**Parameters:**

All parameters are passed via a table.

- ``tes3reference`` **reference**: The reference that will drop the item.
- ``tes3physicalobject`` **item**: The item to be dropped.

**Returned:**

- ``nil``


This functions wraps around the vanilla ``Drop`` function.

.. note:: ``mwscript`` functions can also accept ``string`` parameters.

Examples
----------------------------------------------------------------------------------------------------

.. code-block:: lua

    mwscript.drop({reference = "galbedir", item = "exquisite_robe_01"})
