
xOr
========================================================

**Parameters:**

- ``long`` **leftValue**: First value for the logical operation.
- ``long`` **rightValue**: Second value for the logical operation.

**Returned:**

- ``long`` **result**: 1 if the logical operation returns true.

This function performs an OR logical operation, and returns its result. An OR operation returns true if either of the values are non-zero.

= = =======
A B xOr A B
= = =======
0 0 0
0 1 1
1 0 1
1 1 1
= = =======
