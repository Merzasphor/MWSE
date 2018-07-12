
mwscript.onActivate
====================================================================================================

**Parameters:**

All parameters are passed via a table.

- ``tes3reference`` **reference**: The reference to detect if activated.

**Returned:**

- ``boolean`` **result**: ``true`` if the reference was activated.


This functions wraps around the vanilla ``OnActivate`` function.

.. note:: ``mwscript`` functions can also accept ``string`` parameters.

Examples
----------------------------------------------------------------------------------------------------

.. code-block:: lua

    if mwscript.onActivate{reference = "fargoth"} then
        -- activate was detected and intercepted!
        tes3.messageBox("Fargoth ignores you.")
    end
