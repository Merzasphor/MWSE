# tes3bsaLoader

A class responsible for handling the loading of BSA files.

## Properties

### `archives`

*Read-only*. An array-style table of archive files.

**Returns**:

* `result` ([tes3archive](../../types/tes3archive)[])

***

### `firstArchive`

*Read-only*. The start of the list of loaded archives. This is the last loaded archive, meaning first in priority.

**Returns**:

* `result` ([tes3archive](../../types/tes3archive))

***

## Methods

### `findFile`

Searches for a file in the archive list, and returns the archive and index that it can be found in.

```lua
local archive, index = myObject:findFile(path)
```

**Parameters**:

* `path` (string): The path to the file held in the archive.

**Returns**:

* `archive` ([tes3archive](../../types/tes3archive), nil): The found archive, or `nil` if no result was found.
* `index` (number, nil): The index in the archive that the path was found at, or `nil` if no result was found.

***

