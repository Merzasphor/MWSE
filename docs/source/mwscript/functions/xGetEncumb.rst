
xGetEncumb
========================================================

**Parameters:**

- *None*

**Returned:**

- ``float`` **weight**: The weight, in pounds, of all the reference's inventory. This value is negative if leveled items are present.

Calculates the total, unmodified encumbrance of the target reference's inventory. This function does not take into account any *feather* or *burden* spell effects.

.. note:: If the target has any leveled items in its inventory, the returned **weight** is negative.
