# tes3dataHandler

A core game object used for storing both active and non-dynamic gameplay data.

## Properties

### `backgroundThread`

*Read-only*. A Windows handle to the background processing thread.

**Returns**:

* `result` (number)

***

### `backgroundThreadId`

*Read-only*. The thread ID for the background processing thread.

**Returns**:

* `result` (number)

***

### `backgroundThreadRunning`

*Read-only*. Access to the running state for the background processing thread.

**Returns**:

* `result` (boolean)

***

### `cellChanged`

*Read-only*. A flag set for the frame that the player has changed cells.

**Returns**:

* `result` (boolean)

***

### `centralGridX`

*Read-only*. The position of the origin horizontal grid coordinate.

**Returns**:

* `result` (boolean)

***

### `centralGridY`

*Read-only*. The position of the origin longitudinal grid coordinate.

**Returns**:

* `result` (boolean)

***

### `currentAmbientWaterSound`

Access to the current ambient water sound.

**Returns**:

* `result` ([tes3sound](../../types/tes3sound))

***

### `currentCell`

*Read-only*. Access to the cell that the player is currently in.

**Returns**:

* `result` ([tes3cell](../../types/tes3cell))

***

### `currentInteriorCell`

*Read-only*. Access to the current interior cell, if the player is in an interior.

**Returns**:

* `result` ([tes3cell](../../types/tes3cell))

***

### `exteriorCells`

*Read-only*. A table of nine tes3cellExteriorData objects for any loaded exterior cells.

**Returns**:

* `result` (table)

***

### `lastExteriorCell`

*Read-only*. Access to the last visited exterior cell.

**Returns**:

* `result` ([tes3cell](../../types/tes3cell))

***

### `mainThread`

*Read-only*. A Windows handle to the main execution thread.

**Returns**:

* `result` (number)

***

### `mainThreadId`

*Read-only*. The thread ID for the main execution thread.

**Returns**:

* `result` (number)

***

### `nonDynamicData`

*Read-only*. A child structure where core game objects are held.

**Returns**:

* `result` ([tes3nonDynamicData](../../types/tes3nonDynamicData))

***

### `threadSleepTime`

*Read-only*. No description yet available.

**Returns**:

* `result` (number)

***

### `useCellTransitionFader`

An engine flag that controls if there is a fade in/out between cells.

**Returns**:

* `result` (boolean)

***

### `worldLandscapeRoot`

*Read-only*. One of the core parent scene graph nodes.

**Returns**:

* `result` ([niNode](../../types/niNode))

***

### `worldObjectRoot`

*Read-only*. One of the core parent scene graph nodes.

**Returns**:

* `result` ([niNode](../../types/niNode))

***

### `worldPickObjectRoot`

*Read-only*. One of the core parent scene graph nodes.

**Returns**:

* `result` ([niNode](../../types/niNode))

***

