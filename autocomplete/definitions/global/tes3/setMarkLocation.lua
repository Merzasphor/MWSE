return {
	type = "function",
	description = [[This function sets the player's mark location to the one specified.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "position", type = "tes3vector3|number[]", description = "Coordinates of the mark's position." },
			{ name = "rotation", type = "number", optional = true, default = "tes3.player.orientation.z", description = "This argument controls which direction the player's mark location will be facing." },
			{ name = "cell", type = "tes3cell", optional = true, description = "A cell in which the mark should be placed. This argument is unnecessary when setting the Mark's location to an exterior cell." },
		},
	}},
}
