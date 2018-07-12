
mwscript.getDetected
====================================================================================================

**Parameters:**

All parameters are passed via a table.

- ``tes3reference`` **reference**: The detecting reference.
- ``tes3reference`` **target**: The target to be detected.

**Returned:**

- ``boolean`` **result**: ``true`` if the target is detected by the reference.


This functions wraps around the vanilla ``Getdetected`` function.

.. note:: ``mwscript`` functions can also accept ``string`` parameters.

Examples
----------------------------------------------------------------------------------------------------

.. code-block:: lua

    -- scan the current cell for npcs who detect the player
    for ref in tes3.getPlayerCell():iterateReferences(tes3.objectType.npc) do
        if mwscript.getDetected({reference = ref, target = tes3.player}) then
            tes3.messageBox("%s can detect you!", ref.object.name)
        end
    end
