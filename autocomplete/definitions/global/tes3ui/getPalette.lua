return {
	type = "function",
	description = [[Gets a standard palette color. Returns an array containing the RGB color values, in the range [0.0, 1.0].

![Palette colors](https://raw.githubusercontent.com/MWSE/MWSE/master/docs/source/assets/images/ui%20palletes.png)

*Above: All the palette colors in-game with default settings. Note that some entries are entirely black. In order of appearance, those are backgroundColor, blackColor, and journalTopicColor.*
]],
	arguments = {
		{ name = "name", type = "string", description = "The name of the palette color. Maps to values in [`tes3.palette`](https://mwse.github.io/MWSE/references/palettes/) enumeration." },
	},
	returns = {{ name = "palette", type = "number[]", description = "An array containing the RGB color values, in the range [0.0, 1.0]." }},
	examples = {
		["example"] = {
			title = "Here is the code used to construct the menu from the image above. This can be used to preview in-game all the available color palettes."
		}
	}
}
