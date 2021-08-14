# mwseTimerController

A Timer Controller is a class used to sort and trigger callbacks based on an arbitrary timekeeping mechanic.

## Properties

### `clock`

The current clock time for this timer controller.

**Returns**:

* `result` (number)

***

## Methods

### `create`

Creates a timer for the given Timer Controller.

```lua
local timer = mwseTimerController:create({ type = ..., duration = ..., callback = ..., iterations = ... })
```

**Parameters**:

* `params` (table)
	* `type` (number)
	* `duration` (number)
	* `callback` (function)
	* `iterations` (number): *Optional*.

**Returns**:

* `timer` ([mwseTimer](../../types/mwseTimer))

***

## Functions

### `new`

Creates a new Timer Controller. Its initial clock is zero, unless a start time is provided.

```lua
local result = mwseTimerController.new(startTime)
```

**Parameters**:

* `startTime` (number): *Optional*.

**Returns**:

* `result` ([mwseTimerController](../../types/mwseTimerController))

***

