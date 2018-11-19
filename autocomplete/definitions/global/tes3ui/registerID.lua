return {
	type = "function",
	description = [[Registers a UI element name, returning a UI_ID. Once a property is registered, this function always returns the same UI_ID. These UI_IDs are used by the API to locate elements that may not exist (a weak reference), instead of by element name.

The registry namespace is shared between Property and UI_ID. It is advisable to use a namespace prefix to avoid collisions with other mods.]],
	arguments = {
		{ name = "s", type = "string" },
	},
	returns = "number",
}
