return {
	type = "function",
	description = [[Casts a spell from a given reference to a target reference. The caster doesn't need to know the spell.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3reference|tes3mobileActor|string", description = "The caster reference." },
			{ name = "target", type = "tes3reference|tes3mobileActor|string", description = "The target reference." },
			{ name = "spell", type = "tes3spell|string", description = "The spell the caster uses." },
		},
	}},
	returns = {{ name = "executed", type = "boolean" }},
}
