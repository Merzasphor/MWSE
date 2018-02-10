
xGetIngredientEffect
========================================================

**Parameters:**

- ``string`` **id**: The id of the ingredient to fetch data for.
- ``long`` **effectIndex**: A value between 1 and 4, matching the effect index desired.

**Returned:**

- ``long`` **effectType**: The `Effect Type`_ that the ingredient has at the given **effectIndex**.
- ``long`` **skillAttributeType**: The `Attribute Type`_ or `Skill Type`_, if the **effectType** supports one. Otherwise will always be -1.

This function allows scripts to determine the effects of a given ingredient programmatically. Scripts can alter these values as well using `xSetIngredientEffect`_.


Example
-------

::

  begin Example_xGetIngredientEffect

  long effect
  long skillAttribute

  setx effect skillAttribute to xGetIngredientEffect "food_kwama_egg_01" 1

  MessageBox "skill / attribute: %g" skillAttribute
  MessageBox "effect: %g" effectID
  MessageBox "food_kwama_egg_01"

  end


.. _`Effect Type`: ../references.html#magic-effects
.. _`Attribute Type`: ../references.html#attribute-types
.. _`Skill Type`: ../references.html#skill-types
.. _`xSetIngredientEffect`: xSetIngredientEffect.html
