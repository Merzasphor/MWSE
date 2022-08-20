return {
	type = "function",
	description = [[Creates an object and returns it. The created object will be part of the saved game.]],
	arguments = {
		{
			name = "params",
			type = "table",
			tableParams = {
				{
					name = "id",
					type = "string",
					optional = true,
					description = "The id of the new object."
				},
				{
					name = "objectType",
					type = "number",
					description = [[The type of object to create. Maps to values in the [`tes3.objectType`](https://mwse.github.io/MWSE/references/object-types/) table. Supported object types are:
		- `tes3.objectType.activator`
		- `tes3.objectType.alchemy`
		- `tes3.objectType.armor`
		- `tes3.objectType.book`
		- `tes3.objectType.clothing`
		- `tes3.objectType.container`
		- `tes3.objectType.enchantment`
		- `tes3.objectType.misc`
		- `tes3.objectType.sound`
		- `tes3.objectType.spell`
		- `tes3.objectType.static`
		- `tes3.objectType.weapon`
]]
				},
				{
					name = "getIfExists",
					type = "boolean",
					optional = true,
					default = true,
					description = "If `true`, an existing object of the same `objectType` and `id` will be returned instead of creating a new one."
				},
			},
		}
	},
	returns = {
		{
			name = "createdObject",
			type = "tes3activator|tes3alchemy|tes3armor|tes3book|tes3clothing|tes3container|tes3enchantment|tes3misc|tes3sound|tes3spell|tes3static|tes3weapon"
		},
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
