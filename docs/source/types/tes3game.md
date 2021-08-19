# tes3game

A core game object used for storing game settings.

## Properties

### `parentWindowHandle`

*Read-only*. The Windows HWND for the parent window.

**Returns**:

* `result` (number)

***

### `playerTarget`

*Read-only*. The current activation target.

**Returns**:

* `result` ([tes3reference](../../types/tes3reference))

***

### `renderDistance`

The game's rendering distance.

**Returns**:

* `result` (number)

***

### `screenShotsEnabled`

State on if screenshots are enabled.

**Returns**:

* `result` (boolean)

***

### `screenX`

*Read-only*. The screen's horizontal position.

**Returns**:

* `result` (number)

***

### `screenY`

*Read-only*. The screen's vertical position.

**Returns**:

* `result` (number)

***

### `soundQuality`

Sound quality level.

**Returns**:

* `result` (number)

***

### `voice`

Mix volumes for voices.

**Returns**:

* `result` (number)

***

### `volumeEffect`

Mix volumes for effects.

**Returns**:

* `result` (number)

***

### `volumeFootsteps`

Mix volumes for footsteps.

**Returns**:

* `result` (number)

***

### `volumeMaster`

Mix volumes for all sounds.

**Returns**:

* `result` (number)

***

### `volumeMedia`

Mix volumes for music.

**Returns**:

* `result` (number)

***

### `windowHandle`

*Read-only*. The Windows HWND for the window.

**Returns**:

* `result` (number)

***

### `wireframeProperty`

*Read-only*. The reused wireframe property, appled when toggling wireframe rendering.

**Returns**:

* `result` ([niProperty](../../types/niProperty))

***

### `worldSceneGraphRoot`

*Read-only*. Access to the root of the scene graph.

**Returns**:

* `result` ([niNode](../../types/niNode))

***

## Methods

### `clearTarget`

Clears data related to activation, resetting what the player can activate.

```lua
tes3game:clearTarget()
```

***

