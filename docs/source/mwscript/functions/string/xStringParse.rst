
xStringParse
========================================================

**Parameters:**

- ``string`` **pattern**: The pattern to parse.
- ``string`` **source**: Indicates how much of the **pattern** matched successfully.

**Returned:**

- ``long`` **matchCount**: The number of matches returned.
- ``varies`` (many) **matches**: The values parsed out of the string.

This function identifies and extracts data from the **source** string based on the **pattern** string. The first return value **matchCount** is a long indicating how much of the pattern matched successfully. The **matches** by the pattern will then be returned in order.

In the pattern string, all of the special features begin with a ``%`` symbol. Some, simply match special characters that can't otherwise be typed in the pattern string.

====== ====================================
Token  Description
====== ====================================
``%%`` Matches a single % sign.
``%n`` Matches the new line marker, CR/LF.
``%q`` Matches the " quotation mark.
====== ====================================

The rest return the values matched so they can be stored in variables with ``setx``.

====== ====================================
Token  Description
====== ====================================
``%d`` Matches a decimal integer and the value is returned as type long.
``%h`` Matches a hexadecimal integer and the value is returned as type long.
``%f`` Matches a real number and the value is returned as type float.
``%s`` Matches the rest of the string and returns it as type string.
``%l`` Matches exactly four characters and returns them as type long.
====== ====================================

.. note:: The uppercase forms ``%N``, ``%Q``, ``%D``, ``%H``, ``%F``, ``%S``, and ``%L`` also work.

MWSE Version Checking
--------------------------------------------------------

A special use case of xStringParse is to check the version of MWSE. If a value of zero is returned, the version of MWSE is older than version 2.0.

To do this, **pattern** must be ``MWSE_VERSION``. **source** is instead a ``long``, to compare to the return value. If the version returned is greater than or equal to **source**, the second return value is 1.

Example:

::

  long version
  long versionAbove2p0

  setx version versionAbove2p0 to xStringParse "MWSE_VERSION" 2000000

The version returned is spaced. Version 2.0.0 is 2000000 while the hypothetical version 2.34.9 would be 2034009.
