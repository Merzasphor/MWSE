
xSetCondition
========================================================

**Parameters:**

- ``float`` **Condition**: New condition that will be set on the reference.

**Returned:**

- ``long`` **result**: 1 if the reference's was modified, otherwise 0.

Sets the current condition of armor and weapons. Armor must not be at 100% or this function will fail. It must have already sustained some damage.

.. tip:: Use `xGetCondition`_ to read this value.

.. _`xGetCondition`: xGetCondition.html
