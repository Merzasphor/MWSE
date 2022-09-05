---
hide:
  - toc
---

# Texturing Property Filter Modes

!!! tip
	These values are available in Lua by their index in the `ni.texturingPropertyFilterMode` table. For example, `ni.texturingPropertyFilterMode.bilerpMipNearest` has a value of `5`.

Index             | Value  | Description
----------------- | ------ | -----------------------------------------------
nearest           | `0`    | Uses nearest neighbor, with no mipmapping. The most common reason to use nearest neighbor filtering is to achieve a "blocky" effect.
bilerp            | `1`    | Uses bilinear interpolation with no mipmapping. It linearly interpolates between the four texels that enclose the texture coordinate. It causes the texture to look blurry.
trilerp           | `2`    | Uses bilinear interpolation on each of the two nearest mipmap levels, then performs linear mipmap interpolation between the results.
nearestMipNearest | `3`    | Uses "nearest level mipmapping", then uses nearest neighbor on the result.
nearestMipLerp    | `4`    | Uses nearest neighbor on each of the two nearest mipmap levels and then performs linear mipmap interpolation between the results.
bilerpMipNearest  | `5`    | Uses "nearest level mipmapping", then uses "bilinear interpolation" on the result.
