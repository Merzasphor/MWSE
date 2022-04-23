return {
	type = "function",
	description = [[Gets a standard palette color. Returns an array containing the RGB color values, in the range [0.0, 1.0].]],
	arguments = {
		{ name = "name", type = "string", description = "The name of the palette color. Maps to values in [`tes3.palette`](https://mwse.github.io/MWSE/references/palettes/) enumeration." },
	},
	returns = {{ name = "palette", type = "number[]", description = "An array containing the RGB color values, in the range [0.0, 1.0]." }},
}
