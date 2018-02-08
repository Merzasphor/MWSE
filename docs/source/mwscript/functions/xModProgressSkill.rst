
xModProgressSkill
========================================================

**Parameters:**

- ``long`` **skillID**: The `Skill`_ ID to modify.
- ``float`` **value**: The value to modify the skill's progress by.
- ``long`` **normalized**: flag indicating whether value is raw (0) or normalized (1)

**Returned:**

- ``short`` **result**: ``1`` if successful, otherwise ``0``.

Modifies the current progress for the given skill. If the new progress value is less than zero, it's
set to zero instead. Returns non-zero on success, zero on failure. This function will fail if
skill ID is out of range.

.. _`Skill`: ../references.html#skills
