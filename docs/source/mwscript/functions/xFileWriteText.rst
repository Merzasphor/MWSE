
xFileWriteText
========================================================

**Parameters:**

- ``string`` **filename**: The file to write value to.
- ``string`` **format**: The format to use when writing to the file.
- ``varies`` **values**: Multiple values that match the **format**.

**Returned:**

- *None*

Writes a formatted ``string`` to the file at the current position and advances. 

The formatting rules are the same as for the `xStringBuild`_ function with one addition. Placing a ``%`` at the end of the pattern will suppress the NULL that is normally printed, so a format string ending with ``%N%`` can be used to create a normal text file.

.. note:: The file is truncated at the current position (just after the end of the new value). This means that you cannot use this to modify the values in the middle of an existing file.

.. _`xStringBuild`: xStringBuild.html
