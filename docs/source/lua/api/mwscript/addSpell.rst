
mwscript.addSpell
====================================================================================================

**Parameters:**

All parameters are passed via a table.

- ``tes3reference`` **reference**: The reference that the spell will be added to.
- ``tes3spell`` **spell**: The spell that will be added.

**Returned:**

- ``nil``


This functions wraps around the vanilla ``AddSpell`` function.

.. note:: ``mwscript`` functions can also accept ``string`` parameters.

Examples
----------------------------------------------------------------------------------------------------

.. code-block:: lua

    mwscript.addSpell({reference = "player", spell = "levitate"})
