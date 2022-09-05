---
hide:
  - toc
---

# Stencil Test Functions

!!! tip
	These values are available in Lua by their index in the `ni.stencilTestFunction` table. For example, `ni.stencilTestFunction.equal` has a value of `2`.

Index        | Value  | Description
------------ | ------ | ----------------
never        | `0`    | Test will allways return false. Nothing is drawn at all.
less         | `1`    | The test will only succeed if the pixel is nearer than the previous pixel.
equal        | `2`    | Test will only succeed if the z value of the pixel to be drawn is equal to the value of the previously drawn pixel.
lessEqual    | `3`    | Test will succeed if the z value of the pixel to be drawn is smaller than or equal to the value in the Stencil Buffer.
greater      | `4`    | The test will only succeed if the pixel is farther than the previous pixel.
notEqual     | `5`    | Test will succeed if the z value of the pixel to be drawn is NOT equal to the value of the previously drawn pixel.
greaterEqual | `6`    | Test will succeed if the z value of the pixel to be drawn is bigger than or equal to the value in the Stencil Buffer.
always       | `7`    | Test will allways succeed. The Stencil Buffer value is ignored.
