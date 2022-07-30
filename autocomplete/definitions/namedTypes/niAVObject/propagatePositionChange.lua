return {
	type = "method",
	description = [[Alias for `update()` method. Updates the world transforms of this node and its children, which makes changes visible for rendering. Use after changing any local rotation, translation, scale, or bounds.]],
	arguments = {{
			name = "args",
			optional = true,
			type = "table",
			tableParams = {
				{ name = "time", type = "number", optional = true, default = 0, description = "" },
				{ name = "controllers", type = "boolean", optional = true, default = false, description = "Update object's controllers." },
				{ name = "bounds", type = "boolean", optional = true, default = true, description = "Update object's bounds." },
			}
		},
	}
}