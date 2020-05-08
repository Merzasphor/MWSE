return {
	type = "class",
	description = [[Object that represent a camera in the scene graph. They have no inherent geometric representation, but use their parents' transforms to determine their location and orientation in world space. This organization enables cameras in Gamebryo to be attached to scene graph objects and automatically follow them for "in-car" cameras and "missile-cams".]],
	inherits = "niAVObject",
}