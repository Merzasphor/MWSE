return {
	type = "function",
	description = [[This function will compile and run a mwscript chunk of code. This is not ideal to use, but can be used for features not yet exposed to lua.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "script", type = "tes3script", optional = true, default = "tes3.worldController.scriptGlobals", description = "The base script to base the execution from." },
			{ name = "source", type = "number", description = "The compilation source to use. Defaults to tes3.scriptSource.default" },
			{ name = "command", type = "string", description = "The script text to compile and run." },
			{ name = "variables", type = "tes3scriptVariables", optional = true, description = "If a reference is provided, the reference's variables will be used." },
			{ name = "reference", type = "tes3reference|tes3mobileActor|string", description = "The reference to target for execution." },
			{ name = "dialogue", type = "tes3dialogue|string", optional = true, description = "If compiling for dialogue context, the dialogue associated with the script." },
			{ name = "info", type = "tes3dialogueInfo", optional = true, description = "The info associated with the dialogue." },
		},
	}},
	returns = {{ name = "executed", type = "boolean" }},
}
