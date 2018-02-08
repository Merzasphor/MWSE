
xPlace
========================================================

**Parameters:**

- ``string`` **objectID**: The object ID of the item to add.

**Returned:**

- ``reference`` **placedObject**: The reference to the placed object.

This is based on the vanilla PlaceAtPC function that can take variable **objectID**. Unlike the original function, xPlace does not allow specifying a count or location for the placed object.

xPlace returns a reference to the **placedObject** that can be used to take further actions or obtain further information.

.. note:: Unlike previous version of MWSE, the reference returned from xPlace is immediately available on the same frame it was created.
