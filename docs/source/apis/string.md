# string

This library provides generic functions for string manipulation, such as finding and extracting substrings, and pattern matching. When indexing a string in Lua, the first character is at position 1 (not at 0, as in C). Indices are allowed to be negative and are interpreted as indexing backwards, from the end of the string. Thus, the last character is at position -1, and so on.

## Functions

### `string.endswith`

Returns true if a string ends with a given pattern.

```lua
local result = string.endswith(s, pattern)
```

**Parameters**:

* `s` (string)
* `pattern` (string)

**Returns**:

* `result` (boolean)

***

### `string.format`

This function creates a string, given various values. The format follows the printf format, with the additional option of %q to automatically quote a string.

```lua
local result = string.format(format, unknown)
```

**Parameters**:

* `format` (string): The format string to use for the output.
* `unnamed` (values): Values to format into the given string.

**Returns**:

* `result` (string)

***

### `string.insert`

Returns a string where one string has been inserted into another at a given position.

```lua
local inserted = string.insert(s1, s2, position)
```

**Parameters**:

* `s1` (string): The string to insert into.
* `s2` (string): The string to insert.
* `position` (number): The position to insert s2 into s1.

**Returns**:

* `inserted` (string): A copy of s1 with s2 inserted into it.

***

### `string.multifind`

Performs the logic of find, using a table of patterns.

If any of the available patterns match, the matching pattern is returned followed by the normal results of the find.

```lua
string.multifind(s, pattern, index, plain)
```

**Parameters**:

* `s` (string): The string to perform finds on.
* `pattern` (table): An array-style table that contains pattern strings.
* `index` (number): Start index of the find.
* `plain` (boolean): If true, a normal search instead of a pattern search will be performed.

***

### `string.startswith`

Returns true if a string begins with a given pattern.

```lua
local result = string.startswith(s, pattern)
```

**Parameters**:

* `s` (string)
* `pattern` (string)

**Returns**:

* `result` (boolean)

***

