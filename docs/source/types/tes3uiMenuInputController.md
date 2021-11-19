# tes3uiMenuInputController

A core came structure responsible for managing the input around menu elements.

## Properties

### `lastInputTime`

The amount of seconds that have passed since the last time the input was updated.

**Returns**:

* `result` (number)

***

### `menuController`

A handle back to the main menu controller.

**Returns**:

* `result` ([tes3uiMenuController](../../types/tes3uiMenuController))

***

### `textInputFocus`

The element that is currently focused for text input.

**Returns**:

* `result` ([tes3uiElement](../../types/tes3uiElement))

***

## Methods

### `flushBufferedTextEvents`

Clears the current text input. If no text has been passed to the current text focus, this will prevent it from doing so.

```lua
tes3uiMenuInputController:flushBufferedTextEvents()
```

***

