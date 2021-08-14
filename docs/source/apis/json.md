# json

Provides support for interacting with json data through an extended dkjson module.

## Properties

### `json.null`

You can use this value for setting explicit null values.

**Returns**:

* `result` (number)

***

### `json.version`

Current version of dkjson.

**Returns**:

* `result` (string)

***

## Functions

### `json.decode`

Decode string into a table.

```lua
local result = json.decode(s, position, nullValue)
```

**Parameters**:

* `s` (string)
* `position` (number): *Default*: `1`.
* `nullValue` (string, nil): *Default*: `nil`.

**Returns**:

* `result` (table)

***

### `json.encode`

Create a string representing the object. Object can be a table, a string, a number, a boolean, nil, json.null or any object with a function __tojson in its metatable. A table can only use strings and numbers as keys and its values have to be valid objects as well. It raises an error for any invalid data types or reference cycles.

```lua
local result = json.encode(object, state)
```

**Parameters**:

* `object` (table)
* `state` (table)

**Returns**:

* `result` (string)

***

### `json.loadfile`

Loads the contents of a file through json.decode. Files loaded from Data Files\\MWSE\\{fileName}.json.

```lua
local result = json.loadfile(fileName)
```

**Parameters**:

* `fileName` (string)

**Returns**:

* `result` (table)

***

### `json.quotestring`

Quote a UTF-8 string and escape critical characters using JSON escape sequences. This function is only necessary when you build your own __tojson functions.

```lua
local result = json.quotestring(s)
```

**Parameters**:

* `s` (string)

**Returns**:

* `result` (string)

***

### `json.savefile`

Saves a serializable table to Data Files\\MWSE\\{fileName}.json, using json.encode.

```lua
json.savefile(fileName, object, config)
```

**Parameters**:

* `fileName` (string)
* `object` (table)
* `config` (table): *Optional*.

***

