return {
	type = "method",
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "force", type = "boolean", optional = true, default = "true" },
			{ name = "isResettingData", type = "boolean", optional = true, default = "false" },
			{ name = "resetCollisionGroups", type = "boolean", optional = true, default = "true" }
		}
	}},
}