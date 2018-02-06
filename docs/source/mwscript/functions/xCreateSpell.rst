
xCreateSpell
========================================================

**Parameters:**

- ``string`` **ID**: The object ID of the spell to create.
- ``string`` **name**: The name of the spell to create.

**Returned:**

- ``long`` **wasCreated**: 1 if the spell was successfully created.

Creates a new spell with all flags cleared, origin set to spellmaker (2) and a single Water Breathing effect and adds it to the master spell list.

.. note:: This function will fail if **ID** already exists or if either **ID** or **name** are longer than 31 characters.
