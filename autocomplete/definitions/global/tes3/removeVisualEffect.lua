return {
	type = "function",
	description = [[Removes one or more visual effects created either through magical effects or `tes3.createVisualEffect()`.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "vfx", type = "tes3vfx", optional = true, description = "If provided, the specific VFX handle will be deleted." },
			{ name = "avObject", type = "niAVObject", optional = true, description = "If provided, any VFXs associated with the given niAVObject will be deleted." },
			{ name = "serial", type = "number", optional = true, description = "The magic source instance serial number to remove effects for. This must be paired with a reference as well." },
			{ name = "reference", type = "tes3reference|string", optional = true, description = "The reference to remove all visual effects from. A serial may also be provided." },
		},
	}},
	returns = {
		{ name = "removedCount", type = "number", description = "The amount of VFX removed by this function call." }
	}
}
