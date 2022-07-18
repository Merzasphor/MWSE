return {
	type = "function",
	description = [[Fetches an attachment with a given type from a reference. Will return `nil` if no attachment of that type has been found.]],
	arguments = {
		{
			name = "reference",
			type = "tes3reference",
			description = "The reference to get the attachment from."
		},
		{
			name = "attachment",
			type = "string",
			description = [[The type of attachment to get. Possible values are:
	- `"bodyPartManager"`: Returns `tes3bodyPartManager`
	- `"light"`: Returns `tes3lightNode`
	- `"lock"`: Returns `tes3lockNode`
	- `"leveledBase"`: Returns `tes3reference`
	- `"travelDestination"`: Returns `tes3travelDestinationNode`
	- `"variables"`: Returns `tes3itemData`
	- `"actor"`: Returns `tes3mobileActor`
	- `"animation"`: Returns `tes3animationData`
]]
		},
	},
	valuetype = "nil|tes3bodyPartManager|tes3itemData|tes3lightNode|tes3lockNode|tes3mobileActor|tes3reference|tes3travelDestinationNode|tes3animationData",
}
