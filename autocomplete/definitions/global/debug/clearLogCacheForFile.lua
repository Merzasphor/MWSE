return {
	type = "function",
	description = [[Clears any prefix information from cache for use with `debug.log`. This is useful if your file loads dynamically via `dofile`, and is subject to change during development.]],
	arguments = {
		{ name = "file", type = "string?", description = "The path to the file. If omitted, the calling file will have its associated log cache removed." },
	},
}
