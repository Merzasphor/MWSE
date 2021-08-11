# tes3gameFile

Represents a loaded ESM, ESP, or ESS file.

## Properties

### `author`

The file's author.

**Returns**:

* `result` (string)

***

### `cellName`

The current cell, from a save game.

**Returns**:

* `result` (string)

***

### `currentHealth`

The player's health, from a save game.

**Returns**:

* `result` (number)

***

### `day`

The current day, from a save game.

**Returns**:

* `result` (number)

***

### `daysPassed`

The number of days passed, from a save game.

**Returns**:

* `result` (number)

***

### `description`

The description of the file.

**Returns**:

* `result` (string)

***

### `filename`

The simple filename.

**Returns**:

* `result` (string)

***

### `fileSize`

The size of the file.

**Returns**:

* `result` (number)

***

### `gameHour`

The current game hour, from a save game.

**Returns**:

* `result` (number)

***

### `highestFormID`

No description yet available.

**Returns**:

* `result` (number)

***

### `masters`

An array-style table of the tes3gameFiles that this is dependent upon.

**Returns**:

* `result` (table)

***

### `maxHealth`

The player's maximum health, from a save game.

**Returns**:

* `result` (number)

***

### `modifiedTime`

The timestamp that the file was modified.

**Returns**:

* `result` (string)

***

### `month`

The current month, from a save game.

**Returns**:

* `result` (number)

***

### `path`

The path to the file.

**Returns**:

* `result` (string)

***

### `playerName`

The player's name, from a save game.

**Returns**:

* `result` (string)

***

### `year`

The current year, from a save game.

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

