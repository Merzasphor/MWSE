
xFileSeek
========================================================

**Parameters:**

- ``string`` **filename**: The file to seek in.
- ``long`` **position**: 

**Returned:**

- *None*

This function moves the current reading position to the specified offset in the file.

You should call this or `xFileRewind`_ every frame before using other file functions. Use an offset divisible by 2 to read shorts and an offset divisible by 4 to read longs.

This function isn't very useful if the file contains string data.

.. _`xFileRewind`: xFileRewind.html
