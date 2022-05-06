return {
	type = "value",
	description = [[A table of x/y/z rotation keys. Each value in the table is an array of animation keys, with a length matching `numKeys`. Because an axis key can be `nil`, use `pairs` instead of `ipairs` to iterate over this table.]],
	valuetype = "table<number, niFloatKey[]>",
	readOnly = true,
}
