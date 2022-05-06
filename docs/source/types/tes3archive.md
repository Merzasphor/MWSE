# tes3archive

Loaded data from a BSA file.

## Properties

### `fileCount`

*Read-only*. The number of file entries in the BSA.

**Returns**:

* `result` (number)

***

### `nextArchive`

*Read-only*. The next archive to access after this one.

**Returns**:

* `result` ([tes3archive](../../types/tes3archive))

***

### `offsetToFileNameHashes`

*Read-only*. The offset in the BSA file where file name hashes can be found.

**Returns**:

* `result` (number)

***

### `path`

*Read-only*. The full path to the BSA, relative to the Morrowind installation directory.

**Returns**:

* `result` (string)

***

### `sizesAndOffsets`

*Read-only*. An array of sizes and offsets for entries in the archive.

**Returns**:

* `result` ([tes3archiveOffsetSizeData](../../types/tes3archiveOffsetSizeData)[])

***

## Methods

### `findFileIndex`

Searches for a file in the archive, and returns the index that it can be found in.

```lua
local index = myObject:findFileIndex(path)
```

**Parameters**:

* `path` (string): The path to the file held in the archive.

**Returns**:

* `index` (number, nil): The index in the archive that the path was found at, or `nil` if no result was found.

***

