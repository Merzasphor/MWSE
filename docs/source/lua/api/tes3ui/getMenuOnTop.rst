
tes3ui.getMenuOnTop
====================================================================================================

Returns the front-most visible top-level menu. This is what you could consider the active menu, but may also include the console, choice menus, etc.

.. code-block:: lua

    local top = tes3ui.getMenuOnTop()

**Parameters:**

- *None*

**Returns:**

- `Element`_ **result**
    The menu element, or ``nil`` if there are no menus visible.


.. _`Element`: ../../type/tes3ui/element.html
