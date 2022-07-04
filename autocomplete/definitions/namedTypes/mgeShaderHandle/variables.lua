return {
	type = "value",
	description = [[Lists the shader's editable variables. The result table has the variable names as keys, and the variable types as values. To get and set the actual variable, use the expression `shaderHandle.<variableName>`.

	Variable types are:
	'b' boolean
	'i' integer
	'f' float
	's' string
	'a' float array
	'2' vec2
	'3' vec3
	'4' vec4
	'm' matrix]],
	valuetype = "table<string, string>",
}