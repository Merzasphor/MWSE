return {
	type = "value",
	description = [[An array-style table of the [`tes3effect`](https://mwse.github.io/MWSE/types/tes3effect/) data on the object.]],
	readOnly = true,
	valuetype = "tes3effect[]",
	examples = {
		["isHostile"] = {
			title = "Determining if a spell is hostile",
			description = "The following function returns `true` if the spell contains at least one hostile effect. This criterion can be considered subjective, but that rule is also used by the game to determine if a use of the spell on an NPC is considered an offense.",
		}
	}
}
