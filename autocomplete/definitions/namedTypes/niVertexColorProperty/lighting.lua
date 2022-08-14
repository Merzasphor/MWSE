return {
	type = "value",
	description = [[Describes how vertex colors influence lighting.

Value | Mode                   | Description
----- | ---------------------- | -----------------
0     | LIGHT_MODE_EMISSIVE    | Only the emissive component of the lighting equation is used. No dynamic lights are considered in the lighting process.
1	  | LIGHT_MODE_EMI_AMB_DIF | The emissive, ambient, and diffuse components of the lighting equation are all used.]],
	valuetype = "integer",
}