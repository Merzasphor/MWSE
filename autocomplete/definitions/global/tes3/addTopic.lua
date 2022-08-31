return {
	type = "function",
	description = [[Adds a topic to the valid topic list for the player. This doesn't create a dynamic new topic.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "topic", type = "tes3dialogue|string", description = "The topic to add" },
			{ name = "updateGUI", type = "boolean", optional = true, default = true, description = "If true, the GUI will be updated respecting the adding of the topic." },
		},
	}},
	returns = {
		{ name = "wasAdded", type = "boolean", description = "True if the topic was successfully added. This can be false if the topic already existed in the player's list." },
	}
}