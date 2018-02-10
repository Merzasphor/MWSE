
xGetEffectInfo
========================================================

**Parameters:**

- ``long`` **type**: The `Object Type`_ to get the effect of.
- ``string`` **objectID**: The Object ID of the object to get the effect of.
- ``long`` **index**: The effect index to get the info from, from 1 to 8.

**Returned:**

- ``long`` **effectId**: The `Effect ID`_ of the effect.
- ``long`` **skillAttribId**: The `Attribute`_ or `Skill`_ ID associated with the effect, if applicable.
- ``long`` **rangeType**: 0 = SELF, 1 = TOUCH, 2 = TARGET
- ``long`` **area**: Area of effect.
- ``long`` **duration**: Duration in seconds.
- ``long`` **magMin**: Minimum magnitude.
- ``long`` **magMax**: Maximum magnitude.

Returns the properties of an effect on the given alchemy item, spell, or enchantment.

.. note:: On failure, **effectId** is set to -1.

.. _`Object Type`: ../references.html#record-types
.. _`Effect ID`: ../references.html#magic-effects
.. _`Attribute`: ../references.html#attributes
.. _`Skill`: ../references.html#skills
