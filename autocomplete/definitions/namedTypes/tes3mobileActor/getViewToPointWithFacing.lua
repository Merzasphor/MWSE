return {
	type = "method",
	description = "Returns the angle between provided point in space and the actor's current position with provided facing (which effectively overrides the actor's facing used in other getViewTo methods). The returned angle is in degress in range [-180, 180], where 0 degrees is directly in front of the provided facing angle with the origin in actor's position.",
	arguments = {
		{ name = "facing", type = "number", description = "The facing angle in radians. The values should be in [0, PI] interval." },
		{ name = "point", type = "tes3vector3", description = "The target point to calculate the facing angle." },
	},
	returns = { name = "angle", type = "number", description = "In range of [-180, 180] in degrees." }
}