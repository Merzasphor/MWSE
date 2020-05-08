return {
	type = "class",
	description = [[
        NiGeometryData objects contain the actual geometry data necessary to render an NiGeometry object. When an NiGeometry-based object is constructed, all the actual geometry data, including arrays of vertices, normals, colors, and texture coordinates, are stored in a corresponding NiGeometryData object. The arrays become owned by the NiGeometryData object, which then has the responsibility of deleting them upon destruction or reallocation.
    ]],
	inherits = "niObject",
}