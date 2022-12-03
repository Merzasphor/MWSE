return {
	type = "method",
	description = [[Fetches a filtered list of the active magic effects on the actor.]],
	arguments = {{
		name = "params",
		type = "table",
		optional = true,
		tableParams = {
			{ name = "effect", type = "integer", optional = true, description = "The magic effect ID to search for, from [`tes3.effect`](https://mwse.github.io/MWSE/references/magic-effects/) table." },
			{ name = "serial", type = "integer", optional = true, description = "The magic instance serial to search for." },
		},
	}},
	valuetype = "tes3activeMagicEffect[]",
}
