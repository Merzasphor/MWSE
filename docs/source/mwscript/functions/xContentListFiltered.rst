
xContentListFiltered
========================================================

**Parameters:**

- ``long`` **node**: For the first call, this should be 0 to get the first item. In following iterations, this value will be what is returned as **nextNode** from the previous call.
- ``long`` **typeFilter**: A type filter that matches the `Record Type`_ that is desired. Only items matching that type will be returned. A value of 0 will perform no type filtering, making this function behave identically to `xContentList`_.

**Returned:**

- ``string`` **id**: The id string of the item.
- ``long`` **count**: How many items are in the item stack.
- ``long`` **type**: The `Record Type`_ of the item.
- ``long`` **value**: The value of the item.
- ``float`` **weight**: The weight of the item.
- ``string`` **name**: The name of the item.
- ``long`` **nextNode**: The next node to provide back into this function to continue looping. When this value is 0, there are no more items.

This function behaves similar to `xContentList`_, with the added convenience of filtering to a specific `Record Type`_.

.. tip:: If you are trying to specifically get the equipped items of an actor, consider using `xEquipmentList`_.

.. _`xContentList`: xContentList.html
.. _`xEquipmentList`: xEquipmentList.html
.. _`Record Type`: ../references.html#record-types


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

  set filter to 1212369985 ; ALCH

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

This example shows how to efficiently transfer all ingredients from the player to another container. A placeholder variable, such as "_", can be used to ignore return values that are not needed for your script.

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
      setx id count _ _ _ _ _ to src->xContentListFiltered _ 1380404809

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
  setx weapID to pcRef->xContentListFiltered 0 1346454871

  if ( weapID != 0 )
      MessageBox "No weapons are allowed inside the royal chamber!"
      PlaySound3D "Door Heavy Close"
      return
  endif

  Activate

  end
