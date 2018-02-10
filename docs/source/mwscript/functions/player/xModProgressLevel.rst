
xModProgressLevel
========================================================

**Parameters:**

- ``long`` **value**: Value added toward the player's progress to next level.

**Returned:**

- ``short`` **result**: ``1`` if successful, otherwise ``0``.

Adds value to the progress to the next player level. If the new progress value is less than zero,
it's set to zero instead. Returns non-zero on success, zero on failure.
