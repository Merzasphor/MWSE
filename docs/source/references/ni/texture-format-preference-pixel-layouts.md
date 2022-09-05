---
hide:
  - toc
---

# Texture Format Preference Pixel Layouts

!!! tip
	These values are available in Lua by their index in the `ni.textureFormatPrefsPixelLayout` table. For example, `ni.textureFormatPrefsPixelLayout.trueColor32` has a value of `2`.

Index       | Value  | Description
----------- | ------ | ----------------
palettized8 | `0`    | Texture prefers an 8 bit palettized format (with or without alpha).
highColor16 | `1`    | Texture prefers a 16-bit per pixel RGB(A) format.
trueColor32 | `2`    | Texture prefers a 24/32-bit per pixel RGB(A) format.
compressed  | `3`    | Texture prefers a compressed format.
bumpMap     | `4`    | Texture prefers a Bump-map format.
default     | `5`    | Texture can use whatever format best matches the source data.
