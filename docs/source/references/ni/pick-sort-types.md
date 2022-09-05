---
hide:
  - toc
---

# Pick Sort Types

!!! tip
	These values are available in Lua by their index in the `ni.pickSortType` table. For example, `ni.pickSortType.sort` has a value of `0`.

Index  | Value  | Description
------ | ------ | ----------------
sort   | `0`    | The points returned by picking opertion will be sorted along the distance from the ray origin.
noSort | `1`    | The points returned by picking opertion will not be sorted.
