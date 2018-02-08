
xSetSkillInfo
========================================================

**Parameters:**

- ``long`` **skillID**: 1 if the effect was added, or 0 if it wasn't.

**Returned:**

- ``long`` **skillID**:  ID of the `Skill`_ to be modified.
- ``long`` **attributeID**: ID of the new governing `Attribute`_.
- ``long`` **specialization**: The new `Specialization Type`_.
- ``float`` **action1**: Progress value for the 1st action.
- ``float`` **action2**: Progress value for the 2nd action.
- ``float`` **action3**: Progress value for the 3rd action.
- ``float`` **action4**: Progress value for the 4th action.

All parameters seem to take effect immediately. There may be side-effects other than those listed below that I have not discovered yet.
Changing the governing attribute will cause any subsequent skill-ups to count toward that attribute at level-up.
(Which implies they're counted, not inferred, and could be modified. Stay tuned...)
Changing the specialization will cause the target progress needed for skill up to change. This function invokes the native
skill-up function when changing specialization, in case the change would cause progress to reach 100.
Actions can be set a negative value, in which case they'll remove progress, but progress will never go below zero.

.. _`Skill`: ../references.html#skills
.. _`Attribute`: ../references.html#attributes
.. _`Specialization Type`: ../references.html#specialization-types


setx attribute specialization action1 action2 action3 action4 to xGetSkillInfo 9