
xDeleteEffect
========================================================

**Parameters:**

- ``long`` **type**: The `Object Type`_ to delete an effect from. Must be an alchemy, spell, or enchantment object.
- ``string`` **id**: The object ID to remove an effect from.
- ``long`` **index**: The index of the effect to remove. Must be between (inclusive) 1 and 8.

**Returned:**

- ``long`` **result**: 1 if the effect was deleted.

Removes the effect at index from the given spell or enchantment.

Other effects are reordered, e.g. if effect 1 is removed, effect 2 becomes 1, 3 becomes 2, etc.

.. _`Object Type`: ../../reference.html#object-types
