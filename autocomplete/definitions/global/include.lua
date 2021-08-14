return {
	type = "function",
	description = [[Loads the given module. This functions identically to `require`, but will return `nil` instead of erroring if the module couldn't be found.

The function starts by looking into the `package.loaded` table to determine whether `modname` is already loaded. If it is, then require returns the value stored at `package.loaded[modname]`. Otherwise, it tries to find a loader for the module.]],
	arguments = {
		{ name = "modname", type = "string" },
	},
	valuetype = "table|nil",
}