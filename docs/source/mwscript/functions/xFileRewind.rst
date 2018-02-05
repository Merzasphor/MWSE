
xFileRewind
========================================================

**Parameters:**

- ``string`` **filename**: The file to rewind.

**Returned:**

- *None*

This function moves the current reading position to the start of the file.

Call this or `xFileSeek`_ at the start of any script which uses file reading or writing functions, otherwise you will have problems with the current file position not being as expected.

.. _`xFileSeek`: xFileSeek.html
