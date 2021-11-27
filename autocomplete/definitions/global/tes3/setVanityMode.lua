return {
	type = "function",
	description = [[Toggles the camera into vanity mode. In vanity mode the camera is in third person and it is orbiting slowly around the player character. Returns true if changed to vanity mode.

Note that unlike the vanity mode caused by not doing anything for a while, this vanity mode must be toggled to go off.]],
	arguments = {{
		name = "params",
		type = "table",
		tableParams = {
			{ name = "enabled", type = "boolean", optional = true, default = true, description = "This flag sets the vanity mode as enabled or disabled." },
			{ name = "checkVanityDisabled", type = "boolean", optional = true, default = true, description = "This will prevent changing vanity mode according to vanityDisabled flag on tes3.mobilePlayer." },
			{ name = "toggle", type = "boolean", optional = true, default = false, description = "When this flag is set to true. The vanity mode will be toggled. If the player was in vanity mode, this will make the player leave vanity mode. Conversly, if the player wasn't in the vanity mode, this will turn on the vanity mode." },
		},
	}},
	returns = {
		{ name = "changedVanityMode", type = "boolean" },
	},
}
