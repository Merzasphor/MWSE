
math.clamp
========================================================

**Parameters:**

- ``number`` **value**: The number to be clamped.
- ``number`` **min**: The minimum value.
- ``number`` **max**: The maximum value.

**Returned:**

- ``number`` **result**: The clamped value.

This function clamps value between the minimum and maximum.
::
	local x = 13
	math.clamp(x, 0, 10)	--x is larger than max, returns 10
	math.clamp(x, 0, 100)	--x is within min and max, returns x (13)