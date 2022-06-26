return {
	type = "method",
	description = [[Forces the actor to jump. If `velocity` or other parameters with non-default values are specified it will be treated as a non-default jump during the [`jump`](https://mwse.github.io/MWSE/events/jump) event. Returns `false` if the actor is currently unable to jump or the jump has been cancelled, otherwise returns `true`.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{name = "velocity", type = "tes3vector3", optional = true, description = "The initial velocity of the jump. If not specified, the velocity of a regular jump without movement will be used."},
			{name = "applyFatigueCost", type = "boolean", optional = true, default = true, description = "If `true`, reduces the actor's current fatigue by the amount a regular jump would currently cost. Will not reduce fatigue if `false`."},
			{name = "allowMidairJumping", type = "boolean", optional = true, default = false, description = "If `true`, enables the jump to be performed while already jumping or falling. Does not work during levitation or other methods of flying."},
		},
	}},
	valuetype = "boolean",
}
