
mwscript.equip
====================================================================================================

**Parameters:**

All parameters are passed via a table.

- ``tes3reference`` **reference**: TODO
- ``tes3physicalobject`` **item**: TODO

**Returned:**

- ``nil``


This functions wraps around the vanilla ``Equip`` function.

.. note:: ``mwscript`` functions can also accept ``string`` parameters.

Examples
----------------------------------------------------------------------------------------------------

.. code-block:: lua

    mwscript.equip({reference = "fargoth", item = "fur_colovian_helm"})
