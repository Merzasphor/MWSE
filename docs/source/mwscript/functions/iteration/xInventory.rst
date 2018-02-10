
xInventory
========================================================

**Parameters:**

- *None*

**Returned:**

- ``string`` **objectID**: The object ID of the item.
- ``long`` **count**: The number of items in the stack.
- ``node`` **nextStack**: A handle to the next stack in the inventory. This is 0 when no more items are in the inventory.

Returns the **objectID** and **count** of an item in the target's inventory. The **nextStack** can be fed into `xNextStack`_ to continue iteration.

.. warning:: This function is limited. Consider using `xContentList`_, `xContentListFiltered`_ or `xEquipmentList`_ instead. 

.. _`xNextStack`: xNextStack.html
.. _`xContentList`: xContentList.html
.. _`xContentListFiltered`: xContentListFiltered.html
.. _`xEquipmentList`: xEquipmentList.html