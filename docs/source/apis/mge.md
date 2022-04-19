# mge

The mge library allows MGE XE mwscript functions to be called. This is not always ideal, and this library is deprecated.

## Functions

### `mge.clearHUD`

Clears elements from the HUD. Wrapper for MGEWipeHUDElements.

```lua
mge.clearHUD()
```

***

### `mge.disableCameraShake`

Disables MGE XE's camera shake effect. Wrapper for mwscript's MGEDisableCameraShake.

```lua
mge.disableCameraShake()
```

***

### `mge.disableHUD`

Disables a HUD element. If a HUD ID is provided, this is a warpper for MGEDisableHUD, otherwise it is a wrapper for MGENIDDisableHUD.

```lua
mge.disableHUD({ hud = ... })
```

**Parameters**:

* `params` (table)
	* `hud` (string): *Optional*.

***

### `mge.disableShader`

Disables a shader. Wrapper for mwscript's MGEDisableShader.

```lua
mge.disableShader({ shader = ... })
```

**Parameters**:

* `params` (table)
	* `shader` (string)

***

### `mge.disableZoom`

Disables the MGE XE zoom effect. Wrapper for MGEDisableZoom.

```lua
mge.disableZoom()
```

***

### `mge.enableCameraShake`

Enables MGE XE's camera shake effect. Wrapper for mwscript's MGEEnableCameraShake.

```lua
mge.enableCameraShake({ magnitude = ..., acceleration = ... })
```

**Parameters**:

* `params` (table)
	* `magnitude` (number): *Optional*.
	* `acceleration` (number): *Optional*.

***

### `mge.enabled`

Determines if the MGE XE interface is enabled.

```lua
local enabled = mge.enabled()
```

**Returns**:

* `enabled` (boolean)

***

### `mge.enableHUD`

Enables a HUD element. If a HUD ID is provided, this is a warpper for MGEEnableHUD, otherwise it is a wrapper for MGENIDEnableHUD.

```lua
mge.enableHUD({ hud = ... })
```

**Parameters**:

* `params` (table)
	* `hud` (string): *Optional*.

***

### `mge.enableShader`

Enables a shader. Wrapper for mwscript's MGEEnableShader.

```lua
mge.enableShader({ shader = ... })
```

**Parameters**:

* `params` (table)
	* `shader` (string)

***

### `mge.enableZoom`

Enables the MGE XE zoom effect. Wrapper for MGEEnableZoom.

```lua
mge.enableZoom()
```

***

### `mge.freeHUD`

Frees a HUD element. If a HUD ID is provided, this is a warpper for MGEFreeHUD, otherwise it is a wrapper for MGENIDFreeHUD.

```lua
mge.freeHUD({ hud = ... })
```

**Parameters**:

* `params` (table)
	* `hud` (string): *Optional*.

***

### `mge.fullscreenHUD`

Makes a HUD element fullscreen. If a HUD ID is provided, this is a warpper for MGEFullscreenHUD, otherwise it is a wrapper for MGENIDFullscreenHUD.

```lua
mge.fullscreenHUD({ hud = ... })
```

**Parameters**:

* `params` (table)
	* `hud` (string): *Optional*.

***

### `mge.getScreenHeight`

Gets the window's vertical resolution. Wrapper for mwscript's MGEGetHeight.

```lua
local result = mge.getScreenHeight()
```

**Returns**:

* `result` (number)

***

### `mge.getScreenRotation`

Wrapper for MGEGetScreenRotation.

```lua
local result = mge.getScreenRotation()
```

**Returns**:

* `result` (number)

***

### `mge.getScreenWidth`

Gets the window's horizontal resolution. Wrapper for mwscript's MGEGetWidth.

```lua
local result = mge.getScreenWidth()
```

**Returns**:

* `result` (number)

***

### `mge.getUIScale`

Returns the UI scaling used.

```lua
local result = mge.getUIScale()
```

**Returns**:

* `result` (number)

***

### `mge.getVersion`

Gets the MGE version. Wrapper for MGEGetVersion.

```lua
local result = mge.getVersion()
```

**Returns**:

* `result` (number)

***

### `mge.getWeatherDLFog`

Gets distant land fog parameters for a specific weather. See [`mge.setWeatherDLFog()`](https://mwse.github.io/MWSE/apis/mge/#mgesetweatherdlfog).

```lua
local parameters = mge.getWeatherDLFog(weatherID)
```

**Parameters**:

* `weatherID` (number): Maps to values in the [`tes3.weather`](https://mwse.github.io/MWSE/references/weathers/) table.

**Returns**:

* `parameters` (table): An array-style table with `fogDistMultiplier` and `fogOffsetPercent` parameters.

***

### `mge.getWeatherPPLLight`

Gets per-pixel lighting parameters for a specific weather. See [`mge.setWeatherPPLLight()`](https://mwse.github.io/MWSE/apis/mge/#mgesetweatherppllight).

```lua
local parameters = mge.getWeatherPPLLight(weatherID)
```

**Parameters**:

* `weatherID` (number): Maps to values in the [`tes3.weather`](https://mwse.github.io/MWSE/references/weathers/) table.

**Returns**:

* `parameters` (table): An array-style table with `sunMultiplier` and `ambientMultiplier` parameters.

***

### `mge.getWeatherScattering`

Returns an array-style table with 3 distant land atmospheric scattering colours.

```lua
local scattering = mge.getWeatherScattering()
```

**Returns**:

* `scattering` (table)

***

### `mge.getZoom`

Wrapper for MGEGetZoom.

```lua
local result = mge.getZoom()
```

**Returns**:

* `result` (number)

***

### `mge.loadHUD`

Loads a HUD element. This is a warpper for MGELoadHUD.

```lua
mge.loadHUD({ hud = ..., texture = ..., enable = ... })
```

**Parameters**:

* `params` (table)
	* `hud` (string)
	* `texture` (string)
	* `enable` (boolean): *Optional*.

***

### `mge.log`

This function writes information to the mgeXE.log file in the user's installation directory. Wrapper for mwscript's MGELog function.

```lua
mge.log(message)
```

**Parameters**:

* `message` (string)

***

### `mge.modScreenRotation`

Wrapper for MGERotateScreenBy.

```lua
mge.modScreenRotation({ rotation = ... })
```

**Parameters**:

* `params` (table)
	* `rotation` (number)

***

### `mge.positionHUD`

Positions a HUD element. If a HUD ID is provided, this is a warpper for MGEPositionHUD, otherwise it is a wrapper for MGENIDPositionHUD.

```lua
mge.positionHUD({ hud = ..., x = ..., y = ... })
```

**Parameters**:

* `params` (table)
	* `hud` (string): *Optional*.
	* `x` (number)
	* `y` (number)

***

### `mge.scaleHUD`

Scales a HUD element. If a HUD ID is provided, this is a warpper for MGEScaleHUD, otherwise it is a wrapper for MGENIDScaleHUD.

```lua
mge.scaleHUD({ hud = ..., x = ..., y = ... })
```

**Parameters**:

* `params` (table)
	* `hud` (string): *Optional*.
	* `x` (number)
	* `y` (number)

***

### `mge.selectHUD`

Selects a HUD element, to assume for future HUD calls.

```lua
mge.selectHUD({ hud = ... })
```

**Parameters**:

* `params` (table)
	* `hud` (string): *Optional*.

***

### `mge.setCameraShakeAcceleration`

Wrapper for MGECameraShakeZoom.

```lua
mge.setCameraShakeAcceleration({ acceleration = ... })
```

**Parameters**:

* `params` (table)
	* `acceleration` (number)

***

### `mge.setCameraShakeMagnitude`

Wrapper for MGESetCameraShakeMagnitude.

```lua
mge.setCameraShakeMagnitude({ magnitude = ... })
```

**Parameters**:

* `params` (table)
	* `magnitude` (number)

***

### `mge.setHUDEffect`

Sets the effect for a HUD element. If a HUD ID is provided, this is a warpper for MGEChangeHUDEffect, otherwise it is a wrapper for MGENIDChangeHUDEffect.

```lua
mge.setHUDEffect({ hud = ..., effect = ... })
```

**Parameters**:

* `params` (table)
	* `hud` (string): *Optional*.
	* `effect` (string)

***

### `mge.setHUDEffectFloat`

Sets the effect float variable for a HUD element. This is a wrapper for MGENIDSetHUDEffectFloat.

```lua
mge.setHUDEffectFloat({ hud = ..., variable = ..., value = ... })
```

**Parameters**:

* `params` (table)
	* `hud` (string): *Optional*.
	* `variable` (string)
	* `value` (number)

***

### `mge.setHUDEffectLong`

Sets the effect long variable for a HUD element. This is a wrapper for MGENIDSetHUDEffectLong.

```lua
mge.setHUDEffectLong({ hud = ..., variable = ..., value = ... })
```

**Parameters**:

* `params` (table)
	* `hud` (string): *Optional*.
	* `variable` (string)
	* `value` (number)

***

### `mge.setHUDEffectVector4`

Sets the effect vector variable for a HUD element. This is a wrapper for MGENIDSetHUDEffectVec.

```lua
mge.setHUDEffectVector4({ hud = ..., variable = ..., value = ... })
```

**Parameters**:

* `params` (table)
	* `hud` (string): *Optional*.
	* `variable` (string)
	* `value` (table): A table of 4 values.

***

### `mge.setHUDTexture`

Sets the texture for a given HUD element. If a HUD ID is provided, this is a warpper for MGEChangeHUDTexture, otherwise it is a wrapper for MGENIDChangeHUDTexture.

```lua
mge.setHUDTexture({ hud = ..., texture = ... })
```

**Parameters**:

* `params` (table)
	* `hud` (string)
	* `texture` (string)

***

### `mge.setScreenRotation`

Wrapper for MGERotateScreen.

```lua
mge.setScreenRotation({ rotation = ... })
```

**Parameters**:

* `params` (table)
	* `rotation` (number)

***

### `mge.setShaderFloat`

Sets a shader's float variable. Wrapper for mwscript's MGEShaderSetFloat.

```lua
mge.setShaderFloat({ shader = ..., variable = ..., value = ... })
```

**Parameters**:

* `params` (table)
	* `shader` (string)
	* `variable` (string)
	* `value` (number)

***

### `mge.setShaderLong`

Sets a shader's long variable. Wrapper for mwscript's MGEShaderSetLong.

```lua
mge.setShaderLong({ shader = ..., variable = ..., value = ... })
```

**Parameters**:

* `params` (table)
	* `shader` (string)
	* `variable` (string)
	* `value` (number)

***

### `mge.setShaderVector4`

Sets a shader's vector variable. Wrapper for mwscript's MGEShaderSetVector.

```lua
mge.setShaderVector4({ shader = ..., variable = ..., value = ... })
```

**Parameters**:

* `params` (table)
	* `shader` (string)
	* `variable` (string)
	* `value` (table): A table of 4 values.

***

### `mge.setWeatherDLFog`

Sets distant land fog parameters for a specific weather. `fogDistMultiplier` is multiplied by the "Above water fog" distance to get the fog distance for that weather. It has a range of [0, 2]. `fogOffsetPercent` is the percentage of fog applied at zero distance from the camera. It has a range of [0, 90].

Note: "Above water fog" is a setting specific to MGE XE. It can be found on the Distant Land page, under Fog category.

```lua
local result = mge.setWeatherDLFog(weatherID, fogDistMultiplier, fogOffsetPercent)
```

**Parameters**:

* `weatherID` (number): Maps to values in the [`tes3.weather`](https://mwse.github.io/MWSE/references/weathers/) table.
* `fogDistMultiplier` (number)
* `fogOffsetPercent` (number)

**Returns**:

* `result` (number)

***

### `mge.setWeatherPPLLight`

Sets light multipliers used in per-pixel lighting for a specific weather. `sunMultiplier` affects sunlight, while `ambientMultiplier` affects ambient lighting.

```lua
local result = mge.setWeatherPPLLight(weatherID, sunMultiplier, ambientMultiplier)
```

**Parameters**:

* `weatherID` (number): Maps to values in the [`tes3.weather`](https://mwse.github.io/MWSE/references/weathers/) table.
* `sunMultiplier` (number)
* `ambientMultiplier` (number)

**Returns**:

* `result` (number)

***

### `mge.setWeatherScattering`

Sets distant land atmospheric scattering colours.

```lua
local success = mge.setWeatherScattering({ outscatter = ..., inscatter = ... })
```

**Parameters**:

* `params` (table)
	* `outscatter` (table): An array-style table with 3 numbers for red, green and blue color channels. The values can range from 0 to 1.
	* `inscatter` (table): An array-style table with 3 numbers for red, green and blue color channels. The values can range from 0 to 1.

**Returns**:

* `success` (boolean)

***

### `mge.setZoom`

Wrapper for MGEZoom, or MGESetZoom if set to animate.

```lua
mge.setZoom({ amount = ..., animate = ... })
```

**Parameters**:

* `params` (table)
	* `amount` (number)
	* `animate` (boolean): *Default*: `false`.

***

### `mge.startScreenRotation`

Enables MGE XE's screen spin effect. Wrapper for mwscript's MGEScreenSpin.

```lua
mge.startScreenRotation()
```

***

### `mge.stopScreenRotation`

Disables MGE XE's screen spin effect. Wrapper for mwscript's MGEStopSpinSpin.

```lua
mge.stopScreenRotation()
```

***

### `mge.stopZoom`

Wrapper for MGEStopZoom.

```lua
mge.stopZoom()
```

***

### `mge.toggleZoom`

Toggles the MGE XE zoom effect. Wrapper for MGEToggleZoom.

```lua
mge.toggleZoom()
```

***

### `mge.unselectHUD`

Cancels selection for a HUD element. Wrapper for mwscript's MGECancelWithHUD.

```lua
mge.unselectHUD({ hud = ... })
```

**Parameters**:

* `params` (table)
	* `hud` (string)

***

### `mge.zoomIn`

Wrapper for MGEZoomIn, or MGEZoomInBy if an amount is provided.

```lua
mge.zoomIn({ amount = ... })
```

**Parameters**:

* `params` (table)
	* `amount` (number): *Optional*.

***

### `mge.zoomOut`

Wrapper for MGEZoomOut, or MGEZoomOutBy if an amount is provided.

```lua
mge.zoomOut({ amount = ... })
```

**Parameters**:

* `params` (table)
	* `amount` (number): *Optional*.

***

