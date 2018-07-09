
tes3ui.registerProperty
====================================================================================================

Registers a property name, returning a `Property`_. Once a property is registered, this function always returns the same Property.

The registry namespace is shared between `Property`_ and `UI_ID`_. It is advisable to use a namespace prefix to avoid collisions with other mods.

.. code-block:: lua

    local prop_custom = tes3ui.registerProperty("ModName:CustomProperty")

**Parameters:**

- `string`_ **name**
    The unique name of the property. 

**Returns:**

- `Property`_
    The registered Property.


.. _`string`: ../../type/lua/string.html

.. _`Property`: ../../type/tes3ui/property.html
.. _`UI_ID`: ../../type/tes3ui/ui_id.html
