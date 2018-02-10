
xGetClass
========================================================

**Parameters:**

- ``long`` **attributesMask**: A bit mask to apply to the **attributes** value. 
- ``long`` **majorMask**: A bit mask to apply to the **majorSkills** value. 
- ``long`` **minorMask**: A bit mask to apply to the **minorSkills** value.

**Returned:**

- ``string`` **classID**: The unique string identifier of the class.
- ``string`` **name**: The name of the class.
- ``long`` **playable**: 1 if the class can be chosen by the PC, 0 otherwise.
- ``long`` **specialization**: 0 = Combat, 1 = Magic, 2 = Stealth
- ``long`` **attributes**: A bitmap of the two primary attributes. The result is obtained by adding the values found in the attributes table below.
- ``long`` **majorSkills**: A bitmap of the 5 major skills. The result is obtained by adding the values found in the skills table below. 
- ``long`` **minorSkills**: A bitmap of the 5 minor skills. The result is obtained by adding the values found in the skills table below. 

Returns info about the class of the target NPC/PC, or 0 if the target is not an NPC or the PC.

.. note:: For a custom class created at PC creation, the **classID** is "NEWCLASSID_CHARGEN" and **playable** is 0

Attribute and Skill Bitmaps
--------------------------------------------------------

===== ============
Value Attribute
===== ============
1     Strength
2     Intelligence
4     Willpower
8     Agility
16    Speed
32    Endurance
64    Personality
128   Luck
===== ============

======== ============
Value    Skill
======== ============
1        Block
2        Armorer
4        Medium Armor
8        Heavy Armor
16       Blunt Weapon
32       Long Blade
64       Axe
128      Spear
256      Athletics
512      Enchant
1024     Destruction
2048     Alteration
4096     Illusion
8192     Conjuration
16384    Mysticism
32768    Restoration
65536    Alchemy
131072   Unarmored
262144   Security
524288   Sneak
1048576  Acrobatics
2097152  Light Armor
4194304  Short Blade
8388608  Marksman
16777216 Mercantile
33554432 Speechcraft
67108864 Hand-to-Hand
======== ============
