
xSetBaseEffectInfo
========================================================

**Parameters:**

- ``long`` **effectID**: The `Magic Effect`_ to modify.
- ``long`` **school**: New spell `School`_.
- ``float`` **cost**: New base cost in magicka.
- ``long`` **flags**: New `Magic Effect Flags`_. Only spellmaking, enchanting, and negative lighting are valid here. All others are ignored.

**Returned:**

- ``long`` **result**: 1 on success, 0 on failure.

This function changes the properties of the effect for all magic that uses it. Changes to **school** and **flags** take effect immediately.

E.g. if you have a spell with a Fire Damage effect and you change the Fire Damage **school** to Alteration, casting that spell will raise Alteration instead of Destruction. Likewise, if you clear the Spellmaking or Enchanting flags, Fire Damage will no longer be available at the respective crafter. Changes to the base **cost** take effect on any subsequent spell or magic item creation, but don't affect any spells or items already in the game.

.. _`Magic Effect`: ../references.html#magic-effects
.. _`Magic Effect Flags`: ../references.html#magic-effects-flags
.. _`School`: ../references.html#schools
