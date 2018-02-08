
xSetProgressLevel
========================================================

**Parameters:**

- ``long`` **progress**: New value for the player's progress to next level.

**Returned:**

- ``short`` **result**: ``1`` if successful, otherwise ``0``.

Sets the progress to next level. There are some limits to what you can do with this, because of how the game handles this
and other values.

Progress is stored in memory as a signed long (32 bits, max value = 2147483647).
Progress is stored in the save file as an unsigned char (8 bits, max value = 255)
Progress is cast to a float before being displayed on the character screen.
This appears to be true for iLevelupTotal as well.
