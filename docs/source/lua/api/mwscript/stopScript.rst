
mwscript.stopScript
====================================================================================================

**Parameters:**

All parameters are passed via a table.

- ``tes3script`` **script**: The script to be started.

**Returned:**

- ``nil``


This functions wraps around the vanilla ``StopScript`` function.

.. note:: ``mwscript`` functions can also accept ``string`` parameters.

Examples
----------------------------------------------------------------------------------------------------

.. code-block:: lua

    mwscript.stopScript({script = "dbattackScript"})
