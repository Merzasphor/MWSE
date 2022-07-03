return {
	type = "class",
	description = [[Wander AI package causing an actor to move around at random. Actors will choose points to walk to based on the path grid of the cell they are in.

	Idle nodes represent the percentage chance the actor will stand still and perform the particular idle animation. Each idle is checked, and the one that passes with the highest roll is played. If no Idle passes the random roll, the actor will move (walk)]],
	inherits = "tes3aiPackage",
}