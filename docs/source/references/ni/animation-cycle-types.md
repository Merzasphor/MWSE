---
hide:
  - toc
---

# Animation Cycle Types

!!! tip
	These values are available in Lua by their index in the `ni.animCycleType` table. For example, `ni.animCycleType.reverse` has a value of `2`.

Index   | Value  | Description
------- | ------ | ------------------------
loop    | `0`    | At the end of the animation, it's looped again from the beginning.
reverse | `2`    | At the end of the animation, it's played in reverse achieving a ping-pong effect.
clamp   | `4`    | Animation stops at the end.
