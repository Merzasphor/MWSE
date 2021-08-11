# Logic Functions

--8<-- "mwse-deprecated.md"


## `xAnd`

**Parameters:**

- ``long`` **leftValue**: First value for the logical operation.
- ``long`` **rightValue**: Second value for the logical operation.

**Returned:**

- ``long`` **result**: 1 if the logical operation returns true.

This function performs an AND logical operation, and returns its result. An AND operation returns true if both of the values are non-zero.

A | B | `xAnd A B`
- | - | ----------
0 | 0 | 0
0 | 1 | 0
1 | 0 | 0
1 | 1 | 1


***

## `xNot`

**Parameters:**

- ``long`` **value**: Value for the logical operation.

**Returned:**

- ``long`` **result**: 1 if the logical operation returns true.

This function performs a NOT logical operation, and returns its result. A NOT operation returns true if its parameter is zero.

A | `xNot A`
- | --------
0 | 1
1 | 0


***

## `xOr`

**Parameters:**

- ``long`` **leftValue**: First value for the logical operation.
- ``long`` **rightValue**: Second value for the logical operation.

**Returned:**

- ``long`` **result**: 1 if the logical operation returns true.

This function performs an OR logical operation, and returns its result. An OR operation returns true if either of the values are non-zero.

A | B | `xOr A B`
- | - | ---------
0 | 0 | 0
0 | 1 | 1
1 | 0 | 1
1 | 1 | 1


***

## `xXor`

**Parameters:**

- ``long`` **leftValue**: First value for the logical operation.
- ``long`` **rightValue**: Second value for the logical operation.

**Returned:**

- ``long`` **result**: 1 if the logical operation returns true.

This function performs an XOR logical operation, and returns its result. An XOR operation returns true if one of the values is non-zero, but not both.

A | B |` xXor A B`
- | - | ----------
0 | 0 | 0
0 | 1 | 1
1 | 0 | 1
1 | 1 | 0