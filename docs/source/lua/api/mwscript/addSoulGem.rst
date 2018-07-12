
mwscript.addSoulGem
====================================================================================================

**Parameters:**

All parameters are passed via a table.

- ``tes3reference`` **reference**: The reference that the soulgem will be added to.
- ``tes3creature`` **creature**: The created soulgem's trapped creature.
- ``tes3miscitem`` **soulgem**: The soulgem type that will be created.

**Returned:**

- ``nil``


This functions wraps around the vanilla ``AddSoulgem`` function.

.. note:: ``mwscript`` functions can also accept ``string`` parameters.

Examples
----------------------------------------------------------------------------------------------------

.. code-block:: lua

    mwscript.addSoulGem({reference = "player", creature = "alit", soulgem = "misc_soulgem_petty"})
