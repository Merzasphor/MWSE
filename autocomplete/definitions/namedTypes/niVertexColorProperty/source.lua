return {
	type = "value",
	description = [[Determines how vertex and material colors are mixed on subclasses of niAVObject.

Value | Mode                   | Description
----- | ---------------------- | -----------------
0     | VERT_MODE_SRC_IGNORE   | Emissive, ambient, and diffuse colors are all specified by the niMaterialProperty.
1	  | VERT_MODE_SRC_EMISSIVE | Emissive colors are specified by the source vertex colors. Ambient and Diffuse are specified by the niMaterialProperty.
2	  | VERT_MODE_SRC_AMB_DIF  | Ambient and Diffuse colors are specified by the source vertex colors. Emissive is specified by the niMaterialProperty (Default).]],
	valuetype = "integer",
}