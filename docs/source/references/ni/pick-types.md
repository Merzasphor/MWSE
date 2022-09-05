---
hide:
  - toc
---

# Pick Types

!!! tip
	These values are available in Lua by their index in the `ni.pickType` table. For example, `ni.pickType.findAll` has a value of `0`.

Index     | Value  | Description
--------- | ------ | ----------------
findAll   | `0`    | The picking operation continues for the `maxDistance` units given to the `pickObjects` method.
findFirst | `1`    | The picking operation will end at first intersection.
