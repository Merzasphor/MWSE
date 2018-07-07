
tes3ui.createMenu
====================================================================================================

Creates a top-level menu.

.. code-block:: lua

    tes3ui.enterMenuMode{id = id_mymenu, fixedFrame = true}

**Parameters:**

Uses named parameters.

- `UI_ID`_ **id** ``required``
    The ID of the menu to have focus when menu mode activates.

- `boolean`_ **dragFrame** ``optional``
    Constructs a draggable and resizeable frame and background for the menu. It is similar to the stats, inventory, magic and map menus in the standard UI. After construction, position and minimum dimensions should be set.
    
- `boolean`_ **fixedFrame** ``optional``
    Constructs a fixed (non-draggable) frame and background for the menu. The layout system should automatically center and size it to fit whatever is added to the menu.
    
**Returns:**

- `Element`_ **result**
    The newly constructed menu element.


.. _`boolean`: ../../type/lua/boolean.html

.. _`Element`: ../../type/tes3ui/element.html
.. _`UI_ID`: ../../type/tes3ui/ui_id.html
