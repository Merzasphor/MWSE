# mwse

The mwse library provides methods for interacting with MWSE itself, rather than direct TES3 objects.

## Properties

### `mwse.buildDate`

A numerical representation of the date that version of MWSE currently being used was built on.

Formatted as YYYYMMDD.

**Returns**:

* `result` (number)

??? example "Example: Check if the user has minimal required MWSE build installed."

	```lua
	-- Ensure we have the features we need.
	if (mwse.buildDate == nil or mwse.buildDate < 20210817) then
		mwse.log("[Example] Build date of %s does not meet minimum build date of 20210817.", mwse.buildDate)
		return
	end

	```

***

### `mwse.gameTimers`

The mwseTimerController responsible for game-type timers.

**Returns**:

* `result` ([mwseTimerController](../../types/mwseTimerController))

***

### `mwse.realTimers`

The mwseTimerController responsible for real-type timers.

**Returns**:

* `result` ([mwseTimerController](../../types/mwseTimerController))

***

### `mwse.simulateTimers`

The mwseTimerController responsible for simulate-type timers.

**Returns**:

* `result` ([mwseTimerController](../../types/mwseTimerController))

***

### `mwse.version`

A numerical representation of the release version of MWSE currently being used.

Formatted as AAABBBCCC, where A is the major version, BBB is the minor version, and CCC is the patch version. BBB and CCC are forward-padded.

It is usually better to use `mwse.buildDate` instead.

**Returns**:

* `result` (number)

***

## Functions

### `mwse.clearScriptOverride`

Configures MWSE to no longer execute a lua function instead when a script would run. This undoes the work of `mwse.overrideScript`.

```lua
local result = mwse.clearScriptOverride(scriptId)
```

**Parameters**:

* `scriptId` (string)

**Returns**:

* `result` (boolean)

***

### `mwse.getVersion`

Equivalent to mwse.version.

```lua
local result = mwse.getVersion()
```

**Returns**:

* `result` (number)

***

### `mwse.getVirtualMemoryUsage`

Returns the amount of memory used, in bytes.

```lua
local result = mwse.getVirtualMemoryUsage()
```

**Returns**:

* `result` (number)

***

### `mwse.loadConfig`

Loads a config table from Data Files\\MWSE\\config\\{fileName}.json.
	
If the default values table is passed, empty keys in the config will be filled in using its values. Additionally, if no file exists, the function will return the default table.

```lua
local result = mwse.loadConfig(fileName, defaults)
```

**Parameters**:

* `fileName` (string): The non-extensioned name of the config file.
* `defaults` (table): *Optional*. A table of default values.

**Returns**:

* `result` (table)

***

### `mwse.loadTranslations`

Loads translations from the i18n folder for a given mod. This is locale-aware, using the result from `tes3.getLanguage()`. See the [mod translations guide](https://mwse.github.io/MWSE/guides/mod-translations/) for more information.

```lua
local i18n = mwse.loadTranslations(mod)
```

**Parameters**:

* `mod` (string): Name of the folder that your main.lua mod can be found in.

**Returns**:

* `i18n` (function): The callable translation results.

***

### `mwse.log`

This function writes information to the mwse.log file in the user's installation directory.

The message accepts formatting and additional parameters matching string.format's usage.

```lua
mwse.log(message, formatValues)
```

**Parameters**:

* `message` (string)
* `formatValues` (variadic): *Optional*.

***

### `mwse.longToString`

Converts a TES3 object type (e.g. from tes3.objectType) into an uppercase, 4-character string.

```lua
local result = mwse.longToString(type)
```

**Parameters**:

* `type` (number)

**Returns**:

* `result` (string)

***

### `mwse.overrideScript`

Configures MWSE to execute a given function instead when a script would run.

```lua
local result = mwse.overrideScript(scriptId, callback)
```

**Parameters**:

* `scriptId` (string)
* `callback` (function)

**Returns**:

* `result` (boolean)

***

### `mwse.saveConfig`

Saves a config table to Data Files\\MWSE\\config\\{fileName}.json.

```lua
local result = mwse.saveConfig(fileName, object, config)
```

**Parameters**:

* `fileName` (string)
* `object` (unknown)
* `config` (table): *Optional*.

**Returns**:

* `result` (table)

***

### `mwse.stringToLong`

Converts an uppercase, 4-character string into a TES3 object type.

```lua
local result = mwse.stringToLong(tag)
```

**Parameters**:

* `tag` (string)

**Returns**:

* `result` (number)

***

