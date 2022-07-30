return {
	type = "class",
	description = [[niParticlesData objects contain the geometry data necessary to render a niParticles object. When a niParticles-based object is created, the actual geometry data is stored in an attached niParticlesData object.

There are two ways to adjust particle size within an niParticles object. The `radius` affects all the particles in this niParticlesData object. There is also a `size` for each particle (available as `sizes` array), which is a ratio between 0.0 and 1.0 that is multiplied by the radius to obtain the final rendered size of the particle.]],
	inherits = "niTriBasedGeometryData",
}