return {
	type = "function",
	description = [[Returns `true` if the `target` actor can cast spells, otherwise returns `false`.]],
	arguments = {
		{
			name = "params",
			type = "table",
			tableParams = {
				{
					name = "target",
					type = "tes3reference|tes3mobileActor|tes3actor",
					description = "The actor to check."
				},
			}
		}
	},
	valuetype = "boolean",
}
