---
hide:
  - toc
---

# Animation Types

!!! tip
	These values are available in Lua by their index in the `ni.animType` table. For example, `ni.animType.appTime` has a value of `0`.

Index    | Value  | Description
-------- | ------ | ------------------------
appTime  | `0`    | The time controller will simply use the Update time (after applying the frequency and phase modifications) to directly interpolate the state of the animation.
appInit  | `1`    | The time controller will use the modified Update time to determine how long it has been since the animation has started playing and then use that local time to interpolate the state of the animation.
