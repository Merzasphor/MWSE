
xKeyPressed
========================================================

**Parameters:**

- ``long`` **keyCode**: The `Virtual-Key Code`_ to check for input.

**Returned:**

- ``long`` (many) **keyStatus**: The status of **keyCode** if the parameter is non-zero. Otherwise it returns multiple times, with every key code pressed.

Monitors the status of the keyboard (and mouse buttons). This can be similar to GetPCSneaking, but actually detects whether a particular key is really being pressed. If input parameter code is a `Virtual-Key Code`_ (between 1 and 254) the return value will indicate the status of that key. A non-zero value means the key is being pressed. If the input code is 0, then on each call, the function will return the key code for the key (or one of the keys) currently being pressed.

.. warning:: Some of the codes match different keys on different keyboard layouts.

.. note:: The key VK code for a given input can be fetched using `xKeyPressed`_, instead of having to rely on hardcoded values.

.. _`xKeyPressed`: xKeyPressed.html
.. _`Virtual-Key Code`: https://msdn.microsoft.com/en-us/library/windows/desktop/dd375731(v=vs.85).aspx
