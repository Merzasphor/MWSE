return {
	type = "method",
	description = "Returns the angle between provided point in space and the front side of the actor on whom the method was called. The returned angle is in degress in range [-180, 180], where 0 degrees is directly in front of the actor, the negative values are on the actor's left side, and positive values on the actor's right.",
	arguments = {
		{ name = "point", type = "tes3vector3", description = "The target point to calculate the facing angle." },
	},
	returns = { name = "angle", type = "number", description = "In range of [-180, 180] in degrees." }
}