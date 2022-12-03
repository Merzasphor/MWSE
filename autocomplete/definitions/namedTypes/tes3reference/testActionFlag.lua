return {
	type = "method",
	description = [[Returns the flag's value in the reference's action data attachment.]],
	arguments = {
		{ name = "flagIndex", type = "integer", description = "The action flag to test. Maps to values in [`tes3.actionFlag`](https://mwse.github.io/MWSE/references/action-flags/) namespace." },
	},
	valuetype = "boolean",
}