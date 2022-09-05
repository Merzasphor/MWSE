---
hide:
  - toc
---

# Billboard Modes

!!! tip
	These values are available in Lua by their index in the `ni.billboardMode` table. For example, `ni.billboardMode.rotateAboutUp` has a value of `1`.

Index             | Value  | Description
----------------- | ------ | ------------------------
alwaysFaceCamera  | `0`    | Causes the model-space z-vector to be in line with the camera's view plane normal. In other words, any plane of constant z in model space will have its normal parallel to the camera's direction vector. Each frame, the rotation required to reestablish this orientation is minimized. As a result, this mode may differ from rigidFaceCamera.
rotateAboutUp     | `1`    | Causes the model-space z-vector of the billboard to be as close as possible to the camera's direction vector while only allowing rotation about the billboard's model-space up-axis [0,1,0]. This mode is useful for simulating cylindrically symmetric objects, such as light posts and trees, using a single cross-sectional flat image.
rigidFaceCamera   | `2`    | The billboard has a normal that is always parallel to the camera's direction vector and the billboard and camera coordinate frames change rigidly together.
