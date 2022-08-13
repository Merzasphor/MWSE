return {
	type = "value",
	description = [[Controls whether the system will be reset when the niParticleSystemController loops. If this flag is set to `true`, existing particles will be eliminated when the controller loops, and any run-up indicated by `.emitStartTime` variable will occur. Otherwise, the controller will simply continue running from the beginning of the loop, and the existing particles will continue to run until they die out naturally.]],
	valuetype = "boolean",
}
