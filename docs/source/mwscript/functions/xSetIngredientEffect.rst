
xSetIngredientEffect
========================================================

**Parameters:**

- ``string`` **id**: The id of the ingredient to fetch data for.
- ``long`` **effectIndex**: A value between 1 and 4, matching the effect index desired.
- ``long`` **effectType**: The `Effect Type`_ that the ingredient has at the given **effectIndex**.
- ``long`` **skillAttributeType**: The `Attribute Type`_ or `Skill Type`_, if the **effectType** supports one.

**Returned:**

- ``long`` **success**: If the effect was set, this value is 1. If it failed, the value is 0.

This function allows scripts to modify the effects of an ingredient programmatically.

To instead retrieve these values, use  `xGetIngredientEffect`_.

.. _`Effect Type`: ../references.html#effect-types
.. _`Attribute Type`: ../references.html#attribute-types
.. _`Skill Type`: ../references.html#skill-types
.. _`xGetIngredientEffect`: xGetIngredientEffect.html
