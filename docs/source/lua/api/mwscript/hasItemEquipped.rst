
mwscript.hasItemEquipped
====================================================================================================

**Parameters:**

All parameters are passed via a table.

- ``tes3reference`` **reference**: The reference to check equip state for.
- ``tes3physicalobject`` **item**: The item to check if equipped.

**Returned:**

- ``boolean`` **result**: ``true`` if the reference has the item equipped.


This functions wraps around the vanilla ``HasItemEquipped`` function.

.. note:: ``mwscript`` functions can also accept ``string`` parameters.

Examples
----------------------------------------------------------------------------------------------------

.. code-block:: lua

    mwscript.hasItemEquipped({reference = "fargoth", item = "fur_colovian_helm"})
