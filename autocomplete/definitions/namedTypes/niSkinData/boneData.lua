return {
	type = "value",
	description = [[An array of objects containing one entry for each bone that influences vertices in the skinned mesh. The order of the entries in the `boneData` array corresponds to the order of the bones in the bone array in the `niSkinInstance` objects that point to this `niSkinData`. Each object in this array contains all the data needed to deform vertices by a single bone.]],
	readOnly = true,
	valuetype = "niSkinDataBoneData[]",
}
