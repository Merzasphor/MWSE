# tes3dataHandler

A core game object used for storing both active and non-dynamic gameplay data.

## Properties

### `backgroundThread`

A Windows handle to the background processing thread.

**Returns**:

* `result` (number)

***

### `backgroundThreadId`

The thread ID for the background processing thread.

**Returns**:

* `result` (number)

***

### `backgroundThreadRunning`

Access to the running state for the background processing thread.

**Returns**:

* `result` (boolean)

***

### `cellChanged`

A flag set for the frame that the player has changed cells.

**Returns**:

* `result` (boolean)

***

### `centralGridX`

The position of the origin horizontal grid coordinate.

**Returns**:

* `result` (boolean)

***

### `centralGridY`

The position of the origin longitudinal grid coordinate.

**Returns**:

* `result` (boolean)

***

### `currentAmbientWaterSound`

Access to the current ambient water sound.

**Returns**:

* `result` ([tes3sound](../../types/tes3sound))

***

### `currentCell`

Access to the cell that the player is currently in.

**Returns**:

* `result` ([tes3cell](../../types/tes3cell))

***

### `currentInteriorCell`

Access to the current interior cell, if the player is in an interior.

**Returns**:

* `result` ([tes3cell](../../types/tes3cell))

***

### `exteriorCells`

A table of nine tes3cellExteriorData objects for any loaded exterior cells.

**Returns**:

* `result` (table)

***

### `lastExteriorCell`

Access to the last visited exterior cell.

**Returns**:

* `result` ([tes3cell](../../types/tes3cell))

***

### `mainThread`

A Windows handle to the main execution thread.

**Returns**:

* `result` (number)

***

### `mainThreadId`

The thread ID for the main execution thread.

**Returns**:

* `result` (number)

***

### `nonDynamicData`

A child structure where core game objects are held.

**Returns**:

* `result` ([tes3nonDynamicData](../../types/tes3nonDynamicData))

***

### `threadSleepTime`

No description yet available.

**Returns**:

* `result` (number)

***

### `useCellTransitionFader`

An engine flag that controls if there is a fade in/out between cells.

**Returns**:

* `result` (boolean)

***

### `worldLandscapeRoot`

One of the core parent scene graph nodes.

**Returns**:

* `result` ([niNode](../../types/niNode))

***

### `worldObjectRoot`

One of the core parent scene graph nodes.

**Returns**:

* `result` ([niNode](../../types/niNode))

***

### `worldPickObjectRoot`

One of the core parent scene graph nodes.

**Returns**:

* `result` ([niNode](../../types/niNode))

***

