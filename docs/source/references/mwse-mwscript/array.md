# Array Functions

--8<-- "mwse-deprecated.md"


## `xClearArray`

**Parameters:**

- ``long`` **arrayId**: The id of the array to clear.

**Returned:**

- ``long`` **result**: `1` if the array was successfully cleared.

This function clears an array, removing any values from it.


***

## `xCreateArray`

**Parameters:**

- *None*

**Returned:**

- ``long`` **arrayId**: The id of the array that was created.

This function creates an empty array, and returns the id of it.


***

## `xGetArraySize`

**Parameters:**

- ``long`` **arrayId**: The id of the array.

**Returned:**

- ``long`` **size**: The number of elements in the array.

This function determines the size of an array.


***

## `xGetArrayValue`

**Parameters:**

- ``long`` **arrayId**: The id of the array to get a value from.
- ``long`` **index**: The index in the array to fetch.

**Returned:**

- ``long`` **value**: The value in the array at the given **index**.

This function retrieves a value in an array, identified by **arrayId** and at **index**.


***

## `xSetArrayValue`

**Parameters:**

- ``long`` **arrayId**: The id of the array to get a value from.
- ``long`` **index**: The index in the array to fetch.
- ``long`` **value**: The value to set into the array.

**Returned:**

- ``short`` **status**: `1` if the value was set, otherwise 0.

This function retrieves sets a value in an array, identified by **arrayId** and at **index**.