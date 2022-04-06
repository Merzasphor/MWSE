return {
	type = "function",
	description = [[Returns the object's owner, or nil if the object is unowned.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3reference" },
		},
	}},
	returns = {
		{ name = "owner", type = "tes3faction|tes3npc|nil" },
		{ name = "requirement", type = "number|tes3globalVariable|nil", description = "The faction rank required if the owner is a faction, or the global variable needing to be set if the owner is an NPC." },
	},
}
