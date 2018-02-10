
xGetSpellInfo
========================================================

**Parameters:**

- ``string`` **objectID**: The object ID of the spell to get information from.

**Returned:**

- ``string`` **name**: The spell's name.
- ``short`` **type**: 0 = Spell, 1 = Ability, 2 = Blight, 3 = Disease, 4 = Curse, 5 = Power.
- ``short`` **cost**: The cost to cast the spell.
- ``short`` **numEffects**: The number of effects the spell has.
- ``long`` **flags**: Bit array of spell flags. 1 = Auto-Calc, 2 = PC Starting Spell, 4 = Always Succeeds.

This function gets information about a spell, given its **objectID**.

.. tip:: The **numEffects** value is useful when looping over spell effects using `xGetEffectInfo`_.

.. _`xGetEffectInfo`: xGetEffectInfo.html
