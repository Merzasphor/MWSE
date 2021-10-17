# tes3magicEffect

A core magic effect definition.

## Properties

### `allowEnchanting`

Access to the flag that determines if this effect can be used in enchanting.

**Returns**:

* `result` (boolean)

***

### `allowSpellmaking`

Access to the flag that determines if this effect can be used with spellmaking.

**Returns**:

* `result` (boolean)

***

### `appliesOnce`

Access to the base flag that determines if this effect can be used in enchanting.

**Returns**:

* `result` (boolean)

***

### `areaSoundEffect`

The sound effect that plays on area of effect impacts. Can be set to ``nil`` to use the default sound effect for the magic school.

**Returns**:

* `result` ([tes3sound](../../types/tes3sound))

***

### `areaVisualEffect`

No description yet available.

**Returns**:

* `result` ([tes3physicalObject](../../types/tes3physicalObject))

***

### `baseFlags`

No description yet available.

**Returns**:

* `result` (number)

***

### `baseMagickaCost`

The base magicka cost to use in calculations.

**Returns**:

* `result` (number)

***

### `bigIcon`

The path to the large icon to use for the effect. This is derived from the base icon path.

**Returns**:

* `result` (string)

***

### `boltSoundEffect`

The sound effect that plays for magic projectiles. Can be set to ``nil`` to use the default sound effect for the magic school.

**Returns**:

* `result` ([tes3sound](../../types/tes3sound))

***

### `boltVisualEffect`

No description yet available.

**Returns**:

* `result` ([tes3physicalObject](../../types/tes3physicalObject))

***

### `canCastSelf`

Access to the base flag that determines if this effect can be used with a range of self.

**Returns**:

* `result` (boolean)

***

### `canCastTarget`

Access to the base flag that determines if this effect can be used with a range of target.

**Returns**:

* `result` (boolean)

***

### `canCastTouch`

Access to the base flag that determines if this effect can be used with a range of touch.

**Returns**:

* `result` (boolean)

***

### `casterLinked`

Access to the base flag.

**Returns**:

* `result` (boolean)

***

### `castSoundEffect`

The sound effect that plays when casting. Can be set to ``nil`` to use the default sound effect for the magic school.

**Returns**:

* `result` ([tes3sound](../../types/tes3sound))

***

### `castVisualEffect`

No description yet available.

**Returns**:

* `result` ([tes3physicalObject](../../types/tes3physicalObject))

***

### `description`

Player-facing description of the effect.

**Returns**:

* `result` (string)

***

### `flags`

Raw access to the numerical representation of flags. Typically shouldn't be used.

**Returns**:

* `result` (number)

***

### `hasContinuousVFX`

Access to the base flag that determines if this effect's VFX continuously plays.

**Returns**:

* `result` (boolean)

***

### `hasNoDuration`

Access to the base flag that determines if this effect doesn't use a duration.

**Returns**:

* `result` (boolean)

***

### `hasNoMagnitude`

Access to the base flag that determines if this effect doesn't make use of its magnitude.

**Returns**:

* `result` (boolean)

***

### `hitSoundEffect`

The sound effect that plays when the effect hits a target. Can be set to ``nil`` to use the default sound effect for the magic school.

**Returns**:

* `result` ([tes3sound](../../types/tes3sound))

***

### `hitVisualEffect`

No description yet available.

**Returns**:

* `result` ([tes3physicalObject](../../types/tes3physicalObject))

***

### `icon`

The path to the icon to use for the effect.

**Returns**:

* `result` (string)

***

### `illegalDaedra`

Access to the base flag that determines if this effect summons an illegal daedra. This flag isn't used.

**Returns**:

* `result` (boolean)

***

### `isHarmful`

Access to the base flag that determines if this effect is counted as a hostile action.

**Returns**:

* `result` (boolean)

***

### `lightingBlue`

The amount of blue lighting to use when lighting projectiles.

**Returns**:

* `result` (number)

***

### `lightingGreen`

The amount of green lighting to use when lighting projectiles.

**Returns**:

* `result` (number)

***

### `lightingRed`

The amount of red lighting to use when lighting projectiles.

**Returns**:

* `result` (number)

***

### `name`

*Read-only*. Player-facing name of the effect.

**Returns**:

* `result` (string)

***

### `nonRecastable`

Access to the base flag that determines if this effect can be refreshed by recasting.

**Returns**:

* `result` (boolean)

***

### `particleTexture`

*Read-only*. The path to use for the particle effect texture.

**Returns**:

* `result` (boolean)

***

### `school`

The school that the effect is associated with.

**Returns**:

* `result` (number)

***

### `size`

No description yet available.

**Returns**:

* `result` (number)

***

### `sizeCap`

No description yet available.

**Returns**:

* `result` (number)

***

### `skill`

*Read-only*. The skill for the associated school that the effect is associated with.

**Returns**:

* `result` (number)

***

### `speed`

No description yet available.

**Returns**:

* `result` (number)

***

### `spellFailureSoundEffect`

The sound effect that plays when a spell fails to cast, and when magic is resisted. This is determined only by the spell school.

**Returns**:

* `result` ([tes3sound](../../types/tes3sound))

***

### `targetsAttributes`

Access to the base flag that determines if this effect makes use of attributes.

**Returns**:

* `result` (boolean)

***

### `targetsSkills`

Access to the base flag that determines if this effect makes use of skills.

**Returns**:

* `result` (boolean)

***

### `unreflectable`

Access to the base flag that determines if this effect can't be reflected.

**Returns**:

* `result` (boolean)

***

### `usesNegativeLighting`

Access to the base flag that determines if this effect provides negative lighting.

**Returns**:

* `result` (boolean)

***

