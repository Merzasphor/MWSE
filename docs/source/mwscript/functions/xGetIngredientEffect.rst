
xGetIngredientEffect
========================================================

**Parameters:**

- ``string`` **id**: The id of the ingredient to fetch data for.
- ``long`` **effectIndex**: A value between 1 and 4, matching the effect index desired.

**Returned:**

- ``long`` **effectType**: The `Effect Type`_ that the ingredient has at the given **effectIndex**.
- ``long`` **skillAttributeType**: The `Attribute Type`_ or `Skill Type`_, if the **effectType** supports one.

This function allows scripts to determine the effects of a given ingredient programmatically. Scripts can alter these values as well using `xSetIngredientEffect`_.

.. _`Effect Type`: ../references.html#effect-types
.. _`Attribute Type`: ../references.html#attribute-types
.. _`Skill Type`: ../references.html#skill-types
.. _`xSetIngredientEffect`: xSetIngredientEffect.html
