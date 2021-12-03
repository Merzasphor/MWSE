return {
	type = "function",
	description = [[Gets the input configuration for a given keybind.]],
	arguments = {
		{ name = "keybind", type = "number", description = "Maps to [`tes3.keybind`](https://mwse.github.io/MWSE/references/keybinds/) constants." }
	},
	returns = "inputConfig",
	valuetype = "tes3inputConfig",
}