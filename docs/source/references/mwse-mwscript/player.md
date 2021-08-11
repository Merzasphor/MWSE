# Player Functions

--8<-- "mwse-deprecated.md"


## `xGetPCTarget`

**Parameters:**

- **None**

**Returned:**

- `long` **reference**: The target reference, or `0` if none was found.

Returns a reference to the object in the player's crosshair, or `0` if the player is not looking at anything that can be manipulated.


***

## `xGetProgressLevel`

**Parameters:**

- **None**

**Returned:**

- `long` **progress**: The player's progress to next level.

Returns the current progress to the next level.


***

## `xGetProgressSkill`

**Parameters:**

- `long` **skillID**: The [Skill](../../skills) ID to get the progress of.

**Returned:**

- `float` **raw**: Raw skill progress value.
- `float` **normalized**: Normalized skill progress value.

Returns the skill progress for the given skill ID. Returned values will be zero if skill ID is invalid.


***

## `xSetSkillInfo`

**Parameters:**

- `long` **skillID**: 1 if the effect was added, or `0` if it wasn't.

**Returned:**

- `long` **skillID**:  ID of the [Skill](../../skills) to be modified.
- `long` **attributeID**: ID of the new governing [Attribute](../../attributes).
- `long` **specialization**: The new [Specialization Type](../../specialization-types).
- `float` **action1**: Progress value for the 1st action.
- `float` **action2**: Progress value for the 2nd action.
- `float` **action3**: Progress value for the 3rd action.
- `float` **action4**: Progress value for the 4th action.

All parameters seem to take effect immediately. There may be side-effects other than those listed below that I have not discovered yet. Changing the governing attribute will cause any subsequent skill-ups to count toward that attribute at level-up. (Which implies they're counted, not inferred, and could be modified. Stay tuned...)

Changing the specialization will cause the target progress needed for skill up to change. This function invokes the native skill-up function when changing specialization, in case the change would cause progress to reach 100. Actions can be set a negative value, in which case they'll remove progress, but progress will never go below zero.

??? example
	```
	setx attribute specialization action1 action2 action3 action4 to xGetSkillInfo 9
	```


***

## `xModProgressLevel`

**Parameters:**

- `long` **value**: Value added toward the player's progress to next level.

**Returned:**

- `short` **result**: `1` if successful, otherwise `0`.

Adds value to the progress to the next player level. If the new progress value is less than zero, it's set to zero instead. Returns non-zero on success, zero on failure.


***

## `xModProgressSkill`

**Parameters:**

- `long` **skillID**: The [Skill](../../skills) ID to modify.
- `float` **value**: The value to modify the skill's progress by.
- `long` **normalized**: flag indicating whether value is raw (`0`) or normalized (`1`)

**Returned:**

- `short` **result**: `1` if successful, otherwise `0`.

Modifies the current progress for the given skill. If the new progress value is less than zero, it's set to zero instead. Returns non-zero on success, zero on failure. This function will fail if skill ID is out of range.


***

## `xPCCellID`

**Parameters:**

- **None**

**Returned:**

- `string` **cellID**: The player's current cell ID.

Returns a string containing the name of the current cell.


***

## `xPlace`

**Parameters:**

- `string` **objectID**: The object ID of the item to add.

**Returned:**

- `reference` **placedObject**: The reference to the placed object.

This is based on the vanilla PlaceAtPC function that can take variable **objectID**. Unlike the original function, xPlace does not allow specifying a count or location for the placed object.

`xPlace` returns a reference to the **placedObject** that can be used to take further actions or obtain further information.

!!! note
	Unlike previous version of MWSE, the reference returned from `xPlace` is immediately available on the same frame it was created.


***

## `xSetProgressLevel`

**Parameters:**

- `long` **progress**: New value for the player's progress to next level.

**Returned:**

- `short` **result**: `1` if successful, otherwise `0`.

Sets the progress to next level. There are some limits to what you can do with this, because of how the game handles this and other values.

Progress is stored in memory as a signed long (32 bits, max value = `2147483647`). Progress is stored in the save file as an unsigned char (8 bits, max value = `255`). Progress is cast to a float before being displayed on the character screen. This appears to be true for `iLevelupTotal` as well.


***

## `xSetProgressSkill`

**Parameters:**

- `long` **skillID**: The [Skill](../../skills) ID to modify.
- `float` **value**: The value to set the skill's progress to.
- `long` **normalized**: Flag indicating whether value is raw (`0`) or normalized (`1`)

**Returned:**

- `short` **result**: `1` if successful, otherwise `0`.

Sets the current progress for the given skill. If the new progress value is less than zero, it's set to zero instead. Returns non-zero on success, zero on failure. This function will fail if skill ID is out of range.


***

## `xSetSkillInfo`

**Parameters:**

- `long` **skillID**:  ID of the [Skill](../../skills) to be modified.
- `long` **attributeID**: ID of the new governing [Attribute](../../attributes).
- `long` **specialization**: The new [Specialization Type](../../specialization-types).
- `float` **action1**: Progress value for the 1st action.
- `float` **action2**: Progress value for the 2nd action.
- `float` **action3**: Progress value for the 3rd action.
- `float` **action4**: Progress value for the 4th action.

**Returned:**

- `long` **success**: 1 if the effect was added, or 0 if it wasn't.

All parameters seem to take effect immediately. There may be side-effects other than those listed below that I have not discovered yet. Changing the governing attribute will cause any subsequent skill-ups to count toward that attribute at level-up. (Which implies they're counted, not inferred, and could be modified. Stay tuned...)

Changing the specialization will cause the target progress needed for skill up to change. This function invokes the native skill-up function when changing specialization, in case the change would cause progress to reach 100. Actions can be set a negative value, in which case they'll remove progress, but progress will never go below zero.