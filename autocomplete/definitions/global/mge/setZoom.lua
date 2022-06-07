return {
	type = "function",
	deprecated = true,
	description = [[Sets the zoom to a specified amount. Use `mge.camera.zoom = amount` instead.]],
	arguments = { {
		name = "params",
		type = "table",
		tableParams = {
			{ name = "amount", type = "number" },
		},
	} },
}
