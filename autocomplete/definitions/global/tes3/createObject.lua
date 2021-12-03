return {
	type = "function",
	description = [[Create an object and returns it. The created object will be part of the saved game. Supported object types are those that have their own create function, such as tes3activator for example.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "objectType", type = "number", description = "Maps to [`tes3.objectType`](https://mwse.github.io/MWSE/references/object-types/) constants. Used to filter object type to create." },
			{ name = "getIfExists", type = "boolean", default = true, description = "If `true`, an existing object of the same type and ID will be returned instead of creating a new one." },
		},
	}},
	returns = {
		{ name = "createdObject", type = "tes3activator|tes3alchemy|tes3container|tes3enchantment|tes3misc|tes3sound|tes3spell|tes3static|tes3weapon" },
	},
	examples = {
		["createMisc"] = {
			title = "Creates a tes3misc object",
			description = "The example below create a misc item object that could be used to create a placeable reference later on."
		},
		["createStatic"] = {
			title = "Creates a tes3static object",
			description = "The example below create a static object that could be used to create a placeable reference later on."
		},
	},
}
