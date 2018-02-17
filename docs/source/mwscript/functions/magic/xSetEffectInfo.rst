
xSetEffectInfo
========================================================

**Parameters:**

- ``long`` **type**: The `Object Type`_ of the object to alter.
- ``string`` **id**: The object ID of the object to alter.
- ``long`` **index**: The index of the effect to alter.
- ``long`` **effectID**: The `Effect Type`_ to change to.
- ``long`` **skillOrAttributeID**: The `Attribute`_ or `Skill`_ ID to use, if the **effectID** uses one.
- ``long`` **rangeType**: 0 = Self, 1 = Touch, 2 = Target.
- ``long`` **area**: Area of effect.
- ``long`` **duration**: Effect duration (in seconds).
- ``long`` **minimumMagnitude**: Minimum magnitude.
- ``long`` **maximumMagnitude**: Maximum magnitude.

**Returned:**

- ``long`` **result**: 1 on success, 0 on failure.

Modifies an existing effect on the given spell or enchantment.

.. _`Object Type`: ../../references.html#object-types
.. _`Effect Type`: ../../references.html#magic-effects
.. _`Attribute`: ../../references.html#attributes
.. _`Skill`: ../../references.html#skills
