return {
	type = "function",
	description = [[The function returns true if the player is in the vanity mode. Vanity mode is triggered by a period of inactivity from the player or by a `tes3.setVanityMode()` function. The view is switched to third person (if not already), and the camera is orbiting slowly around the player character.]],
	returns = {
		{ name = "result", type = "boolean", description = "Is the vanity mode currently active?" },
	},
}
