
xFileReadShort
========================================================

**Parameters:**

- ``string`` **filename**: The file to read values from.
- ``long`` **count**: The number of values desired.

**Returned:**

- ``long`` **valuesRead**: The number of results actually read. This may differ from **count** if it encountered an error while reading.
- ``short`` **value**: A value read. A number of values are returned equal to **valuesRead**.

Reads a number of ``short`` (2 byte) values requested from **filename** at the current reading position. The current position is then advanced. Returns the number of values actually read (**valuesRead**) followed by the values.
