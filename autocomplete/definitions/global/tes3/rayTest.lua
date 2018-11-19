return {
	type = "function",
	description = [[Preforms a ray test and returns various information related to the result(s). If findAll is set, the result will be a table of results, otherwise only the first result is returned.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "position", type = "tes3vector3|table" },
			{ name = "direction", type = "tes3vector3|table" },
			{ name = "findAll", type = "boolean", default = false, description = "If true, the ray test won't stop after the first result." },
			{ name = "sort", type = "boolean", default = true, description = "If true, the results will be sorted by distance from the origin position." },
			{ name = "useModelBounds", type = "boolean", default = false, description = "If true, model bounds will be tested for intersection. Otherwise triangles will be used." },
			{ name = "useModelCoordinates", type = "boolean", default = false, description = "If true, model coordinates will be used instead of world coordinates." },
			{ name = "useBackTriangles", type = "boolean", default = false },
			{ name = "observeAppCullFlag", type = "boolean", default = true },
			{ name = "returnColor", type = "boolean", default = false },
			{ name = "returnNormal", type = "boolean", default = true },
			{ name = "returnSmoothNormal", type = "boolean", default = false },
			{ name = "returnTexture", type = "boolean", default = false },
		},
	}},
	returns = "result",
	valuetype = "niPickRecord",
}
