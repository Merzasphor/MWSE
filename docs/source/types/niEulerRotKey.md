# niEulerRotKey

An animation key for euler rotations.

This type inherits the following: [niRotKey](../../types/niRotKey), [niAnimationKey](../../types/niAnimationKey)
## Properties

### `keyOrder`

*Read-only*. An array of 3 values that define the ordering used for the contained keys.

**Returns**:

* `result` (number)

***

### `keys`

*Read-only*. A table of x/y/z rotation keys. Each value in the table is an array of animation keys, with a length matching `numKeys`. Because an axis key can be `nil`, use `pairs` instead of `ipairs` to iterate over this table.

**Returns**:

* `result` (table&lt;number, [niFloatKey](../../types/niFloatKey)[]&gt;)

***

### `keyTypes`

*Read-only*. An array of 3 values that define the types used for the contained keys.

**Returns**:

* `result` (number)

***

### `lastIndices`

*Read-only*. An array of 3 values that define the last indices used for each key.

**Returns**:

* `result` (number)

***

### `numKeys`

*Read-only*. An array of 3 values that define the number of keys in each xRotations/yRotations/zRotations.

**Returns**:

* `result` (number)

***

### `timing`

The timing of the animation key.

**Returns**:

* `result` (number)

***

### `value`

The rotation value of the animation key.

**Returns**:

* `result` ([niQuaternion](../../types/niQuaternion))

***

