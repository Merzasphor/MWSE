
mwscript.activate
====================================================================================================

**Parameters:**

All parameters are passed via a table.

- ``tes3reference`` **reference**: The reference that will be activated.

**Returned:**

- ``nil``


This functions wraps around the vanilla ``Activate`` function.

.. note:: ``mwscript`` functions can also accept ``string`` parameters.

Examples
----------------------------------------------------------------------------------------------------

.. code-block:: lua

    -- note: this function is not recommended
    -- instead use: reference:activate(target)

    local target = tes3.getPlayerTarget()

    if mwscript.onActivate{reference = target} then
        mwscript.activate{reference = target}
    end
