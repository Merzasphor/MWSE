return {
	type = "class",
	description = [[This modifer alters the size and fading of the particles. The growing starts once a particle is first created, so that when a particle appears it will grow from nothing to its full size. Particles fade out of existance when they die, changing their size from full to nothing. If the two effects overlap, the particle will be smaller (to extinguish dying particles).]],
	inherits = "niParticleModifier",
}