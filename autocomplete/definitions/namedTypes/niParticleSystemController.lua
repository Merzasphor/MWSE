return {
	type = "class",
	description = [[The niParticleSystemController animates an niParticles-based object. The controller handles birth and death, spawning and motion.

A particle spawn can be set to occur when the particle undergoes a specific condition, such as colliding with an object or dying. When such an event happens, naw particles are generated at the position of the old particle with the same attributes as the original particle. This behaviour will continue until the number of spawn generations equals the number of generations allowed. The number of new particles, precentage of particles that undergo spawning, speed and directional chaos values can be specified.]],
	inherits = "niTimeController",
}