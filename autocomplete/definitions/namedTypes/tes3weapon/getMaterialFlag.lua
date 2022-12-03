return {
	type = "method",
	description = [[Access to the material flag bitfield. Known material flags can be accessed via other weapon properties.]],
	arguments = {
		{ name = "flagBit", type = "integer", description = "`0` corresponds to the `ignoresNormalWeaponResistance` field, `1` corresponds to the `isSilver`." },
	},
	valuetype = "boolean",
}