return {
	type = "function",
	description = [[Determines if the player has a given lua mod active. The key passed to this function is the path to where its main.lua file is, relative to the MWSE\\mods folder. Slashes are automatically replaced with periods, and the key is case-insensitive.]],
	arguments = {
		{ name = "key", type = "string", description = "The key to check." }
	},
	returns = {
		{ name = "isActive", type = "boolean", description = "True if the mod is active, otherwise false." },
	},
	examples = {
		["GetChameleonActive"] = {
			title = "Determine if a Specific Lua Mod is Active",
			description = "In this example, we determine if [Chameleon](https://www.nexusmods.com/morrowind/mods/47996) is active. The mod provides no interop files to try to `include`, and is a simple main.lua file. This makes it hard to otherwise detect.",
		},
	},
}
