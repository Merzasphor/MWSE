return {
	type = "operator",
	overloads = {
		{ rightType = "niColor", resultType = "niColor", description = "Multiplies color channel values." },
		{ rightType = "number", resultType = "niColor", description = "Multiplies each color value with a scalar." },
	}
}
