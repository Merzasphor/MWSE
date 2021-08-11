# tes3statisticSkill

A structure that holds statistical information relating to the current and base values of a skill statistic.

Morrowind statistics do not track buffs and debuffs separately. Instead, total buff or debuff values can be calculated with the tes3.getEffectMagnitude function, using the appropriate buff or debuff magic effect for the statistic.

This type inherits the following: [tes3statistic](../../types/tes3statistic)
## Properties

### `base`

The base value of the skill statistic. Damage, and fortify spell effects don't change base skill value.

**Returns**:

* `result` (number)

***

### `baseRaw`

The base value of the skill statistic, as stored in memory. Prefer to use .base unless you know what you're doing.

**Returns**:

* `result` (number)

***

### `current`

The current value of the skill statistic.

**Returns**:

* `result` (number)

***

### `currentRaw`

The current value of the skill statistic, as stored in memory. Prefer to use .current unless you know what you're doing.

**Returns**:

* `result` (number)

***

### `normalized`

The normalized value of the skill statistic.

**Returns**:

* `result` (number)

***

### `type`

No description yet available.

**Returns**:

* `result` (number)

***

