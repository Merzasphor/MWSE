
xAddEffect
========================================================

**Parameters:**

- ``long`` **objectType**: `Object Type`_ value for the target's type.
- ``string`` **objectID**: Object ID of target spell, enchantment, or potion.
- ``long`` **effectID**: `Magic Effect`_ ID that will be added to the target.
- ``long`` **skillAttributeID**: `Skill`_ or `Attribute`_ ID to be used. (Only for absorb/damage/drain/fortify/restore effects - ignored otherwise.)
- ``long`` **rangeType**: New range type. (0 = SELF, 1 = TOUCH, 2 = TARGET)
- ``long`` **area**: Area of effect.
- ``long`` **duration**: Duration in seconds.
- ``long`` **magMin**: Minimum magnitude.
- ``long`` **magMax**: Maximum magnitude.

**Returned:**

- ``long`` **success**: 1 if the effect was added, or 0 if it wasn't.

Adds a new effect to the given spell, enchantment, or potion.

.. _`Object Type`: ../references.html#object-types
.. _`Magic Effect`: ../references.html#magic-effects
.. _`Attribute`: ../references.html#attributes
.. _`Skill`: ../references.html#skills

Example
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

::

  begin Example_xAddEffect

  short result

  ; Fire Damage (14), On Touch (1), Duration (30), Magnitude (1 to 5)
  setx result to xAddEffect 1279610963 "fire bite" 14 0 1 0 30 1 5

  if ( result != 0 )
      MessageBox "Your 'Fire Bite' spell has been upgraded!"
  endif

  StopScript Example_xAddEffect

  end
