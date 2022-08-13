return {
	type = "class",
	description = [[Represents a spotlight in a scene. The street lights, emmithing the illumination in the cone shape can be represented by this class. Spotlights have a specific location and direction, as well as a distance attenuation and angle attenuation functions. The light direction is handled in the same way as in `niDirectionalLight` - it shines down the model-space positive X axis of the light.]],
	inherits = "niPointLight",
}