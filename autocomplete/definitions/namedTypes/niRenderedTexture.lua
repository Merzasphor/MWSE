return {
	type = "class",
	description = [[A texture that is also a render target. This object can be used with niRenderer:setRenderTarget and rendered into. It can be directly used in a texturing property, or read back into system memory (at a performance cost). After using it as a render target, make sure you reset the renderer with niRenderer:setRenderTarget(nil) so that it's not bound as a source texture and a target at the same time.]],
	inherits = "niTexture",
}
