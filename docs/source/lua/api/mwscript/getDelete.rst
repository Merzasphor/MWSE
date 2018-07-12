
mwscript.getDelete
====================================================================================================

**Parameters:**

All parameters are passed via a table.

- ``tes3reference`` **reference**: The reference to check for deletion.

**Returned:**

- ``boolean`` **result**: ``true`` if reference is deleted.


.. note:: ``mwscript`` functions can also accept ``string`` parameters.

Examples
----------------------------------------------------------------------------------------------------

.. code-block:: lua

    -- scan the current cell for deleted objects
    for ref in tes3.getPlayerCell():iterateReferences() do
        if mwscript.getDelete({reference=ref}) then
            tes3.messageBox("%s is deleted", ref)
        end
    end
