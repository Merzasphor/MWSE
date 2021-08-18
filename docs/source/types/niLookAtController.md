# niLookAtController

Orients an axis of the controlled object towards a lookAt target. The axis is selectable.

Warning: The lookAt property is not reference counted, so this controller must be removed, or lookAt set to nil before the lookAt object is deleted.

This type inherits the following: [niTimeController](../../types/niTimeController), [niObject](../../types/niObject)
## Properties

### `active`

If the controller is active. When inactive, the target does not get updated and animation timing does not advance.

**Returns**:

* `result` (boolean)

***

### `animTimingType`

How the time parameter passed to the update function is treated. Type 0 is the default, which treats the update time as a delta time. Type 1 treats the update time an offset from the start of the animation.

**Returns**:

* `result` (number)

***

### `axis`

A number representing the axis that points at the lookAt object. `flip` determines which end of this axis points at the target.
`0` X axis
`1` Y axis
`2` Z axis

**Returns**:

* `result` (number)

***

### `cycleType`

The animation cycle type. Type 0 is looping, type 2 is reverse, type 4 is clamped.

**Returns**:

* `result` (number)

***

### `flip`

Determines which end of the chosen axis points towards the lookAt target.

**Returns**:

* `result` (boolean)

***

### `frequency`

The animation controller's frequency value.

**Returns**:

* `result` (number)

***

### `highKeyFrame`

No description.

**Returns**:

* `result` (number)

***

### `lastScaledTime`

No description.

**Returns**:

* `result` (number)

***

### `lastTime`

No description.

**Returns**:

* `result` (number)

***

### `lookAt`

The object that this controller will point towards. This is not a reference counted pointer, so this controller must be removed or lookAt set to nil before the lookAt object is deleted. This was probably designed to avoid reference cycles where controllers keep an ancestor node alive.

**Returns**:

* `result` ([niAVObject](../../types/niAVObject))

***

### `lowKeyFrame`

No description.

**Returns**:

* `result` (number)

***

### `nextController`

The next NiTimeController in the list of controllers containing the calling controller.

**Returns**:

* `result` ([niTimeController](../../types/niTimeController))

***

### `phase`

The phase value.

**Returns**:

* `result` (number)

***

### `references`

*Read-only*. The number of references that exist for the given object. When this value hits zero, the object's memory is freed.

**Returns**:

* `result` (string)

***

### `runTimeTypeInformation`

The runtime type information for this object.

**Returns**:

* `result` ([niRTTI](../../types/niRTTI))

***

### `startTime`

No description.

**Returns**:

* `result` (number)

***

### `target`

The scene graph object that this animation controller is to animate.

**Returns**:

* `result` ([niObjectNET](../../types/niObjectNET))

***

## Methods

### `clone`

Creates a copy of this object.

```lua
local result = niObject:clone()
```

**Returns**:

* `result` ([niObject](../../types/niObject))

***

### `isInstanceOfType`

Determines if the object is of a given type, or of a type derived from the given type. Types can be found in the tes3.niType table.

```lua
local result = niObject:isInstanceOfType(type)
```

**Parameters**:

* `type` (number)

**Returns**:

* `result` (boolean)

***

### `isOfType`

Determines if the object is of a given type. Types can be found in the tes3.niType table.

```lua
local result = niObject:isOfType(type)
```

**Parameters**:

* `type` (number)

**Returns**:

* `result` (boolean)

***

### `start`

Starts the controller at the specified time.

```lua
niTimeController:start(time)
```

**Parameters**:

* `time` (number)

***

### `stop`

Stops the controller. If you only want to pause the controller, use the `update` property.

```lua
niTimeController:stop()
```

***
