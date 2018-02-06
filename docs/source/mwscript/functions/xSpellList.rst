
xSpellList
========================================================

**Parameters:**

- ``long`` **node**: For the first call, this should be 0 to get the first spell. In following iterations, this value will be what is returned as **nextNode** from the previous call.

**Returned:**

- ``long`` **totalSpells** : Total number of spells the caller knows.
- ``long`` **spellId** : The spell ID.
- ``long`` **name** : The spell name.
- ``long`` **type** : The spell type. (0=SPELL, 1=ABILITY, 2=BLIGHT, 3=DISEASE, 4=CURSE, 5=POWER)
- ``long`` **cost** : The spell cost.
- ``long`` **effects** : The spell's  number of effects. (1 to 8)
- ``long`` **flags** : The spell flags. (1=AUTOCALC, 2=PCSTART, 4=ALWAYSSUCCEEDS)
- ``long`` **nextNode** : The next node to supply to function to continue looping. When this value is 0, there are no more items.

This function allows a script to iterate through the spell list of an actor and retrieve information about the spells found. Currently this function does not work on creatures.
