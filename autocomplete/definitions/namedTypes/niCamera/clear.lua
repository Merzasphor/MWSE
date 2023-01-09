return {
	type = "method",
	description = [[This method clears the current render target of the camera's renderer. Uses flag values from [`ni.cameraClearFlags`](https://mwse.github.io/MWSE/references/ni/camera-clear-flags/).]],
	arguments = {
		{ name = "flags", type = "number", optional = true, default = "ni.cameraClearFlags.all" },
	},
}