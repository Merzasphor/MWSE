
tes3ui.acquireTextInput
====================================================================================================

Sends all text input to the specified element. Suppresses keybinds while active. Calling this function with a ``nil`` argument will release text input and allow keybinds to work.

.. code-block:: lua

    tes3ui.acquireTextInput(inputElement)

**Parameters:**

- `Element`_ **inputElement**
    The UI element to receive text input, or ``nil``.

**Returns:**

- *None*


.. _`Element`: ../../type/tes3ui/element.html
