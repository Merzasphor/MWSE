return {
	type = "function",
	description = [[Loads the given module. This functions identically to `require`, but will return `nil` instead of erroring if the module couldn't be found.

The function starts by looking into the `package.loaded` table to determine whether `modname` is already loaded. If it is, then `include` returns the value stored at `package.loaded[modname]`. Otherwise, it tries to find a loader for the module.

Intended use case for this function is for making interoperability between mods. You shouldn't `include` your own file, since any errors in the `include`d file will just be printed in the log as error on the `include` line. In other words, include is only used to check if a certain optional mod is present.]],
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