# tes3gameFile

Represents a loaded ESM, ESP, or ESS file.

## Properties

### `author`

*Read-only*. The file's author.

**Returns**:

* `result` (string)

***

### `cellName`

*Read-only*. The current cell, from a save game.

**Returns**:

* `result` (string)

***

### `currentHealth`

*Read-only*. The player's health, from a save game.

**Returns**:

* `result` (number)

***

### `day`

*Read-only*. The current day, from a save game.

**Returns**:

* `result` (number)

***

### `daysPassed`

*Read-only*. The number of days passed, from a save game.

**Returns**:

* `result` (number)

***

### `description`

*Read-only*. The description of the file.

**Returns**:

* `result` (string)

***

### `filename`

*Read-only*. The simple filename.

**Returns**:

* `result` (string)

***

### `fileSize`

*Read-only*. The size of the file.

**Returns**:

* `result` (number)

***

### `gameHour`

*Read-only*. The current game hour, from a save game.

**Returns**:

* `result` (number)

***

### `highestFormID`

*Read-only*. No description yet available.

**Returns**:

* `result` (number)

***

### `masters`

*Read-only*. An array-style table of the tes3gameFiles that this is dependent upon.

**Returns**:

* `result` (table)

***

### `maxHealth`

*Read-only*. The player's maximum health, from a save game.

**Returns**:

* `result` (number)

***

### `modifiedTime`

*Read-only*. The timestamp that the file was modified.

**Returns**:

* `result` (string)

***

### `month`

*Read-only*. The current month, from a save game.

**Returns**:

* `result` (number)

***

### `path`

*Read-only*. The path to the file.

**Returns**:

* `result` (string)

***

### `playerName`

*Read-only*. The player's name, from a save game.

**Returns**:

* `result` (string)

***

### `year`

*Read-only*. The current year, from a save game.

**Returns**:

* `result` (number)

***

## Methods

### `deleteFile`

Deletes the file.

```lua
tes3gameFile:deleteFile()
```

***

