# tes3weatherController

A data structure that handles the weather.

## Properties

### `ambientPostSunriseTime`

Each weather's ambiental color has one color for day and night states each. The day color will be used when the game hour is between `ambientPostSunriseTime` and `ambientPreSunsetTime`. This corresponds to the setting of the same name in Morrowind.ini file.

**Returns**:

* `result` (number)

***

### `ambientPostSunsetTime`

Each weather's ambiental color has one color for day and night states each. The night color will be used when the game hour is between `ambientPostSunsetTime` and `ambientPreSunriseTime`. This corresponds to the setting of the same name in Morrowind.ini file.

**Returns**:

* `result` (number)

***

### `ambientPreSunriseTime`

Each weather's ambiental color has one color for day and night states each. The night color will be used when the game hour is between `ambientPostSunsetTime` and `ambientPreSunriseTime`. This corresponds to the setting of the same name in Morrowind.ini file.

**Returns**:

* `result` (number)

***

### `ambientPreSunsetTime`

Each weather's ambiental color has one color for day and night states each. The day color will be used when the game hour is between `ambientPostSunriseTime` and `ambientPreSunsetTime`. This corresponds to the setting of the same name in Morrowind.ini file.

**Returns**:

* `result` (number)

***

### `currentFogColor`

The current fog color.

**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

***

### `currentSkyColor`

The current sky color.

**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

***

### `currentWeather`

*Read-only*. The current weather.

**Returns**:

* `result` ([tes3weather](../../types/tes3weather))

***

### `daysRemaining`

The days remaining for the current weather.

**Returns**:

* `result` (number)

***

### `fogDepthChangeSpeed`

Controls the speed of how fast the fog comes in. This corresponds to the setting of the same name in Morrowind.ini file.

**Returns**:

* `result` (number)

***

### `fogPostSunriseTime`

Each weather's fog color has one color for day and night states each. The day color will be used when the game hour is between `fogPostSunriseTime` and `fogPreSunsetTime`. This corresponds to the setting of the same name in Morrowind.ini file.

**Returns**:

* `result` (number)

***

### `fogPostSunsetTime`

Each weather's fog color has one color for day and night states each. The night color will be used when the game hour is between `fogPostSunsetTime` and `fogPreSunriseTime`. This corresponds to the setting of the same name in Morrowind.ini file.

**Returns**:

* `result` (number)

***

### `fogPreSunriseTime`

Each weather's fog color has one color for day and night states each. The night color will be used when the game hour is between `fogPostSunsetTime` and `fogPreSunriseTime`. This corresponds to the setting of the same name in Morrowind.ini file.

**Returns**:

* `result` (number)

***

### `fogPreSunsetTime`

Each weather's fog color has one color for day and night states each. The day color will be used when the game hour is between `fogPostSunriseTime` and `fogPreSunsetTime`. This corresponds to the setting of the same name in Morrowind.ini file.

**Returns**:

* `result` (number)

***

### `hoursBetweenWeatherChanges`

The hours between weather changes. Stored as a float value.

**Returns**:

* `result` (number)

***

### `hoursRemaining`

The hours remaining.

**Returns**:

* `result` (number)

***

### `lastActiveRegion`

*Read-only*. Provides read-only access to last active region object.

**Returns**:

* `result` ([tes3region](../../types/tes3region))

***

### `masser`

*Read-only*. Provides read-only access to the Masser moon object.

**Returns**:

* `result` ([tes3moon](../../types/tes3moon))

***

### `nextWeather`

*Read-only*. The next weather.

**Returns**:

* `result` ([tes3weather](../../types/tes3weather))

***

### `sceneRainRoot`

*Read-only*. Provides read-only access to the scene rain root NiNode.

**Returns**:

* `result` ([niNode](../../types/niNode))

***

### `sceneSkyLight`

*Read-only*. Provides read-only access to the scene sky light directional light.

**Returns**:

* `result` ([niDirectionalLight](../../types/niDirectionalLight))

***

### `sceneSkyRoot`

*Read-only*. Provides read-only access to the scene sky root NiNode.

**Returns**:

* `result` ([niNode](../../types/niNode))

***

### `sceneSnowRoot`

*Read-only*. Provides read-only access to the scene snow root NiNode.

**Returns**:

* `result` ([niNode](../../types/niNode))

***

### `sceneStormRoot`

*Read-only*. Provides read-only access to the scene storm root NiNode.

**Returns**:

* `result` ([niNode](../../types/niNode))

***

### `sceneSunBase`

*Read-only*. Provides read-only access to the scenesun base NiNode.

**Returns**:

* `result` ([niNode](../../types/niNode))

***

### `sceneSunGlare`

*Read-only*. Provides read-only access to the scene sun glare NiNode.

**Returns**:

* `result` ([niNode](../../types/niNode))

***

### `sceneSunVis`

*Read-only*. Provides read-only access to the scene sun vis NiNode.

**Returns**:

* `result` ([niNode](../../types/niNode))

***

### `secunda`

*Read-only*. Provides read-only access to the Secunda moon object.

**Returns**:

* `result` ([tes3moon](../../types/tes3moon))

***

### `skyPostSunriseTime`

The sky has one color for day and night states each. The day color will be used when the game hour is between `skyPostSunriseTime` and `skyPreSunsetTime`. This corresponds to the setting of the same name in Morrowind.ini file.

**Returns**:

* `result` (number)

***

### `skyPostSunsetTime`

The sky has one color for day and night states each. The night color will be used when the game hour is between `skyPostSunsetTime` and `skyPreSunriseTime`. This corresponds to the setting of the same name in Morrowind.ini file.

**Returns**:

* `result` (number)

***

### `skyPreSunriseTime`

The sky has one color for day and night states each. The night color will be used when the game hour is between `skyPostSunsetTime` and `skyPreSunriseTime`. This corresponds to the setting of the same name in Morrowind.ini file.

**Returns**:

* `result` (number)

***

### `skyPreSunsetTime`

The sky has one color for day and night states each. The day color will be used when the game hour is between `skyPostSunriseTime` and `skyPreSunsetTime`. This corresponds to the setting of the same name in Morrowind.ini file.

**Returns**:

* `result` (number)

***

### `starsFadingDuration`

The stars will fade in `starsPostSunsetStart` hours after the sunset. They fade out `starsPreSunriseFinish` hours before sunrise. This value represents the duration of the fadeing. This corresponds to the setting of the same name in Morrowind.ini file.

**Returns**:

* `result` (number)

***

### `starsPostSunsetStart`

The stars will start to fade in (appear) `starsPostSunsetStart` hours before sunrise. This corresponds to the setting of the same name in Morrowind.ini file.

**Returns**:

* `result` (number)

***

### `starsPreSunriseFinish`

The stars will start to fade out (disappear) `starsPreSunriseFinish` hours before sunrise. This corresponds to the setting of the same name in Morrowind.ini file.

**Returns**:

* `result` (number)

***

### `sunglareFaderAngleMax`

The sunglare fader maximum angle.

**Returns**:

* `result` (number)

***

### `sunglareFaderColor`

The sunglare fader color.

**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

***

### `sunglareFaderMax`

The sunglare fader maximum.

**Returns**:

* `result` (number)

***

### `sunPostSunriseTime`

The Sun has one color for day and night states each. The day color will be used when the game hour is between `sunPostSunriseTime` and `sunPreSunsetTime`. This corresponds to the setting of the same name in Morrowind.ini file.

**Returns**:

* `result` (number)

***

### `sunPostSunsetTime`

The Sun has one color for day and night states each. The night color will be used when the game hour is between `sunPostSunsetTime` and `sunPreSunriseTime`. This corresponds to the setting of the same name in Morrowind.ini file.

**Returns**:

* `result` (number)

***

### `sunPreSunriseTime`

The Sun has one color for day and night states each. The night color will be used when the game hour is between `sunPostSunsetTime` and `sunPreSunriseTime`. This corresponds to the setting of the same name in Morrowind.ini file.

**Returns**:

* `result` (number)

***

### `sunPreSunsetTime`

The Sun has one color for day and night states each. The day color will be used when the game hour is between `sunPostSunriseTime` and `sunPreSunsetTime`. This corresponds to the setting of the same name in Morrowind.ini file.

**Returns**:

* `result` (number)

***

### `sunriseDuration`

The sunrise duration.

**Returns**:

* `result` (number)

***

### `sunriseHour`

The sunrise hour.

**Returns**:

* `result` (number)

***

### `sunsetDuration`

The sunset duration.

**Returns**:

* `result` (number)

***

### `sunsetHour`

The sunset hour.

**Returns**:

* `result` (number)

***

### `timescaleClouds`

The timescale for clouds.

**Returns**:

* `result` (string)

***

### `transitionScalar`

The scalar transition.

**Returns**:

* `result` (number)

***

### `underwaterColor`

The underwater color, represented as a vector.

**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

***

### `underwaterColorWeight`

The underwater color weight.

**Returns**:

* `result` (number)

***

### `underwaterDayFog`

The underwater day fog value.

**Returns**:

* `result` (number)

***

### `underwaterIndoorFog`

The underwater indoor fog value.

**Returns**:

* `result` (number)

***

### `underwaterNightFog`

The underwater night fog value.

**Returns**:

* `result` (number)

***

### `underwaterSunriseFog`

The underwater sunrise fog value.

**Returns**:

* `result` (number)

***

### `underwaterSunsetFog`

The underwater sunset fog value.

**Returns**:

* `result` (number)

***

### `weathers`

*Read-only*. Array-style table for the different weather types. Each object in the table is a tes3weather.

**Returns**:

* `result` (table)

***

### `windVelocityCurrWeather`

The wind velocity for the current weather.

**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

***

### `windVelocityNextWeather`

The wind velocity for the next weather.

**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

***

## Methods

### `calcSunDamageScalar`

Calculates the sun damage based on the current weather.

```lua
local result = tes3weatherController:calcSunDamageScalar()
```

**Parameters**:


**Returns**:

* `result` (number)

***

### `switchImmediate`

Immediately switches the weather to the provided weather parameter.

```lua
tes3weatherController:switchImmediate(weatherId)
```

**Parameters**:

* `weatherId` (number)

***

### `switchTransition`

Transitions the weather to the provided weather parameter based on the weather controller settings.

```lua
tes3weatherController:switchTransition(weatherId)
```

**Parameters**:

* `weatherId` (number)

***

### `updateVisuals`

Updates the weather controller visuals. This should be called after any weather transitions.

```lua
tes3weatherController:updateVisuals()
```

**Parameters**:


***

