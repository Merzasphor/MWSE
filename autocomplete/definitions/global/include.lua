return {
	type = "function",
	description = [[Loads the given module. This functions identically to `require`, but will return `nil` instead of erroring if the module couldn't be found. If there is another error is found inside the included file, it will still cause an error in the `include`ing file.

The function starts by looking into the `package.loaded` table to determine whether `modname` is already loaded. If it is, then `include` returns the value stored at `package.loaded[modname]`. Otherwise, it tries to find a loader for the module.

Intended use case for this function is for making interoperability between mods.]],
	arguments = {
		{ name = "modname", type = "string" },
	},
	valuetype = "table|nil",
	examples = {
		["include\\includeExample"] = {
			title = "Example",
			description = "How to check whether a user has an optional module installed.",
		}
	}
}