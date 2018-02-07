
xSetSpellInfo
========================================================

**Parameters:**

- ``string`` **spellID**: The spell ID to modify.
- ``string`` **spellName**: New display name. Names longer than 31 characters will be truncated.
- ``long`` **type**: New spell type. (0=SPELL, 1=ABILITY, 2=BLIGHT, 3=DISEASE, 4=CURSE, 5=POWER)
- ``long`` **cost**: New magicka cost.
- ``long`` **flags**: New flags. (1=AUTOCALC, 2=PCSTART, 4=ALWAYSSUCCEEDS)
- ``long`` **origin**: New origin. (1=module, 2=spellmaker, 0 to leave unmodified)

**Returned:**

- ``short`` **result**: ``1`` if the function was successfull, other wise ``0``.