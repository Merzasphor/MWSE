# re

Provides a regular expression style syntax for pattern usage with lpeg.
	
The documentation provided here is only meant to be a quick reference. Please review the complete
documentation (with in-depth discussion and many examples) at: 
http://www.inf.puc-rio.br/~roberto/lpeg/re.html
	
There is also a copy in the MWSE repo at: deps/lpeg/re.html

## Functions

### `re.compile`

Compiles the given string and returns an equivalent lpeg pattern.
	
The given string may define either an expression or a grammar. The optional defs table provides 
extra Lua values to be used by the pattern.

```lua
local result = re.compile(s, defs)
```

**Parameters**:

* `s` (string): The string to compile.
* `defs` (table): *Optional*. Extra lua values to be used by the pattern.

**Returns**:

* `result` (pattern)

***

### `re.find`

Searches the given pattern in the given subject.
	
If it finds a match, returns the index where this occurrence starts and the index where it ends. 
Otherwise, returns nil.

An optional numeric argument init makes the search starts at that position in the subject string.
As usual in Lua libraries, a negative value counts from the end. 

```lua
local result = re.find(subject, pattern, init)
```

**Parameters**:

* `subject` (string): The string to search.
* `pattern` (string): The pattern to search with.
* `init` (number): *Optional*. Start at this position in the subject string.

**Returns**:

* `result` (number)

??? example "Example: Simple Find"

	```lua
	local re = require("re")
	
	local function onLoaded(e)
	    
		-- find the position of the first numeral in a string
		mwse.log("%d %d", re.find("the number 423 is odd", "[0-9]+"))  --> 12 14
		
	end
	
	event.register("loaded", onLoaded)

	```

***

### `re.gsub`

Does a global substitution, replacing all occurrences of pattern in the given subject by replacement.

```lua
local result = re.gsub(subject, pattern, replacement)
```

**Parameters**:

* `subject` (string): The string to search.
* `pattern` (string): The pattern to search with.
* `replacement` (string): Replace all matches with this string.

**Returns**:

* `result` (string)

??? example "Example: Simple Substitution"

	```lua
	local re = require("re")
	
	local function onLoaded(e)
	
		-- returns a string with all vowels replaced by .
		mwse.log(re.gsub("hello World", "[aeiou]", "."))
		--> h.ll. W.rld
		
	end
	
	event.register("loaded", onLoaded)

	```

***

### `re.match`

Matches the given pattern against the given subject, returning all captures.

```lua
local result = re.match(subject, pattern)
```

**Parameters**:

* `subject` (string): The string to search.
* `pattern` (string): The pattern to search with.

**Returns**:

* `result` (string)

??? example "Example: Simple Match"

	```lua
	local re = require("re")
	
	local function onLoaded(e)
	    
		-- returns all words in a string
		mwse.log("%s %s %s %s", re.match("the number 423 is odd", "({%a+} / .)*"))
		--> the    number    is    odd
	
		-- returns the first numeral in a string
		mwse.log(re.match("the number 423 is odd", "s <- {%d+} / . s"))
		--> 423
		
	end
	
	event.register("loaded", onLoaded)

	```

***

### `re.updatelocale`

Updates the pre-defined character classes to the current locale.

```lua
re.updatelocale()
```

***

