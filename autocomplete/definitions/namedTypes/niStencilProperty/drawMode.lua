return {
	type = "value",
	description = [[The face drawing (culling) mode used to draw the object.

Value | Mode             | Behavior
----- | ---------------- | ---------
0     | DRAW_CCW_OR_BOTH | The default mode, chooses between DRAW_CCW or DRAW_BOTH.
1	  | DRAW_CCW         | Draw only the triangles whose vertices are ordered counter-clockwise with respect to the viewer (Standard behavior).
2	  | DRAW_CW          | Draw only the triangles whose vertices are ordered clockwise with respect to the viewer (Effectively flips the faces).
3	  | DRAW_BOTH        | Do not cull back faces of any kind. Draw all triangles, regardless of orientation (Effectively force double-sided).]],
	valuetype = "integer",
}
