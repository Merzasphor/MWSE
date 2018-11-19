return {
	type = "function",
	description = [[Loads the given module. The function starts by looking into the package.loaded table to determine whether modname is already loaded. If it is, then require returns the value stored at package.loaded[modname]. Otherwise, it tries to find a loader for the module. If no module could be found, it returns nil instead of erroring.]],
	arguments = {
		{ name = "modname", type = "string" },
	},
	valuetype = "table",
}