return {
	type = "class",
	description = [[an object that represents a spotlight in a scene. Spotlights have a specific location and direction in space, as well as a distance attenuation function and an angle attenuation function. Location and distance attenuation are inherited from the `niPointLight` class. The light direction is handled in the same way as it is in `niDirectionalLight` -- it shines down the model-space positive X-axis of the light.]],
	inherits = "niPointLight",
}