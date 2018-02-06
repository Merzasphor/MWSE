
xStringBuild
========================================================

**Parameters:**

- ``string`` **format**: The format string to use, given the tokens below.
- ``varies`` (many) **input**: The variables to use, matching the pattern of special tokens below.

**Returned:**

- ``string`` **result**: A string build from the combined input.

xStringBuild returns a new string that is constructed based on the format string and any other variable values as needed. The format string is similar to those for ``MessageBox`` with ``%`` indicating some special character or variable substitution.

Some patterns can be used to place special characters into the string:

====== ===================================================================
Token  Meaning
====== ===================================================================
``%%`` A single % sign is placed in the string.
``%n`` A new line marker (CR/LF) is placed in the string.
``%q`` A quotation mark (") is placed in the string.
====== ===================================================================

The rest are used to insert values from the remaining parameters into the output string.

====== ===================================================================
Token  Meaning
====== ===================================================================
``%d`` A short or long value is inserted as a decimal integer.
``%h`` A short or long value is inserted as a hexadecimal integer.
``%f`` A float value is inserted as real decimal number.
``%s`` A string value is inserted.
``%l`` A long value is inserted as a four character string.
====== ===================================================================

.. note:: The uppercase forms ``%N``, ``%Q``, ``%D``, ``%H``, ``%F``, ``%S``, and ``%L`` also work.

The float specifier takes a precision specifier just like the MessageBox command. The format ``%.3f`` will print a floating point value with three digits after the decimal point.

The string specifier can take two numbers in its specifier:

========= =====================================================================
Token     Meaning
========= =====================================================================
``%2s``   Skips the first two characters of the string, but inserts the rest.
``%.3s``  Inserts only three characters of the string.
``%4.5s`` Skips 4 characters, then inserts the next 5 characters of the string.
========= =====================================================================

.. note:: The compiler doesn't currently support more than 12 parameters at a time.

.. note:: The format string is limited to 64 characters.
