
xLogMessage
========================================================

**Parameters:**

- ``string`` **format**: The formatting for the log message.
- ``varies`` (many) **input**: Values to inject into the **format**.

**Returned:**

- *None*

Writes out formatted strings to the log file (MWSELog.txt). This works much like MessageBox but with the additional formatting options described for `xStringBuild`_. A trailing ``%`` in the format string will suppress the printing of the new line sequence allowing a single line of text to be created with two or more xLogMessage calls. The number of parameters specified in the **format** *MUST* match those supplied or there will be trouble.

.. note:: Literal strings in MWEdit have a maximum length of 63 characters.

.. _`xStringBuild`: xStringBuild.html
