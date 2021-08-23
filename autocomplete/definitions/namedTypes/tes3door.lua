return {
	type = "class",
	description = [[A door game object. Data specific to a single door is stored on the door reference as destination and lock attachments. See ``tes3reference`` for details.

There is a special-case door with id ``PrisonMarker`` used for finding the nearest prison when the player is sent to jail. You should normally exclude this if you are iterating over all doors. Use the ``object.isLocationMarker`` property to detect these markers.]],
	inherits = "tes3physicalObject",
}