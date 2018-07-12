
mwscript.getSpellEffects
====================================================================================================

**Parameters:**

All parameters are passed via a table.

- ``tes3reference`` **reference**: The reference to check if affected.
- ``tes3spell`` **spell**: The spell that will be checked for.

**Returned:**

- ``boolean`` **result**: ``true`` if the reference is under the effects of the spell.


This functions wraps around the vanilla ``GetSpellEffects`` function.

.. note:: ``mwscript`` functions can also accept ``string`` parameters.

Examples
----------------------------------------------------------------------------------------------------

.. code-block:: lua

    mwscript.getSpellEffects({reference = "player", spell = "adrenaline rush"}) then
