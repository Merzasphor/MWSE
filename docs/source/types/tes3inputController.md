# tes3inputController

A data structure, off of the world controller, that handles input.

## Properties

### `creationFlags`

*Read-only*. A bit field representing device capabilities and settings.

**Returns**:

* `result` (number)

***

### `inputMaps`

*Read-only*. The array-style access to input bindings ([tes3inputConfig](https://mwse.github.io/MWSE/types/tes3inputConfig/) objects).

**Returns**:

* `result` (table)

***

### `keyboardState`

*Read-only*. The array-style access to raw key states.

**Returns**:

* `result` (table)

***

### `mouseState`

*Read-only*. The raw DirectInput mouse state.

**Returns**:

* `result` ([tes3directInputMouseState](../../types/tes3directInputMouseState))

***

### `previousKeyboardState`

*Read-only*. The array-style access to the previous frame's raw key states.

**Returns**:

* `result` (table)

***

### `previousMouseState`

*Read-only*. The raw DirectInput mouse state for the previous state.

**Returns**:

* `result` ([tes3directInputMouseState](../../types/tes3directInputMouseState))

***

## Methods

### `isAltDown`

Returns true if either alt modifier key is pressed.

```lua
local isPressed = tes3inputController:isAltDown()
```

**Returns**:

* `isPressed` (boolean): True if either alt key is pressed.

***

### `isCapsLockActive`

Returns true if the caps lock mode is active.

```lua
local isPressed = tes3inputController:isCapsLockActive()
```

**Returns**:

* `isPressed` (boolean): True if caps lock is active.

***

### `isControlDown`

Returns true if either control modifier key is pressed.

```lua
local isPressed = tes3inputController:isControlDown()
```

**Returns**:

* `isPressed` (boolean): True if either control key is pressed.

***

### `isKeyDown`

Performs a key down test for a given scan key code.

```lua
local result = tes3inputController:isKeyDown(key)
```

**Parameters**:

* `key` (number): The scan code to test. Constants available through [`tes3.scanCode`](https://mwse.github.io/MWSE/references/scan-codes/).

**Returns**:

* `result` (boolean)

***

### `isKeyPressedThisFrame`

Checks to see if a given scan code is pressed, and wasn't pressed last frame.

```lua
local result = tes3inputController:isKeyPressedThisFrame(key)
```

**Parameters**:

* `key` (number): The scan code to test. Constants available through [`tes3.scanCode`](https://mwse.github.io/MWSE/references/scan-codes/).

**Returns**:

* `result` (boolean)

***

### `isKeyReleasedThisFrame`

Checks to see if a given scan code is released, and was pressed last frame.

```lua
local result = tes3inputController:isKeyReleasedThisFrame(key)
```

**Parameters**:

* `key` (number): The scan code to test. Constants available through [`tes3.scanCode`](https://mwse.github.io/MWSE/references/scan-codes/).

**Returns**:

* `result` (boolean)

***

### `isMouseButtonDown`

Returns the mouse down state for a given mouse button.

```lua
local result = tes3inputController:isMouseButtonDown(button)
```

**Parameters**:

* `button` (number): The mouse button to test. Must be between `0` and `7`.

**Returns**:

* `result` (boolean)

***

### `isMouseButtonPressedThisFrame`

Returns true if a mouse button was up last frame, and down this frame.

```lua
local result = tes3inputController:isMouseButtonPressedThisFrame(button)
```

**Parameters**:

* `button` (number): The mouse button to test. Must be between `0` and `7`.

**Returns**:

* `result` (boolean)

***

### `isMouseButtonReleasedThisFrame`

Returns true if a mouse button was down last frame, and up this frame.

```lua
local result = tes3inputController:isMouseButtonReleasedThisFrame(button)
```

**Parameters**:

* `button` (number): The mouse button to test. Must be between `0` and `7`.

**Returns**:

* `result` (boolean)

***

### `isShiftDown`

Returns true if either shift modifier key is pressed. It does not take into account caps lock.

```lua
local isPressed = tes3inputController:isShiftDown()
```

**Returns**:

* `isPressed` (boolean): True if either shift key is pressed.

***

### `isSuperDown`

Returns true if either super/windows modifier key is pressed.

```lua
local isPressed = tes3inputController:isSuperDown()
```

**Returns**:

* `isPressed` (boolean): True if either super/windows key is pressed.

***

### `keybindTest`

Performs a test for a given keybind, and optionally a transition state.

```lua
local result = tes3inputController:keybindTest(key, transition)
```

**Parameters**:

* `key` (number): The keybind to test. Constants available through [`tes3.keybind`](https://mwse.github.io/MWSE/references/keybinds/).
* `transition` (number): *Optional*. Transition state, e.g. down, or up. Constants available through [`tes3.keyTransition`](https://mwse.github.io/MWSE/references/key-transitions/).

**Returns**:

* `result` (boolean)

***

