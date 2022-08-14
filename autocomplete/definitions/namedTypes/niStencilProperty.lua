return {
	type = "class",
	description = [[A rendering property that controls the use of a stencil buffer when rendering. Stencil buffering allows effects such as cutouts in a screen, decal polygons without Z-buffer "aliasing", and advanced effects such as volumetric shadows. It also includes a draw-mode setting to allow the game engine to control the culling mode of a set of geometry.

This table describes the actions that can be set to occur as a result of tests for niStencilProperty:

Value | Mode             | Description
----- | ---------------- | -------------
0     | ACTION_KEEP      | Keep the current value in the stencil buffer.
1	  | ACTION_ZERO      | Write zero to the stencil buffer.
2	  | ACTION_REPLACE   | Write the reference value to the stencil buffer.
3	  | ACTION_INCREMENT | Increment the value in the stencil buffer.
4     | ACTION_DECREMENT | Decrement the value in the stencil buffer.
5     | ACTION_INVERT    | Bitwise invert the value in the stencil buffer.]],
	inherits = "niProperty",
}