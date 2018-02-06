
xSetGold
========================================================

**Parameters:**

- ``long`` **gold**:  New value to set the reference's barter gold to.

**Returned:**

- *None*

``xSetGold`` changes the current amount of barter gold possessed by the NPC (or creature). This value is stored in save game files so it will survive a game reload. Setting this will have no effect if you haven't recently bartered with the NPC/creature. (But setting both this and the base gold amount at the same time will likely do what you want.)

.. tip:: Use `xGetGold`_ to read this value.

.. _`xGetGold`: xGetGold.html