# Reference Functions

--8<-- "mwse-deprecated.md"


## `xAddItem`

**Parameters:**

- `string` **objectID**: The object ID of the item to add.
- `long` **count**: The number of items to add.

**Returned:**

- *None*

This is a wrapper for the vanilla AddItem function that can take variable input.


***

## `xDistance`

**Parameters:**

- `reference` **target**: The reference of the target to get the distance from.

**Returned:**

- `float` **distance**: The distance between the calling reference and the **target** reference.

Calculates the distance between the calling reference and **target**.

.. note:: Unlike the vanilla `GetDistance` function, this function will work on non-actors.

??? example "Distance from PC Target"
	This example calculates the distance between the PC and what they are looking at.

	```
	begin DistanceToTarget

	long pcRef
	long targetRef
	float distance

	setx pcRef to xGetRef "player"
	setx targetRef to xGetPCTarget

	setx distance to pcRef->xDistance targetRef

	end
	```


***

## `xExplodeSpell`

**Parameters:**

- `string` **objectID**: The object ID of the spell to explode.

**Returned:**

- *None*

This is a wrapper for the vanilla ExplodeSpell function that can take variable input.


***

## `xGetBaseID`

**Parameters:**

- *None*

**Returned:**

- `string` **id**: The reference's base object ID.

`xGetBaseID` returns reference's base object ID. In contrast to `xRefID`, this function will not include the hexadecimal suffix that identifies unique instances of containers, creatures, or NPCs. For example, where `xRefID` would return `"Fargoth00000000"`, `xGetBaseID` would instead return just `"Fargoth"`.


***

## `xGetCharge`

**Parameters:**

- *None*

**Returned:**

- `float` **charge**: The current charge on a item.

Returns the current charge on a 'cast when used' or 'cast when strikes' enchanted item. Constant effect and non-enchanted items return `0`.


***

## `xGetCondition`

**Parameters:**

- *None*

**Returned:**

- `float` **condition**: The current condition on a item.

Returns the current condition for armor and weapons and remaining uses for lockpicks, probes, and repair tools.


***

## `xGetEnchant`

**Parameters:**

- *None*

**Returned:**

- `string` **enchantID**: The Object ID of the enchantment.
- `short` **type**: The type of the enchantment. `0` = Cast Once, `1` = Cast on Strike, `2` = Cast on Use, `3` = Constant
- `short` **cost**: The cost of the enchantment.
- `float` **currentCharge**: The current charge for the enchantment.
- `long` **maxCharge**: The maximum charge for the enchantment.
- `short` **numEffect**: The number of effects on the enchantment.
- `long` **autocalc**: 1 if the enchantment is auto-calculated.

Returns info about the enchantment on the target item, or 0 if no enchantment is present.


***

## `xGetEncumb`

**Parameters:**

- *None*

**Returned:**

- `float` **weight**: The weight, in pounds, of all the reference's inventory. This value is negative if leveled items are present.

Calculates the total, unmodified encumbrance of the target reference's inventory. This function does not take into account any *feather* or *burden* spell effects.

!!! note
	If the target has any leveled items in its inventory, the returned **weight** is negative.


***

## `xGetItemCount`

**Parameters:**

- `string` **objectId**: The item's object ID to get the count of.

**Returned:**

- `long` **itemCount**: The number of items that the reference has.

This is a wrapper function around `GetItemCount` that allows variable input.


??? example 
	```
	begin Example_xGetItemCount

	long ref

	long id
	long count

	setx ref to xGetRef "player"

	setx id to xStringBuild "Gold_001"

	setx count to ref->xGetItemCount id

	MessageBox "Total Gold: %g" count

	StopScript Example_xGetItemCount

	end
	```


***

## `xGetLockLevel`

**Parameters:**

- **None**

**Returned:**

- `short` **lockLevel**: The reference's lock level, or -1 if none was found.

Returns the lock level of a door or container. This function returns -1 for doors/containers that have never been locked and for items that aren't doors or containers.

This returns the lock level regardless of whether the item is locked or unlocked. Use GetLocked to determine the state of the lock.

Lock level is stored as a signed short (16 bits, max value = 32,767). Values less than 0 do not survive saving, exiting, and reloading. They are converted to their absolute value and the door/container is flagged as unlocked.


***

## `xGetMaxCharge`

**Parameters:**

- *None*

**Returned:**

- `float` **maxCharge**: The current charge on a item.

Returns the maximum charge on an enchanted item.


***

## `xGetMaxCondition`

**Parameters:**

- *None*

**Returned:**

- `float` **maxCondition**: The current maximum condition on a item.

Returns the maxium condition for armor and weapons and maximum uses for lockpicks, probes, and repair tools.


***

## `xGetModel`

**Parameters:**

- `string` **objectId**: The object ID to get the model of. If 0, the reference will be used.

**Returned:**

- `string` **modelPath**: The path to the model.

This function returns the model of an object. This can be done by passing a string for the object Id, or 0 can be passed to use the script's reference.

!!! note
	The path returned does not include the *Data Files\\models* prefix.

??? example "Get Model by Object ID"
	```
	begin Example_xGetModelById

	long model

	setx model to xGetModel "ingred_bonemeal_01"
	if ( model == 0 )
		return
	endif

	xMessageFix "Model: %s" model
	MessageBox "Model: ________________________________"

	end
	```

??? example "Get Model by Reference"
	```
	begin Example_xGetModelByRef

	long ref
	long model

	setx ref to xGetPCTarget
	if ( ref == 0 )
		return
	endif

	setx model to ref->xGetModel 0
	if ( model == 0 )
		return
	endif

	xMessageFix "Model: %s" model
	MessageBox "Model: ________________________________"

	end
	```


***

## `xGetName`

**Parameters:**

- *None*

**Returned:**

- `string` **name**: The reference's name, or `0` if no name was found.

`xGetName` returns a string containing the name (suitable for display, not the objectid) for the object or 0 if the object doesn't have a name. The NPC who falls from the sky near Seyda Neen has an object id of "agronian guy" but his name is "Tarhiel" when you look at his corpse.


***

## `xGetOwnerInfo`

**Parameters:**

- *None*

**Returned:**

- `string` **owner**: The object ID of the NPC or faction owner of the object.
- `long` or `string` **condition**: If owned by a faction, this is a `long` indicating the required rank. If this is an NPC this value is either 0, or a `string` for the global variable to check.
- `long` **type**: The Object Type of **owner**, either NPC or Faction.

Ownership of entities in the world in Morrowind is comprised of two parts: **owner** and **condition** (this can specify when the player being detected taking or using the entity is not considered a crime). These work in two modes:

1. The first is where **owner** is an NPC ID, and **condition** is a global variable - while the global var is set to a non-zero value, activating the entity is never considered a crime.
1. In the second mode, **owner** is a faction id, and **condition** is a rank within it. If the player has equal (or higher) rank in that faction, then he can be seen using or taking the entity without it being a crime. This is how supply chests and beds in guildhalls work (their rank requirement is the minimal rank).

This function allows getting full ownership information of an entity: both parts, whatever they may be (as well as what mode is used for the ownership). It is more in-depth than the `xGetOwner` function, which does not fully handle faction ownership or ownership with a global var requirement.

!!! tip
	If the returned **condition** is a global variable, it can be used with `xGetGlobal` and `xSetGlobal`.


??? example "Boobytrapped Mages Guild and Telvanni faction containers"
	```
	begin boobycontainers
	;if the player tries to open a container owned by either MG or GHT that he
	;doesn't have the required rank to legally take items from, then instead of
	;the container opening, the player will be zapped.

	short framecount
	short temp
	short player_rank
	long pctarget
	long type
	long own_id
	long own_cond

	if ( MenuMode )
		return
	endif

	set framecount to ( framecount + 1 )
	if ( framecount < 30 )
		return
	endif
	set framecount to 0

	setx pctarget to xGetPCTarget
	ifx ( pctarget )
		setx type to pctarget->xRefType
		if ( type != 1414418243 ) ;if it's not a container ref type
			return
		endif
		setx type own_id own_cond to pctarget->xGetOwnerInfo
		if ( type != 1413693766 ) ;if it's not a faction ownership type
			return
		endif

		setx temp to xStringCompare own_id "Mages Guild" ;if the owner of the container is MG, temp will be 0
		ifx ( temp ) ;not MG
			setx temp to xStringCompare own_id "Telvanni"
			ifx ( temp )
				;owner is not MG and not GHT, either
				return
			endif
			;owner is GHT
			set player_rank to GetPCRank "Telvanni" ;doesn't hurt here, but remember 0 and -1 are both possible return values of this function
		else
			;owner is MG
			set player_rank to GetPCRank "Mages Guild"
		endif

		set temp to 0
		if ( player_rank >= own_cond ) ;player is of the right rank in whichever faction to be able to claim the container's contents
			set temp to 1
		endif
		ifx ( temp )
			;originally, there was only a return here.
			;the following block is needed in case activation was already blocked by the OnActivate call (the 2nd instance of it, now) on a previous run, but the player since raised in rank enough; without this line, the player will no longer get the trap, but the container may not open (as it normally should), either
			xSetRef pctarget
			set temp to OnActivate
			ifx ( temp )
				pctarget->Activate
			endif
			return
		endif

		;if reached here, player doesn't meet rank requirement
		xSetRef pctarget
		if ( OnActivate ) ;merely CALLING this function will block any further normal activation attempts. it makes the object's activation temporarily only possible through the Activate function
			MessageBox "A trap is sprung!"
			set temp to - ( player->GetFatigue + 1 )
			player->ModCurrentFatigue temp ;makes player fall down ("knocked out") briefly - causes current fatigue to be -1
			player->PlaySound "destruction hit"
		endif
	endif

	end
	```

??? example "World entity destruction with ownership penalty"
	```
	begin entitydestruction

	;allows the player to destroy objects in the world by striking at them with
	;a weapon (or barehanded). but if the player wouldn't have been (legally) allowed to pick up that
	;object, he gets a bounty as if he stole it (with respect to the GMST that controls the bounty amount for theft).

	;the value of containers is assumed to be only the value of all the items within them.
	;the value of doors is assumed to be 100 septims, and of activators, 200 septims.

	;this script doesn't take into account whether player is detected (sneaking, invisible),
	;etc. well, he's doing a loud and incriminating action, anyway.
	;it doesn't do faction expulsion, either...

	short framecount
	short update_col
	long temp
	long pctarget
	long type
	long value
	long nextref
	long invvalue
	long invcount
	long ownerid
	long condition
	float glob
	;note: in this script, existing vars are often reused, so that a bunch of
	;vars are also used for other purposes than their name suggests.

	;for example, because it is the only float and there's no problem with
	;overwriting it, 'glob' is used to (temporarily) hold both the result of
	;a reading of a global var, and also of reading a float GMST.


	if ( MenuMode )
		return
	endif

	set framecount to ( framecount + 1 )
	if ( framecount < timing1 )
		return
	endif
	set framecount to 0

	if ( player->GetWeaponDrawn == 0 )
		return
	endif

	if ( player->GetWeaponType == 0 )
		return ;ignore lockpicks and probes; unfortuantely this also applies to Short Blades...
	endif

	setx temp to xKeyPressed 1 ;left mouse button
	setx pctarget to xGetPCTarget

	setx temp to xAnd temp pctarget;if player looking at something AND pressing LMB, temp will be 1

	if ( temp == 0 )
		return
	endif

	;you should also be able to just use 'if ( player->GetSoundPlaying "weapon swish" )' instead, to check
	;if the player is making a strike, at least on machines where GetSoundPlaying works fine.
	;you'd also be able to automatically support all swinging weapons, then.

	setx type to pctarget->xRefType
	set value to 0
	set nextref to 0
	if ( type == 1598246990 ) ;NPC
		return
	elseif ( type == 1095062083 ) ;creature
		return
	elseif ( type == 1414418243 ) ;container
		set nextref to 1 ;flag that we need to tally the container's total value
		set update_col to 1
	elseif ( type == 1380929348 ) ;door      (this script allows player to destroy load doors too, careful)
		set value to 100
		set update_col to 1
	elseif ( type == 1230259009 ) ;activator
		set value to 200
		set update_col to 1
	endif


	set invvalue to 0
	set invcount to 0
	setx type ownerid condition to pctarget->xGetOwnerInfo
	if ( type == 0 ) ;no owner
		set value to 1 ;in case 'value' wasn't determined yet - there's no need to calculate it below
	elseif ( type == 1598246990 ) ;NPC owner
		set invvalue to 1 ;(temp flag)
	elseif ( type == 1413693766 ) ;faction owner
		set invcount to 1 ;(temp flag)
	else
		MessageBox "ERROR?!" ;this should never happen
		return
	endif

	ifx ( invvalue ) ;NPC owner
		setx temp to xGetRef ownerid
		ifx ( temp )
			xSetRef temp
			set temp to GetHealth
		else
			set temp to 0 ;if can't find the owner, assume he's dead
		endif
		if ( temp <= 0 ) ;if he's dead, then it's all legal...
			set type to 0 ;no ownership
			set value to 1 ;no need to calculate 'value'
		else
			ifx ( condition )
				setx temp glob to xGetGlobal condition
				ifx ( temp ) ;got the global successfully
					ifx ( glob ) ;if it had a true value
						;then player is allowed to take/use the target
						set type to 0
						set value to 1
					endif
				else
					MessageBox "Got a problem..."
				endif
			endif
		endif
	endif

	ifx ( invcount ) ;faction owner
		;setx temp to xGetPCRank ownerid ;(this function doesn't exist yet)
		set temp to 0 ;temp filler since can't use above line. this makes the player count as of the lowest rank in the faction.

		if ( temp >= condition ) ;if player is of the required rank or above...
			;then it's legal
			set type to 0
			set value to 1
		endif
	endif


	ifx ( value )
	else
		;if value is still 0, we're looking at an item (or a container)

		ifx ( nextref ) ;container
			set nextref to 0
			setx temp invcount temp invvalue temp temp nextref to pctarget->xContentList nextref ;values we don't care about get stored in temp and overwritten
			whilex ( invcount ) ;might take a short... while, if container has tons of stacks in it
				set temp to ( invcount * invvalue )
				set value to ( value + temp )
				ifx ( nextref )
					setx temp invcount temp invvalue temp temp nextref to pctarget->xContentList nextref
				else
					set invcount to 0 ;break the loop
				endif
			endwhile
		else ;looking at an item
			setx value to pctarget->xGetValue
		endif

	endif

	pctarget->Disable ;'destroy' the target
	player->PlaySound "critical damage"
	if ( type ) ;if it was determined to be illegal...
		setx glob to xGetGS 1173 ;GMST fCrimeStealing (default: 1.0)
		set value to ( value * glob )
		ModPCCrimeLevel value
	endif

	if ( update_col )
		set update_col to 0
		;in the event that that the player just disable'd a door or a large
		;container or activator, its collision will normally remain until the
		;cell is re-loaded, and the player won't be able to go through th
		;space it used to occupy.
		;this part of the script solves that issue, making use of the fact that
		;the FixMe function also reloads some stuff in the active cell, such as
		;object coliisions.

		;unfortunately, it also seems to always teleport the player, and,
		;ironically, sometimes cause him to get stuck. therefore, this line is commented out.

		;FixMe
	endif

	end
	```


***

## `xGetQuality`

**Parameters:**

- *None*

**Returned:**

- `float` **quality**: The quality of the reference's base object.

Returns the quality of reference's base object. Supports alchemy apparatus, lockpicks, probes, repair tools.


***

## `xGetRef`

**Parameters:**

- `long` **objectID**: An object ID to get a reference to, or `0` to get the script caller's reference.

**Returned:**

- `long` **reference**: The reference requested, or `0` if none were found.

Returns a reference to one of the active objects that match the object ID. An active object is an object in one of the loaded cells, or a persistent object such as an NPC.


***

## `xGetStackSize`

**Parameters:**

- *None*

**Returned:**

- `long` **stackSize**: The amount of items in the stack, or 0 if not called on a reference.

This function returns the stack size of a given reference. For example if used on a reference to iron arrows, xGetStackSize will tell you how many arrows there are in that stack.

??? example "Get player target's stack size."
	```
	begin Example_xGetStackSize

	long ref
	long size

	setx ref to xGetPCTarget
	if ( ref == 0 )
		return
	endif

	setx size to ref->xGetStackSize

	if ( size > 1 )
		MessageBox "Target stack size is %g." size
	else
		MessageBox "Target is a single item."
	endif

	end
	```


***

## `xGetTrap`

**Parameters:**

- *None*

**Returned:**

- `string` **spellID**: The trap's spell ID.
- `string` **spellName**: The trap's spell name.
- `short` **spellCost**: The trap's spell cost.

Returns info about the reference's trap spell. Only works on container and doors. All returns will be zero if no trap is present.


***

## `xGetValue`

**Parameters:**

- *None*

**Returned:**

- `long` **Value**: The total value or maximum capacity of the object.

`xGetValue` returns the Value of reference's base object.


***

## `xGetWeight`

**Parameters:**

- *None*

**Returned:**

- `float` **weight**: The total weight or maximum capacity of the object.

`xGetWeight` returns the weight of reference's base object. If the reference is a stack of objects, return the total weight of the entire stack. If the reference is a container, return the maximum capacity.


***

## `xMyCellID`

**Parameters:**

- **None**

**Returned:**

- `string` **cellID**: The reference's current cell ID.

Returns a string containing the name of the cell the object (intended to be used with references to unique NPCs) inhabits. So fargoth_ref->xMyCellID would return "Seyda Neen" unless you've lured him into the wilderness for some reason. Useful for locating that missing companion. Can't locate items stored in containers or inventory.


***

## `xMyRef`

**Parameters:**

- **None**

**Returned:**

- `long` **reference**: The caller's reference.

Returns a reference to the calling object.


??? example "Detect if target from local script."
	```
	begin Example_xMyRef

	long myRef
	long targetRef

	setx targetRef to xGetPCTarget
	if ( targetRef == 0 )
		return
	endif

	setx myRef to xMyRef
	if ( myRef == targetRef )
		MessageBox "I'm being targetted!"
	endif

	end
	```


***

## `xPosition`

**Parameters:**

- `float` **x**: The X location to reposition to.
- `float` **y**: The Y location to reposition to.
- `float` **z**: The Z location to reposition to.
- `float` **rotation**: The rotation to take when positioned.

**Returned:**

- *None*

This is a wrapper for the vanilla Position function that can take variable input.


***

## `xPositionCell`

**Parameters:**

- `float` **x**: The X location to reposition to.
- `float` **y**: The Y location to reposition to.
- `float` **z**: The Z location to reposition to.
- `float` **rotation**: The rotation to take when positioned.
- `string` **cellID**: The name/ID of the cell to position to.

**Returned:**

- *None*

This is a wrapper for the vanilla PositionCell function that can take variable input.


***

## `xRefID`

**Parameters:**

- *None*

**Returned:**

- `string` **id**: The reference's ID.

`xRefID` returns the reference's ID. In contrast to `xGetBaseID`, this function will include the hexadecimal suffix that identifies unique instances of containers, creatures, or NPCs. For example, where `xRefID` would return `"Fargoth00000000"`, `xGetBaseID` would instead return just `"Fargoth"`.


***

## `xRefType`

**Parameters:**

- **None**

**Returned:**

- `long` **type**: The Object Type of the reference.

Returns the four byte object name of the calling reference.


***

## `xRemoveItem`

**Parameters:**

- `string` **objectID**: The object ID of the item to remove.
- `long` **count**: The number of items to remove.

**Returned:**

- *None*

This is a wrapper for the vanilla RemoveItem function that can take variable input.


***

## `xSetCharge`

**Parameters:**

- `float` **charge**: New charge that will be set on the reference.

**Returned:**

- `long` **result**: 1 if the reference's was modified, otherwise 0.

Sets the current charge on a 'cast when used' or 'cast when strikes' enchanted item. May not work if the item has never been used.


***

## `xSetCondition`

**Parameters:**

- `float` **Condition**: New condition that will be set on the reference.

**Returned:**

- `long` **result**: 1 if the reference's was modified, otherwise 0.

Sets the current condition of armor and weapons. Armor must not be at 100% or this function will fail. It must have already sustained some damage.


***

## `xSetMaxCharge`

**Parameters:**

- `float` **maxCharge**: New charge that will be set on the reference.

**Returned:**

- `long` **result**: 1 if the reference's was modified, otherwise 0.

Sets the maximum charge on an enchanted item.


***

## `xSetMaxCondition`

**Parameters:**

- `float` **maxCondition**: New maximum condition that will be set on the reference.

**Returned:**

- `long` **result**: 1 if the reference's was modified, otherwise 0.

Sets the maxium condition for armor and weapons and maximum uses for lockpicks, probes, and repair tools.


***

## `xSetName`

**Parameters:**

- `string` **name**:  The new name to apply to the reference's base object. (Maximum 31 characters)

**Returned:**

- *None*

`xSetName` uses the value parameter to change the reference's name. The new name will not persist through restarts.



***

## `xSetQuality`

**Parameters:**

- `float` **quality**: New quality that will be set on the reference's base object.

**Returned:**

- `long` **result**: 1 if the reference's base object was modified, otherwise 0.

`xSetQuality` modifies the quality of reference's base object. Supports alchemy apparatus, lockpicks, probes, repair tools.


***

## `xSetRef`

**Parameters:**

- `reference` **newReference**: A reference to the use for future function calls.

**Returned:**

- *None*

`xSetRef` provides a way of calling object functions where the syntax does not allow it, changing the reference used in future function calls.


***

## `xSetTrap`

**Parameters:**

- `string` **spellID** : The spell ID to set as the trap, or `0` to unset a trap.

**Returned:**

- `short` **result**: `1` if the reference's trap was modified, otherwise `0`.

Sets a trap. Only works on containers or doors. In order to have a trap, a reference must also have a lock. For references without locks, call `Lock 0` and `Unlock` prior to `xSetTrap`.

Traps that are set this way do not persist through saving and loading. If a trap is removed its removal persists only if the object is activated or its lock is manipulated before saving.

If you want to set a trap on a door/container, first check for an existing lock (`xGetLockLevel`). If no lock is already installed, use `Lock 0`, `Unlock` to create the lock/trap object. Set the trap. To make sure the trap is persistent, manipulate the lock, but then put it back to its original state. In other words, if the lock is currently unlocked, lock it (use `xGetLockLevel` to determine the correct lock level) then unlock it. Do the reverse if it's currently unlocked.


***

## `xSetValue`

**Parameters:**

- `long` **value**: New value that will be set on the reference's base object.

**Returned:**

- `long` **result**: 1 if the reference's base object was modified, otherwise 0.

`xSetValue` modifies the value of reference's base object.


***

## `xSetWeight`

**Parameters:**

- `float` **weight**: New weight that will be set on the reference's base object.

**Returned:**

- `long` **result**: 1 if the reference's base object was modified, otherwise 0.

`xSetWeight` modifies the weight of the reference's base object.
