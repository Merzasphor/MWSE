return {
	type = "class",
	description = [[niGeometryData objects contain the geometry data necessary to render a niGeometry object. When a niGeometry-based object is created, the actual geometry data is stored in an attached niGeometryData object.

The distinction between niGeometry and niGeometryData (and other pairs of Gamebryo classes with similarly distinguished names, such as niTriShape and niTriShapeData) is that niGeometry stores data that cannot be shared when an object is instanced, and niGeometryData stores data that can be shared when an object is instanced. So, for example, when a scene graph is cloned, duplicate copies of the niGeometry objects in the original scene graph are created for the new scene graph, but new niGeometryData objects are not created. Instead, the newly-created niGeometry objects refer to the same niGeometryData objects referred to by the original scene graph.]],
	inherits = "niObject",
}