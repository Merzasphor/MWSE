
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
