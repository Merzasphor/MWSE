
xFileReadText
========================================================

**Parameters:**

- ``string`` **filename**: The file to read values from.
- ``string`` **pattern**: The pattern to match when reading.

**Returned:**

- ``long`` **numMatches**: The number of values read.
- ``varies`` **matches**: A value returned. A number of values will be returned matching **numMatches**.

xFileReadText reads a text string from from the file at the current reading position. The current position is then advanced. The **pattern** string is then used to extract data from the string just read; the first return value indicates how much of the pattern is matched. The values matched by the pattern are also returned.

The **pattern** and return values are the same as for the `xStringParse`_ function with one addition: placing a single ``%`` sign at the end of the pattern will cause the read routine to stop when it gets to the end of a line (CR/LF) allowing you to use this to read a normal text file instead of a binary file. Without the trailing % sign on the pattern this will read up to the first NULL character or to the end of the file if it doesn't find a NULL character.

.. _`xStringParse`: xStringParse.html
