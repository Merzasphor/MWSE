
mwscript.scriptRunning
====================================================================================================

**Parameters:**

All parameters are passed via a table.

- ``tes3script`` **script**: The script to check if running.

**Returned:**

- ``boolean`` **result**: ``true`` if the script is currently running.


This functions wraps around the vanilla ``ScriptRunning`` function.

.. note:: ``mwscript`` functions can also accept ``string`` parameters.

Examples
----------------------------------------------------------------------------------------------------

.. code-block:: lua

  mwscript.scriptRunning({script = "tribunalmain"})
