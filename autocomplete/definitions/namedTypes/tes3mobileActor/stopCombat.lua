return {
	type = "method",
	description = [[Ends combat for the actor.]],
	arguments = {
		{ name = "force", type = "boolean", description = "If `false`, the function won't stop combat if the actor has other valid hostile targets." },
	},
}