
xGetMagic
========================================================

**Parameters:**

- *None*

**Returned:**

- ``long`` **objectType**: The `Object Type`_ of the equipped magical source.
- ``string`` **objectID**: The object ID of the spell or enchantment selected.

Returns the currently equipped spell or enchanted item. This is specifically the object that appears in the equipped magic slot and includes on-use magical items as well as spells.

.. note:: The returned **objectType** and **objectID** will always be associated with a *Spell* or *Enchantment* object, not the *Weapon*, *Armor*, *Clothing*, or *Book* that the magic is placed on.

.. _`Object Type`: ../../references.html#object-types
