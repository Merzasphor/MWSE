
mwscript.setLevel
====================================================================================================

**Parameters:**

All parameters are passed via a table.

- ``tes3reference`` **reference**: The reference who's level will be modified.
- ``number`` **level**: The new level value.

**Returned:**

- ``nil``


This functions wraps around the vanilla ``SetLevel`` function.

.. note:: ``mwscript`` functions can also accept ``string`` parameters.

Examples
----------------------------------------------------------------------------------------------------

.. code-block:: lua

    mwscript.setLevel({reference = "fargoth", level = 100})

