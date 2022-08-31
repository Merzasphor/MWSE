return {
	type = "function",
	description = [[Configures a mobile actor to activate an object.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3mobileActor|tes3reference", description = "This actor will activate the provided `target` reference." },
			{ name = "target", type = "tes3reference", description = "The reference to activate." },
			{ name = "reset", type = "boolean", optional = true, default = true },
		},
	}},
}