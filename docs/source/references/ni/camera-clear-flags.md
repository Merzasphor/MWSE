---
hide:
  - toc
---

# Camera clear flags

!!! tip
	These values are available in Lua by their index in the `ni.cameraClearFlags` table. For example, `ni.cameraClearFlags.backBuffer` has a value of `1`.

Index       | Value  | Description
------------| ------ | ------------------------
backBuffer  | `1`    | Clears the back buffer (color buffer).
stencil     | `2`    | Clears the stencil buffer.
zBuffer     | `4`    | Clears the Z buffer.
all         | `7`    | Clears all buffers.