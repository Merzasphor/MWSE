
xScriptRunning
========================================================

**Parameters:**

- ``string`` **scriptName**: The name of the script to determine the status of.

**Returned:**

- ``long`` **status**: 1 if the script is running, or 0 if it is not (or does not exist).

This function is a wrapper around ``ScriptRunning`` which allows a variable input.

.. note:: Two other wrapper functions exist to allow dynamic script execution, `xStartScript`_ and `xStopScript`_.

.. _`xStartScript`: xStartScript.html
.. _`xStopScript`: xStopScript.html
