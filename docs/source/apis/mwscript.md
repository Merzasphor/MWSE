# mwscript

!!! warning
	This API is deprecated. See below for more information about what to use instead.

The mwscript library allows vanilla mwscript functions to be called. This is not always ideal, and this library is deprecated. Avoid using it if at all possible.

## Functions

### `mwscript.activate`

Wrapper for the Activate mwscript function.

```lua
mwscript.activate({ reference = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): *Optional*. The target reference for this command to be executed on. Defaults to the normal script execution reference.

***

### `mwscript.addItem`

Wrapper for the AddItem mwscript function.

```lua
local executed = mwscript.addItem({ reference = ..., item = ..., count = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): *Optional*. The target reference for this command to be executed on. Defaults to the normal script execution reference.
	* `item` ([tes3item](../../types/tes3item), string): The item to be added.
	* `count` (number): *Default*: `1`. The number of items to be added.

**Returns**:

* `executed` (boolean)

***

### `mwscript.addSoulGem`

Wrapper for the AddSoulGem mwscript function.

```lua
local executed = mwscript.addSoulGem({ reference = ..., creature = ..., soulgem = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): *Optional*. The target reference for this command to be executed on. Defaults to the normal script execution reference.
	* `creature` ([tes3creature](../../types/tes3creature), string): The creature to be stored in the soul gem.
	* `soulgem` ([tes3misc](../../types/tes3misc), string): The soul gem to store the soul in.

**Returns**:

* `executed` (boolean)

***

### `mwscript.addSpell`

Wrapper for the AddItem mwscript function.

```lua
local executed = mwscript.addSpell({ reference = ..., spell = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): *Optional*. The target reference for this command to be executed on. Defaults to the normal script execution reference.
	* `spell` ([tes3spell](../../types/tes3spell), string)

**Returns**:

* `executed` (boolean)

***

### `mwscript.addToLevCreature`

Wrapper for the AddToLevCreature mwscript function.

```lua
local executed = mwscript.addToLevCreature({ list = ..., creature = ..., level = ... })
```

**Parameters**:

* `params` (table)
	* `list` ([tes3leveledCreature](../../types/tes3leveledCreature), string): Leveled creature list to add a creature to.
	* `creature` ([tes3actor](../../types/tes3actor), string): Creature to add to the list.
	* `level` (number): *Default*: `0`. Minimum level for the creature to spawn.

**Returns**:

* `executed` (boolean)

***

### `mwscript.addToLevItem`

Wrapper for the AddToLevItem mwscript function.

```lua
local executed = mwscript.addToLevItem({ list = ..., item = ..., level = ... })
```

**Parameters**:

* `params` (table)
	* `list` ([tes3leveledItem](../../types/tes3leveledItem), string): Leveled item list to add a creature to.
	* `item` ([tes3item](../../types/tes3item), string): Item to add to the list.
	* `level` (number): *Default*: `0`. Minimum level for the item to spawn.

**Returns**:

* `executed` (boolean)

***

### `mwscript.addTopic`

Wrapper for the AddItem mwscript function.

```lua
local executed = mwscript.addTopic({ topic = ... })
```

**Parameters**:

* `params` (table)
	* `topic` ([tes3dialogue](../../types/tes3dialogue), string)

**Returns**:

* `executed` (boolean)

***

### `mwscript.aiTravel`

Wrapper for the AITravel mwscript function.

```lua
local executed = mwscript.aiTravel({ reference = ..., x = ..., y = ..., z = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): *Optional*. The target reference for this command to be executed on. Defaults to the normal script execution reference.
	* `x` (number)
	* `y` (number)
	* `z` (number)

**Returns**:

* `executed` (boolean)

***

### `mwscript.disable`

Wrapper for the Disable mwscript function.

```lua
local executed = mwscript.disable({ reference = ..., modify = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): *Optional*. The target reference for this command to be executed on. Defaults to the normal script execution reference.
	* `modify` (boolean): *Default*: `true`. Set the object as modified.

**Returns**:

* `executed` (boolean)

***

### `mwscript.drop`

Wrapper for the Drop mwscript function.

```lua
local executed = mwscript.drop({ reference = ..., item = ..., count = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): *Optional*. The target reference for this command to be executed on. Defaults to the normal script execution reference.
	* `item` ([tes3item](../../types/tes3item), string): The item to be dropped.
	* `count` (number): *Default*: `1`. The number of items to drop.

**Returns**:

* `executed` (boolean)

***

### `mwscript.enable`

Wrapper for the Enable mwscript function.

```lua
local executed = mwscript.enable({ reference = ..., modify = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): *Optional*. The target reference for this command to be executed on. Defaults to the normal script execution reference.
	* `modify` (boolean): *Default*: `true`. Set the object as modified.

**Returns**:

* `executed` (boolean)

***

### `mwscript.equip`

Wrapper for the Equip mwscript function.

```lua
local executed = mwscript.equip({ reference = ..., item = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): *Optional*. The target reference for this command to be executed on. Defaults to the normal script execution reference.
	* `item` ([tes3item](../../types/tes3item), string): The item to be equipped.

**Returns**:

* `executed` (boolean)

***

### `mwscript.explodeSpell`

Wrapper for the ExplodeSpell mwscript function.

```lua
local executed = mwscript.explodeSpell({ reference = ..., spell = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): *Optional*. The target reference for this command to be executed on. Defaults to the normal script execution reference.
	* `spell` ([tes3spell](../../types/tes3spell), string)

**Returns**:

* `executed` (boolean)

***

### `mwscript.getButtonPressed`

Wrapper for the GetButtonPressed mwscript function.

```lua
local buttonIndex = mwscript.getButtonPressed()
```

**Returns**:

* `buttonIndex` (number)

***

### `mwscript.getDetected`

Wrapper for the GetDetected mwscript function.

```lua
local result = mwscript.getDetected({ reference = ..., target = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): *Optional*. The target reference for this command to be executed on. Defaults to the normal script execution reference.
	* `target` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): Actor to check detection for.

**Returns**:

* `result` (boolean)

***

### `mwscript.getDisabled`

Wrapper for the GetDisabled mwscript function.

```lua
local result = mwscript.getDisabled({ reference = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): *Optional*. The target reference for this command to be executed on. Defaults to the normal script execution reference.

**Returns**:

* `result` (boolean)

***

### `mwscript.getDistance`

Wrapper for the GetDistance mwscript function.

```lua
local result = mwscript.getDistance({ reference = ..., target = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): *Optional*. The target reference for this command to be executed on. Defaults to the normal script execution reference.
	* `target` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): Actor to check distance to.

**Returns**:

* `result` (boolean)

***

### `mwscript.getItemCount`

Use `tes3.getItemCount` instead. Wrapper for the `GetItemCount` mwscript function.

```lua
local result = mwscript.getItemCount({ reference = ..., item = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): *Optional*. The target reference for this command to be executed on. Defaults to the normal script execution reference.
	* `item` ([tes3item](../../types/tes3item), string)

**Returns**:

* `result` (number)

***

### `mwscript.getPCJumping`

Wrapper for the GetPCJumping mwscript function.

```lua
local result = mwscript.getPCJumping()
```

**Returns**:

* `result` (boolean)

***

### `mwscript.getPCRunning`

Wrapper for the GetPCRunning mwscript function.

```lua
local result = mwscript.getPCRunning()
```

**Returns**:

* `result` (boolean)

***

### `mwscript.getPCSneaking`

Wrapper for the GetPCSneaking mwscript function.

```lua
local result = mwscript.getPCSneaking()
```

**Returns**:

* `result` (boolean)

***

### `mwscript.getReference`

Returns the script target for the currently running Morrowind script, if any.

```lua
local result = mwscript.getReference()
```

**Returns**:

* `result` ([tes3reference](../../types/tes3reference))

***

### `mwscript.getScript`

Returns the currently running Morrowind script, if any.

```lua
local result = mwscript.getScript()
```

**Returns**:

* `result` ([tes3script](../../types/tes3script))

***

### `mwscript.getSpellEffects`

Wrapper for the GetSpellEffects mwscript function.

```lua
local result = mwscript.getSpellEffects({ reference = ..., spell = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): *Optional*. The target reference for this command to be executed on. Defaults to the normal script execution reference.
	* `spell` ([tes3spell](../../types/tes3spell), string)

**Returns**:

* `result` (boolean)

***

### `mwscript.hasItemEquipped`

Wrapper for the HasItemEquipped mwscript function.

```lua
local result = mwscript.hasItemEquipped({ reference = ..., item = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): *Optional*. The target reference for this command to be executed on. Defaults to the normal script execution reference.
	* `item` ([tes3item](../../types/tes3item), string): The item to check for.

**Returns**:

* `result` (boolean)

***

### `mwscript.placeAtPC`

Wrapper for the PlaceAtPC mwscript function.

```lua
local lastPlacedReference = mwscript.placeAtPC({ reference = ..., object = ..., count = ..., distance = ..., direction = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): *Optional*. The target reference for this command to be executed on. Defaults to the normal script execution reference.
	* `object` ([tes3object](../../types/tes3object), string): The object to place.
	* `count` (number): *Default*: `1`.
	* `distance` (number): *Default*: `256`.
	* `direction` (number): *Default*: `1`.

**Returns**:

* `lastPlacedReference` ([tes3reference](../../types/tes3reference))

***

### `mwscript.playSound`

Wrapper for the PlaySound mwscript function.

```lua
local result = mwscript.playSound({ reference = ..., sound = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): *Optional*. The target reference for this command to be executed on. Defaults to the normal script execution reference.
	* `sound` ([tes3sound](../../types/tes3sound), string)

**Returns**:

* `result` (boolean)

***

### `mwscript.position`

Wrapper for the Position mwscript function.

```lua
local executed = mwscript.position({ reference = ..., cell = ..., x = ..., y = ..., z = ..., rotation = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): *Optional*. The target reference for this command to be executed on. Defaults to the normal script execution reference.
	* `cell` (string)
	* `x` (number): *Default*: `0`.
	* `y` (number): *Default*: `0`.
	* `z` (number): *Default*: `0`.
	* `rotation` (number): *Default*: `0`.

**Returns**:

* `executed` (boolean)

***

### `mwscript.positionCell`

Wrapper for the PositionCell mwscript function.

```lua
local executed = mwscript.positionCell({ reference = ..., cell = ..., x = ..., y = ..., z = ..., rotation = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): *Optional*. The target reference for this command to be executed on. Defaults to the normal script execution reference.
	* `cell` (string)
	* `x` (number): *Default*: `0`.
	* `y` (number): *Default*: `0`.
	* `z` (number): *Default*: `0`.
	* `rotation` (number): *Default*: `0`.

**Returns**:

* `executed` (boolean)

***

### `mwscript.removeItem`

Wrapper for the RemoveItem mwscript function.

```lua
local executed = mwscript.removeItem({ reference = ..., item = ..., count = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): *Optional*. The target reference for this command to be executed on. Defaults to the normal script execution reference.
	* `item` ([tes3item](../../types/tes3item), string): The item to be added.
	* `count` (number): *Default*: `1`. The number of items to be added.

**Returns**:

* `executed` (boolean)

***

### `mwscript.removeSpell`

Wrapper for the RemoveSpell mwscript function.

```lua
local executed = mwscript.removeSpell({ reference = ..., spell = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): *Optional*. The target reference for this command to be executed on. Defaults to the normal script execution reference.
	* `spell` ([tes3spell](../../types/tes3spell), string)

**Returns**:

* `executed` (boolean)

***

### `mwscript.scriptRunning`

Wrapper for the ScriptRunning mwscript function.

```lua
local result = mwscript.scriptRunning({ script = ... })
```

**Parameters**:

* `params` (table)
	* `script` ([tes3script](../../types/tes3script), string)

**Returns**:

* `result` (boolean)

***

### `mwscript.setLevel`

Wrapper for the SetLevel mwscript function.

```lua
local executed = mwscript.setLevel({ reference = ..., level = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): *Optional*. The target reference for this command to be executed on. Defaults to the normal script execution reference.
	* `level` (number)

**Returns**:

* `executed` (boolean)

***

### `mwscript.startCombat`

Wrapper for the StartCombat mwscript function.

```lua
local executed = mwscript.startCombat({ reference = ..., target = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): *Optional*. The target reference for this command to be executed on. Defaults to the normal script execution reference.
	* `target` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): Actor to start combat with.

**Returns**:

* `executed` (boolean)

***

### `mwscript.startScript`

Wrapper for the StartCombat mwscript function.

```lua
local executed = mwscript.startScript({ reference = ..., script = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): *Optional*. The target reference for this command to be executed on. Defaults to the normal script execution reference.
	* `script` ([tes3script](../../types/tes3script), string)

**Returns**:

* `executed` (boolean)

***

### `mwscript.stopCombat`

Wrapper for the StopCombat mwscript function.

```lua
local executed = mwscript.stopCombat({ reference = ..., target = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): *Optional*. The target reference for this command to be executed on. Defaults to the normal script execution reference.
	* `target` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): Actor to stop combat with.

**Returns**:

* `executed` (boolean)

***

### `mwscript.stopScript`

Wrapper for the StartCombat mwscript function.

```lua
local executed = mwscript.stopScript({ reference = ..., script = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): *Optional*. The target reference for this command to be executed on. Defaults to the normal script execution reference.
	* `script` ([tes3script](../../types/tes3script), string)

**Returns**:

* `executed` (boolean)

***

### `mwscript.stopSound`

Wrapper for the StopSound mwscript function.

```lua
local result = mwscript.stopSound({ reference = ..., sound = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference), [tes3mobileActor](../../types/tes3mobileActor), string): *Optional*. The target reference for this command to be executed on. Defaults to the normal script execution reference.
	* `sound` ([tes3sound](../../types/tes3sound), string)

**Returns**:

* `result` (boolean)

***

### `mwscript.wakeUpPC`

Wrapper for the WakeUpPC mwscript function.

```lua
mwscript.wakeUpPC()
```

***

