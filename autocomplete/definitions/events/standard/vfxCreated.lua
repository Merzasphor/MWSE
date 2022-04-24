return {
	type = "event",
	description = "The vfxCreated event fires when a managed visual effect is created by the game engine or through `tes3.createVisualEffect`.",
	eventData = {
		["vfx"] = {
			type = "tes3vfx",
			readOnly = true,
			description = "The created visual effect.",
		},
		["context"] = {
			type = "string",
			readOnly = true,
			description = "Context for what type of VFX this was created at. For example, if the VFX was created at a position the value will be `tes3.vfxContext.position`, while an effect created onto the caster's hands will be created with the context of a `tes3.vfxContext.niNode`. This maps to the values in `tes3.vfxContext`.",
		},
	},
}
