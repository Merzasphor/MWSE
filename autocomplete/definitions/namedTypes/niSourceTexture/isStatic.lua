return {
	type = "value",
	description = [[The static flag. If this flag is true, then the application cannot assume that any dynamic changes to the app pixel data will be reflected in the rendered image, even if the revision ID of the app pixel data is changed. If the flag is false, then the changing the revision ID of the app pixel data will cause the rendered version of the texture to be updated. Renderers use this flag for optimization purposes. The default setting is true – by default, all NiSourceTextures are assumed to be static. Applications must manually clear this flag for textures they intend to modify.]],
	valuetype = "boolean",
}