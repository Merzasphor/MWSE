
xFileWriteString
========================================================

**Parameters:**

- ``string`` **filename**: The file to write value to.
- ``string`` **value**: The value to write to file.

**Returned:**

- *None*

Writes a ``string`` **value** to **filename** at the current position. The string is stored in the file as a C-style null-terminated string. The current position is then advanced.

.. note:: The file is truncated at the current position (just after the end of the new value). This means that you cannot use this to modify the values in the middle of an existing file.
