return {
	type = "function",
	description = [[Emulates the player committing a crime. Returns `true` if the crime was witnessed by an actor.]],
	arguments = {
		{
			name = "params",
			type = "table",
			tableParams = {
				{
					name = "type",
					type = "number",
					optional = true,
					default = "tes3.crimeType.theft",
					description = "The type of crime to be committed. Maps to values in the [`tes3.crimeType`](https://mwse.github.io/MWSE/references/crime-types/) table."
				},
				{
					name = "victim",
					type = "tes3mobileNPC|tes3actor|tes3faction",
					optional = true,
					default = "tes3.mobilePlayer",
					description = "The victim of the crime. This can be an individual actor or a entire faction. Has no effect on crimes with a `type` of `tes3.crimeType.trespass` or `tes3.crimeType.werewolf`."
				},
				{
					name = "value",
					type = "number",
					optional = true,
					default = "0",
					description = "Only valid if `type` is `tes3.crimeType.theft`. The value of the stolen objects."
				},
				{
					name = "forceDetection",
					type = "boolean",
					optional = true,
					default = "false",
					description = "If `true`, bypasses regular detection logic and forces all nearby actors to detect the crime."
				},
			}
		}
	},
	valuetype = "boolean"
}
