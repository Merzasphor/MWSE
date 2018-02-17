
xModAttribute
========================================================

**Parameters:**

- ``long`` **attributeID**: The `Attribute`_ ID to modify.
- ``float`` **value**: The value to modify the attribute by.

**Returned:**

- ``short`` **result**: Result of the function.

Modifies the current and base values of the specified attribute. This suffers from the same
display issue as xSetLevel. It ignores the 100 max attribute limit.

.. note:: This function only supports the player and NPCs.

.. _`Attribute`: ../../references.html#attributes
