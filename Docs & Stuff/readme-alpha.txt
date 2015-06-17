0.9.5-alpha.20150617
https://github.com/Merzasphor/MWSE

This is a WIP modification to the Morrowind Script Extender, based on version 0.9.4a.
There may be bugs. Proceed with caution!

Updates since MWSE-WIP-2015-02-16:

- xGetOwner now returns the id string of faction owners.
- Added experimental basic array support. (xCreateArray, xSetArrayValue, xGetArrayValue)
- Added functions to read and manipulate skill progress. These should mirror related MWE 
  functionality. (xGetProgressSkill, xSetProgressSkill, xModProgressSkill)
- Refactored level progress functions to make use of player data structures instead of fixed 
  offsets. (xGetProgressLevel, xSetProgressLevel)
- Fixed a bug that made setting level progress to zero fail. (xSetProgressLevel)
- Added a function to modify level progress by a fixed value. (xModProgressLevel)
- Added a function to get base skill values that uses an argument to determine the skill to read. 
  (xGetBaseSkill)

See "New Updates" for details.
  
This archive contains the following items:
readme-alpha.txt - this file :-)
MWSE Launcher.exe - the original unmodified launcher from the 0.9.4a release.
MWSE.dll - updated DLL
customfunctions.dat - for MWEdit. Adds opcodes for the new functions so that MWEdit can compile them.
MWSE_Test.esp - a plugin used for testing the new functions.
ArrayDemo.esp - a plugin demonstrating arrays and other new functions.

Trying it out:

!!!Make backups of any already existing files!!!

Copy MWSE Launcher.exe and MWSE.dll to your Morrowind directory.
If you're using MGE XE, run MGEXEgui.exe and check "Disable internal MWSE" on the "In-Game" tab.
Run MWSE Launcher.exe and click "Launch Morrowind"

The included plugin runs scripts that do the following:
Displays a message whenever the base value of one of the player's skills changes or whenever the 
player's progress to the next level changes.
Displays a message showing information about the player's current target.
Writes all loaded NPCs, items, statics to text files whenever the player's weapon is drawn.

To compile scripts with the new functions, copy customfunctions.dat to your MWEdit directory. No other
changes are needed to make MWEdit recognize and compile the new functions.

Credits:
This software is based on the 0.9.4a release of MWSE.
Original MWSE developers:
03-08-2005 CDC
26-02-2007 SF MWSE Dev Team
Cody Erekson
Tim Peters
Grant McDorman
Anthony Garcia

License:
The Morrowind Script Extender is free software, licensed according to
the GNU Public License, and comes with ABSOLUTELY NO WARRANTY. See the
file gpl.txt for details if you are interested in distributing or
modifying the program.

-----New Updates-----

Functions:

xCreateArray
arrayId (long): xCreateArray
Creates a new arbitrary length array and returns an id that refers to the array. If arrayId is 0,
creating the array failed. arrayId is guaranteed to only require 24 bits of precision, making it 
safe to store it in a global. Arrays can store floats or longs interchangeably. Arrays are not 
persistent, and will not survive a save/exit/load cycle. 

xGetArrayValue
value (float|long): xGetArrayValue arrayId (long) index (long)
Returns value at index in the array at arrayId. Arrays have 0 based indices. If index is out of
bounds, this function will return 0 and print a message in MWSELog.txt.

xSetArrayValue
result (short): xSetArrayValue arrayId (long) index (long) value (float|long)
Sets the index in the array at arrayId to value. If the index is out of bounds, the array grows to 
accomodate it. Returns non-zero on success and zero on failure. On failure, an appropriate message 
is added to MWSELog.txt. 

xGetProgressSkill
value (float): xGetProgressSkill skillId (long)
Returns the skill progress for the given skillId.

xSetProgressSkill
result (short): xSetProgressSkill skillId (long) value (float)
Sets the given progress for the given skillId to value. Returns non-zero on success, zero on 
failure. This function will fail if skillId is out of range or value < 0.

xModProgressSkill
result (short): xModProgressSkill skillId (long) value (float)
Adds value to the progress for the given skillId. If the new progress value is less than zero, it's
set to zero instead. Returns non-zero on success, zero on failure. This function will fail if 
skillId is out of range.

xModProgressLevel
result (short): xModProgressLevel value (long)
Adds value to the progress to the next player level. If the new progress value is less than zero, 
it's set to zero instead. Returns non-zero on success, zero on failure.

xGetBaseSkill
value (float): xGetBaseSkill skillId (long)
Returns the base value of the skill associated with skillId. This function is intended to 
replace the original xGetBase[skill] functions. They should be considered deprecated, and may be
removed in the future.

Skill IDs:

0 Block
1 Armorer
2 Medium Armor
3 Heavy Armor
4 Blunt Weapon
5 Long Blade
6 Axe
7 Spear
8 Athletics
9 Enchant
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
26 HandToHand

Notes on skill progress:
The game stores and displays progress differently. The stored value is a float that's incremented
by the value associated with a given skill's action (these can be found in the CS). The displayed
value represents progress toward a target that is calculated based on several variables.

The algorithm that calculates progress requirement:
(from https://wiki.openmw.org/index.php?title=Research:Stats_and_Levelling) 

progress[skill] += skillGain
progressRequirement = 1 + playerSkills[skill]
 
if skill in player.majorSkills:
    progressRequirement *= fMajorSkillBonus
elif skill in player.minorSkills:
    progressRequirement *= fMinorSkillBonus
elif skill in player.miscSkills:
    progressRequirement *= fMiscSkillBonus
 
if skill in player.class.specialization.skills:
    progressRequirement *= fSpecialSkillBonus
 
if int(progress[skill]) >= int(progressRequirement):
    progress[skill] = 0
    playerSkills[skill] increased by 1, triggering further functions

The displayed value is then given by:
(int)(100 * progress[skill]/progressRequirement)
	
MWSE is able to reliably access nearly all of the above information. The missing piece is the set
of skill/specialization associations. I've found what appears to be an array of SKIL records that
contain this information, but have not yet been able to find a reliable way to access it. If I can
resolve this, I'll add functions to calculate the displayed value and/or progressRequirement.
	
Examples:
See ArrayDemo.esp for scripts that demonstrate these functions.

*******************************************************************************

Previous WIP updates:

Compatible with MGE XE 0.10.0 beta 9 or later.

The following functions have been updated/fixed:

xFirstNPC, xFirstItem, xFirstStatic, and xNextRef now find all references in exterior cells 
and skip references that have been deleted by plugins.
xGetValue can return the value of ammo and repair items.
xGetWeight can return the weight of ammo and repair items.
xGetContentList can return the weight and value of ammo and repair items.
xGetCondition returns the current (not max) condition of armor, weapons, lockpicks, probes, and repair items.

The following functions have been added:

xGetGS
value (float|long): xGetGS id (long)
Returns the value of the GMST referenced by id. See gmst_index.txt for a list of ids and associated GMSTs.
This is a port of the MGE XE function of the same name and should behave identically.

value: the value of the GMST
id: the id of the GMST

*******************************************************************************

xSetGSLong and xSetGSFloat
xSetGSLong|xSetGSFloat: id (long) value (long|float)
Sets the value of the GMST referenced by id. See gmst_index.txt for a list of ids and associated GMSTs.
This is a port of the MGE XE function of the same name and should behave identically.

id: the id of the GMST
value: the value to set the GMST to

*******************************************************************************

xGetClass
classId (string ref) name (string ref) playable (long) specialization (long) attributes (long) majorSkills (long) minorSkills (long): ref->xGetClass attributesMask (long) majorMask (long) minorMask (long)
Returns info about the class of the target NPC/PC, 0 if the target is not an NPC or the PC.

classId: the unique string identifier of the class. "NEWCLASSID_CHARGEN" is the
id of a custom class created by the PC during character generation.
name: the name of the class.
playable: 1 if the class can be chosen by the PC, 0 otherwise. This is 0 if the
class is a custom class created by the PC during character generation.
specialization: 0 = Combat, 1 = Magic, 2 = Stealth
attributes: a bitmap of the two primary attributes. The result is obtained by
adding the values found in the attributes table.
majorSkills: a bitmap of the 5 major skills. The result is obtained by adding
the values found in the skills table.
minorSkills: a bitmap of the 5 minor skills. The result is obtained by adding
the values found in the skills table.

attributeMask: a bit mask to apply to the attributes value.
majorMask: a bit mask to apply to the majorSkills value.
minorMask: a bit mask to apply to the minorSkills value.

If a mask is 0, the corresponding value is unaltered.

See the script below for an example of how to use the masks.

Attribute       Value
Strength            1
Intelligence        2
Willpower           4
Agility             8
Speed              16
Endurance          32
Personality        64
Luck              128

Skill           Value
Block               1
Armorer             2
Medium Armor        4
Heavy Armor         8
Blunt Weapon       16
Long Blade         32
Axe                64
Spear             128
Athletics         256
Enchant           512
Destruction      1024
Alteration       2048
Illusion         4096
Conjuration      8192
Mysticism       16384
Restoration     32768
Alchemy         65536
Unarmored      131072
Security       262144
Sneak          524288
Acrobatics    1048576
Light Armor   2097152
Short Blade   4194304
Marksman      8388608
Mercantile   16777216
Speechcraft  33554432
Hand-to-Hand 67108864

Example:
; This script displays messages if the player's target has Hand-To-Hand and 
; Unarmored as major skills or Hand-To-Hand or Unarmored as minor skills.

long pcTarget
long classId
long name
long play
long spec
long attrib
long major
long minor
long mask
short continue

; Hand-to-hand + Unarmored
set mask to ( 67108864 + 131072 )

setx pcTarget to xGetPCTarget
setx classId name play spec attrib major minor to pcTarget->xGetClass 0 mask mask

; Hand-to-Hand AND Unarmored
; If the result from xGetClass is equal to the mask, then all components of the
; mask are present.
if ( major == mask )
	set continue to 1
else
	set continue to 0
endif

ifx (continue)
	xMessageFix "%s has hand-to-hand and unarmored as major skills." name
	MessageBox "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh"
endif

; Hand-to-Hand OR Unarmored
; If the result from xGetClass is not 0, then at least one of the components of
; the mask is present.
ifx (minor)
	xMessageFix "%s has hand-to-hand or unarmored as a minor skill." name
	MessageBox "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh"
endif

*******************************************************************************

xGetEnchant
enchantId (string ref) type (short) cost (short) charge (float) maxCharge (long) numEffects (short) autocalc (long): ref->xGetEnchant
Returns info about the enchantment on the target item, 0 if no enchantment present.

type: 0 = Cast Once, 1 = Cast When Strikes, 2 = Cast When Used, 3 = Constant
autocalc: 0 = off, 1 = on

Example:
long enchId
short type
short cost
float charge
long maxCharge
short numEffects
long autocalc
long target

setx target to xGetPCTarget
setx enchId type cost charge maxCharge numEffects autocalc to target->xGetEnchant

Notes:
Scrolls are not currently supported, but will be in a future update.

*******************************************************************************

xGetEnchantInfo
type (short) cost (short) maxCharge (long) numEffects (short) autocalc (long): xGetEnchantInfo enchantId (string | string ref)
Returns info about the given enchantId, 0 if enchantId is invalid.

type: 0 = Cast Once, 1 = Cast When Strikes, 2 = Cast When Used, 3 = Constant
autocalc: 0 = off, 1 = on

Example:
short type
short cost
long maxCharge
short numEffects
long autocalc

setx type cost charge maxCharge numEffects autocalc to xGetEnchantInfo "admonition_en"

*******************************************************************************

xGetEnchantEffectInfo
effectId (short) rangeType (long) area (long) duration (long) minMagnitude (long) maxMagnitude (long): xGetEnchantEffectInfo enchantId (string | string ref) effectIndex (short)
Returns info about one of the effects of the given enchantId, -1 if the enchantId is 
invalid or the index is out of range [1, numEffects]. To determine the number of valid
effects, call xGetEnchantInfo or xGetEnchant first.

rangeType: 0 = SELF, 1 = TOUCH, 2 = TARGET

Example:
short effect
long range
long area
long duration
long min
long max

setx effect range area duration min max to xGetEnchantEffectInfo "admonition_en" 2

*******************************************************************************

xGetSpell
result (short): ref->xGetSpell spellId (string | string ref)
Returns 1 if spellId is present, 0 otherwise.

Example:
long spellId
long target
short result
long target

setx target to xGetPCTarget
setx spellId to xStringBuild "summon golden saint"
setx result to target->xGetSpell spellId

Notes:
This is not a wrapper for GetSpell; it's a reimplementation. It only works
for NPCs and the player. Creatures will be supported in the future.

*******************************************************************************

xSpellList
totalSpellCount (long) spellId (string ref) name (string ref) type (short) cost (short) numEffects (short) flags (long) next (long): ref->xSpellList curr (long)
Iterates through the target's spell list. Call with curr = 0 to retrieve the head
of the list.

totalSpellCount: total number of spells the target knows
next: reference to the next spell in the list. next = 0 when at the end of the list.

Example:
; Displays the player's spells one at a time.
float time
long pcRef	
long totalSpells
long spellId
long name
short type
short cost
short effects
long flags
long next

set time to ( time + GetSecondsPassed )

if ( time > 7 )
	set time to 0
else
	return
endif

setx pcRef to xGetRef "player"
setx totalSpells spellId name type cost effects flags next to pcRef->xSpellList next
xMessageFix "TS: %d ID: %s N: %s T: %d C: %d E: %d F: %d" totalSpells spellId name type cost effects flags
MessageBox "Yet such is oft the course of deeds that move the wheels of the world: small hands do them because they must, while the eyes of the great are elsewhere."

Notes:
This only works for NPCs and the player. Creatures will be supported in the future.

*******************************************************************************

xGetSpellInfo
name (string ref) type (short) cost (short) numEffects (short) flags (long): xGetSpellInfo spellId (string | string ref)
Returns info about the given spellId, 0 if spellId is invalid.

type: 0 = SPELL, 1 = ABILITY, 2 = BLIGHT, 3 = DISEASE, 4 = CURSE, 5 = POWER
flags: (combination of these values) 1 = AUTOCALC, 2 = PCSTART, 4 = ALWAYSSUCCEEDS

Example:
long name
short type
short cost
short effects
long flags

setx name type cost effects flags to xGetSpellInfo "trap_fire00"

*******************************************************************************

xGetSpellEffectInfo
effectId (short) skillId (short) attributeId (short) rangeType (long) area (long) duration (long) minMagnitude (long) maxMagnitude (long): xGetSpellEffectInfo spellId (string | string ref) effectIndex (short)
Returns info about one of the effects of the given spellId, -1 if the spellId is 
invalid or the index is out of range [1, numEffects]. To determine the number of valid
effects, call xGetSpellInfo or xSpellList first.

rangeType: 0 = SELF, 1 = TOUCH, 2 = TARGET

Example:
short effect
short skill
short attrib
long range
long area
long duration
long min
long max

setx effect skill attrib range area duration min max to xGetSpellEffectInfo "trap_fire00" 1

*******************************************************************************

xLongToFloats xFloatsToLong
val1 (float) val2 (float): xLongToFloats val (long)
val (long): xFloatsToLong val1 (float) val2 (float)
These functions store and retrieve a long value using a pair of floats. 

Example:
long lVal1
long lVal2
float fVal1
float fVal2

set lVal1 to 2147483647
setx fVal1 fVal2 to xLongToFloats lVal1
setx lVal2 to xFloatsToLong fVal1 fVal2

if ( lVal1 == lVal2 )
	MessageBox "Success!"
else
	MessageBox "Failure!"
endif

Notes:

These functions are intended to work around the issue that all globals are really floats.
They work by splitting the long 32 bit value into two 16 bit values and adding a flag to
indicate which value maps to the high 16 bits.

I had hoped to use a single float, but not all bits are propagated when a float is NaN.

Argument order doesn't matter.

MWEdit doesn't like to compile these functions with globals as arguments, so you'll
need to use temporary locals for now.

*******************************************************************************

xGetTrap
spellId (string ref) name (string ref) cost (short): ref->xGetTrap 
Returns info about the spell used for trap, 0 if no trap is present.

Example:
; Gets the trap of the player's target and stores it in spellId.
long target
long spellId
long name
short cost
setx target to xGetPCTarget
setx spellId name cost to target->xGetTrap

*******************************************************************************

xSetTrap
success (short): ref->xSetTrap spellId (string | string ref)
Sets a trap. Returns 1 if successful, 0 if not (no trap/lock installed or invalid spellId).
Pass 0 to remove an installed trap.

Example:
; Sets a trap on the player's target.
long target
setx target to xGetPCTarget
target->xSetTrap "trap_fire00"

Notes:
There must be a lock installed to set a trap. To set a trap on an object
with no lock installed, call Lock 0 and Unlock on the object first.

Traps that are set this way do not persist through saving and loading. If a trap is
removed its removal persists only if the object is activated or its lock is manipulated
before saving. 

This will likely be fixed in the future; there's probably another flag somewhere 
that needs to be set.

To summarize the above:
If you want to set a trap on a door/container, first check for an existing lock
(xGetLockLevel). If no lock is already installed, use Lock 0, Unlock to create
the lock/trap record. Set the trap. To make sure the trap is persistent, 
manipulate the lock, but then put it back to its original state. In other words,
if the lock is currently unlocked, lock it (use xGetLockLevel to determine the
correct lock level) then unlock it. Do the reverse if it's currently unlocked.

*******************************************************************************

xExplodeSpell
Wrapper for ExplodeSpell.
Parameters: long | string
Return type: none

Example:
; Explodes a spell using a string variable on the player's target.
long target
setx target to xGetPCTarget
long spellId
setx spellId to xStringBuild, "trap_frost00"
target->xExplodeSpell, spellId

*******************************************************************************

xSetProgressLevel
Sets the progress to next level. Returns 1 if successful, 0 otherwise.
Parameters: long
Return type: short

Notes:
This function will not trigger level up or any other messages.

There are some limits to what you can do with this, because of how the game handles this
and other values.

Progress is stored in memory as a signed long (32 bits, max value = 2147483647).
Progress is stored in the save file as an unsigned char (8 bits, max value = 255)
Progress is cast to a float before being displayed on the character screen.
This appears to be true for iLevelupTotal as well. 

Example:
; Sets the player's level progress to 5
long pcRef
setx pcRef to xGetRef, "player"
pcRef->xSetProgress, 5

*******************************************************************************

xGetLockLevel
Returns the lock level of a door or container.
Return type: short

Notes: 
This function returns -1 for doors/containers that have never been locked and for items that aren't
doors or containers.
This returns the lock level regardless of whether the item is locked or unlocked. Use GetLocked
to determine the state of the lock.
Lock level is stored as a signed short (16 bits, max value = 32,767). Values less than 0 do not 
survive saving, exiting, and reloading. They are converted to their absolute value and the 
door/container is flagged as unlocked.

Example:
; Gets the lock level of the player's target and stores it in lockLevel.
long target
long lockLevel
setx target to xGetPCTarget
setx lockLevel to target->xGetLockLevel

*******************************************************************************

xGetBaseAcrobatics xGetBaseAlchemy xGetBaseAlteration xGetBaseArmorer xGetBaseAthletics
xGetBaseAxe xGetBaseBlock xGetBaseBluntWeapon xGetBaseConjuration xGetBaseDestruction
xGetBaseEnchant xGetBaseHandToHand xGetBaseHeavyArmor xGetBaseIllusion xGetBaseLightArmor
xGetBaseLongBlade xGetBaseMarksman xGetBaseMediumArmor xGetBaseMercantile xGetBaseMysticism
xGetBaseRestoration xGetBaseSecurity xGetBaseShortBlade xGetBaseSneak xGetBaseSpear
xGetBaseSpeechcraft xGetBaseUnarmored

Returns the base value of the associated skill.
Return type: float

Example:
; Gets the player's base Acrobatics value and stores it in baseAcrobatics.
long pcRef
float baseAcrobatics
setx pcRef to xGetRef, "player"
setx baseAcrobatics to pcRef->xGetBaseAcrobatics

*******************************************************************************

xGetProgressLevel
Returns the current progress to the next level.
Return type: long

Example:
; Gets the player's progress to next level and stores it in currProgress.
long pcRef
long currProgress
setx pcRef to xGetRef, "player"
setx currProgress to pcRef->xGetProgressLevel

*******************************************************************************
