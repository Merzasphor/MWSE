# tes3region

A structure that contains region information.

This type inherits the following: [tes3baseObject](../../types/tes3baseObject)
## Properties

### `blocked`

The blocked state of the object.

**Returns**:

* `result` (boolean)

***

### `deleted`

*Read-only*. The deleted state of the object.

**Returns**:

* `result` (boolean)

***

### `disabled`

*Read-only*. The disabled state of the object.

**Returns**:

* `result` (boolean)

***

### `id`

*Read-only*. The unique identifier for the object.

**Returns**:

* `result` (string)

***

### `modified`

The modification state of the object since the last save.

**Returns**:

* `result` (boolean)

***

### `name`

The region's name. It must be a string less than 32 characters long.

**Returns**:

* `result` (string)

***

### `objectFlags`

*Read-only*. The raw flags of the object.

**Returns**:

* `result` (number)

***

### `objectType`

*Read-only*. The type of object. Maps to values in [`tes3.objectType`](https://mwse.github.io/MWSE/references/object-types/).

**Returns**:

* `result` (number)

***

### `persistent`

The persistent flag of the object.

**Returns**:

* `result` (boolean)

***

### `sleepCreature`

*Read-only*. The region's leveled creature that can be spawned while the player is sleeping.

**Returns**:

* `result` ([tes3leveledCreature](../../types/tes3leveledCreature))

***

### `sounds`

*Read-only*. Array-style table for the different region sounds. Each object in the table is a [`tes3regionSound`](https://mwse.github.io/MWSE/types/tes3regionSound/).

**Returns**:

* `result` (table)

***

### `sourceless`

The soruceless flag of the object.

**Returns**:

* `result` (boolean)

***

### `sourceMod`

*Read-only*. The filename of the mod that owns this object.

**Returns**:

* `result` (string)

***

### `supportsLuaData`

If true, references of this object can store temporary or persistent lua data.

**Returns**:

* `result` (boolean)

***

### `weather`

The region's current weather.

**Returns**:

* `result` ([tes3weather](../../types/tes3weather))

***

### `weatherChanceAsh`

The chance the Ash weather-type will be used. Must be an integer between 0 - 100.

**Returns**:

* `result` (number)

***

### `weatherChanceBlight`

The chance the Blight weather-type will be used. Must be an integer between 0 - 100.

**Returns**:

* `result` (number)

***

### `weatherChanceBlizzard`

The chance the Blizzard weather-type will be used. Must be an integer between 0 - 100.

**Returns**:

* `result` (number)

***

### `weatherChanceClear`

The chance the Clear weather-type will be used. Must be an integer between 0 - 100.

**Returns**:

* `result` (number)

***

### `weatherChanceCloudy`

The chance the Cloudy weather-type will be used. Must be an integer between 0 - 100.

**Returns**:

* `result` (number)

***

### `weatherChanceFoggy`

The chance the Foggy weather-type will be used. Must be an integer between 0 - 100.

**Returns**:

* `result` (number)

***

### `weatherChanceOvercast`

The chance the Overcast weather-type will be used. Must be an integer between 0 - 100.

**Returns**:

* `result` (number)

***

### `weatherChanceRain`

The chance the Rain weather-type will be used. Must be an integer between 0 - 100.

**Returns**:

* `result` (number)

***

### `weatherChances`

*Read-only*. Array-style table for the different weather chances. Each object in the table is a number, between 1 - 100. The index of the table is the weather type.

**Returns**:

* `result` (table)

***

### `weatherChanceSnow`

The chance the Snow weather-type will be used. Must be an integer between 0 - 100.

**Returns**:

* `result` (number)

***

### `weatherChanceThunder`

The chance the Thunder weather-type will be used. Must be an integer between 0 - 100.

**Returns**:

* `result` (number)

***

## Methods

### `__tojson`

Serializes the object to json.

```lua
local string = tes3baseObject:__tojson()
```

**Returns**:

* `string` (string)

***

### `changeWeather`

Changes the current weather for the region to the provided weather-type parameter.

```lua
tes3region:changeWeather(weatherId)
```

**Parameters**:

* `weatherId` (number): Maps to values in [`tes3.weather`](https://mwse.github.io/MWSE/references/weather-types/) namespace.

***

### `randomizeWeather`

Changes the weather to a random weather type.

```lua
tes3region:randomizeWeather()
```

**Parameters**:


***

