
--[[
	Mod configuration system.

	Part of the MWSE Project. This module is responsible for creating a uniform UI that mods can
	extend to provide a single place for users to configure their mods.
]]--

-- UI ID for the core mod config menu, so we can repeatedly access it.
local UIID_mwse_modConfigMenu = nil

-- Storage for mod config packages. 
local configMods = {}

-- The current package that we are configuring.
local currentModConfig = nil

-- Reusable access to UI elements.
local modConfigContainer = nil

-- Callback for when a mod name has been clicked in the left pane.
local function onClickModName(e)
	-- If we have a current mod, fire its close event.
	if (currentModConfig and currentModConfig.onClose) then
		currentModConfig.onClose(modConfigContainer)
	end

	-- Update the current mod package.
	currentModConfig = configMods[e.text]

	-- Destroy and recreate the parent container.
	local modConfigPane = modConfigContainer.parent
	modConfigContainer:destroy()
	modConfigContainer = modConfigPane:createBlock({})
	modConfigContainer.layoutWidthFraction = 1.0
	modConfigContainer.layoutHeightFraction = 1.0
	modConfigContainer.paddingLeft = 4

	-- Fire the mod's creation event if it has one.
	if (currentModConfig.onCreate) then
		currentModConfig.onCreate(modConfigContainer)
	end

	-- Change the mod config title bar to include the mod's name.
	local menu = tes3ui.findMenu(UIID_mwse_modConfigMenu)
	menu.text = "Mod Configuration - " .. e.text
	menu:updateLayout()
end

-- Callback for when the close button has been clicked.
local function onClickCloseButton(e)
	-- If we have a current mod, fire its close event.
	if (currentModConfig and currentModConfig.onClose) then
		currentModConfig.onClose(modConfigContainer)
	end

	-- Get the main menu so we can show it again.
	local mainMenu = tes3ui.findMenu(tes3ui.registerID("MenuOptions"))
	if (mainMenu) then
		-- Destroy the mod config menu.
		local modConfigMenu = tes3ui.findMenu(UIID_mwse_modConfigMenu)
		if (modConfigMenu) then
			currentModConfig = nil
			modConfigContainer = nil
			modConfigMenu:destroy()
		end

		-- Show the main menu again.
		mainMenu.visible = true
	else
		mwse.log("Couldn't find main menu!")
	end
end

-- Callback for when the mod config button has been clicked.
-- Here, we'll create the GUI and set up everything.
local function onClickModConfigButton()
	local menu = tes3ui.findMenu(UIID_mwse_modConfigMenu)
	if (menu == nil) then
		-- Create the main menu frame.
		menu = tes3ui.createMenu({ id = UIID_mwse_modConfigMenu, dragFrame = true })
		menu.text = "Mod Configuration"
		menu.minWidth = 600
		menu.minHeight = 500;
		menu.width = 1200
		menu.height = 800
		menu.positionX = menu.width / -2
		menu.positionY = menu.height / 2

		-- Create the left-right flow.
		local mainHorizontalBlock = menu:createBlock({})
		mainHorizontalBlock.flowDirection = "left_to_right"
		mainHorizontalBlock.layoutWidthFraction = 1.0
		mainHorizontalBlock.layoutHeightFraction = 1.0

		-- Create the mod list.
		local modList = mainHorizontalBlock:createVerticalScrollPane({})
		modList.width = 250
		modList.minWidth = 250
		modList.maxWidth = 250
		modList.layoutWidthFraction = -1.0
		modList.layoutHeightFraction = 1.0

		-- Get a sorted list of mods.
		local sortedConfigModNames = {}
		for name, package in pairs(configMods) do
			-- Allow package.hidden to be set to prevent it from showing up in the list.
			if (not package.hidden) then
				table.insert(sortedConfigModNames, name)
			end
		end
		table.sort(sortedConfigModNames)

		-- Fill in the mod list.
		for i = 1, #sortedConfigModNames do
			local modName = sortedConfigModNames[i]
			local entry = modList:createTextSelect({})
			entry.text = modName
			entry:register("mouseClick", onClickModName)
		end

		-- Create container for mod content. This will be deleted whenever the pane is reloaded.
		modConfigContainer = mainHorizontalBlock:createBlock({})
		modConfigContainer.layoutWidthFraction = 1.0
		modConfigContainer.layoutHeightFraction = 1.0
		modConfigContainer.paddingLeft = 4

		-- Dummy content until a mod is clicked.
		menu:updateLayout()
		local modText = modConfigContainer:createLabel({ text = "Sed ut perspiciatis, unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam eaque ipsa, quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt, explicabo. Nemo enim ipsam voluptatem, quia voluptas sit, aspernatur aut odit aut fugit, sed quia consequuntur magni dolores eos, qui ratione voluptatem sequi nesciunt, neque porro quisquam est, qui dolorem ipsum, quia dolor sit amet consectetur adipisci[ng] velit, sed quia non-numquam [do] eius modi tempora inci[di]dunt, ut labore et dolore magnam aliquam quaerat voluptatem. Ut enim ad minima veniam, quis nostrum exercitationem ullam corporis suscipit laboriosam, nisi ut aliquid ex ea commodi consequatur? Quis autem vel eum iure reprehenderit, qui in ea voluptate velit esse, quam nihil molestiae consequatur, vel illum, qui dolorem eum fugiat, quo voluptas nulla pariatur?" })
		modText.wrapText = true

		-- Create bottom button block.
		local bottomBlock = menu:createBlock{}
		bottomBlock.layoutWidthFraction = 1.0
		bottomBlock.autoHeight = true
		bottomBlock.alignX = 1.0

		-- Add a close button to the bottom block.
		local closeButton = bottomBlock:createButton{ text = tes3.getGMST(27).value }
		closeButton:register("mouseClick", onClickCloseButton)

		-- Cause the menu to refresh itself.
		menu:updateLayout()
	else
		menu.visible = true
	end

	-- Hide main menu.
	local mainMenu = tes3ui.findMenu(tes3ui.registerID("MenuOptions"))
	if (mainMenu) then
		mainMenu.visible = false
	else
		mwse.log("Couldn't find main menu!")
	end

	tes3ui.enterMenuMode(menu.id)
end

-- Get the number of mods that aren't hidden.
local function getActiveModConfigCount()
	local count = 0
	for name, package in pairs(configMods) do
		-- Allow package.hidden to be set to prevent it from showing up in the list.
		if (not package.hidden) then
			count = count + 1
		end
	end
	return count
end

-- Callback for when the MenuOptions element is created. We'll extend it with our new button.
local function onCreatedMenuOptions(e)
	-- Don't show the UI if we don't have any mod configs to show.
	if (getActiveModConfigCount() == 0) then
		return
	end

	local mainMenu = e.element
	local button = mainMenu:createButton({ text = "Mod Configuration" })
	button:register("mouseClick", onClickModConfigButton)

	mainMenu.autoWidth = true
	mainMenu.autoHeight = true

	mainMenu:updateLayout()
end
event.register("uiCreated", onCreatedMenuOptions, { filter = "MenuOptions" })

-- Define a new function in the mwse namespace that lets mods register for mod config.
function mwse.registerModConfig(name, package)
	-- Prevent duplicate registration.
	if (configMods[name] ~= nil) then
		error(string.format("mwse.registerModConfig: A mod with the name %s has already been registered!", name))
	end

	-- Add the package to the list.
	package.name = name
	configMods[name] = package
end

-- When we've initialized, set up our UI IDs and let other mods know that we are ready to boogie.
local function onInitialized()
	UIID_mwse_modConfigMenu = tes3ui.registerID("MWSE:ModConfigMenu")

	event.trigger("modConfigReady")
end
event.register("initialized", onInitialized)