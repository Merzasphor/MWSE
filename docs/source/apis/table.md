# table

This library provides generic functions for table manipulation. It provides all its functions inside the table table.

## Functions

### `table.bininsert`

Inserts a given value through BinaryInsert into the table sorted by [, comp].

If 'comp' is given, then it must be a function that receives two table elements, and returns true when the first is less than the second, e.g. comp = function(a, b) return a > b end, will give a sorted table, with the biggest value on position 1. [, comp] behaves as in table.sort(table, value [, comp]) returns the index where 'value' was inserted

```lua
local result = table.bininsert(t, value, comp)
```

**Parameters**:

* `t` (table)
* `value` (unknown)
* `comp` (unknown): *Optional*.

**Returns**:

* `result` (number)

***

### `table.binsearch`

Performs a binary search for a given value.

If the value is found: It returns a table holding all the mathing indices (e.g. { startindice,endindice } ) endindice may be the same as startindice if only one matching indice was found

If compval is given: then it must be a function that takes one value and returns a second value2, to be compared with the input value, e.g.: compvalue = function( value ) return value[1] end

If reversed is set to true: then the search assumes that the table is sorted in reverse order (largest value at position 1) note when reversed is given compval must be given as well, it can be nil/_ in this case

Return value: on success: a table holding matching indices (e.g. { startindice,endindice } ) on failure: nil

```lua
local result = table.binsearch(t, value, compval, reversed)
```

**Parameters**:

* `t` (table)
* `value` (unknown)
* `compval` (unknown): *Optional*.
* `reversed` (unknown): *Optional*.

**Returns**:

* `result` (table)

***

### `table.choice`

Returns a random element from the given table.

```lua
local result = table.choice(t)
```

**Parameters**:

* `t` (table)

**Returns**:

* `result` (unknown)

***

### `table.clear`

This clears all keys and values from a table, but preserves the allocated array/hash sizes. This is useful when a table, which is linked from multiple places, needs to be cleared and/or when recycling a table for use by the same context. This avoids managing backlinks, saves an allocation and the overhead of incremental array/hash part growth.

Please note this function is meant for very specific situations. In most cases it's better to replace the (usually single) link with a new table and let the garbage collection do its work.

```lua
table.clear(table)
```

**Parameters**:

* `table` (table): The table to clear.

***

### `table.copy`

Shallowly copies a table's contents to a destination table. If no destination table is provided, a new table will be created. Note that sub tables will not be copied, and will still refer to the same data.

```lua
local result = table.copy(from, to)
```

**Parameters**:

* `from` (table)
* `to` (table): *Optional*.

**Returns**:

* `result` (table)

***

### `table.copymissing`

Copies a table's contents from one table to another, including subtitles. If a non-table key is already defined, it will not be overwritten. Metatables are not copied.

```lua
table.copymissing(to, from)
```

**Parameters**:

* `to` (table)
* `from` (table)

***

### `table.deepcopy`

Copies a table's contents. All subtables will also be copied, as will any metatable.

```lua
local result = table.deepcopy(t)
```

**Parameters**:

* `t` (table)

**Returns**:

* `result` (table)

***

### `table.empty`

Returns true if the table is empty, otherwise, it returns false.

```lua
local result = table.empty(t)
```

**Parameters**:

* `t` (table)

**Returns**:

* `result` (boolean)

***

### `table.find`

Returns the key for a given value, or nil if the table does not contain the value.

```lua
local result = table.find(t, value)
```

**Parameters**:

* `t` (table)
* `value` (unknown)

**Returns**:

* `result` (unknown)

***

### `table.invert`

Returns a copy of `t` with the keys and values flipped.

```lua
local result = table.invert(t)
```

**Parameters**:

* `t` (table)

**Returns**:

* `result` (table)

***

### `table.keys`

Returns an array-style table of all keys in the given table, t. Optionally, it will sort the returned table.

```lua
local keys = table.keys(t, sort)
```

**Parameters**:

* `t` (table): The table to get keys for.
* `sort` (boolean, function, nil): *Optional*. If true, the returned table will be sorted. If a function is passed, the table will be sorted using the given function.

**Returns**:

* `keys` (table): An array of all table keys.

***

### `table.new`

This creates a pre-sized table. This is useful for big tables if the final table size is known and automatic table resizing is too expensive.

```lua
local newTable = table.new(narray, nhash)
```

**Parameters**:

* `narray` (number): A hint for how many elements the table will have as a sequence.
* `nhash` (number): A hint for how many other elements the table will have.

**Returns**:

* `newTable` (table): The pre-sized table that was created.

***

### `table.removevalue`

Removes a value from a given table. Returns true if the value was successfully removed.

```lua
local result = table.removevalue(t, value)
```

**Parameters**:

* `t` (table)
* `value` (unknown)

**Returns**:

* `result` (boolean)

***

### `table.size`

Returns the number of elements inside the table. Unlike the length operator (#) this will work with any table.

```lua
local result = table.size(t)
```

**Parameters**:

* `t` (table)

**Returns**:

* `result` (number)

***

### `table.traverse`

This function is used to iterate over values and its subtables in the table.

Each "node" is an object with a children table of other "nodes", each of which might have their own children. For example, a sceneNode is made up of niNodes, and each niNodes can have a list of niNode children. This is best used for recursive data structures like UI elements and sceneNodes etc.

```lua
local result = table.traverse(t, k)
```

**Parameters**:

* `t` (table): A table to transverse.
* `k` (unknown): *Default*: `children`. The key of a table inside t object.

**Returns**:

* `result` (iterator)

??? example "Example: Iterate over all scene nodes attached to player."

	```lua
	local function onLoaded()
	    mwse.log("Player's scene graph:")
	    for node in table.traverse({tes3.player.sceneNode}) do
	        mwse.log("%s : %s", node.RTTI.name, node.name)
	    end
	end
	
	event.register("loaded", onLoaded)

	```

***

### `table.values`

Returns an array-style table of all values in the given table, t. Optionally, it will sort the returned table.

```lua
local values = table.values(t, sort)
```

**Parameters**:

* `t` (table): The table to get values for.
* `sort` (boolean, function, nil): *Optional*. If true, the returned table will be sorted. If a function is passed, the table will be sorted using the given function.

**Returns**:

* `values` (table): An array of all table values.

***

