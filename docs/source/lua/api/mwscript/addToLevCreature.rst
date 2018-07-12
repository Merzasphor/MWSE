
mwscript.addToLevCreature
====================================================================================================

**Parameters:**

All parameters are passed via a table.

- ``tes3list`` **list**: The levelled creature list that will be added to.
- ``tes3creature`` **creature**: The creature that will be added.
- ``number`` **level**: The minimum player level to trigger the creature.

**Returned:**

- ``nil``


This functions wraps around the vanilla ``AddToLevCreature`` function.

.. note:: ``mwscript`` functions can also accept ``string`` parameters.

Examples
----------------------------------------------------------------------------------------------------

.. code-block:: lua

    mwscript.addToLevCreature({list = "ex_azurascoast_sleep", creature = "ash_ghoul", level = 25})
