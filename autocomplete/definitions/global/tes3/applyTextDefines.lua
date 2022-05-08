return {
	type = "function",
	description = [[Returns a string with all the [text defines](https://en.uesp.net/wiki/Morrowind_Mod:Text_Defines) replaced in the input string. This can be used to replicate the behavior of book and dialogue text.]],
	arguments = { {
		name = "params",
		type = "table",
		tableParams = {
			{ name = "text", type = "string", description = "The input string to do text replacements for." },
			{ name = "actor", type = "tes3actor", description = "The actor to use for replacements like `%Name` and `%Faction`." },
		},
	} },
	returns = {
		{ name = "result", type = "string" },
	},
}
