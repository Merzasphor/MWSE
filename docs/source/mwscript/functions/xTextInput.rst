
xTextInput
========================================================

**Parameters:**

- ``string`` **string**: The string to modify with the user's input.
- ``long`` **endCode**: The `Virtual-Key Code`_ used to stop reading input.

**Returned:**

- ``long`` **length**: The length of **text**.
- ``string`` **text**: The text entered.

This function allows you to directly read keyboard input from the user and the results will be returned as a string. Pass a string and a virtual key code to the function. The function will wait for a key to be pressed and then take one of three actions. If the key pressed matches the **endCode** parameter, the string and its length are returned. If the key pressed is a printable ASCII character, the character is added to the string and the string and the number 0 are returned. If the key is RETURN or BACKSPACE, a new line is started or one character is removed from the string, and the modifed string and a 0 are returned. The function returns after each key press so that the current value of the string can be shown with xMessageFix and MessageBox but the string should only be used normally after the length is returned. Player controls should be disabled while this function is used.

.. note:: `xGetKeyBind`_ can be used to determine a specific key the user has configured.

.. _`xGetKeyBind`: xGetKeyBind.html
.. _`Virtual-Key Code`: https://msdn.microsoft.com/en-us/library/windows/desktop/dd375731(v=vs.85).aspx
