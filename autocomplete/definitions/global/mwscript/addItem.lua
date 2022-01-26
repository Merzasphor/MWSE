return {
	type = "function",
	description = [[Wrapper for the AddItem mwscript function. Replacements: [`tes3.addItem()`](https://mwse.github.io/MWSE/apis/tes3/#tes3additem), [`inventory:addItem()`](https://mwse.github.io/MWSE/types/tes3inventory/#additem), and depending on your needs [`mobileActor:equip()`](https://mwse.github.io/MWSE/types/tes3mobileActor/#equip).]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "reference", type = "tes3reference|tes3mobileActor|string", description = "The target reference for this command to be executed on. Defaults to the normal script execution reference.", optional = true },
			{ name = "item", type = "tes3item|string", description = "The item to be added." },
			{ name = "count", type = "number", default = 1, description = "The number of items to be added." },
		},
	}},
	returns = {{ name = "executed", type = "boolean" }},
}
