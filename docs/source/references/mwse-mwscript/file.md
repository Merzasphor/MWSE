# File Functions

--8<-- "mwse-deprecated.md"


## `xFileReadFloat`

**Parameters:**

- `string` **filename**: The file to read values from.
- `long` **count**: The number of values desired.

**Returned:**

- `long` **valuesRead**: The number of results actually read. This may differ from **count** if it encountered an error while reading.
- `float` **value**: A value read. A number of values are returned equal to **valuesRead**.

Reads a number of `float` (4 byte) values requested from **filename** at the current reading position. The current position is then advanced. Returns the number of values actually read (**valuesRead**) followed by the values.


***

## `xFileReadLong`

**Parameters:**

- `string` **filename**: The file to read values from.
- `long` **count**: The number of values desired.

**Returned:**

- `long` **valuesRead**: The number of results actually read. This may differ from **count** if it encountered an error while reading.
- `long` **value**: A value read. A number of values are returned equal to **valuesRead**.

Reads a number of `long` (4 byte) values requested from **filename** at the current reading position. The current position is then advanced. Returns the number of values actually read (**valuesRead**) followed by the values.


***

## `xFileReadShort`

**Parameters:**

- `string` **filename**: The file to read values from.
- `long` **count**: The number of values desired.

**Returned:**

- `long` **valuesRead**: The number of results actually read. This may differ from **count** if it encountered an error while reading.
- `short` **value**: A value read. A number of values are returned equal to **valuesRead**.

Reads a number of `short` (2 byte) values requested from **filename** at the current reading position. The current position is then advanced. Returns the number of values actually read (**valuesRead**) followed by the values.


***

## `xFileReadString`

**Parameters:**

- `string` **filename**: The file to read values from.

**Returned:**

- `string` **value**: The value read from the file.

Reads from **filename** at the current reading position, until a C-style null terminator (`\0`/`0x00`) is read. The current position is advanced as read, and the resultant bytes are returned as a string.


***

## `xFileReadText`

**Parameters:**

- `string` **filename**: The file to read values from.
- `string` **pattern**: The pattern to match when reading.

**Returned:**

- `long` **numMatches**: The number of values read.
- `varies` **matches**: A value returned. A number of values will be returned matching **numMatches**.

xFileReadText reads a text string from from the file at the current reading position. The current position is then advanced. The **pattern** string is then used to extract data from the string just read; the first return value indicates how much of the pattern is matched. The values matched by the pattern are also returned.

The **pattern** and return values are the same as for the `xStringParse` function with one addition: placing a single `%` sign at the end of the pattern will cause the read routine to stop when it gets to the end of a line (CR/LF) allowing you to use this to read a normal text file instead of a binary file. Without the trailing % sign on the pattern this will read up to the first NULL character or to the end of the file if it doesn't find a NULL character.


***

## `xFileRewind`

**Parameters:**

- `string` **filename**: The file to rewind.

**Returned:**

- *None*

This function moves the current reading position to the start of the file.

Call this or `xFileSeek` at the start of any script which uses file reading or writing functions, otherwise you will have problems with the current file position not being as expected.


***

## `xFileSeek`

**Parameters:**

- `string` **filename**: The file to seek in.
- `long` **position**: 

**Returned:**

- *None*

This function moves the current reading position to the specified offset in the file.

You should call this or `xFileRewind` every frame before using other file functions. Use an offset divisible by 2 to read shorts and an offset divisible by 4 to read longs.

This function isn't very useful if the file contains string data.


***

## `xFileWriteFloat`

**Parameters:**

- `string` **filename**: The file to write value to.
- `float` **value**: The value to write to file.

**Returned:**

- *None*

Writes a `float` (4 byte) **value** to **filename** at the current position. The current position is then advanced.

!!! note
	The file is truncated at the current position (just after the end of the new value). This means that you cannot use this to modify the values in the middle of an existing file.


***

## `xFileWriteLong`

**Parameters:**

- `string` **filename**: The file to write value to.
- `long` **value**: The value to write to file.

**Returned:**

- *None*

Writes a `long` (4 byte) **value** to **filename** at the current position. The current position is then advanced.

!!! note
	The file is truncated at the current position (just after the end of the new value). This means that you cannot use this to modify the values in the middle of an existing file.


***

## `xFileWriteShort`

**Parameters:**

- `string` **filename**: The file to write value to.
- `short` **value**: The value to write to file.

**Returned:**

- *None*

Writes a `short` (2 byte) **value** to **filename** at the current position. The current position is then advanced.

!!! note
	The file is truncated at the current position (just after the end of the new value). This means that you cannot use this to modify the values in the middle of an existing file.


***

## `xFileWriteString`

**Parameters:**

- `string` **filename**: The file to write value to.
- `string` **value**: The value to write to file.

**Returned:**

- *None*

Writes a `string` **value** to **filename** at the current position. The string is stored in the file as a C-style null-terminated string. The current position is then advanced.

!!! note
	The file is truncated at the current position (just after the end of the new value). This means that you cannot use this to modify the values in the middle of an existing file.


***

## `xFileWriteText`

**Parameters:**

- `string` **filename**: The file to write value to.
- `string` **format**: The format to use when writing to the file.
- `varies` **values**: Multiple values that match the **format**.

**Returned:**

- *None*

Writes a formatted `string` to the file at the current position and advances. 

The formatting rules are the same as for the `xStringBuild` function with one addition. Placing a `%` at the end of the pattern will suppress the NULL that is normally printed, so a format string ending with `%N%` can be used to create a normal text file.

!!! note
	The file is truncated at the current position (just after the end of the new value). This means that you cannot use this to modify the values in the middle of an existing file.