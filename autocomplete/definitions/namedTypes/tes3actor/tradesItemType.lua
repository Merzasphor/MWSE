return {
	type = "method",
	description = [[Checks if the actor will buy and sell items of a given object type. e.g. `actor:tradesItemType(tes3.objectType.repairItem)`]],
	arguments = {
		{ name = "objectType", type = "tes3objectType", description = "[`tes3.objectType.*`](https://mwse.github.io/MWSE/references/object-types/) constants can be passed here." },
	},
	valuetype = "boolean",
}
