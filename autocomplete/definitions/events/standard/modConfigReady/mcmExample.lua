local config = require("MyMod.config")

local function onModConfigReady()
	local template = mwse.mcm.createTemplate({ name = "My Mod" })
	template:saveOnClose("My Mod", config)

	local settings = template:createSideBarPage({ label = "Settings" })
	settings.sidebar:createInfo({
		-- This text will be on the right-hand side block
		text = "My Mod v. 1.0\n\nCreated by me.\n\nHover over a feature for more info."
	})

	settings:createOnOffButton({
		label = "Feature",
		-- The text in the description will replace the text
		-- in sidebar on the right-hand side, when this button
		-- is hovered over.
		description = "This feature does...",
		variable = mwse.mcm.createTableVariable({
			id = "feature",
			table = config,
		})
	})

end

event.register(tes3.event.modConfigReady, onModConfigReady)