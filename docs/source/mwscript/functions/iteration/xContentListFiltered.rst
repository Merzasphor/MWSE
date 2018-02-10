
xContentListFiltered
========================================================

**Parameters:**

- ``long`` **node**: For the first call, this should be 0 to get the first item. In following iterations, this value will be what is returned as **nextNode** from the previous call.
- ``long`` **filter**: A filter that matches the `Filter Mask`_ that is desired. Only items matching the type(s) will be returned. This means that passing a value of 0 will return nothing.

**Returned:**

- ``string`` **id**: The id string of the item.
- ``long`` **count**: How many items are in the item stack.
- ``long`` **type**: The `Record Type`_ of the item.
- ``long`` **value**: The value of the item.
- ``float`` **weight**: The weight of the item.
- ``string`` **name**: The name of the item.
- ``long`` **nextNode**: The next node to provide back into this function to continue looping. When this value is 0, there are no more items.

This function behaves similar to `xContentList`_, with the added convenience of filtering for one or more `Record Type`_. 

.. tip:: If you are trying to specifically get the equipped items of an actor, consider using `xEquipmentList`_.

.. _`xContentList`: xContentList.html
.. _`xEquipmentList`: xEquipmentList.html
.. _`Record Type`: ../references.html#record-types

Filter Mask
-----------------------------

The filter mask below is meant to be summed for each `Record Type`_ desired in the filter. The exception to this rule is the ENCH filter, which restricts the results to enchanted items.

For example, if you wanted clothing (128) and armor (16) results, you would pass a value of 144 (128+16).

===== =========
Type  Mask
===== =========
ACTI  1
ALCH  2
AMMO  4
APPA  8
ARMO  16
BODY  32
BOOK  64
CLOT  128
CONT  256
CREA  512
DOOR  1024
INGR  2048
LEVC  4096
LEVI  8192
LIGH  16384
LOCK  32768
MISC  65536
NPC   131072
PROB  262144
REPA  524288
STAT  1048576
WEAP  2097152
ENCH  4194304
===== =========

Example: Simple Filtered Loop
-----------------------------

This example demonstrates how to loop through all potions the player is carrying.

::

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


Example: Transfer Ingredients
-----------------------------

This example shows how to efficiently transfer all ingredients and potions from the player to another container. A placeholder variable, such as "_", can be used to ignore return values that are not needed for your script.

::

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


Example: Get first item of a specific type.
-------------------------------------------

This example shows how to efficiently check if the player is carrying any weapons at all. No explicit loop is needed here, so evaluating the weapon id alone will suffice.

::

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
