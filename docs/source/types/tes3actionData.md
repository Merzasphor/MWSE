# tes3actionData

A substructure of mobile actors that provides information about the current or previous action.

## Properties

### `aiBehaviorState`

The behavior state of the [tes3actionData](https://mwse.github.io/MWSE/types/tes3actionData).

Value | Behavior
----- | ---------
-1    | Undecided
0     | Hello
2     | Idle
3     | Attack
4     | Avoid
6     | Flee
8     | Walk
12    | Greet

**Returns**:

* `result` (number)

***

### `animationAttackState`

No description yet available.

**Returns**:

* `result` (number)

***

### `attackDirection`

**Deprecated. Use tes3actionData.physicalAttackType instead.** When attacking, the direction swung with the weapon. This shows if the actor was thrusting, swinging, or chopping.

**Returns**:

* `result` (number)

***

### `attackSwing`

When attacking, this value represents how much the weapon has been pulled back. The value ranges from [0.0 - 1.0].

**Returns**:

* `result` (number)

***

### `currentAnimationGroup`

No description yet available.

**Returns**:

* `result` (number)

***

### `hitTarget`

No description yet available.

**Returns**:

* `result` ([tes3mobileActor](../../types/tes3mobileActor))

***

### `lastBarterHoursPassed`

No description yet available.

**Returns**:

* `result` (number)

***

### `nockedProjectile`

The currently nocked projectile the associated actor is using. It is available while charging a projectile attack, before releasing the projectile. This can be modified, but can only be set to nil, which will remove the projectile without consuming ammo.

**Returns**:

* `result` ([tes3mobileProjectile](../../types/tes3mobileProjectile))

***

### `physicalAttackType`

A number from the tes3.physicalAttackType enumeration identifying the physical attack type. Can be tes3.physicalAttackType.slash, .chop, .thrust, .projectile, .creature1, .creature2, or .creature3.

**Returns**:

* `result` (number)

***

### `physicalDamage`

When attacking, this is the value of the weapon damage that was rolled. This value doesn't take into account the actor's strength, or other additional damage.

**Returns**:

* `result` (number)

***

### `stolenFrom`

No description yet available.

**Returns**:

* `result` ([tes3object](../../types/tes3object))

***

### `target`

No description yet available.

**Returns**:

* `result` ([tes3mobileActor](../../types/tes3mobileActor))

***

### `walkDestination`

If moving to a location, this is the position to be walked to.

**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

***

