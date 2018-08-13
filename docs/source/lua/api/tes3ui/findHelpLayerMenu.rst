
tes3ui.findHelpLayerMenu
====================================================================================================

Locates a help layer menu through its id. Help layer menus include notifications and tooltips that are always above the rest of the interface. The game realizes this using a separate menu root and set of functions.

.. code-block:: lua

    tes3ui.findHelpLayerMenu(id_mymenu)

**Parameters:**

- `UI_ID`_ **menuID**
    The ID of the menu to locate.

**Returns:**

- `Element`_ **result**
    The menu element, or ``nil`` if it was not found.


.. _`Element`: ../../type/tes3ui/element.html
.. _`UI_ID`: ../../type/tes3ui/ui_id.html
