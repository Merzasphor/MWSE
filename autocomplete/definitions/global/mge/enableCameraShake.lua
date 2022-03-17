return {
	type = "function",
	description = [[Enables MGE XE's camera shake effect. Wrapper for mwscript's MGEEnableCameraShake.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "magnitude", type = "number", optional = true },
			{ name = "acceleration", type = "number", optional = true },
		},
	}},
}