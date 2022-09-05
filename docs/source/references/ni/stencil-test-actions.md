---
hide:
  - toc
---

# Stencil Test Actions

!!! tip
	These values are available in Lua by their index in the `ni.stencilTestAction` table. For example, `ni.stencilTestAction.increment` has a value of `3`.

Index     | Value  | Description
--------- | ------ | ----------------
keep      | `0`    | Keep the current value in the stencil buffer.
zero      | `1`    | Write zero to the stencil buffer.
replace   | `2`    | Write the value of `reference` property of niStencilProperty to the stencil buffer.
increment | `3`    | Increment the value in the stencil buffer.
decrement | `4`    | Decrement the value in the stencil buffer.
invert    | `5`    | Bitwise invert the value in the stencil buffer.
