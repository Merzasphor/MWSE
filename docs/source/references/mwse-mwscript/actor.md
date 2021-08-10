# Actor Functions

--8<-- "mwse-deprecated.md"


***

## `xActivate`

**Parameters:**

- `reference` **target**: What the reference will try to activate. 

**Returned:**

- *None*

This function allows the forced activation of one reference onto another. Unlike the vanilla `Activate` function, this allows variable input and will work even when `OnActivate` hasn't been triggered in the script.

.. note:: Unlike the vanilla activate function, the reference is the actor that will activate something, rather than the object to activate.

??? example "Force the PC to Activate"
	```
	begin test

	long targetRef
	long pcRef

	; Don't force pickup if we're not sneaking.
	if ( GetPCSneaking == 0 )
		return
	endif

	; Get a reference to what the player is looking at.
	setx targetRef to xGetPCTarget
	if ( targetRef == 0 )
		return
	endif

	; Get a reference to the player, and force them to activate what they are looking at.
	setx pcRef to xGetRef "player"
	pcRef->xActivate targetRef

	end
	```


***

## `xAddSpell`

**Parameters:**

- `string` **objectID**: The object ID of the spell to add.

**Returned:**

- *None*

This is a wrapper for the vanilla `AddSpell` function that can take variable input.


***

## `xAITravel`

**Parameters:**

- `float` **x**: The position to travel to on the X axis.
- `float` **y**: The position to travel to on the Y axis.
- `float` **z**: The position to travel to on the Z axis.

**Returned:**

- *None*

This is a wrapper for the vanilla AITravel function that can take variable input.


***

## `xDrop`

**Parameters:**

- `string` **objectID**: The object ID of the item to drop.
- `long` **count**: The number of items to drop.

**Returned:**

- *None*

This is a wrapper for the vanilla Drop function that can take variable input.

!!! note
	`xDrop` N+1 items will leave 1 phantom icon plus N real items in the dropping actors inventory.  `xGetItemCount` will not report the 1 phantom icon.  However, `xRemoveItem` will remove the phantom safely.  So "safe" procedure for `xDrop` seems to be to follow up with `xRemoveItem` of the same count.  Additionally for non-player actors in menumode, exit and re-entry to menumode is needed to refresh the icons and avoid phantom icon interaction that could result in permanent item doubling or CTD.  This also applies to the standard drop function.


***

## `xEquip`

**Parameters:**

- `string` **objectID**: The object ID of the item to equip.

**Returned:**

- *None*

This is a wrapper for the vanilla Equip function that can take variable input.


***

## `xGetAttribute`

**Parameters:**

- `long` **attributeID**: The [Attribute](../../attributes) ID to get the value of.

**Returned:**

- `float` **value**: Current value of the attribute.

Returns the current value of the referenced object's attribute.

!!! note
	This function only supports the player and NPCs.


***

## `xGetBaseAttribute`

**Parameters:**

- `long` **attributeID**: The [Attribute](../../attributes) ID to get the value of.

**Returned:**

- `float` **value**: Base value of the attribute.

Returns the base current value of the referenced object's attribute.

!!! note
	This function only supports the player and NPCs.


***

## `xGetBaseGold`

**Parameters:**

- *None*

**Returned:**

- `long` **gold**: The base amount of bartering gold of the reference.

Returns the base amount of barter gold assigned to the NPC (or creature). This is the value that resets automatically each day.


***

## `xGetBaseSkill`

**Parameters:**

- `long` **skillID**: The [Skill ID](../../skills) to get the value of.

**Returned:**

- `float` **value**: Base value of the skill.

Returns the base value of the referenced object's skill.

!!! note
	This function only supports the player and NPCs.


***

## `xGetClass`

**Parameters:**

- `long` **attributesMask**: A bit mask to apply to the **attributes** value. 
- `long` **majorMask**: A bit mask to apply to the **majorSkills** value. 
- `long` **minorMask**: A bit mask to apply to the **minorSkills** value.

**Returned:**

- `string` **classID**: The unique string identifier of the class.
- `string` **name**: The name of the class.
- `long` **playable**: 1 if the class can be chosen by the PC, 0 otherwise.
- `long` **specialization**: `0` = Combat, `1` = Magic, `2` = Stealth
- `long` **attributes**: A bitmap of the two primary attributes. The result is obtained by adding the values found in the attributes table below.
- `long` **majorSkills**: A bitmap of the 5 major skills. The result is obtained by adding the values found in the skills table below. 
- `long` **minorSkills**: A bitmap of the 5 minor skills. The result is obtained by adding the values found in the skills table below. 

Returns info about the class of the target NPC/PC, or 0 if the target is not an NPC or the PC.

For a custom class created at PC creation, the **classID** is "NEWCLASSID_CHARGEN" and **playable** is `0`.

### Attribute and Skill Bitmaps

Value | Attribute
----- | ------------
1     | Strength
2     | Intelligence
4     | Willpower
8     | Agility
16    | Speed
32    | Endurance
64    | Personality
128   | Luck

Value    | Skill
-------- | ------------
1        | Block
2        | Armorer
4        | Medium Armor
8        | Heavy Armor
16       | Blunt Weapon
32       | Long Blade
64       | Axe
128      | Spear
256      | Athletics
512      | Enchant
1024     | Destruction
2048     | Alteration
4096     | Illusion
8192     | Conjuration
16384    | Mysticism
32768    | Restoration
65536    | Alchemy
131072   | Unarmored
262144   | Security
524288   | Sneak
1048576  | Acrobatics
2097152  | Light Armor
4194304  | Short Blade
8388608  | Marksman
16777216 | Mercantile
33554432 | Speechcraft
67108864 | Hand-to-Hand


***

## `xGetCombat`

**Parameters:**

- *None*

**Returned:**

- `reference` **reference**: Reference to the current combat target.

Returns a reference to the reference NPC/creature's combat target, or `0` if the reference is not in combat.


***

## `xGetGold`

**Parameters:**

- *None*

**Returned:**

- `long` **gold**: The reference's current barter gold.

`xGetGold` returns the current amount of barter gold possessed by the NPC (or creature). The base gold amount is used if you haven't bartered with the NPC/creature recently.


***

## `xGetMagic`

**Parameters:**

- *None*

**Returned:**

- `long` **objectType**: The [Object Type](../../object-types) of the equipped magical source.
- `string` **objectID**: The object ID of the spell or enchantment selected.

Returns the currently equipped spell or enchanted item. This is specifically the object that appears in the equipped magic slot and includes on-use magical items as well as spells.

!!! note
	The returned **objectType** and **objectID** will always be associated with a *Spell* or *Enchantment* object, not the *Weapon*, *Armor*, *Clothing*, or *Book* that the magic is placed on.


***

## `xGetMaxFatigue`

**Parameters:**

- **None**

**Returned:**

- `float` **maxFatigue**: The reference's maximum fatigue.

!!! noteReturns maximum fatigue. 
	This function only supports the player and NPCs.


***

## `xGetMaxHealth`

**Parameters:**

- **None**

**Returned:**

- `float` **maxHealth**: The reference's maximum health.

!!! noteReturns maximum health. 
	This function only supports the player and NPCs.


***

## `xGetMaxMagicka`

**Parameters:**

- **None**

**Returned:**

- `float` **maxMagicka**: The reference's maximum magicka.

!!! noteReturns maximum magicka. 
	This function only supports the player and NPCs.


***

## `xGetRace`

**Parameters:**

- `short` **returnType**: The return pattern desired. See below for details.

**Returned (returnType is 0):**

- `string` **raceID**: The object ID of the target's race.

**Returned (returnType is 1):**

- `array` **arrayID**: An array ID containing the values of the race.

This function fetches the objectID or complete details about the target's race.

!!! warning
	The arrays returned by this function when **returnType** is `1` are volatile. They should not be used for custom storage. Whenever xGetRace is called, the arrays are cleared and refilled with up-to-date information.

If **returnType** is `0`, the response is the race's object ID. Otherwise, the returned array contains the following values:

Index | Type      | Contents
----- | --------- | --------------------------
0     | `string`  | Object ID.
1     | `string`  | Name.
2     | `array`   | Skill bonuses.
3     | `array`   | Starting attributes.
4     | `float`   | Male height.
5     | `float`   | Female height.
6     | `float`   | Male weight.
7     | `float`   | Female weight.
8     | `long`    | Playable flag.
9     | `long`    | Beast flag.

The skill bonuses array begins with index 0 holding the number of skill bonuses (a value between 0 and 7). Pairs of values are then returned. The odd indexes hold the [Skill](../../skills) while the even indexes hold the bonus to the given skill.

The starting attributes array contains the following values:

Index | Type   | Contents
----- | ------ | --------------------------
0     | `long` | Male strength.
1     | `long` | Female strength.
2     | `long` | Male intelligence.
3     | `long` | Female intelligence.
4     | `long` | Male willpower.
5     | `long` | Female willpower.
6     | `long` | Male agility.
7     | `long` | Female agility.
8     | `long` | Male speed.
9     | `long` | Female speed.
10    | `long` | Male endurance.
11    | `long` | Female endurance.
12    | `long` | Male personality.
13    | `long` | Female personality.
14    | `long` | Male luck.
15    | `long` | Female luck.


***

## `xGetService`

**Parameters:**

- `long` **mask**: A filter to limit the **services** returned.

**Returned:**

- `long` **services**: The services offered by the reference, limited by **mask**.

This function returns a bitfield of services offered by a given reference.

The service values are shown in the following table. If an NPC offers more than one service the sum of the service numbers will be returned. The **mask** parameter can be used as a filter to limit the return value to only consider the services indicated.

Value  | Service
------ | ---------------------------------
1      | Barters for weapons.
2      | Barters for armor.
4      | Barters for clothing.
8      | Barters for books.
16     | Barters for ingredients.
32     | Barters for lockpicks.
64     | Barters for probes.
128    | Barters for lights.
256    | Barters for alchemical apparatus.
512    | Barters for repair tools.
1024   | Barters for miscellaneous items.
2048   | Offers spells.
4096   | Barters for enchanted items.
8192   | Barters for potions.
16384  | Provides training.
32768  | Provides spellmaking service.
65536  | Provides enchanting service.
131072 | Repairs armor and weapons.

!!! note
	Previous versions of MWSE made use of `xIsTrader`, `xIsTrainer`, and `xIsProvider`. This function supersedes those. Old scripts that use them will continue to work, but new scripts should make use of `xGetService`.


***

## `xGetSkill`

**Parameters:**

- `long` **skillID**: The [Skill](../../skills) ID to get the value of.

**Returned:**

- `float` **value**: Current value of the skill.

Returns the current value of the referenced object's skill.

!!! note
	This function only supports the player and NPCs.


***

## `xGetSpell`

**Parameters:**

- `string` **spellID**: The spell ID to search for.

**Returned:**

- `long` **result**: `1` if the spell was found, otherwise `0`.

Returns `1` if spellId is present, `0` otherwise. This is not a wrapper for `GetSpell`; it's a reimplementation. It only works for NPCs and the player.


***

## `xGetSpellEffects`

**Parameters:**

- `string` **spellID**: The spell ID to check for.

**Returned:**

- `long` **result**: `1` if the object is equipped, otherwise `0`.

Returns `1` if the calling object is under the effect of the given spell, or `0` otherwise.


***

## `xHasItemEquipped`

**Parameters:**

- `string` **objectID**: The object ID to check if equipped.

**Returned:**

- `long` **result**: `1` if the object is equipped, otherwise `0`.

Returns `1` if the NPC or creature has the object equipped, `0` otherwise.


***

## `xIsFemale`

**Parameters:**

- **None**

**Returned:**

- `long` **result**:  `1` if the reference is female, otherwise `0`.

Returns `1` if the NPC is female and 0 otherwise.


***

## `xModAttribute`

**Parameters:**

- `long` **attributeID**: The [Attribute](../../attributes) ID to modify.
- `float` **value**: The value to modify the attribute by.

**Returned:**

- `short` **result**: Result of the function.

Modifies the current and base values of the specified attribute. This suffers from the same display issue as xSetLevel. It ignores the 100 max attribute limit.

!!! note
	This function only supports the player and NPCs.


***

## `xModService`

**Parameters:**

- `long` **services**: The combined value of services the reference should offer (positive) or refuse (negative).

**Returned:**

- *None*

Uses the **services** parameter to modify the services offered by an NPC. A positive value adds that service (or set of services) to those already offered. A negative value will remove a service or service. The changes are not permanent.

Value  | Service
------ | ---------------------------------
1      | Barters for weapons.
2      | Barters for armor.
4      | Barters for clothing.
8      | Barters for books.
16     | Barters for ingredients.
32     | Barters for lockpicks.
64     | Barters for probes.
128    | Barters for lights.
256    | Barters for alchemical apparatus.
512    | Barters for repair tools.
1024   | Barters for miscellaneous items.
2048   | Offers spells.
4096   | Barters for enchanted items.
8192   | Barters for potions.
16384  | Provides training.
32768  | Provides spellmaking service.
65536  | Provides enchanting service.
131072 | Repairs armor and weapons.


***

## `xRemoveSpell`

**Parameters:**

- `string` **objectID**: The object ID of the spell to remove.

**Returned:**

- *None*

This is a wrapper for the vanilla `RemoveSpell` function that can take variable input.


***

## `xSetBaseGold`

**Parameters:**

- `long` **gold**:  New value to set the reference's base barter gold to.

**Returned:**

- *None*

Changes the base amount of barter gold assigned to the NPC (or creature). Unfortunately this change won't be saved with the save game so you will need to reset it after each game reload or after the "72-hour bug" affects the merchant.


***

## `xSetGold`

**Parameters:**

- `long` **gold**:  New value to set the reference's current barter gold to.

**Returned:**

- *None*

`xSetGold` changes the current amount of barter gold possessed by the NPC (or creature). This value is stored in save game files so it will survive a game reload. Setting this will have no effect if you haven't recently bartered with the NPC/creature. But setting both this and the base gold amount at the same time will likely do what you want.


***

## `xSetLevel`

**Parameters:**

- `long` **level**:  New value to set the reference's level to.

**Returned:**

- *None*

Sets the level of the given reference. This function is a wrapper for `SetLevel`, and suffers from the same display issue: when using this function on the player, the character screen does not update with the new level.


***

## `xSetService`

**Parameters:**

- `long` **services**: The combined value of services the reference should offer.

**Returned:**

- *None*

`xSetService` uses the value parameter to change the NPC to offer the set of services represented by the number. The service number values are used and any old services are ignored.

For example using a value of `8` will make the NPC a bookseller. A value of `131587` (`1+2+512+131072`) is typical for smiths. The values changed by this function are not permanent and may be reset after 72-hours or a game reload.

Value  | Service
------ | ---------------------------------
1      | Barters for weapons.
2      | Barters for armor.
4      | Barters for clothing.
8      | Barters for books.
16     | Barters for ingredients.
32     | Barters for lockpicks.
64     | Barters for probes.
128    | Barters for lights.
256    | Barters for alchemical apparatus.
512    | Barters for repair tools.
1024   | Barters for miscellaneous items.
2048   | Offers spells.
4096   | Barters for enchanted items.
8192   | Barters for potions.
16384  | Provides training.
32768  | Provides spellmaking service.
65536  | Provides enchanting service.
131072 | Repairs armor and weapons.


***

## `xStartCombat`

**Parameters:**

- `long` **reference**: Target reference for the caller to initiate combat with.

**Returned:**

- **None**

`xStartCombat` is a wrapper for the original StartCombat to take variables.