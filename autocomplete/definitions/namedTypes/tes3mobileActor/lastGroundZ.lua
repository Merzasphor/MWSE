return {
	type = "value",
	description = [[This has a large negative value if the actor is on the ground. When the actor jumps, this will have a positive value. During `jump` event this value is still negative. A split second after, it will have the value of the `.z` coordinate when the actor was on the ground. Beware that this value changes after some amount of time while the actors is in the air.]],
	valuetype = "number",
}