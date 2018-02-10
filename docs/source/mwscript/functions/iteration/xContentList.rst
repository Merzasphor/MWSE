
xContentList
========================================================

**Parameters:**

- ``long`` **node**: For the first call, this should be 0 to get the first item. In following iterations, this value will be what is returned as **nextNode** from the previous call.

**Returned:**

- ``string`` **id**: The object ID string of the item.
- ``long`` **count**: How many items are in the item stack.
- ``long`` **type**: The `Object Type`_ of the item.
- ``long`` **value**: The value of the item.
- ``float`` **weight**: The weight of the item. (Always 0.000001 for LEVI objects.)
- ``string`` **name**: The name of the item.
- ``long`` **nextNode**: The next node to provide back into this function to continue looping. When this value is 0, there are no more items.

This function allows a script to iterate through the inventory of an actor or container and retrieve information about the contents found. Unlike the `xInventory`_ and `xNextStack`_ functions, `xContentList`_ also provides access to the type, value, weight, and name of items processed.

.. tip:: If you are only interested in items of specific types, consider using `xContentListFiltered`_ instead.
.. tip:: If you are only interested in items currently equipped by the actor, consider using `xEquipmentList`_.

.. _`Object Type`: ../references.html#object-types
.. _`xContentList`: xContentList.html
.. _`xContentListFiltered`: xContentListFiltered.html
.. _`xEquipmentList`: xEquipmentList.html
.. _`xInventory`: xInventory.html
.. _`xNextStack`: xNextStack.html