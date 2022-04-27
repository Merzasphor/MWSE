--- @meta
--- @diagnostic disable:undefined-doc-name

--- The mge library allows MGE XE mwscript functions to be called. This is not always ideal, and this library is deprecated.
--- @class mgelib
mge = {}

--- Clears elements from the HUD. Wrapper for MGEWipeHUDElements.
function mge.clearHUD() end

--- Disables MGE XE's camera shake effect. Wrapper for mwscript's MGEDisableCameraShake.
function mge.disableCameraShake() end

--- Disables a HUD element. If a HUD ID is provided, this is a warpper for MGEDisableHUD, otherwise it is a wrapper for MGENIDDisableHUD.
--- @param params mge.disableHUD.params This table accepts the following values:
--- 
--- `hud`: string? — *Optional*. No description yet available.
function mge.disableHUD(params) end

---Table parameter definitions for `mge.disableHUD`.
--- @class mge.disableHUD.params
--- @field hud string? *Optional*. No description yet available.

--- Disables a shader. Wrapper for mwscript's MGEDisableShader.
--- @param params mge.disableShader.params This table accepts the following values:
--- 
--- `shader`: string — No description yet available.
function mge.disableShader(params) end

---Table parameter definitions for `mge.disableShader`.
--- @class mge.disableShader.params
--- @field shader string No description yet available.

--- Disables the MGE XE zoom effect. Wrapper for MGEDisableZoom.
function mge.disableZoom() end

--- Enables MGE XE's camera shake effect. Wrapper for mwscript's MGEEnableCameraShake.
--- @param params mge.enableCameraShake.params This table accepts the following values:
--- 
--- `magnitude`: number? — *Optional*. No description yet available.
--- 
--- `acceleration`: number? — *Optional*. No description yet available.
function mge.enableCameraShake(params) end

---Table parameter definitions for `mge.enableCameraShake`.
--- @class mge.enableCameraShake.params
--- @field magnitude number? *Optional*. No description yet available.
--- @field acceleration number? *Optional*. No description yet available.

--- Determines if the MGE XE interface is enabled.
--- @return boolean enabled No description yet available.
function mge.enabled() end

--- Enables a HUD element. If a HUD ID is provided, this is a warpper for MGEEnableHUD, otherwise it is a wrapper for MGENIDEnableHUD.
--- @param params mge.enableHUD.params This table accepts the following values:
--- 
--- `hud`: string? — *Optional*. No description yet available.
function mge.enableHUD(params) end

---Table parameter definitions for `mge.enableHUD`.
--- @class mge.enableHUD.params
--- @field hud string? *Optional*. No description yet available.

--- Enables a shader. Wrapper for mwscript's MGEEnableShader.
--- @param params mge.enableShader.params This table accepts the following values:
--- 
--- `shader`: string — No description yet available.
function mge.enableShader(params) end

---Table parameter definitions for `mge.enableShader`.
--- @class mge.enableShader.params
--- @field shader string No description yet available.

--- Enables the MGE XE zoom effect. Wrapper for MGEEnableZoom.
function mge.enableZoom() end

--- Frees a HUD element. If a HUD ID is provided, this is a warpper for MGEFreeHUD, otherwise it is a wrapper for MGENIDFreeHUD.
--- @param params mge.freeHUD.params This table accepts the following values:
--- 
--- `hud`: string? — *Optional*. No description yet available.
function mge.freeHUD(params) end

---Table parameter definitions for `mge.freeHUD`.
--- @class mge.freeHUD.params
--- @field hud string? *Optional*. No description yet available.

--- Makes a HUD element fullscreen. If a HUD ID is provided, this is a warpper for MGEFullscreenHUD, otherwise it is a wrapper for MGENIDFullscreenHUD.
--- @param params mge.fullscreenHUD.params This table accepts the following values:
--- 
--- `hud`: string? — *Optional*. No description yet available.
function mge.fullscreenHUD(params) end

---Table parameter definitions for `mge.fullscreenHUD`.
--- @class mge.fullscreenHUD.params
--- @field hud string? *Optional*. No description yet available.

--- Gets the window's vertical resolution. Wrapper for mwscript's MGEGetHeight.
--- @return number result No description yet available.
function mge.getScreenHeight() end

--- Wrapper for MGEGetScreenRotation.
--- @return number result No description yet available.
function mge.getScreenRotation() end

--- Gets the window's horizontal resolution. Wrapper for mwscript's MGEGetWidth.
--- @return number result No description yet available.
function mge.getScreenWidth() end

--- Returns the UI scaling used.
--- @return number result No description yet available.
function mge.getUIScale() end

--- Gets the MGE version. Wrapper for MGEGetVersion.
--- @return number result No description yet available.
function mge.getVersion() end

--- Gets distant land fog parameters for a specific weather. See [`mge.setWeatherDLFog()`](https://mwse.github.io/MWSE/apis/mge/#mgesetweatherdlfog).
--- @param weatherID number Maps to values in the [`tes3.weather`](https://mwse.github.io/MWSE/references/weathers/) table.
--- @return table parameters An array-style table with `fogDistMultiplier` and `fogOffsetPercent` parameters.
function mge.getWeatherDLFog(weatherID) end

--- Gets per-pixel lighting parameters for a specific weather. See [`mge.setWeatherPPLLight()`](https://mwse.github.io/MWSE/apis/mge/#mgesetweatherppllight).
--- @param weatherID number Maps to values in the [`tes3.weather`](https://mwse.github.io/MWSE/references/weathers/) table.
--- @return table parameters An array-style table with `sunMultiplier` and `ambientMultiplier` parameters.
function mge.getWeatherPPLLight(weatherID) end

--- Returns an array-style table with 3 distant land atmospheric scattering colours.
--- @return table scattering No description yet available.
function mge.getWeatherScattering() end

--- Wrapper for MGEGetZoom.
--- @return number result No description yet available.
function mge.getZoom() end

--- Loads a HUD element. This is a warpper for MGELoadHUD.
--- @param params mge.loadHUD.params This table accepts the following values:
--- 
--- `hud`: string — No description yet available.
--- 
--- `texture`: string — No description yet available.
--- 
--- `enable`: boolean? — *Optional*. No description yet available.
function mge.loadHUD(params) end

---Table parameter definitions for `mge.loadHUD`.
--- @class mge.loadHUD.params
--- @field hud string No description yet available.
--- @field texture string No description yet available.
--- @field enable boolean? *Optional*. No description yet available.

--- This function writes information to the mgeXE.log file in the user's installation directory. Wrapper for mwscript's MGELog function.
--- @param message string No description yet available.
function mge.log(message) end

--- Wrapper for MGERotateScreenBy.
--- @param params mge.modScreenRotation.params This table accepts the following values:
--- 
--- `rotation`: number — No description yet available.
function mge.modScreenRotation(params) end

---Table parameter definitions for `mge.modScreenRotation`.
--- @class mge.modScreenRotation.params
--- @field rotation number No description yet available.

--- Positions a HUD element. If a HUD ID is provided, this is a warpper for MGEPositionHUD, otherwise it is a wrapper for MGENIDPositionHUD.
--- @param params mge.positionHUD.params This table accepts the following values:
--- 
--- `hud`: string? — *Optional*. No description yet available.
--- 
--- `x`: number — No description yet available.
--- 
--- `y`: number — No description yet available.
function mge.positionHUD(params) end

---Table parameter definitions for `mge.positionHUD`.
--- @class mge.positionHUD.params
--- @field hud string? *Optional*. No description yet available.
--- @field x number No description yet available.
--- @field y number No description yet available.

--- Scales a HUD element. If a HUD ID is provided, this is a warpper for MGEScaleHUD, otherwise it is a wrapper for MGENIDScaleHUD.
--- @param params mge.scaleHUD.params This table accepts the following values:
--- 
--- `hud`: string? — *Optional*. No description yet available.
--- 
--- `x`: number — No description yet available.
--- 
--- `y`: number — No description yet available.
function mge.scaleHUD(params) end

---Table parameter definitions for `mge.scaleHUD`.
--- @class mge.scaleHUD.params
--- @field hud string? *Optional*. No description yet available.
--- @field x number No description yet available.
--- @field y number No description yet available.

--- Selects a HUD element, to assume for future HUD calls.
--- @param params mge.selectHUD.params This table accepts the following values:
--- 
--- `hud`: string? — *Optional*. No description yet available.
function mge.selectHUD(params) end

---Table parameter definitions for `mge.selectHUD`.
--- @class mge.selectHUD.params
--- @field hud string? *Optional*. No description yet available.

--- Wrapper for MGECameraShakeZoom.
--- @param params mge.setCameraShakeAcceleration.params This table accepts the following values:
--- 
--- `acceleration`: number — No description yet available.
function mge.setCameraShakeAcceleration(params) end

---Table parameter definitions for `mge.setCameraShakeAcceleration`.
--- @class mge.setCameraShakeAcceleration.params
--- @field acceleration number No description yet available.

--- Wrapper for MGESetCameraShakeMagnitude.
--- @param params mge.setCameraShakeMagnitude.params This table accepts the following values:
--- 
--- `magnitude`: number — No description yet available.
function mge.setCameraShakeMagnitude(params) end

---Table parameter definitions for `mge.setCameraShakeMagnitude`.
--- @class mge.setCameraShakeMagnitude.params
--- @field magnitude number No description yet available.

--- Sets the effect for a HUD element. If a HUD ID is provided, this is a warpper for MGEChangeHUDEffect, otherwise it is a wrapper for MGENIDChangeHUDEffect.
--- @param params mge.setHUDEffect.params This table accepts the following values:
--- 
--- `hud`: string? — *Optional*. No description yet available.
--- 
--- `effect`: string — No description yet available.
function mge.setHUDEffect(params) end

---Table parameter definitions for `mge.setHUDEffect`.
--- @class mge.setHUDEffect.params
--- @field hud string? *Optional*. No description yet available.
--- @field effect string No description yet available.

--- Sets the effect float variable for a HUD element. This is a wrapper for MGENIDSetHUDEffectFloat.
--- @param params mge.setHUDEffectFloat.params This table accepts the following values:
--- 
--- `hud`: string? — *Optional*. No description yet available.
--- 
--- `variable`: string — No description yet available.
--- 
--- `value`: number — No description yet available.
function mge.setHUDEffectFloat(params) end

---Table parameter definitions for `mge.setHUDEffectFloat`.
--- @class mge.setHUDEffectFloat.params
--- @field hud string? *Optional*. No description yet available.
--- @field variable string No description yet available.
--- @field value number No description yet available.

--- Sets the effect long variable for a HUD element. This is a wrapper for MGENIDSetHUDEffectLong.
--- @param params mge.setHUDEffectLong.params This table accepts the following values:
--- 
--- `hud`: string? — *Optional*. No description yet available.
--- 
--- `variable`: string — No description yet available.
--- 
--- `value`: number — No description yet available.
function mge.setHUDEffectLong(params) end

---Table parameter definitions for `mge.setHUDEffectLong`.
--- @class mge.setHUDEffectLong.params
--- @field hud string? *Optional*. No description yet available.
--- @field variable string No description yet available.
--- @field value number No description yet available.

--- Sets the effect vector variable for a HUD element. This is a wrapper for MGENIDSetHUDEffectVec.
--- @param params mge.setHUDEffectVector4.params This table accepts the following values:
--- 
--- `hud`: string? — *Optional*. No description yet available.
--- 
--- `variable`: string — No description yet available.
--- 
--- `value`: table — A table of 4 values.
function mge.setHUDEffectVector4(params) end

---Table parameter definitions for `mge.setHUDEffectVector4`.
--- @class mge.setHUDEffectVector4.params
--- @field hud string? *Optional*. No description yet available.
--- @field variable string No description yet available.
--- @field value table A table of 4 values.

--- Sets the texture for a given HUD element. If a HUD ID is provided, this is a warpper for MGEChangeHUDTexture, otherwise it is a wrapper for MGENIDChangeHUDTexture.
--- @param params mge.setHUDTexture.params This table accepts the following values:
--- 
--- `hud`: string — No description yet available.
--- 
--- `texture`: string — No description yet available.
function mge.setHUDTexture(params) end

---Table parameter definitions for `mge.setHUDTexture`.
--- @class mge.setHUDTexture.params
--- @field hud string No description yet available.
--- @field texture string No description yet available.

--- Wrapper for MGERotateScreen.
--- @param params mge.setScreenRotation.params This table accepts the following values:
--- 
--- `rotation`: number — No description yet available.
function mge.setScreenRotation(params) end

---Table parameter definitions for `mge.setScreenRotation`.
--- @class mge.setScreenRotation.params
--- @field rotation number No description yet available.

--- Sets a shader's float variable. Wrapper for mwscript's MGEShaderSetFloat.
--- @param params mge.setShaderFloat.params This table accepts the following values:
--- 
--- `shader`: string — No description yet available.
--- 
--- `variable`: string — No description yet available.
--- 
--- `value`: number — No description yet available.
function mge.setShaderFloat(params) end

---Table parameter definitions for `mge.setShaderFloat`.
--- @class mge.setShaderFloat.params
--- @field shader string No description yet available.
--- @field variable string No description yet available.
--- @field value number No description yet available.

--- Sets a shader's long variable. Wrapper for mwscript's MGEShaderSetLong.
--- @param params mge.setShaderLong.params This table accepts the following values:
--- 
--- `shader`: string — No description yet available.
--- 
--- `variable`: string — No description yet available.
--- 
--- `value`: number — No description yet available.
function mge.setShaderLong(params) end

---Table parameter definitions for `mge.setShaderLong`.
--- @class mge.setShaderLong.params
--- @field shader string No description yet available.
--- @field variable string No description yet available.
--- @field value number No description yet available.

--- Sets a shader's vector variable. Wrapper for mwscript's MGEShaderSetVector.
--- @param params mge.setShaderVector4.params This table accepts the following values:
--- 
--- `shader`: string — No description yet available.
--- 
--- `variable`: string — No description yet available.
--- 
--- `value`: table — A table of 4 values.
function mge.setShaderVector4(params) end

---Table parameter definitions for `mge.setShaderVector4`.
--- @class mge.setShaderVector4.params
--- @field shader string No description yet available.
--- @field variable string No description yet available.
--- @field value table A table of 4 values.

--- Sets distant land fog parameters for a specific weather. `fogDistMultiplier` is multiplied by the "Above water fog" distance to get the fog distance for that weather. It has a range of [0, 2]. `fogOffsetPercent` is the percentage of fog applied at zero distance from the camera. It has a range of [0, 90].
--- 
--- Note: "Above water fog" is a setting specific to MGE XE. It can be found on the Distant Land page, under Fog category.
--- @param weatherID number Maps to values in the [`tes3.weather`](https://mwse.github.io/MWSE/references/weathers/) table.
--- @param fogDistMultiplier number No description yet available.
--- @param fogOffsetPercent number No description yet available.
--- @return number result No description yet available.
function mge.setWeatherDLFog(weatherID, fogDistMultiplier, fogOffsetPercent) end

--- Sets light multipliers used in per-pixel lighting for a specific weather. `sunMultiplier` affects sunlight, while `ambientMultiplier` affects ambient lighting.
--- @param weatherID number Maps to values in the [`tes3.weather`](https://mwse.github.io/MWSE/references/weathers/) table.
--- @param sunMultiplier number No description yet available.
--- @param ambientMultiplier number No description yet available.
--- @return number result No description yet available.
function mge.setWeatherPPLLight(weatherID, sunMultiplier, ambientMultiplier) end

--- Sets distant land atmospheric scattering colours.
--- @param params mge.setWeatherScattering.params This table accepts the following values:
--- 
--- `outscatter`: table — An array-style table with 3 numbers for red, green and blue color channels. The values can range from 0 to 1.
--- 
--- `inscatter`: table — An array-style table with 3 numbers for red, green and blue color channels. The values can range from 0 to 1.
--- @return boolean success No description yet available.
function mge.setWeatherScattering(params) end

---Table parameter definitions for `mge.setWeatherScattering`.
--- @class mge.setWeatherScattering.params
--- @field outscatter table An array-style table with 3 numbers for red, green and blue color channels. The values can range from 0 to 1.
--- @field inscatter table An array-style table with 3 numbers for red, green and blue color channels. The values can range from 0 to 1.

--- Wrapper for MGEZoom, or MGESetZoom if set to animate.
--- @param params mge.setZoom.params This table accepts the following values:
--- 
--- `amount`: number — No description yet available.
--- 
--- `animate`: boolean? — *Default*: `false`. No description yet available.
function mge.setZoom(params) end

---Table parameter definitions for `mge.setZoom`.
--- @class mge.setZoom.params
--- @field amount number No description yet available.
--- @field animate boolean? *Default*: `false`. No description yet available.

--- Enables MGE XE's screen spin effect. Wrapper for mwscript's MGEScreenSpin.
function mge.startScreenRotation() end

--- Disables MGE XE's screen spin effect. Wrapper for mwscript's MGEStopSpinSpin.
function mge.stopScreenRotation() end

--- Wrapper for MGEStopZoom.
function mge.stopZoom() end

--- Toggles the MGE XE zoom effect. Wrapper for MGEToggleZoom.
function mge.toggleZoom() end

--- Cancels selection for a HUD element. Wrapper for mwscript's MGECancelWithHUD.
--- @param params mge.unselectHUD.params This table accepts the following values:
--- 
--- `hud`: string — No description yet available.
function mge.unselectHUD(params) end

---Table parameter definitions for `mge.unselectHUD`.
--- @class mge.unselectHUD.params
--- @field hud string No description yet available.

--- Wrapper for MGEZoomIn, or MGEZoomInBy if an amount is provided.
--- @param params mge.zoomIn.params This table accepts the following values:
--- 
--- `amount`: number? — *Optional*. No description yet available.
function mge.zoomIn(params) end

---Table parameter definitions for `mge.zoomIn`.
--- @class mge.zoomIn.params
--- @field amount number? *Optional*. No description yet available.

--- Wrapper for MGEZoomOut, or MGEZoomOutBy if an amount is provided.
--- @param params mge.zoomOut.params This table accepts the following values:
--- 
--- `amount`: number? — *Optional*. No description yet available.
function mge.zoomOut(params) end

---Table parameter definitions for `mge.zoomOut`.
--- @class mge.zoomOut.params
--- @field amount number? *Optional*. No description yet available.

