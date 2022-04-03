return {
	type = "method",
	description = [[]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "actor", type = "tes3mobileActor", description = "The actor to perform a check for." },
			{ name = "container", type = "tes3iterator", description = "Container is a actor's AI planner e.g. `mobile.aiPlanner`." },
		},
	}},
}
