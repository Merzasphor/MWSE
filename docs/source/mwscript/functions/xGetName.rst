
xGetName
========================================================

**Parameters:**

- *None*

**Returned:**

- ``string`` **name**: The reference's name, or `0` if no name was found.

``xGetName`` returns a string containing the name (suitable for display, not the objectid) for the object or 0 if the object doesn't have a name. The NPC who falls from the sky near Seyda Neen has an object id of "agronian guy" but his name is "Tarhiel" when you look at his corpse.

.. tip:: Use `xSetName`_ to edit this value.

.. _`xSetName`: xSetName.html