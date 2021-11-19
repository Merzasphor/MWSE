# tes3processManager



## Properties

### `aiDistance`

A value which controls how far the game AI is processed, measured in game distance units. Corresponds to AI Distance slider in Options menu.

**Returns**:

* `result` (number)

***

### `aiDistanceScale`

A value which controls how far the game AI is processed. Corresponds to AI Distance slider in Options menu. This scale is in range [0, 1]. Where 0 means the minimal AI processing range, while 1 means maximal AI processing range.

**Returns**:

* `result` (number)

***

## Functions

### `checkAlarmRadius`



```lua
tes3processManager.checkAlarmRadius({ actor = ..., container = ... })
```

**Parameters**:

* `params` (table)
	* `actor` ([tes3mobileActor](../../types/tes3mobileActor)): 
	* `container` ([tes3aiPlanner](../../types/tes3aiPlanner)): 

***

### `checkNearbyEnemiesAllowRest`

Performs a check whether any potential nearby enemies allow the player to rest.

```lua
local result = tes3processManager.checkNearbyEnemiesAllowRest()
```

**Returns**:

* `result` (boolean)

***

### `checkPlayerDistance`



```lua
tes3processManager.checkPlayerDistance()
```

***

### `detectPresence`

This function performs a check for presence of a given mobile actor.

```lua
tes3processManager.detectPresence({ actor = ..., unknown = ... })
```

**Parameters**:

* `params` (table)
	* `actor` ([tes3mobileActor](../../types/tes3mobileActor)): The actor to perform a check for.
	* `unknown` (boolean)

***

### `detectSneak`

This function performs a check whether a detector can detect another actor sneaking.

```lua
local isDetected = tes3processManager.detectSneak({ detector = ..., target = ..., unknown = ... })
```

**Parameters**:

* `params` (table)
	* `detector` ([tes3mobileActor](../../types/tes3mobileActor)): The detector actor to perform a check for.
	* `target` ([tes3mobileActor](../../types/tes3mobileActor)): The target actor to perform a check for.
	* `unknown` (boolean)

**Returns**:

* `isDetected` (boolean)

***

