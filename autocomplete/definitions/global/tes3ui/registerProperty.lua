return {
	type = "function",
	description = [[Registers a property name, returning a Property. Once a property is registered, this function always returns the same Property.

The registry namespace is shared between Property and UI_ID. It is advisable to use a namespace prefix to avoid collisions with other mods.]],
	arguments = {
		{ name = "s", type = "string" },
	},
	returns = "number",
}
