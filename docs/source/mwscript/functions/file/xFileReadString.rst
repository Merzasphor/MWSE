
xFileReadString
========================================================

**Parameters:**

- ``string`` **filename**: The file to read values from.

**Returned:**

- ``string`` **value**: The value read from the file.

Reads from **filename** at the current reading position, until a C-style null terminator (``\0``/``0x00``) is read. The current position is advanced as read, and the resultant bytes are returned as a string.
