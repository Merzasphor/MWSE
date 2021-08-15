return {
	type = "method",
	description = [[Performs a test for a given keybind, and optionally a transition state.]],
	arguments = {
		{ name = "key", type = "number", description = "The keybind to test. Constants available through `tes3.keybind`." },
		{ name = "transition", type = "number", optional = true, description = "Transition state, e.g. down, or up. Constants available through `tes3.keyTransition`." },
	},
	valuetype = "boolean",
}