
xTextInput
========================================================

**Parameters:**

- ``string`` **string**: The string to modify with the user's input.
- ``long`` **endCode**: The `Virtual-Key Code`_ used to stop reading input.

**Returned:**

- ``long`` **length**: The length of **text**.
- ``string`` **text**: The text entered.

This function is identical to `xTextInput`_ except that the function simply checks the status of keys and returns immediately rather than waiting for a key to be pressed.

.. _`xTextInput`: xTextInput.html
.. _`Virtual-Key Code`: https://msdn.microsoft.com/en-us/library/windows/desktop/dd375731(v=vs.85).aspx
