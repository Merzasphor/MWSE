# tes3uiEventData

Contains information from a standard UI callback. This is the parameter passed to callbacks when using `:register`, `:registerBefore`, or `:registerAfter`.

## Properties

### `forwardSource`

*Read-only*. No description yet available.

**Returns**:

* `result` ([tes3uiElement](../../types/tes3uiElement))

***

### `id`

*Read-only*. The ID of the event that is being triggered.

**Returns**:

* `result` (number)

***

### `relativeX`

*Read-only*. For mouse-related events, this is the relative horizontal position for the current element.

**Returns**:

* `result` (number, nil)

***

### `relativeY`

*Read-only*. For mouse-related events, this is the relative vertical position for the current element.

**Returns**:

* `result` (number, nil)

***

### `source`

*Read-only*. The element that owns the event.

**Returns**:

* `result` ([tes3uiElement](../../types/tes3uiElement))

***

### `widget`

*Read-only*. No description yet available.

**Returns**:

* `result` ([tes3uiElement](../../types/tes3uiElement))

***

