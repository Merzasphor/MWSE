
xLongToFloats
========================================================

**Parameters:**

- ``long`` **value**: Value to split.

**Returned:**

- ``float`` **result1**: First half of the split **value**.
- ``float`` **result2**: Second half of the split **value**.

This function stores a long value using a pair of floats. It is intended to work around the issue that all globals are really floats.

This work by splitting the long 32-bit value into two 16-bit values and adding a flag to indicate which value maps to the high 16 bits. Argument order doesn't matter.

.. warning:: MWEdit doesn't like to compile these functions with globals as arguments, and temporary locals will need to be used instead.

Example
--------------------------------------------------------

::

  long lVal1
  long lVal2
  float fVal1
  float fVal2
  
  set lVal1 to 2147483647
  setx fVal1 fVal2 to xLongToFloats lVal1
  setx lVal2 to xFloatsToLong fVal1 fVal2
  
  if ( lVal1 == lVal2 )
      MessageBox "Success!"
  else
      MessageBox "Failure!"
  endif
