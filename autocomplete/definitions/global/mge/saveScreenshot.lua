return {
	type = "function",
	description = "Saves a screenshot.",
	arguments = {{
		name = "params",
		type = "table",
		optional = true,
		tableParams = {
			{ name = "path", type = "string", "The location of the folder to save the screenshot to. Relative to the Morrowind directory. *Needs* to include the file format extension." },
			{ name = "captureWithUI", type = "boolean", optional = true, default = false, description = "If set to `true`, the screenshot will include the user interface." },
		},
	}},
}
