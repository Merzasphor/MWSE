
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
