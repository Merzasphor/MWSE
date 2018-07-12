
mwscript.removeSpell
====================================================================================================

**Parameters:**

All parameters are passed via a table.

- ``tes3reference`` **reference**: The reference that the spell will be removed from.
- ``tes3spell`` **spell**: The spell that will be removed.

**Returned:**

- ``nil``


This functions wraps around the vanilla ``RemoveSpell`` function.

.. note:: ``mwscript`` functions can also accept ``string`` parameters.

Examples
----------------------------------------------------------------------------------------------------

.. code-block:: lua

  mwscript.removeSpell({reference = "player", spell = "levitate"})
