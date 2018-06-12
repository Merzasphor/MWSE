
math.clamp
========================================================

This function clamps value between the minimum and maximum.

**Parameters:**

- ``number`` **value**: The number to be clamped.
- ``number`` **min**: The minimum value.
- ``number`` **max**: The maximum value.

**Returned:**

- ``number`` **result**: The clamped value.

.. code-block:: lua

    local x = 13
	
    x = math.clamp(x, 0, 10)	--x is larger than max, returns 10
	print(x)    --prints 10

    x = math.clamp(x, 0, 100)	--x is within min and max, returns x (13)
	print(x)    --prints 13