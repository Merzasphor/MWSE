return {
	type = "value",
	description = [[An array-style table of the [`tes3effect`](https://mwse.github.io/MWSE/types/tes3effect/) data on the object.]],
	readOnly = true,
	valuetype = "tes3effect[]",
	examples = {
		["..\\..\\tes3spell\\effects\\isHostile"] = {
			title = "Determining if an enchantment is hostile",
			description = "The following function returns `true` if the enchantment contains at least one hostile effect. This criterion can be considered subjective, but that rule is also used by the game to determine if use of enchantment on an NPC is considered an offense.",
		}
	}
}
