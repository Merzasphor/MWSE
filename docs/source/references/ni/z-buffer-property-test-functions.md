---
hide:
  - toc
---

# Z-Buffer Property Test Functions

!!! tip
	These values are available in Lua by their index in the `ni.zBufferPropertyTestFunction` table. For example, `ni.zBufferPropertyTestFunction.less` has a value of `1`.

!!! note
	Less than means closer to the camera and greater than means farther from the camera, regardless of the low-level hardware representation of Z values.

Index        | Value  | Description
------------ | ------ | -----------------------------------------------
always       | `0`    | Test will allways succeed. The Z Buffer value is ignored.
less         | `1`    | The test will only succeed if the pixel is nearer than the previous pixel.
equal        | `2`    | Test will only succeed if the Z value of the pixel to be drawn is equal to the value of the previous drawn pixel.
lessEqual    | `3`    | Test will succeed if the Z value of the pixel to be drawn is smaller than or equal to the value in the Z Buffer.
greater      | `4`    | The test will only succeed if the pixel is farther than the previous pixel.
notEqual     | `5`    | Test will succeed if the Z value of the pixel to be drawn is NOT equal to the value of the previously drawn pixel.
greaterEqual | `6`    | Test will succeed if the Z value of the pixel to be drawn is bigger than or equal to the value in the Z Buffer.
never        | `7`    | Test will allways return false. Nothing is drawn at all.
