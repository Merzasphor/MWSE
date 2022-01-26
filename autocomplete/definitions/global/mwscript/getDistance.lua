return {
	type = "function",
	description = [[Use [`tes3reference.position`](https://mwse.github.io/MWSE/types/tes3reference/#position) or [`tes3mobileActor.position`](https://mwse.github.io/MWSE/types/tes3mobileActor/#position) to compute the distance or depending on the desired effect, [`tes3mobileActor.playerDistance`](https://mwse.github.io/MWSE/types/tes3mobileActor/#playerdistance). Wrapper for the GetDistance mwscript function. Replacement: any reference or mobile actor has [`position`](https://mwse.github.io/MWSE/types/tes3reference/#position) field, while the distance can be computed. In addition, mobile actor has [`mobile.playerDistance`]() field.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3reference|tes3mobileActor|string", description = "The target reference for this command to be executed on. Defaults to the normal script execution reference.", optional = true },
			{ name = "target", type = "tes3reference|tes3mobileActor|string", description = "Actor to check distance to." },
		},
	}},
	returns = "boolean",
}
