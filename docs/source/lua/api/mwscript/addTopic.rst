
mwscript.addTopic
====================================================================================================

**Parameters:**

All parameters are passed via a table.

- ``string`` **topic**: The dialogue topic to be added the list of known topics.

**Returned:**

- ``nil``


This functions wraps around the vanilla ``AddTopic`` function.

.. note:: ``mwscript`` functions can also accept ``string`` parameters.

Examples
----------------------------------------------------------------------------------------------------

.. code-block:: lua

    mwscript.addTopic({topic = "Background"})
