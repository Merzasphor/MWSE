# Iteration Functions

--8<-- "mwse-deprecated.md"


## `xContentList`

**Parameters:**

- `long` **node**: For the first call, this should be `0` to get the first item. In following iterations, this value will be what is returned as **nextNode** from the previous call.

**Returned:**

- `string` **id**: The object ID string of the item.
- `long` **count**: How many items are in the item stack.
- `long` **type**: The [Object Type](../../object-types) of the item.
- `long` **value**: The value of the item.
- `float` **weight**: The weight of the item. (Always `0.000001` for LEVI objects.)
- `string` **name**: The name of the item.
- `long` **nextNode**: The next node to provide back into this function to continue looping. When this value is 0, there are no more items.

This function allows a script to iterate through the inventory of an actor or container and retrieve information about the contents found. Unlike the `xInventory` and `xNextStack` functions, `xContentList` also provides access to the type, value, weight, and name of items processed.

If you are only interested in items of specific types, consider using `xContentListFiltered` instead. If you are only interested in items currently equipped by the actor, consider using `xEquipmentList`.


***

## `xContentListFiltered`

**Parameters:**

- `long` **node**: For the first call, this should be 0 to get the first item. In following iterations, this value will be what is returned as **nextNode** from the previous call.
- `long` **filter**: A filter that matches the Filter Mask that is desired. Only items matching the type(s) will be returned. This means that passing a value of 0 will return nothing.

**Returned:**

- `string` **id**: The id string of the item.
- `long` **count**: How many items are in the item stack.
- `long` **type**: The [Object Type](../../object-types) of the item.
- `long` **value**: The value of the item.
- `float` **weight**: The weight of the item.
- `string` **name**: The name of the item.
- `long` **nextNode**: The next node to provide back into this function to continue looping. When this value is 0, there are no more items.

This function behaves similar to `xContentList`, with the added convenience of filtering for one or more [Object Type](../../object-types).

If you are trying to specifically get the equipped items of an actor, consider using `xEquipmentList`.

### Filter Mask

The filter mask below is meant to be summed for each [Object Type](../../object-types) desired in the filter. The exception to this rule is the ENCH filter, which restricts the results to enchanted items.

For example, if you wanted clothing (`128`) and armor (`16`) results, you would pass a value of `144` (`128+16`).

Type  | Mask
----- | -------
ACTI  | 1
ALCH  | 2
AMMO  | 4
APPA  | 8
ARMO  | 16
BODY  | 32
BOOK  | 64
CLOT  | 128
CONT  | 256
CREA  | 512
DOOR  | 1024
INGR  | 2048
LEVC  | 4096
LEVI  | 8192
LIGH  | 16384
LOCK  | 32768
MISC  | 65536
NPC   | 131072
PROB  | 262144
REPA  | 524288
STAT  | 1048576
WEAP  | 2097152
ENCH  | 4194304

??? example "Simple Filtered Loop"
	This example demonstrates how to loop through all potions the player is carrying.

	```
	begin Example_xContentListFiltered

	long id
	long count
	long type
	long value
	float weight
	long name

	long next
	long filter

	long ref
	long loop

	setx ref to xGetRef "player"

	set filter to 2 ; ALCH

	set loop to 1
	whilex ( loop )
		setx id count type value weight name next to ref->xContentListFiltered next filter

		xLogMessage "id: %s" id
		xLogMessage "    count: %d" count
		xLogMessage "    type: %l" type
		xLogMessage "    value: %d" value
		xLogMessage "    weight: %.2f" weight
		xLogMessage "    name: %s" name
		xLogMessage "    next: %d" next

		set loop to next
	endwhile

	StopScript Example_xContentListFiltered

	end
	```


??? example "Transfer Ingredients"
	This example shows how to efficiently transfer all ingredients and potions from the player to another container. A placeholder variable, such as "_", can be used to ignore return values that are not needed for your script.

	```
	begin TransferIngreds

	long _
	long id
	long count

	long src
	long dst

	setx src to xGetRef "player"
	setx dst to xGetRef "ingred_storage"

	set count to 1
	whilex ( count )
		; get the next ingred and count
		setx id count _ _ _ _ _ to src->xContentListFiltered _ 2050 ; INGR + ALCH

		; remove the ingred from source
		src->xRemoveItem id count

		; add the ingred to destination
		dst->xAddItem id count

		; continue with next ingredient
		set count to _
	endwhile

	src->PlaySound3D "Item Ingredient Down"

	StopScript TransferIngreds

	end
	```


??? example "Get first item of a specific type."
	This example shows how to efficiently check if the player is carrying any weapons at all. No explicit loop is needed here, so evaluating the weapon id alone will suffice.

	```
	begin NoWeaponsAllowed

	; local script on a door

	long pcRef
	long weapID

	if ( OnActivate == 0 )
		return
	endif

	setx pcRef to xGetRef "player"
	setx weapID to pcRef->xContentListFiltered 0 2097152 ; Weapon

	if ( weapID != 0 )
		MessageBox "No weapons are allowed inside the royal chamber!"
		PlaySound3D "Door Heavy Close"
		return
	endif

	Activate

	end
	```


***

## `xEquipmentList`

**Parameters:**

- `long` **node**: For the first call, this should be 0 to get the first equipped item. In following iterations, this value will be what is returned as **nextNode** from the previous call.
- `long` **typeFilter**: A type filter that matches the [Object Type](../../object-types) that is desired. Only equipped items matching that type will be returned. A value of 0 will perform no type filtering.
- `long` **subTypeFilter**: An optional subtype filter, allowing the loop to search for a specific [Armor Type](../../armor-slots), [Clothing Type](../../clothing-slots) or [Weapon Type](../../weapon-types). The value passed must be one higher than the value on the linked table. A value of 0 will perform no subtype filtering.

**Returned:**

- `string` **id**: The id string of the equipped item.
- `long` **count**: This value will always be 1. Future version of MWSE may expand this to return the actual item count for arrows, bolts, and thrown weapons.
- `long` **type**: The [Object Type](../../object-types) of the equipped item.
- `long` **subtype**: The [Armor Type](../../armor-slots), [Clothing Type](../../clothing-slots) or [Weapon Type](../../weapon-types) of the equipped item, or `0` if it is not an armor, clothing, or weapon object. Note that the value returned is one higher than the value on the given table.
- `long` **value**: The value of the equipped item.
- `float` **weight**: The weight of the equipped item.
- `string` **name**: The name of the equipped item.
- `string` **enchantId**: The enchantment id of the equipped item. This can be fed to enchantment related functions that take an id.
- `long` **nextNode**: The next node to provide back into this function to continue looping. When this value is 0, there are no more equipped items.

This function behaves similar to `xContentList`/`xContentListFiltered`, returning inventory information. This allows looping over equipped items instead of all items in the target's inventory.

!!! note
	The **subTypeFilter** parameter does not exactly match the associated table. Instead, the function requires one *more* than the value on the table. For example if searching for clothing objects, a value of `0` will perform no filtering by subtype, while a value of `1` will filter for only pants.

!!! tip
	At present this function is the only way to reliably get the equipment a reference has currently worn. Using the **typeFilter** and **subTypeFilter** the script can quickly query to see if, for example, the player is wearing pants.

??? example "Simple Equipment Loop"
	This example demonstrates how to do a simple loop through all equipped items (on the player in this instance).

	```
	Begin loopEquippedItems

	long id
	long count
	long type
	long subtype
	long value
	long weight
	long name
	long enchantId
	long node

	long loop

	long ref

	setx ref to xGetRef "player"

	set loop to 1
	whilex ( loop )
		setx id count type subtype value weight name enchantId node to ref->xEquipmentList node 0 0

		; Code to be run for each looped item.

		set loop to node
	endwhile

	End
	```

??? example "Get Equipped Weapon's Enchantment"
	This example shows how to get the enchantment objectId for the currently equipped weapon. Looping isn't required as the player can never have more than one equipped weapon.

	```
	begin GetPlayerWeaponInfo

	long ref

	long id
	long count
	long type
	long subtype
	long value
	long weight
	long name
	long ench
	long node

	; get the player reference
	setx ref to xGetRef "player"

	; get info about his weapon
	setx id count type subtype value weight name ench node to ref->xEquipmentList 0 1346454871 0

	ifx ( name )
		xMessageFix "Weapon: %s" name
		MessageBox "Weapon: ________________________________"
	endif

	ifx ( ench )
		xMessageFix "Enchantment: %s" ench
		MessageBox "Enchantment: ________________________________"
	endif

	end
	```


***

## `xFirstItem`

**Parameters:**

- *None*

**Returned:**

- `long` **reference**: The first reference in the current cell's "Item" list.

`xFirstItem` returns the first reference in the current cell's "Item" list. Despite the name of this function, the associated list can contain references of any [Object Type](../../object-types) other than those exclusive to `xFirstNPC`. Once acquired, the reference can be used with various other MWSE functions, such as `xRefID` and `xRefType`. Passing the reference as the argument to the `xNextRef` function will return the next reference in its associated list.

!!! note
	Scripts that intend to process *all* references in the loaded cells will need to independently handle the separate lists provided by `xFirstItem`, `xFirstStatic`, and `xFirstNPC`.


***

## `xFirstNPC`

**Parameters:**

- *None*

**Returned:**

- `long` **reference**: The first reference in the current cell's "NPC" list.

`xFirstNPC` returns the first reference in the current cell's "NPC" list. Once acquired, the reference can be used with various other MWSE functions, such as `xRefID` and `xRefType`. Passing the reference as the argument to the `xNextRef` function will return the next reference in its associated list.

!!! note
	Scripts that intend to process *all* references in the loaded cells will need to independently handle the separate lists provided by `xFirstItem`, `xFirstStatic`, and `xFirstNPC`.


***

## `xFirstStatic`

**Parameters:**

- *None*

**Returned:**

- `long` **reference**: The first reference in the current cell's "Static" list.

`xFirstStatic` returns the first reference in the current cell's "Static" list. Despite the name of this function, the associated list can contain references of any [Object Type](../../object-types) other than those exclusive to `xFirstNPC`. Once acquired, the reference can be used with various other MWSE functions, such as `xRefID` and `xRefType`. Passing the reference as the argument to the `xNextRef` function will return the next reference in its associated list.

.. note:: Scripts that intend to process *all* references in the loaded cells will need to independently handle the separate lists provided by `xFirstItem`, `xFirstStatic`, and `xFirstNPC`.


***

## `xInventory`

**Parameters:**

- *None*

**Returned:**

- `string` **objectID**: The object ID of the item.
- `long` **count**: The number of items in the stack.
- `node` **nextStack**: A handle to the next stack in the inventory. This is 0 when no more items are in the inventory.

Returns the **objectID** and **count** of an item in the target's inventory. The **nextStack** can be fed into `xNextStack` to continue iteration.

!!! warning
	This function is limited. Consider using `xContentList`, `xContentListFiltered` or `xEquipmentList` instead.


***

## `xNextRef`

**Parameters:**

- `long` **reference**: A valid reference. See `xFirstItem`, `xFirstNPC`, `xFirstStatic`.

**Returned:**

- `long` **nextReference**: The next reference in the given reference's associated list.

`xNextRef` returns the next reference in the supplied reference's associated list.


***

## `xNextStack`

**Parameters:**

- `node` **stack**: The result from a previous `xInventory` or xNextStack call.

**Returned:**

- `string` **objectID**: The object ID of the item.
- `long` **count**: The number of items in the stack.
- `node` **nextStack**: A handle to the next stack in the inventory. This is 0 when no more items are in the inventory.

Returns the **objectID** and **count** of an item in the target's inventory. The **nextStack** can be fed into xNextStack to continue iteration.

!!! warning
	This function is limited. Consider using `xContentList`, `xContentListFiltered` or `xEquipmentList` instead. 


***

## `xSpellList`

**Parameters:**

- `long` **node**: For the first call, this should be 0 to get the first spell. In following iterations, this value will be what is returned as **nextNode** from the previous call.

**Returned:**

- `long` **totalSpells** : Total number of spells the caller knows.
- `long` **spellId** : The spell ID.
- `long` **name** : The spell name.
- `long` **type** : The spell type. (`0` = spell, `1` = ability, `2` = blight, `3` = disease, `4` = curse, `5` = power)
- `long` **cost** : The spell cost.
- `long` **effects** : The spell's number of effects (`1` to `8`).
- `long` **flags** : The spell flags. (`1` = autocalc, `2` = PC start, `4` = always succeeds)
- `long` **nextNode** : The next node to supply to function to continue looping. When this value is `0`, there are no more items.

This function allows a script to iterate through the spell list of an actor and retrieve information about the spells found. Currently this function does not work on creatures.