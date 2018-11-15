
References
===========================================================

MWSE functions sometimes need magic numbers to help denote specific types. This page helps to explain what these values mean, and what they are.

Armor Types
-----------------------------------------------------------

=== =============================================
ID  Armor Type
=== =============================================
0   Helmet
1   Cuirass
2   Left Pauldron
3   Right Pauldron
4   Greaves
5   Boots
6   Left Gauntlet
7   Right Gauntlet
8   Shield
9   Left Bracer
10  Right Bracer
=== =============================================

.. note:: `xEquipmentList <functions/iteration/xEquipmentList.html>`_'s returns this value as the subtype for armor objects. Note that the values are **increased by one** by that function.

Attributes
-----------------------------------------------------------

== ============
ID Attribute
== ============
0  Strength
1  Intelligence
2  Willpower
3  Agility
4  Speed
5  Endurance
6  Personality
7  Luck
== ============

Clothing Types
-----------------------------------------------------------

=== =============================================
ID  Type
=== =============================================
0   Pants
1   Shoes
2   Shirt
3   Belt
4   Robe
5   Right Glove
6   Left Glove
7   Skirt
8   Ring
9   Amulet
=== =============================================

.. note:: `xEquipmentList <functions/iteration/xEquipmentList.html>`_'s returns this value as the subtype for clothing objects. Note that the values are **increased by one** by that function.

Control Types
-----------------------------------------------------------

=== =============
ID  Type
=== =============
0   Forward
1   Back
2   Slide Left
3   Slide Right
4   Use
5   Activate
6   Ready Item
7   Ready Magic
8   Crouch/Sneak
9   Run
10  Always Run
11  Auto Run
12  Jump
13  Next Weapon
14  Prev Weapon
15  Next Spell
16  Prev Spell
17  Toggle POV
18  Menu Mode
19  Journal
20  Rest
21  Quick Menu
22  Quick 1
23  Quick 2
24  Quick 3
25  Quick 4
26  Quick 5
27  Quick 6
28  Quick 7
29  Quick 8
30  Quick 9
31  Quick 10
32  Quick Save
33  Quick Load
=== =============

Magic Effects
-----------------------------------------------------------

=== =============================================
ID  Effect
=== =============================================
0   Water Breathing
1   Swift Swim
2   Water Walking
3   Shield
4   Fire Shield
5   Lightning Shield
6   Frost Shield
7   Burden
8   Feather
9   Jump
10  Levitate
11  Slow Fall
12  Lock
13  Open
14  Fire Damage
15  Shock Damage
16  Frost Damage
17  Drain Attribute
18  Drain Health
19  Drain Magicka
20  Drain Fatigue
21  Drain Skill
22  Damage Attribute
23  Damage Health
24  Damage Magicka
25  Damage Fatigue
26  Damage Skill
27  Poison
28  Weakness to Fire
29  Weakness to Frost
30  Weakness to Shock
31  Weakness to Magicka
32  Weakness to Common Disease
33  Weakness to Blight Disease
34  Weakness to Corprus Disease
35  Weakness to Poison
36  Weakness to Normal Weapons
37  Disintegrate Weapon
38  Disintegrate Armor
39  Invisibility
40  Chameleon
41  Light
42  Sanctuary
43  NightEye
44  Charm
45  Paralyze
46  Silence
47  Blind
48  Sound
49  Calm Humanoid
50  Calm Creature
51  Frenzy Humanoid
52  Frenzy Creature
53  Demoralize Humanoid
54  Demoralize Creature
55  Rally Humanoid
56  Rally Creature
57  Dispel
58  Soultrap
59  Telekinesis
60  Mark
61  Recall
62  Divine Intervention
63  Almsivi Intervention
64  Detect Animal
65  Detect Enchantment
66  Detect Key
67  Spell Absorption
68  Reflect
69  Cure Common Disease
70  Cure Blight Disease
71  Cure Corprus Disease
72  Cure Poison
73  Cure Paralyzation
74  Restore Attribute
75  Restore Health
76  Restore Magicka
77  Restore Fatigue
78  Restore Skill
79  Fortify Attribute
80  Fortify Health
81  Fortify Magicka
82  Fortify Fatigue
83  Fortify Skill
84  Fortify MaximumMagicka
85  Absorb Attribute
86  Absorb Health
87  Absorb Magicka
88  Absorb Fatigue
89  Absorb Skill
90  Resist Fire
91  Resist Frost
92  Resist Shock
93  Resist Magicka
94  Resist Common Disease
95  Resist Blight Disease
96  Resist Corprus Disease
97  Resist Poison
98  Resist Normal Weapons
99  Resist Paralysis
100 Remove Curse
101 Turn Undead
102 Summon Scamp
103 Summon Clannfear
104 Summon Daedroth
105 Summon Dremora
106 Summon AncestralGhost
107 Summon SkeletalMinion
108 Summon Bonewalker
109 Summon GreaterBonewalker
110 Summon Bonelord
111 Summon WingedTwilight
112 Summon Hunger
113 Summon GoldenSaint
114 Summon FlameAtronach
115 Summon FrostAtronach
116 Summon StormAtronach
117 Fortify Attack
118 Command Creature
119 Command Humanoid
120 Bound Dagger
121 Bound Longsword
122 Bound Mace
123 Bound BattleAxe
124 Bound Spear
125 Bound Longbow
126 EXTRASPELL
127 Bound Cuirass
128 Bound Helm
129 Bound Boots
130 Bound Shield
131 Bound Gloves
132 Corprus
133 Vampirism
134 Summon Centurion Sphere
135 Sun Damage
136 Stunted Magicka
137 Summon Fabricant
138 Call Wolf
139 Call Bear
140 Summon Bonewolf
141 sEffectSummonCreature04
142 sEffectSummonCreature05
=== =============================================

.. note:: The attribute- and skill-affecting effects are often paired with a specific attribute or skill in function calls. See the associated tables below for their values.

Magic Effects Flags
-----------------------------------------------------------

====== ================
Value  Meaning
====== ================
1      Targets skill.
2      Targets attribute.
4      No duration.
8      No magnitude.
16     Harmful.
32     Continuous VFX.
64     Cast self.
128    Cast touch.
256    Cast target.
512    Valid for spellmaking.
1024   Valid for enchanting.
2048   Negative lighting.
4096   Applied once.
8192   Stealth.
16384  Non-recastable.
32768  Illegal daedra.
65536  Unreflectable.
131072 Caster linked.
====== ================

.. note:: Negative lighting does not appear to have any effect.

Object Types
-----------------------------------------------------------

========== ===== =================
Value      Code  Meaning
========== ===== =================
1230259009 ACTI  Activator
1212369985 ACTI  Alchemy
1330466113 AMMO  Ammunition
1095782465 ACTI  Apparatus
1330467393 ARMO  Armor
1263488834 BOOK  Book
1414483011 CLOT  Clothing
1414418243 CONT  Container
1095062083 CREA  Creature
1380929348 DOOR  Door
1380404809 INGR  Ingredient
1129727308 LEVC  Levelled Creature
1230390604 LEVI  Levelled Item
1212631372 LIGH  Light
1262702412 LOCK  Lockpick
1129531725 MISC  Misc Item
1598246990 NPC\_ NPC
1112494672 PROB  Probe
1095779666 REPA  Repair Item
1414546259 SCPT  Script
1195658835 SNDG  Sound Generator
1279610963 SPEL  Spell
1413567571 STAT  Static
1346454871 WEAP  Weapon
========== ===== =================

.. note:: The **AMMO** object type is for arrows and bolts only, even though these usually show up in the weapons tab of the Construction Set. Thrown weapons do not have this type.

Skill Types
-----------------------------------------------------------

== =============
ID Type
== =============
0  Major
1  Minor
2  Miscellaneous
== =============

Skills
-----------------------------------------------------------

== ============
ID Skill
== ============
0  Block
1  Armorer
2  Medium Armor
3  Heavy Armor
4  Blunt Weapon
5  Long Blade
6  Axe
7  Spear
8  Athletics
9  Enchant
10 Destruction
11 Alteration
12 Illusion
13 Conjuration
14 Mysticism
15 Restoration
16 Alchemy
17 Unarmored
18 Security
19 Sneak
20 Acrobatics
21 Light Armor
22 Short Blade
23 Marksman
24 Mercantile
25 Speechcraft
26 Hand to Hand
== ============

Schools
-----------------------------------------------------------

== ================
ID School
== ================
0  Alteration
1  Conjuration
2  Destruction
3  Illusion
4  Mysticism
5  Restoration
== ================

Specialization Types
-----------------------------------------------------------

== ==============
ID Specialization
== ==============
0  Combat
1  Magic
2  Stealth
== ==============

Weapon Types
-----------------------------------------------------------

=== =============================================
ID  Weapon Type
=== =============================================
0   Short Blade One Hand
1   Long Blade One Hand
2   Long Blade Two Close
3   Blunt One Hand
4   Blunt Two Close
5   Blunt Two Wide
6   Spear Two Wide
7   Axe One Hand
8   Axe Two Hand
9   Marksman Bow
10  Marksman Crossbow
11  Marksman Thrown
12  Arrow
13  Bolt
=== =============================================

.. note:: `xEquipmentList <functions/iteration/xEquipmentList.html>`_'s returns this value as the subtype for weapon objects. Note that the values are **increased by one** by that function.
