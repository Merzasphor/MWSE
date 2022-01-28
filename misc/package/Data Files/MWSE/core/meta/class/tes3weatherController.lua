--- @meta

--- A data structure that handles the weather.
--- @class tes3weatherController
--- @field ambientPostSunriseTime number Each weather's ambiental color has one color for day and night states each. The day color will be used when the game hour is between `ambientPostSunriseTime` and `ambientPreSunsetTime`. This corresponds to the setting of the same name in Morrowind.ini file.
--- @field ambientPostSunsetTime number Each weather's ambiental color has one color for day and night states each. The night color will be used when the game hour is between `ambientPostSunsetTime` and `ambientPreSunriseTime`. This corresponds to the setting of the same name in Morrowind.ini file.
--- @field ambientPreSunriseTime number Each weather's ambiental color has one color for day and night states each. The night color will be used when the game hour is between `ambientPostSunsetTime` and `ambientPreSunriseTime`. This corresponds to the setting of the same name in Morrowind.ini file.
--- @field ambientPreSunsetTime number Each weather's ambiental color has one color for day and night states each. The day color will be used when the game hour is between `ambientPostSunriseTime` and `ambientPreSunsetTime`. This corresponds to the setting of the same name in Morrowind.ini file.
--- @field currentFogColor tes3vector3 The current fog color.
--- @field currentSkyColor tes3vector3 The current sky color.
--- @field currentWeather tes3weatherAsh|tes3weatherBlight|tes3weatherBlizzard|tes3weatherClear|tes3weatherCloudy|tes3weatherFoggy|tes3weatherOvercast|tes3weatherRain|tes3weatherSnow|tes3weatherThunder *Read-only*. The current weather.
--- @field daysRemaining number The days remaining for the current weather.
--- @field fogDepthChangeSpeed number Controls the speed of how fast the fog comes in. This corresponds to the setting of the same name in Morrowind.ini file.
--- @field fogPostSunriseTime number Each weather's fog color has one color for day and night states each. The day color will be used when the game hour is between `fogPostSunriseTime` and `fogPreSunsetTime`. This corresponds to the setting of the same name in Morrowind.ini file.
--- @field fogPostSunsetTime number Each weather's fog color has one color for day and night states each. The night color will be used when the game hour is between `fogPostSunsetTime` and `fogPreSunriseTime`. This corresponds to the setting of the same name in Morrowind.ini file.
--- @field fogPreSunriseTime number Each weather's fog color has one color for day and night states each. The night color will be used when the game hour is between `fogPostSunsetTime` and `fogPreSunriseTime`. This corresponds to the setting of the same name in Morrowind.ini file.
--- @field fogPreSunsetTime number Each weather's fog color has one color for day and night states each. The day color will be used when the game hour is between `fogPostSunriseTime` and `fogPreSunsetTime`. This corresponds to the setting of the same name in Morrowind.ini file.
--- @field hoursBetweenWeatherChanges number The hours between weather changes. Stored as a float value.
--- @field hoursRemaining number The hours remaining.
--- @field lastActiveRegion tes3region *Read-only*. Provides read-only access to last active region object.
--- @field masser tes3moon *Read-only*. Provides read-only access to the Masser moon object.
--- @field nextWeather tes3weatherAsh|tes3weatherBlight|tes3weatherBlizzard|tes3weatherClear|tes3weatherCloudy|tes3weatherFoggy|tes3weatherOvercast|tes3weatherRain|tes3weatherSnow|tes3weatherThunder *Read-only*. The next weather.
--- @field sceneRainRoot niBillboardNode|niCollisionSwitch|niNode|niSwitchNode *Read-only*. Provides read-only access to the scene rain root NiNode.
--- @field sceneSkyLight niDirectionalLight *Read-only*. Provides read-only access to the scene sky light directional light.
--- @field sceneSkyRoot niBillboardNode|niCollisionSwitch|niNode|niSwitchNode *Read-only*. Provides read-only access to the scene sky root NiNode.
--- @field sceneSnowRoot niBillboardNode|niCollisionSwitch|niNode|niSwitchNode *Read-only*. Provides read-only access to the scene snow root NiNode.
--- @field sceneStormRoot niBillboardNode|niCollisionSwitch|niNode|niSwitchNode *Read-only*. Provides read-only access to the scene storm root NiNode.
--- @field sceneSunBase niBillboardNode|niCollisionSwitch|niNode|niSwitchNode *Read-only*. Provides read-only access to the scenesun base NiNode.
--- @field sceneSunGlare niBillboardNode|niCollisionSwitch|niNode|niSwitchNode *Read-only*. Provides read-only access to the scene sun glare NiNode.
--- @field sceneSunVis niBillboardNode|niCollisionSwitch|niNode|niSwitchNode *Read-only*. Provides read-only access to the scene sun vis NiNode.
--- @field secunda tes3moon *Read-only*. Provides read-only access to the Secunda moon object.
--- @field skyPostSunriseTime number The sky has one color for day and night states each. The day color will be used when the game hour is between `skyPostSunriseTime` and `skyPreSunsetTime`. This corresponds to the setting of the same name in Morrowind.ini file.
--- @field skyPostSunsetTime number The sky has one color for day and night states each. The night color will be used when the game hour is between `skyPostSunsetTime` and `skyPreSunriseTime`. This corresponds to the setting of the same name in Morrowind.ini file.
--- @field skyPreSunriseTime number The sky has one color for day and night states each. The night color will be used when the game hour is between `skyPostSunsetTime` and `skyPreSunriseTime`. This corresponds to the setting of the same name in Morrowind.ini file.
--- @field skyPreSunsetTime number The sky has one color for day and night states each. The day color will be used when the game hour is between `skyPostSunriseTime` and `skyPreSunsetTime`. This corresponds to the setting of the same name in Morrowind.ini file.
--- @field starsFadingDuration number The stars will fade in `starsPostSunsetStart` hours after the sunset. They fade out `starsPreSunriseFinish` hours before sunrise. This value represents the duration of the fadeing. This corresponds to the setting of the same name in Morrowind.ini file.
--- @field starsPostSunsetStart number The stars will start to fade in (appear) `starsPostSunsetStart` hours before sunrise. This corresponds to the setting of the same name in Morrowind.ini file.
--- @field starsPreSunriseFinish number The stars will start to fade out (disappear) `starsPreSunriseFinish` hours before sunrise. This corresponds to the setting of the same name in Morrowind.ini file.
--- @field sunglareFaderAngleMax number The sunglare fader maximum angle.
--- @field sunglareFaderColor tes3vector3 The sunglare fader color.
--- @field sunglareFaderMax number The sunglare fader maximum.
--- @field sunPostSunriseTime number The Sun has one color for day and night states each. The day color will be used when the game hour is between `sunPostSunriseTime` and `sunPreSunsetTime`. This corresponds to the setting of the same name in Morrowind.ini file.
--- @field sunPostSunsetTime number The Sun has one color for day and night states each. The night color will be used when the game hour is between `sunPostSunsetTime` and `sunPreSunriseTime`. This corresponds to the setting of the same name in Morrowind.ini file.
--- @field sunPreSunriseTime number The Sun has one color for day and night states each. The night color will be used when the game hour is between `sunPostSunsetTime` and `sunPreSunriseTime`. This corresponds to the setting of the same name in Morrowind.ini file.
--- @field sunPreSunsetTime number The Sun has one color for day and night states each. The day color will be used when the game hour is between `sunPostSunriseTime` and `sunPreSunsetTime`. This corresponds to the setting of the same name in Morrowind.ini file.
--- @field sunriseDuration number The sunrise duration.
--- @field sunriseHour number The sunrise hour.
--- @field sunsetDuration number The sunset duration.
--- @field sunsetHour number The sunset hour.
--- @field timescaleClouds string The timescale for clouds.
--- @field transitionScalar number The scalar transition.
--- @field underwaterColor tes3vector3 The underwater color, represented as a vector.
--- @field underwaterColorWeight number The underwater color weight.
--- @field underwaterDayFog number The underwater day fog value.
--- @field underwaterIndoorFog number The underwater indoor fog value.
--- @field underwaterNightFog number The underwater night fog value.
--- @field underwaterSunriseFog number The underwater sunrise fog value.
--- @field underwaterSunsetFog number The underwater sunset fog value.
--- @field weathers table *Read-only*. Array-style table for the different weather types. Each object in the table is a tes3weather.
--- @field windVelocityCurrWeather tes3vector3 The wind velocity for the current weather.
--- @field windVelocityNextWeather tes3vector3 The wind velocity for the next weather.
tes3weatherController = {}

--- Calculates the sun damage based on the current weather.
--- @return number result No description yet available.
function tes3weatherController:calcSunDamageScalar() end

--- Immediately switches the weather to the provided weather parameter.
--- @param weatherId number No description yet available.
function tes3weatherController:switchImmediate(weatherId) end

--- Transitions the weather to the provided weather parameter based on the weather controller settings.
--- @param weatherId number No description yet available.
function tes3weatherController:switchTransition(weatherId) end

--- Updates the weather controller visuals. This should be called after any weather transitions.
function tes3weatherController:updateVisuals() end

