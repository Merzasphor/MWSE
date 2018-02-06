
xSetBaseGold
========================================================

**Parameters:**

- ``long`` **gold**:  New value to set the reference's base barter gold to.

**Returned:**

- *None*

Changes the base amount of barter gold assigned to the NPC (or creature). Unfortunately this change won't be saved with the save game so you will need to reset it after each game reload or after the "72-hour bug" affects the merchant.

.. tip:: Use `xGetBaseGold`_ to read this value.

.. _`xGetBaseGold`: xGetBaseGold.html