# lfs

LuaFileSystem is a Lua library developed to complement the set of functions related to file systems offered by the standard Lua distribution. This library has been further extended by MWSE.

## Functions

### `lfs.attributes`

Returns a table with the file attributes corresponding to filepath (or nil followed by an error message and a system-dependent error code in case of error). If the second optional argument is given and is a string, then only the value of the named attribute is returned (this use is equivalent to lfs.attributes(filepath)[request_name], but the table is not created and only one attribute is retrieved from the O.S.). if a table is passed as the second argument, it (result_table) is filled with attributes and returned instead of a new table. The attributes are described as follows; attribute mode is a string, all the others are numbers, and the time related attributes use the same time reference of os.time: dev, mode, nlink, access, modification, change, size, permissions.

```lua
local attributes, error = lfs.attributes(path, request, resultTable)
```

**Parameters**:

* `path` (string): The path, relative to the current directory, to get attributes for.
* `request` (string): *Optional*. The specific attribute to look for. If provided, the return value becomes the requested value (or nil) instead of a table.
* `resultTable` (table): *Optional*. If provided, this table will be reused as the result table. If not provided, a new table is created.

**Returns**:

* `attributes` (table, string, number, nil): All attributes in a table, the value of a specific attribute if one was requested, or nil on an error.
* `error` (string, nil): In the case of an error, a string describing the issue.

***

### `lfs.chdir`

Changes the current working directory to the given path. Note that this is global. Do not use this function without restoring the previous directory at the end of your logic. Failure to do so can cause unrecoverable errors.

```lua
local success, error = lfs.chdir(path)
```

**Parameters**:

* `path` (string): The path to change to.

**Returns**:

* `success` (boolean, nil): true in case of success, or nil on an error.
* `error` (string, nil): In the case of an error, a string describing the issue.

***

### `lfs.currentdir`

Changes the current working directory to the given path.

```lua
local path, error = lfs.currentdir()
```

**Returns**:

* `path` (string, nil): The current working directory, or nil on an error.
* `error` (string, nil): In the case of an error, a string describing the issue.

***

### `lfs.dir`

Creates a Lua iterator over the entries of a given directory. This can be used to create a for loop of directories. Be wary that current and parent directory markers may be available in the results.

```lua
lfs.dir(path)
```

**Parameters**:

* `path` (string): The path to iterate over.

***

### `lfs.directoryexists`

Simple check to determine if a directory exists.

```lua
local success = lfs.directoryexists(path)
```

**Parameters**:

* `path` (string): The path to determine existance of.

**Returns**:

* `success` (boolean): true if the directory exists.

***

### `lfs.fileexists`

Simple check to determine if a file exists.

```lua
local success = lfs.fileexists(path)
```

**Parameters**:

* `path` (string): The path to determine existance of.

**Returns**:

* `success` (boolean): true if the file exists.

***

### `lfs.link`

Creates a link. This is a hard link by default.

```lua
local success, error = lfs.link(old, new, symlink)
```

**Parameters**:

* `old` (string): The object to link to.
* `new` (string): The name of the link.
* `symlink` (boolean): *Optional*. If true, the link will be symbolic instead.

**Returns**:

* `success` (boolean, nil): true in case of success, or nil on an error.
* `error` (string, nil): In the case of an error, a string describing the issue.

***

### `lfs.lock`

Locks a file or a part of it. This function works on open files; the file handle should be specified as the first argument.

```lua
local success, error = lfs.lock(filehandle, mode, start, length)
```

**Parameters**:

* `filehandle` ([ioFile](../../types/ioFile)): The file handle to lock.
* `mode` (string): "r" for a read/shared lock, or "w" for a write/exclusive lock.
* `start` (number): *Optional*. The starting point of the file to lock.
* `length` (number): *Optional*. The length of the file, relative to start, to lock.

**Returns**:

* `success` (boolean, nil): true if the operation was successful, or nil in the case of an error.
* `error` (string, nil): In the case of an error, a string describing the issue. In particular, if the lock exists and is not stale it returns the "File exists" message.

***

### `lfs.lock_dir`

Creates a lockfile (called lockfile.lfs) in path if it does not exist and returns the lock. If the lock already exists checks if it's stale, using the second parameter (default for the second parameter is INT_MAX, which in practice means the lock will never be stale. The lock object has a method to free it.

```lua
local success, error = lfs.lock_dir(path)
```

**Parameters**:

* `path` (string): The path to lock.

**Returns**:

* `success` ([lfsLock](../../types/lfsLock), nil): The lock object to manage, or nil in the case of an error.
* `error` (string, nil): In the case of an error, a string describing the issue. In particular, if the lock exists and is not stale it returns the "File exists" message.

***

### `lfs.mkdir`

Creates a new directory.

```lua
local success, error = lfs.mkdir(dirname)
```

**Parameters**:

* `dirname` (string): The name of the new directory.

**Returns**:

* `success` (boolean, nil): true in case of success, or nil on an error.
* `error` (string, nil): In the case of an error, a string describing the issue.

***

### `lfs.rmdir`

Removes an existing directory. Unless using the recursive parameter, only empty directories can be removed.

```lua
local success, error = lfs.rmdir(dirname, recursive)
```

**Parameters**:

* `dirname` (string): The name of the directory to remove.
* `recursive` (boolean): *Default*: `false`. If true, all contents of the directory will be removed as well.

**Returns**:

* `success` (boolean, nil): true in case of success, or nil on an error.
* `error` (string, nil): In the case of an error, a string describing the issue.

***

### `lfs.setmode`

Sets the writing mode for a file.

```lua
local success, errorOrOldMode = lfs.setmode(file, mode)
```

**Parameters**:

* `file` ([ioFile](../../types/ioFile)): The file to set mode for.
* `mode` (string): The file's new mode. Can be either "binary" or "text".

**Returns**:

* `success` (boolean, nil): true in case of success, or nil on an error.
* `errorOrOldMode` (string): If succesful, this will be the previous file mode used. In the case of an error, a string describing the issue.

***

### `lfs.touch`

Set access and modification times of a file. Both access and modified times are measured in seconds, matching the OS time function.

```lua
local success, error = lfs.touch(path, accessTime, modifiedTime)
```

**Parameters**:

* `path` (string): The path to touch.
* `accessTime` (number): *Optional*. The new access time to set.
* `modifiedTime` (number): *Optional*. The new last modified time to set

**Returns**:

* `success` (boolean, nil): true in case of success, or nil on an error.
* `error` (string, nil): In the case of an error, a string describing the issue.

***

### `lfs.unlock`

Unlocks a file or a part of it. This function works on open files; the file handle should be specified as the first argument.

```lua
local success, error = lfs.unlock(filehandle, mode, start, length)
```

**Parameters**:

* `filehandle` ([ioFile](../../types/ioFile)): The file handle to unlock.
* `mode` (string): "r" for a read/shared lock, or "w" for a write/exclusive unlock.
* `start` (number): *Optional*. The starting point of the file to unlock.
* `length` (number): *Optional*. The length of the file, relative to start, to unlock.

**Returns**:

* `success` (boolean, nil): true if the operation was successful, or nil in the case of an error.
* `error` (string, nil): In the case of an error, a string describing the issue. In particular, if the lock exists and is not stale it returns the "File exists" message.

***

