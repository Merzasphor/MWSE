return {
	type = "function",
	description = [[Returns both the viewport width and the viewport height. Note that this is the real resolution of the screen. For a value scaled by MGE's menu scaling, see the [same-named function](https://mwse.github.io/MWSE/apis/tes3ui/#tes3uigetviewportsize) in the tes3ui namespace. To get the scale used, check [getViewportScale](https://mwse.github.io/MWSE/apis/tes3ui/#tes3uigetviewportscale) in the tes3ui namespace.]],
	returns = {
		{ name = "width", type = "number", description = "The width of the viewport." },
		{ name = "height", type = "number", description = "The height of the viewport." },
	}
}
