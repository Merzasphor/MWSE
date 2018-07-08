
tes3ui.enterMenuMode
====================================================================================================

Pauses gameplay and enables the mouse cursor. Interaction with inventory and world objects are suppressed while the specified menu exists.

.. code-block:: lua

    tes3ui.enterMenuMode(id_mymenu)

**Parameters:**

- `UI_ID`_ **menuID**
    The ID of the menu to receive focus during menu mode.

**Returns:**

- `boolean`_ **result**
    ``true`` if switching mode, ``false`` if menu mode was already active.


.. _`boolean`: ../../type/lua/boolean.html

.. _`UI_ID`: ../../type/tes3ui/ui_id.html
