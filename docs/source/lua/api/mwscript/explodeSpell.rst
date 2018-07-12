
mwscript.explodeSpell
====================================================================================================

**Parameters:**

All parameters are passed via a table.

- ``tes3reference`` **reference**: The reference that will cast the spell.
- ``tes3spell`` **spell**: The spell to be cast.

**Returned:**

- ``nil``


This functions wraps around the vanilla ``ExplodeSpell`` function.

.. note:: ``mwscript`` functions can also accept ``string`` parameters.

Examples
----------------------------------------------------------------------------------------------------

.. code-block:: lua

    mwscript.explodeSpell({reference = "fargoth", spell = "potent poison"})
