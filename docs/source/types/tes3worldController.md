# tes3worldController

A core game object used for storing world simulation data.

## Properties

### `aiDistanceScale`

A value in the range [0, 1]. The (relative) maximum distance setting for AI simulation. Corresponds to the AI distance option in the Options menu.

**Returns**:

* `result` (number)

***

### `allMobileActors`

*Read-only*. The list of all active mobile actors ([`tes3mobileActor`](https://mwse.github.io/MWSE/types/tes3mobileActor/)). Mobile actors expire after 72 hours if they have not been in a loaded cell.

**Returns**:

* `result` ([tes3iterator](../../types/tes3iterator))

***

### `armCamera`

*Read-only*. The access to the first person arms camera.

**Returns**:

* `result` ([tes3worldControllerRenderCamera](../../types/tes3worldControllerRenderCamera))

***

### `audioController`

*Read-only*. The audio controller.

**Returns**:

* `result` ([tes3audioController](../../types/tes3audioController))

***

### `blindnessFader`

*Read-only*. Screen overlay fader for the blind effect.

**Returns**:

* `result` ([tes3fader](../../types/tes3fader))

***

### `characterRenderTarget`

*Read-only*. 

**Returns**:

* `result` (tes3worldControllerRenderTarget)

***

### `charGenState`

*Read-only*. The `charGenState` global variable. Indicates progress through character generation. Has a value of `-1` when chargen is complete.

**Returns**:

* `result` ([tes3globalVariable](../../types/tes3globalVariable))

***

### `countMusicTracksBattle`

*Read-only*. The number of available battle music tracks.

**Returns**:

* `result` (number)

***

### `countMusicTracksExplore`

*Read-only*. The number of available explore music tracks.

**Returns**:

* `result` (number)

***

### `criticalDamageSound`

The sound played when an actor takes damage from a critical hit. It plays instead of the normal health damage sound.

**Returns**:

* `result` ([tes3sound](../../types/tes3sound))

***

### `cursorOff`

If the target crosshair is disabled. Corresponds to the "Crosshair" option in the Options menu.

**Returns**:

* `result` (boolean)

***

### `day`

*Read-only*. The `Day` global variable, indicating the current day. Day numbering starts at `1` for the first day of a month.

**Returns**:

* `result` ([tes3globalVariable](../../types/tes3globalVariable))

***

### `daysPassed`

*Read-only*. The `DaysPassed` global variable, indicating the days passed since the game started for this character.

**Returns**:

* `result` ([tes3globalVariable](../../types/tes3globalVariable))

***

### `deadFloatScale`



**Returns**:

* `result` (number)

***

### `defaultLandSound`



**Returns**:

* `result` ([tes3sound](../../types/tes3sound))

***

### `defaultLandWaterSound`



**Returns**:

* `result` ([tes3sound](../../types/tes3sound))

***

### `deltaTime`

The time interval (in seconds) between this frame and the last frame. Useful for calculations that involve movement or damage over a period of time.

**Returns**:

* `result` (number)

***

### `difficulty`

A number in the range [-1, 1]. Corresponds to the "Difficulty" option in the Options menu.

**Returns**:

* `result` (number)

***

### `drowingDamageSound`

The sound played when an actor takes health damage while drowning. It plays instead of the normal health damage sound.

**Returns**:

* `result` ([tes3sound](../../types/tes3sound))

***

### `drownSound`

The sound played when an actor is losing health by drowning.

**Returns**:

* `result` ([tes3sound](../../types/tes3sound))

***

### `enchantedItemEffect`

*Read-only*. The animated texture effect that is applied onto equipped enchanted items.

**Returns**:

* `result` (niTextureEffect)

***

### `enchantedItemEffectCreated`

*Read-only*. If the enchantedItemEffect is available.

**Returns**:

* `result` (boolean)

***

### `enchantedItemEffectTextures`

*Read-only*. An array of textures used for the enchanted item effect.

**Returns**:

* `result` ([tes3iterator](../../types/tes3iterator))

***

### `flagLevitationDisabled`

If levitation is disabled.

**Returns**:

* `result` (boolean)

***

### `flagTeleportingDisabled`

If teleporting is disabled.

**Returns**:

* `result` (boolean)

***

### `globalScripts`

*Read-only*. A list of active global scripts.

**Returns**:

* `result` ([tes3iterator](../../types/tes3iterator))

***

### `handToHandHit2Sound`

A sound played when a hand to hand attack hits. For each attack, `handToHandHitSound` or `handToHandHitSound2` are randomly chosen.

**Returns**:

* `result` ([tes3sound](../../types/tes3sound))

***

### `handToHandHitSound`

A sound played when a hand to hand attack hits. For each attack, `handToHandHitSound` or `handToHandHitSound2` are randomly chosen.

**Returns**:

* `result` ([tes3sound](../../types/tes3sound))

***

### `healthDamageSound`

The sound played when health damage is taken.

**Returns**:

* `result` ([tes3sound](../../types/tes3sound))

***

### `heavyArmorHitSound`

The sound played when a heavy armor piece is hit.

**Returns**:

* `result` ([tes3sound](../../types/tes3sound))

***

### `helpDelay`

A number in the range [0, 2]. The delay in seconds before a tooltip appears. Corresponds to the "Menu help delay" option in the Options menu.

**Returns**:

* `result` (number)

***

### `hitFader`

*Read-only*. Screen overlay fader that pulses when damage is taken.

**Returns**:

* `result` ([tes3fader](../../types/tes3fader))

***

### `hour`

*Read-only*. The `GameHour` global variable, indicating the time of day.

**Returns**:

* `result` ([tes3globalVariable](../../types/tes3globalVariable))

***

### `hudStyle`

No known effect.

**Returns**:

* `result` (number)

***

### `inputController`

*Read-only*. The controller responsible for player input.

**Returns**:

* `result` ([tes3inputController](../../types/tes3inputController))

***

### `instance`

*Read-only*. 

**Returns**:

* `result` (HINSTANCE)

***

### `itemRepairSound`

The sound played when an item is repaired.

**Returns**:

* `result` ([tes3sound](../../types/tes3sound))

***

### `lastFrameTime`

*Read-only*. The value of `tes3.worldController.systemTime` at the start of the previous frame. Measured in milliseconds since the program was started.

**Returns**:

* `result` (object)

***

### `lightArmorHitSound`

The sound played when a light armor piece is hit.

**Returns**:

* `result` ([tes3sound](../../types/tes3sound))

***

### `mapController`

*Read-only*. The controller responsible for the world and local maps.

**Returns**:

* `result` (tes3mapController)

***

### `maxFPS`

Maximum framerate target for the engine's FPS limiter.

**Returns**:

* `result` (number)

***

### `mediumArmorHitSound`

The sound played when a medium armor piece is hit.

**Returns**:

* `result` ([tes3sound](../../types/tes3sound))

***

### `menuAlpha`

A value in the range [0, 1]. The alpha value of the black background of menus. Corresponds to the "Menu transparency" option in the Options menu.

**Returns**:

* `result` (number)

***

### `menuCamera`

*Read-only*. The access to the camera used to render menus.

**Returns**:

* `result` ([tes3worldControllerRenderCamera](../../types/tes3worldControllerRenderCamera))

***

### `menuClickSound`

The sound played when a UI button or other control is clicked.

**Returns**:

* `result` ([tes3sound](../../types/tes3sound))

***

### `menuController`

*Read-only*. The controller responsible for the menu system.

**Returns**:

* `result` ([tes3uiMenuController](../../types/tes3uiMenuController))

***

### `menuSizeSound`

Unused sound. Not used when a menu is resized.

**Returns**:

* `result` ([tes3sound](../../types/tes3sound))

***

### `missSound`

The sound played when a weapon fails its to-hit check.

**Returns**:

* `result` ([tes3sound](../../types/tes3sound))

***

### `mobController`

*Read-only*. The controller responsible for mobile objects and collision.

**Returns**:

* `result` ([tes3mobController](../../types/tes3mobController))

***

### `month`

*Read-only*. The `Month` global variable, indicating the current month. Month numbering starts at `0` for the first month, Morning Star.

**Returns**:

* `result` ([tes3globalVariable](../../types/tes3globalVariable))

***

### `monthsToRespawn`

*Read-only*. The `monthsToRespawn` global variable, used by the game to count the time left until containers are respawned. This is decremented at the end of a month (or end of a day with the appropriate MCP option). When it reaches `0`, containers are respawned.

**Returns**:

* `result` ([tes3globalVariable](../../types/tes3globalVariable))

***

### `mouseSensitivityX`

The horizontal camera rotation sensitivity. Corresponds to the "Horizontal sensitivity" option in the Options menu.

**Returns**:

* `result` (number)

***

### `mouseSensitivityY`

The vertical camera rotation sensitivity. Corresponds to the "Vertical sensitivity" option in the Options menu.

**Returns**:

* `result` (number)

***

### `musicSituation`

The kind of music being played. Only updates when music is not muted.
`0` Explore music
`1` Combat music
`2` Main menu music

Note: These values are available as [`tes3.musicSituation`](https://mwse.github.io/MWSE/references/music-situations/) constants

**Returns**:

* `result` (number)

***

### `nodeCursor`

*Read-only*. The scenegraph node for the target crosshair.

**Returns**:

* `result` ([niNode](../../types/niNode))

***

### `parentWindowHandle`

*Read-only*. Handle to the parent window.

**Returns**:

* `result` (HWND)

***

### `projectionDistance`



**Returns**:

* `result` (number)

***

### `quests`

*Read-only*. A list of all available [`tes3quest`](https://mwse.github.io/MWSE/types/tes3quest/)s.

**Returns**:

* `result` ([tes3iterator](../../types/tes3iterator))

***

### `quickSaveWhenResting`

Controls if auto-save on resting or waiting is enabled. Corresponds to the "Auto-save when rest" option in the Options menu.

**Returns**:

* `result` (object)

***

### `rechargingItems`

*Read-only*. A list of enchanted items that are recharging (type [`tes3rechargingItem`](https://mwse.github.io/MWSE/types/tes3rechargingItem/)). Items in the list may not all belong to the player.

**Returns**:

* `result` ([tes3iterator](../../types/tes3iterator))

***

### `shaderWaterReflectTerrain`

If pixel shader water reflection includes terrain. Not functional with MGE enabled.

**Returns**:

* `result` (boolean)

***

### `shaderWaterReflectUpdate`

Period between reflection updates for pixel shader water. Not functional with MGE enabled.

**Returns**:

* `result` (number)

***

### `shadowCamera`

*Read-only*. The access to the camera used for shadows rendering.

**Returns**:

* `result` ([tes3worldControllerRenderCamera](../../types/tes3worldControllerRenderCamera))

***

### `shadows`

An integer in the range [0,6]. Controls the amount of actor shadows drawn. Corresponds to the "Real-time shadows" option in the Options menu.

**Returns**:

* `result` (number)

***

### `showSubtitles`

If subtitles are shown. Corresponds to the "Subtitles" option in the Options menu.

**Returns**:

* `result` (boolean)

***

### `simulationTimeScalar`

A scalar used for simulation time. At the start of every frame, the `deltaTime` is multiplied by this value. Doing this here is safer than doing it in another event.

**Returns**:

* `result` (number)

***

### `splashController`

*Read-only*. Access to the splash controller.

**Returns**:

* `result` ([tes3splashController](../../types/tes3splashController))

***

### `splashscreenCamera`

*Read-only*. The access to the camera used to render splashscreens.

**Returns**:

* `result` ([tes3worldControllerRenderCamera](../../types/tes3worldControllerRenderCamera))

***

### `stopGameLoop`

When true, the game simulation loop will stop. Not normally used, and may have other unknown effects.

**Returns**:

* `result` (boolean)

***

### `sunglareFader`

*Read-only*. Screen overlay fader for sunglare.

**Returns**:

* `result` ([tes3fader](../../types/tes3fader))

***

### `systemTime`

*Read-only*. Time in milliseconds since the program was started.

**Returns**:

* `result` (number)

***

### `timescale`

*Read-only*. The `timescale` global variable. Used to convert real time to in-game time.

**Returns**:

* `result` ([tes3globalVariable](../../types/tes3globalVariable))

***

### `transitionFader`

*Read-only*. Screen overlay fader for cell transitions.

**Returns**:

* `result` ([tes3fader](../../types/tes3fader))

***

### `useBestAttack`

Automatically choose the best attack direction for attacks. Corresponds to the "Always use best attack" option in the Options menu.

**Returns**:

* `result` (boolean)

***

### `viewHeight`

*Read-only*. The height of the UI viewport in pixels. Affected by UI scaling. For screen resolution, use [`tes3.getViewportSize()`](https://mwse.github.io/MWSE/apis/tes3/#tes3getviewportsize).

**Returns**:

* `result` (number)

***

### `viewWidth`

*Read-only*. The width of the UI viewport in pixels. Affected by UI scaling. For screen resolution, use [`tes3.getViewportSize()`](https://mwse.github.io/MWSE/apis/tes3/#tes3getviewportsize).

**Returns**:

* `result` (number)

***

### `weaponSwishSound`

The sound played when an attack with a melee weapon is performed. It always plays when a melee attack is released, irrespective of hit or miss.

**Returns**:

* `result` ([tes3sound](../../types/tes3sound))

***

### `weatherController`

*Read-only*. The weather controller.

**Returns**:

* `result` ([tes3weatherController](../../types/tes3weatherController))

***

### `werewolfFader`

*Read-only*. Screen overlay fader for werewolf vision.

**Returns**:

* `result` ([tes3fader](../../types/tes3fader))

***

### `werewolfFOV`

The camera FOV when the player is a werewolf.

**Returns**:

* `result` (number)

***

### `worldCamera`

*Read-only*. The access to the world camera.

**Returns**:

* `result` ([tes3worldControllerRenderCamera](../../types/tes3worldControllerRenderCamera))

***

### `year`

*Read-only*. The `Year` global variable, indicating the current year.

**Returns**:

* `result` ([tes3globalVariable](../../types/tes3globalVariable))

***

## Functions

### `applyEnchantEffect`

This function applies an enchantment's effects to a scene node.

```lua
local result = tes3worldController.applyEnchantEffect({ node = ..., enchantment = ... })
```

**Parameters**:

* `params` (table)
	* `node` ([niNode](../../types/niNode)): A scene node to which to apply the enchantment's effects.
	* `enchantment` ([tes3enchantment](../../types/tes3enchantment)): The enchantment's effects to apply.

**Returns**:

* `result` (boolean)

***

