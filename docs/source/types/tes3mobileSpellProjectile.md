# tes3mobileSpellProjectile

A mobile object for a spell projectile.

This type inherits the following: [tes3mobileProjectile](../../types/tes3mobileProjectile), [tes3mobileObject](../../types/tes3mobileObject)
## Properties

### `animTime`

The time index for the projectile model's animation controllers.

**Returns**:

* `result` (number)

***

### `attackSwing`

The attack swing value of the attacker at the time of releasing the projectile.

**Returns**:

* `result` (number)

***

### `boundSize`

A vector that shows the size of the bounding box in each direction. Note that this is a convenience feature, and delivers the `x` and `y` values from `boundSize2D` with the `z` value of the mobile's `height`. Editing the values of the returned vector will not change the values that they came from, though setting the property itself will work.

**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

***

### `boundSize2D`

A vector that shows the size of the bounding box in X and Y directions. `boundSize` is a convenience property that exposes the bounding in 3 dimensions.

**Returns**:

* `result` ([tes3vector2](../../types/tes3vector2))

***

### `cellX`

*Read-only*. The X grid coordinate of the cell the mobile is in.

**Returns**:

* `result` (number)

***

### `cellY`

*Read-only*. The Y grid coordinate of the cell the mobile is in.

**Returns**:

* `result` (number)

***

### `damage`

Access to the raw damage that this projectile will inflict.

**Returns**:

* `result` (number)

***

### `expire`

A flag that causes the projectile to expire when set to `1`.

**Returns**:

* `result` (number)

***

### `firingMobile`

*Read-only*. The mobile that fired this projectile.

**Returns**:

* `result` ([tes3mobileActor](../../types/tes3mobileActor))

***

### `firingWeapon`

*Read-only*. The weapon that fired this projectile.

**Returns**:

* `result` ([tes3weapon](../../types/tes3weapon))

***

### `flags`

Access to the root mobile object flags, represented as an integer. Should not be accessed directly.

**Returns**:

* `result` (number)

***

### `height`

The height of the mobile above the ground.

**Returns**:

* `result` (number)

***

### `impulseVelocity`

A vector that represents the 3D acceleration of the object.

**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

***

### `initialSpeed`

*Read-only*. The initial speed that the projectile was launched at.

**Returns**:

* `result` (number)

***

### `movementCollision`

Controls if the mobile has movement collision active. When false, the mobile can move through any object, but can still block other mobiles, and can still be hit in combat. Actors will still follow pathgrids, ramps and stairs when navigating.

**Returns**:

* `result` (boolean)

***

### `movementFlags`

Access to the root mobile object movement flags, represented as an integer. Should not be accessed directly.

**Returns**:

* `result` (number)

***

### `objectType`

*Read-only*. The type of mobile object. Maps to values in [`tes3.objectType`](https://mwse.github.io/MWSE/references/object-types/) namespace.

**Returns**:

* `result` (number)

***

### `playerDistance`

The distance to the player. Updated every frame when the mobile is in an active cell.

**Returns**:

* `result` (number)

***

### `position`

A vector that represents the 3D position of the object.

**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

***

### `prevMovementFlags`

Access to the root mobile object movement flags from the previous frame, represented as an integer. Should not be accessed directly.

**Returns**:

* `result` (number)

***

### `reference`

*Read-only*. Access to the reference object for the mobile, if any.

**Returns**:

* `result` ([tes3reference](../../types/tes3reference))

***

### `rotationSpeed`

The angular speed that the projectile rotates around its local Y axis.

**Returns**:

* `result` (number)

***

### `spellInstance`

Access to the magic source instance of the object.

**Returns**:

* `result` ([tes3magicSourceInstance](../../types/tes3magicSourceInstance))

***

### `spellInstanceSerial`

Unique indentifier for just this magic source.

**Returns**:

* `result` (number)

***

### `velocity`

Access to the current velocity of the projectile.

**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

***

## Methods

### `explode`

Detonates the projectile, as if it hit a static object. The effects of detonation are not applied immediately, but later in the frame, at the same time as projectile collisions. This ensures consistent behaviour of the magic system.

```lua
tes3mobileSpellProjectile:explode()
```

***

