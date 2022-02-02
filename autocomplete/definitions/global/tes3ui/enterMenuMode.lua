return {
	type = "function",
	description = [[Requests menu mode be activated on a menu with a given id.]],
	arguments = {
		{ name = "id", type = "string|number" },
	},
	returnDescription = "true if the menu was switched, or false if it was already active.",
	valuetype = "boolean",
}
