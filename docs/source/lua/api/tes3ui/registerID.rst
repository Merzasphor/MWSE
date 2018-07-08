
tes3ui.registerID
====================================================================================================

Registers a UI element name, returning a UI_ID. Once a property is registered, this function always returns the same UI_ID. These UI_IDs are used by the API to locate elements that may not exist (a weak reference), instead of by element name.

The registry namespace is shared between `Property`_ and `UI_ID`_. It is advisable to use a namespace prefix to avoid collisions with other mods.

.. code-block:: lua

    local id_buttonOK = tes3ui.registerID("ModName:CustomMenuName_OK")

**Parameters:**

- `string`_ **name**
    The name of the UI element. 

**Returns:**

- `UI_ID`_
    The registered UI_ID.


.. _`string`: ../../type/lua/string.html

.. _`Property`: ../../type/tes3ui/property.html
.. _`UI_ID`: ../../type/tes3ui/ui_id.html
