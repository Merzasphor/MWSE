# tes3vfx

A managed visual effect, attached to position, reference, or arbitrary node. These can be created through script with `tes3.createVisualEffect` and destroyed with `tes3.removeVisualEffect`.

## Properties

### `age`

The VFX's current age, in seconds.

**Returns**:

* `result` (number)

***

### `attachNode`

The node the VFX was created to attach to, if it was created for node attachment.

**Returns**:

* `result` ([niNode](../../types/niNode), nil)

***

### `beginKeyTime`

The start of the VFX's keyframe timing. This is fetched from the creating effect's time controller at the time of the VFX's creation.

**Returns**:

* `result` (number)

***

### `effectNode`

The cloned node of the associated `effectObject`.

**Returns**:

* `result` ([niNode](../../types/niNode))

***

### `effectObject`

The object responsible for this VFX's appearance. Its scene node is cloned into `effectNode`.

**Returns**:

* `result` ([tes3physicalObject](../../types/tes3physicalObject))

***

### `endKeyTime`

The end of the VFX's keyframe timing. This is fetched from the creating effect's time controller at the time of the VFX's creation.

**Returns**:

* `result` (number)

***

### `expired`

A flag controlling if the effect is expired. This can be set to cause the effect to remove itself on the next update.

**Returns**:

* `result` (boolean)

***

### `id`

*Read-only*. The unique numberic identifier for this visual effect.

**Returns**:

* `result` (number)

***

### `keyTime`

The VFX's current keyframe timing. When this value exceeds the `endKeyTime`, the effect will either loop back to `beginKeyTime` or the effect will expire.

**Returns**:

* `result` (number)

***

### `maxAge`

The VFX's maximum age, in seconds. 

**Returns**:

* `result` (number)

***

### `position`

The position the VFX was created at.

**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

***

### `sourceInstance`

*Read-only*. The serial number of the associated source instance.

**Returns**:

* `result` (number)

***

### `sourceInstanceSerial`

The serial number of the associated source instance.

**Returns**:

* `result` (number)

***

### `target`

The reference the target is associated with, if any.

**Returns**:

* `result` ([tes3reference](../../types/tes3reference))

***

### `verticalOffset`

The VFX's vertical offset, at the time of creation. Changing this value will not automatically readjust the VFX's visual node.

**Returns**:

* `result` (number)

***

