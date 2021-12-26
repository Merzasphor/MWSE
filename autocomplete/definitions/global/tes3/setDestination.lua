return {
	type = "function",
	description = [[Sets or changes the destination of a door to a new location.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3reference", description = "The door reference that will be updated." },
			{ name = "position", type = "tes3vector3|table", description = "The new coordinates of the transition." },
			{ name = "orientation", type = "tes3vector3|table", description = "The new rotation to use after transition." },
			{ name = "cell", type = "tes3cell|string", optional = true, description = "The cell to transition to, if transitioning to an interior." },
		},
	}},
}