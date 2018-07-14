
math.round
========================================================

Returns the value rounded to the specified number of digits.

**Parameters:**

- ``number`` **value**: The number to be rounded.
- ``number`` **digits**: The number of digits to round to.

**Returned:**

- ``number`` **result**: The rounded value.

.. code-block:: lua

   local result = math.round(0.8)
   assert(result == 1)

   local result = math.round(0.567, 2)
   assert(result == 0.57)
