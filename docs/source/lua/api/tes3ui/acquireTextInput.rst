
tes3ui.acquireTextInput
====================================================================================================

Sends all text input to the specified element. Suppresses keybinds while active. Calling this function with a ``nil`` argument will release text input and allow keybinds to work.

.. code-block:: lua

    tes3ui.acquireTextInput(id_input)

**Parameters:**

- `UI_ID`_ **elementID**
    The ID of the UI element to receive text input, or ``nil``.

**Returns:**

- *None*


.. _`UI_ID`: ../../type/tes3ui/ui_id.html
