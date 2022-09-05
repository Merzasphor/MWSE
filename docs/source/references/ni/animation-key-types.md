---
hide:
  - toc
---

# Animation Key Types

!!! tip
	These values are available in Lua by their index in the `ni.animationKeyType` table. For example, `ni.animationKeyType.tcb` has a value of `3`.

Index    | Value  | Description
-------- | ------ | ------------------------
noInterp | `0`    | Don't use interpolation.
linear   | `1`    | Linear interpolation.
bezier   | `2`    | Bezier (actually Hermite) interpolation.
tcb      | `3`    | Tension-Continuity-Bias interpolation.
TCB      | `3`    |
euler    | `4`    | Euler interpolation — only applies to interpolation of rotation in `niEulerRotKey`s.
