
math.remap
========================================================

**Parameters:**

- ``number`` **value**: The number to be remapped.
- ``number`` **previous minimum**: The original minimum value.
- ``number`` **previous maximum**: The original maximum value.
- ``number`` **new minimum**: The new minimum value.
- ``number`` **new maximum**: The new maximum value.

**Returned:**

- ``number`` **result**: The remapped value.

This function remaps value from one scale to another.

.. code-block:: lua

    local x = 13
    math.remap(x, 0, 100, -1, 1)	--remap x from a percentage to -1 to 1. returns -0.74
    math.remap(x, 0, 100, 100, 0)	--remap x, inverting the percentage. returns 87
