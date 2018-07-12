
mwscript.onDeath
====================================================================================================

**Parameters:**

All parameters are passed via a table.

- ``tes3reference`` **reference**:  The reference to detect if died on this frame.

**Returned:**

- ``boolean`` **result**: ``true`` if the reference died this frame.


This functions wraps around the vanilla ``OnDeath`` function.

.. note:: ``mwscript`` functions can also accept ``string`` parameters.

Examples
----------------------------------------------------------------------------------------------------

.. code-block:: lua

    mwscript.onDeath({reference = "fargoth"})

