return {
	type = "value",
	description = [[An array containing texture index numbers. They are 0-based indexes. They index into the global land texture list, `tes3.dataHandler.nonDynamicData.landTextures`. Adjustment is required when indexing the list through lua.]],
	readOnly = true,
	valuetype = "number[]",
}