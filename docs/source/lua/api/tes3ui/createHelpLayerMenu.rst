
tes3ui.createHelpLayerMenu
====================================================================================================

Creates a help layer menu. Help layer menus include notifications and tooltips that are always above the rest of the interface. The game realizes this using a separate menu root and set of functions.

Note, to create tooltips with the correct behaviour, use `tes3ui.createTooltipMenu`_.

Unlike standard menus, help layer menus are always created with a fixed frame.

.. code-block:: lua

    tes3ui.createHelpLayerMenu{id = id_mymenu}

**Parameters:**

Uses named parameters.

- `UI_ID`_ **id** ``required``
    The menu's ID. The menu can be later accessed by ``tes3ui.findHelpLayerMenu(id)``.

**Returns:**

- `Element`_ **result**
    The newly constructed menu element.


.. _`Element`: ../../type/tes3ui/element.html
.. _`UI_ID`: ../../type/tes3ui/ui_id.html

.. _`tes3ui.createTooltipMenu`: createTooltipMenu.html