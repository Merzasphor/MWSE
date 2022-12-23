return {
	type = "value",
	description = [[Access to the script context for this reference and its associated script.]],
	readOnly = true,
	valuetype = "tes3scriptContext",
	examples = {
		["hasCompanionShare"] = {
			title = "Checking reference's script variables",
			description = "Companions usually have a mwscript script with variable named `companion` set to 1. This can be used to determine if a reference is player's companion or not. Note that companion share functionality was added to Morrowind in Tribunal expansion. In vanilla game it is used by Tribunal companions. Also, companion mods usually use this feature. But note that all the followers (during certain parts of their quests) from base Morrowind don't have companion share.",
		},
		["isFollower"] = {
			title = "Checking if an actor is a follower",
			description = "In this example we provide a way to check if a certain actor is currently player's follower. This function can also be useful besides the one from previous example, since not all of the followers have companion share enabled.",
		}
	}
}