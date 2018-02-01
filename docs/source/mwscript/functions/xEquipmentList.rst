
xEquipmentList
========================================================

:Parameters:

    - ``long`` **node**: For the first call, this should be 0 to get the first equipped item. In following iterations, this value will be what is returned as **nextNode** from the previous call.
    - ``long`` **typeFilter**: A type filter that matches the `Record Type`_ that is desired. Only equipped items matching that type will be returned. A value of 0 will perform no type filtering.
    - ``long`` **subTypeFilter**: An optional subtype filter, allowing the loop to search for a specific `Armor Type`_, `Clothing Type`_ or `Weapon Type`_. The value passed must be one higher than the value on the linked table. A value of 0 will perform no subtype filtering.

:Returned:

    - ``string`` **id**: The id string of the equipped item.
    - ``long`` **count**: This value will always be 1. Future version of MWSE may expand this to return the actual item count for arrows, bolts, and thrown weapons.
    - ``long`` **type**: The `Record Type`_ of the equipped item.
    - ``long`` **subtype**: The `Armor Type`_, `Clothing Type`_ or `Weapon Type`_ of the equipped item, or 0 if it is not an armor, clothing, or weapon record. Note that the value returned is one higher than the value on the given table.
    - ``long`` **value**: The value of the equipped item.
    - ``float`` **weight**: The weight of the equipped item.
    - ``string`` **name**: The name of the equipped item.
    - ``string`` **enchantId**: The enchantment id of the equipped item. This can be fed to enchantment related functions that take an id.
    - ``long`` **nextNode**: The next node to provide back into this function to continue looping. When this value is 0, there are no more equipped items.

This function behaves similar to `xContentList`_/`xContentListFiltered`_, returning inventory information. This function allows looping over equipped items instead of all items, and also returns some subtype information.

.. note:: The **subTypeFilter** parameter does not exactly match the associated table. Instead, the function requires one *more* than the value on the table. For example if searching for clothing records, a value of 0 will perform no filtering by subtype, while a value of 1 will filter for only pants.

Example
-------

::

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
  
  set loop to 1
  whilex ( loop )
      setx id count type subtype value weight name enchantId node to xEquipmentList node 0 0
  
      ; Code to be run for each looped item.
  
      set loop to node
  endwhile
  
  End

.. _`xContentList`: xContentList.html
.. _`xContentListFiltered`: xContentListFiltered.html
.. _`Record Type`: ../references.html#record-types
.. _`Armor Type`: ../references.html#armor-types
.. _`Clothing Type`: ../references.html#clothing-types
.. _`Weapon Type`: ../references.html#weapon-types
