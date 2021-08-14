# mwse.stack

The stack library provides functions to interact with the mwse mwscript stack, for dealing with custom mwscript extensions.

## Functions

### `mwse.stack.clear`

Purges all elements from the stack.

```lua
mwse.stack.clear()
```

***

### `mwse.stack.dump`

Prints all values on the stack in hex format to the log file.

```lua
mwse.stack.dump()
```

***

### `mwse.stack.empty`

Determines if the stack is empty.

```lua
local result = mwse.stack.empty()
```

**Returns**:

* `result` (boolean)

***

### `mwse.stack.popFloat`

Pops a value of mwscript type "float" off of the stack.

```lua
local unnamed1 = mwse.stack.popFloat()
```

**Returns**:

* `unnamed` (number): *Optional*.

***

### `mwse.stack.popLong`

Pops a value of mwscript type "long" off of the stack.

```lua
local unnamed1 = mwse.stack.popLong()
```

**Returns**:

* `unnamed` (number): *Optional*.

***

### `mwse.stack.popObject`

Pops a value of mwscript type "long" off of the stack, and tries to reinterpret as a game object.

```lua
local unnamed1 = mwse.stack.popObject()
```

**Returns**:

* `unnamed` ([tes3baseObject](../../types/tes3baseObject)): *Optional*.

***

### `mwse.stack.popShort`

Pops a value of mwscript type "short" off of the stack.

```lua
local unnamed1 = mwse.stack.popShort()
```

**Returns**:

* `unnamed` (number): *Optional*.

***

### `mwse.stack.popString`

Pops a value of mwscript type "long" off of the stack, and tries to reinterpret as a string.

```lua
local unnamed1 = mwse.stack.popString()
```

**Returns**:

* `unnamed` (string): *Optional*.

***

### `mwse.stack.pushFloat`

Pushes a value of mwscript type "float" onto the stack.

```lua
local result = mwse.stack.pushFloat(value)
```

**Parameters**:

* `value` (number)

**Returns**:

* `result` (nil)

***

### `mwse.stack.pushLong`

Pushes a value of mwscript type "long" onto the stack.

```lua
local result = mwse.stack.pushLong(value)
```

**Parameters**:

* `value` (number)

**Returns**:

* `result` (nil)

***

### `mwse.stack.pushObject`

Pushes a value of mwscript type "long" onto the stack, which matches the address of a given game object.

```lua
local result = mwse.stack.pushObject(value)
```

**Parameters**:

* `value` ([tes3baseObject](../../types/tes3baseObject))

**Returns**:

* `result` (nil)

***

### `mwse.stack.pushShort`

Pushes a value of mwscript type "short" onto the stack.

```lua
local result = mwse.stack.pushShort(value)
```

**Parameters**:

* `value` (number)

**Returns**:

* `result` (nil)

***

### `mwse.stack.pushString`

Adds a string to mwse's string storage, and pushes a value of mwscript type "long" onto the stack that represents the string.

```lua
local result = mwse.stack.pushString(value)
```

**Parameters**:

* `value` (string)

**Returns**:

* `result` (nil)

***

### `mwse.stack.size`

Returns the number of elements currently on the stack.

```lua
local result = mwse.stack.size()
```

**Returns**:

* `result` (number)

***

