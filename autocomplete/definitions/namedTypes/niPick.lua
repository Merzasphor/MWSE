return {
	type = "class",
	description = [[This class is the entry point into the picking intersection system.  With the specification of a ray, the class allows an application to perform picking operations on a scene graph or any subtree within a scene graph.  Given a ray and a subtree, the subtree is traversed and any intersected objects satisfying user-defined constraints are added to an array. Intersections are only computed with bounding spheres (coarse scale operation) or with triangle geometry (fine scale operation).]]
}