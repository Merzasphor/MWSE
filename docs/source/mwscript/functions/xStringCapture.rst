
xStringCapture
========================================================

**Parameters:**

- ``string`` **string**: The string to search for **pattern** in.
- ``string`` **pattern**: The regex pattern to use.
- ``long`` **desiredMatches**: The number of results to return.

**Returned:**

- ``string`` (many) **matches**: Results of the pattern matching for **pattern** on **string**. The function always return **desiredMatches** results.

This function performs much as `xStringMatch`_, but returns the result groups of the regex match. The a number of results matching **desiredMatches** is always returned. The **matches** will be 0 if a match isn't made.

.. _`xStringMatch`: xStringMatch.html
