--- @meta
--- @diagnostic disable:undefined-doc-name

--- The tes3ui library provides access to manipulating the game's GUI.
--- @class tes3uilib
tes3ui = {}

--- Sends all text input to the specified element.  Calling this function with a nil argument will release text input and allow keybinds to work. Suppresses most keybinds while active, except the Journal open/close keybind (it's up to the individual menu implementation).
--- 
--- Only one element can have control of input, and there is no automatic restoration of control if one element takes control from another. Be careful of conflicts with other users of this function.
--- @param element tes3uiElement? *Optional*. No description yet available.
function tes3ui.acquireTextInput(element) end

--- When used in a mouse event, causes the element to capture further mouse events even when the cursor goes outside the element. Setting mouse capture should always be accompanied by releasing it on a complementary event. This is commonly used for dragging, so that it can continue even if the mouse moves slightly outside the element.
--- 
--- The capture is always removed when the element is destroyed. The capture may also be removed when the mouse is released, but this is not reliable, as the engine forgets what to do if there is input from any other controller while the mouse is held down.
---
--- [Examples available in online documentation](https://mwse.github.io/MWSE/apis/tes3ui/#tes3uicapturemousedrag).
--- @param capture boolean Turns on mouse capture for the element currently processing a mouse event if true, sending all further mouse events to that element. Turns off capture if false.
function tes3ui.captureMouseDrag(capture) end

--- Creates a simple dialogue choice, as per the `Choice` mwscript function.
--- @param text string The text to display for the choice.
--- @param index number The choice index associated with the given text.
function tes3ui.choice(text, index) end

--- Closes the Journal.
--- @return boolean result No description yet available.
function tes3ui.closeJournal() end

--- Creates a help layer menu. Help layer menus include notifications and tooltips that are always above the rest of the interface. The game realizes this using a separate menu root and set of functions.
--- 
--- Note, to create tooltips with the correct behaviour, use tes3ui.createTooltipMenu.
--- 
--- Unlike standard menus, help layer menus are always created with a fixed frame.
--- @param params tes3ui.createHelpLayerMenu.params This table accepts the following values:
--- 
--- `id`: string|number — The menu’s ID. The menu can be later accessed by tes3ui.findHelpLayerMenu(id).
--- @return tes3uiElement result No description yet available.
function tes3ui.createHelpLayerMenu(params) end

---Table parameter definitions for `tes3ui.createHelpLayerMenu`.
--- @class tes3ui.createHelpLayerMenu.params
--- @field id string|number The menu’s ID. The menu can be later accessed by tes3ui.findHelpLayerMenu(id).

--- Creates a top-level menu.
--- @param params tes3ui.createMenu.params This table accepts the following values:
--- 
--- `id`: string|number — The menu’s ID. The menu can be later accessed by tes3ui.findMenu(id).
--- 
--- `dragFrame`: boolean? — *Default*: `false`. Constructs a draggable and resizeable frame and background for the menu. It is similar to the stats, inventory, magic and map menus in the standard UI. After construction, position and minimum dimensions should be set.
--- 
--- `fixedFrame`: boolean? — *Default*: `false`. Constructs a fixed (non-draggable) frame and background for the menu. The layout system should automatically centre and size it to fit whatever is added to the menu.
--- 
--- `loadable`: boolean? — *Default*: `true`. If set to false, calls to loadMenuPosition will fail.
--- @return tes3uiElement result No description yet available.
function tes3ui.createMenu(params) end

---Table parameter definitions for `tes3ui.createMenu`.
--- @class tes3ui.createMenu.params
--- @field id string|number The menu’s ID. The menu can be later accessed by tes3ui.findMenu(id).
--- @field dragFrame boolean? *Default*: `false`. Constructs a draggable and resizeable frame and background for the menu. It is similar to the stats, inventory, magic and map menus in the standard UI. After construction, position and minimum dimensions should be set.
--- @field fixedFrame boolean? *Default*: `false`. Constructs a fixed (non-draggable) frame and background for the menu. The layout system should automatically centre and size it to fit whatever is added to the menu.
--- @field loadable boolean? *Default*: `true`. If set to false, calls to loadMenuPosition will fail.

--- Creates a respond text. This function is used for the mwscript `Choice` function.
--- @param params tes3ui.createResponseText.params This table accepts the following values:
--- 
--- `text`: string — The text to display.
--- 
--- `type`: number? — *Optional*. The type for the response. Defaults to `choice` responses.
--- 
--- `index`: number? — *Optional*. The answer index for the response. Only used for `choice` responses.
function tes3ui.createResponseText(params) end

---Table parameter definitions for `tes3ui.createResponseText`.
--- @class tes3ui.createResponseText.params
--- @field text string The text to display.
--- @field type number? *Optional*. The type for the response. Defaults to `choice` responses.
--- @field index number? *Optional*. The answer index for the response. Only used for `choice` responses.

--- Creates a tooltip menu, which can be an empty menu or an item tooltip. This should be called from within a tooltip event callback. These automatically follow the mouse cursor, and are also destroyed automatically when the mouse leaves the originating element. Creating an item tooltip will invoke the uiObjectTooltip event.
---
--- [Examples available in online documentation](https://mwse.github.io/MWSE/apis/tes3ui/#tes3uicreatetooltipmenu).
--- @param params tes3ui.createTooltipMenu.params? This table accepts the following values:
--- 
--- `item`: tes3alchemy|tes3apparatus|tes3armor|tes3book|tes3clothing|tes3ingredient|tes3light|tes3lockpick|tes3misc|tes3probe|tes3repairTool|tes3weapon|string|nil — *Optional*. The item to create a tooltip for. If not specified, the tooltip will be empty.
--- 
--- `itemData`: tes3itemData? — *Optional*. The item data for the item.
--- @return tes3uiElement result No description yet available.
function tes3ui.createTooltipMenu(params) end

---Table parameter definitions for `tes3ui.createTooltipMenu`.
--- @class tes3ui.createTooltipMenu.params
--- @field item tes3alchemy|tes3apparatus|tes3armor|tes3book|tes3clothing|tes3ingredient|tes3light|tes3lockpick|tes3misc|tes3probe|tes3repairTool|tes3weapon|string|nil *Optional*. The item to create a tooltip for. If not specified, the tooltip will be empty.
--- @field itemData tes3itemData? *Optional*. The item data for the item.

--- Requests menu mode be activated on a menu with a given id.
--- @param id string|number No description yet available.
--- @return boolean result No description yet available.
function tes3ui.enterMenuMode(id) end

--- Locates a help layer menu through its id. Help layer menus include notifications and tooltips that are always above the rest of the interface. The game realizes this using a separate menu root and set of functions.
--- @param id string|number No description yet available.
--- @return tes3uiElement result No description yet available.
function tes3ui.findHelpLayerMenu(id) end

--- Locates a top-level menu through its id.
--- @param id string|number The ID of the menu to locate.
--- @return tes3uiElement result No description yet available.
function tes3ui.findMenu(id) end

--- Forces the game to update the inventory tile GUI elements. Unlike tes3ui.updateInventoryTiles, this will force-resync the player's inventory to the GUI, rather than updating what is already in the GUI system.
function tes3ui.forcePlayerInventoryUpdate() end

--- Determines what sort of search is being done when performing an inventory selection, e.g. "alembic" or "ingredient" or "soulGemFilled".
--- @return string result No description yet available.
function tes3ui.getInventorySelectType() end

--- Returns the top-most, active menu.
--- @return tes3uiElement result No description yet available.
function tes3ui.getMenuOnTop() end

--- Gets a standard palette color. Returns an array containing the RGB color values, in the range [0.0, 1.0].
--- @param name string The name of the palette color. Maps to values in [`tes3.palette`](https://mwse.github.io/MWSE/references/palettes/) enumeration.
--- @return number[] palette An array containing the RGB color values, in the range [0.0, 1.0].
function tes3ui.getPalette(name) end

--- Returns the mobile actor currently providing services to the player.
--- @return tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer result No description yet available.
function tes3ui.getServiceActor() end

--- Returns the UI scale, set in MGE.
--- @return number scale The UI scale value set from MGE.
function tes3ui.getViewportScale() end

--- Returns both the viewport width and the viewport height. Note that this value is not necessarily the real resolution of the screen. For that value, see the [`same-named function`](https://mwse.github.io/MWSE/apis/tes3/#tes3getviewportsize) in the tes3 namespace. To get the scale used, check `getViewportScale`.
--- @return number width The scaled width of the viewport.
--- @return number height The scaled height of the viewport.
function tes3ui.getViewportSize() end

--- Requests menu mode be deactivated on a menu with a given id.
--- @return boolean result No description yet available.
function tes3ui.leaveMenuMode() end

--- Logs a message to the console. The message accepts formatting and additional parameters matching string.format's usage.
---
--- [Examples available in online documentation](https://mwse.github.io/MWSE/apis/tes3ui/#tes3uilog).
--- @param message string No description yet available.
--- @vararg any *Optional*. No description yet available.
function tes3ui.log(message, ...) end

--- Logs a message to the console.
---
--- [Examples available in online documentation](https://mwse.github.io/MWSE/apis/tes3ui/#tes3uilogtoconsole).
--- @param text string No description yet available.
--- @param isCommand boolean? *Default*: `false`. Passing `true` will make the text in the console selectable by using up arrow key. If it is a valid command, then pressing enter will call it.
function tes3ui.logToConsole(text, isCommand) end

--- 
--- @param unknown nil No description yet available.
--- @return string executed No description yet available.
function tes3ui.lookupID(unknown) end

--- Checks if the game is in menu mode.
--- @return boolean result No description yet available.
function tes3ui.menuMode() end

--- Causes the tooltip to be redisplayed. This will not use a configured delay. This will not function if the help menu does not currently exist, or if it is not currently visible.
function tes3ui.refreshTooltip() end

--- Registers a UI element name, returning a UI_ID. Once a property is registered, this function always returns the same UI_ID. These UI_IDs are used by the API to locate elements that may not exist (a weak reference), instead of by element name.
--- 
--- The registry namespace is shared between Property and UI_ID. It is advisable to use a namespace prefix to avoid collisions with other mods.
--- @param s string No description yet available.
--- @return number result No description yet available.
function tes3ui.registerID(s) end

--- Registers a property name, returning a Property. Once a property is registered, this function always returns the same Property.
--- 
--- The registry namespace is shared between Property and UI_ID. It is advisable to use a namespace prefix to avoid collisions with other mods.
--- @param s string No description yet available.
--- @return number result No description yet available.
function tes3ui.registerProperty(s) end

--- Displays the book menu with arbitrary text. Paging is automatically handled. It needs to follow book text conventions as in the Construction Set. In essence, it uses HTML syntax. Important: every book needs to end with a `<BR>` statement to be displayed properly. See [`bookGetText`](https://mwse.github.io/MWSE/events/bookGetText/#examples) for an example of properly formatted book text.
--- @param text string No description yet available.
function tes3ui.showBookMenu(text) end

--- 
--- @param params tes3ui.showDialogueMessage.params This table accepts the following values:
--- 
--- `text`: string? — *Default*: ``. The text of the shown message.
--- 
--- `style`: number? — *Default*: `0`. 
--- 
--- `answerIndex`: number? — *Default*: `0`. 
function tes3ui.showDialogueMessage(params) end

---Table parameter definitions for `tes3ui.showDialogueMessage`.
--- @class tes3ui.showDialogueMessage.params
--- @field text string? *Default*: ``. The text of the shown message.
--- @field style number? *Default*: `0`. 
--- @field answerIndex number? *Default*: `0`. 

--- This function opens the inventory select menu which lets the player select items from an inventory. These items can be selected from any actor's inventory and can be filtered with the `filter` callback. The selected item can be retrieved in the function assigned to `callback`.
--- @param params tes3ui.showInventorySelectMenu.params This table accepts the following values:
--- 
--- `reference`: tes3reference? — *Default*: `tes3player`. The reference of a `tes3actor` whose inventory will be used.
--- 
--- `title`: string — The text used for the title of the inventory select menu.
--- 
--- `leaveMenuMode`: boolean? — *Optional*. Determines if menu mode should be exited after closing the inventory select menu. By default, it will be in the state it was in before this function was called.
--- 
--- `noResultsText`: string? — *Optional*. The text used for the message that gets shown to the player if no items have been found in the inventory. The default text is equivalent to the `sInventorySelectNoItems` GMST value, unless `"ingredients"` or `"soulgemFilled"` has been assigned to `filter`, in which case the default text is equivalent to either the `sInventorySelectNoIngredients` or `sInventorySelectNoSoul` GMST value respectively.
--- 
--- `noResultsCallback`: function? — *Optional*. A function which is called when no items have been found in the inventory, right before the message containing `noResultsText` is shown.
--- 
--- `filter`: function|string|nil — *Optional*. This determines which items should be shown in the inventory select menu. Accepts either a string or a function.
--- --- 
--- --- 		If assigning a string it has to be one of the following values:
--- --- 
--- --- 		- `alembic`: Only [tes3apparatus](https://mwse.github.io/MWSE/types/tes3apparatus/) items of type `tes3.apparatusType.alembic` will be shown. 
--- --- 		- `calcinator`: Only [tes3apparatus](https://mwse.github.io/MWSE/types/tes3apparatus/) items of type `tes3.apparatusType.calcinator` will be shown. 
--- --- 		- `enchanted`: Only enchanted items will be shown. 
--- --- 		- `ingredients`: Only [tes3ingredient](https://mwse.github.io/MWSE/types/tes3ingredient/) items will be shown. 
--- --- 		- `mortar`: Only [tes3apparatus](https://mwse.github.io/MWSE/types/tes3apparatus/) items of type `tes3.apparatusType.mortarAndPestle` will be shown. 
--- --- 		- `quickUse`: Only items available for quick use will be shown.
--- --- 		- `retort`: Only [tes3apparatus](https://mwse.github.io/MWSE/types/tes3apparatus/) items of type `tes3.apparatusType.retort` will be shown. 
--- --- 		- `soulgemFilled`: Only filled soulgems will be shown.
--- --- 
--- --- 		If assigning a function it will be called when determining if an item should be added to the inventory select menu. A table `filterParams` will be passed to this function. Returning `true` from this function will add the item to the inventory select menu, whereas returning `false` will prevent it from being added.
--- --- 
--- --- 		- `filterParams` (table)
--- --- 			- `item` ([tes3item](https://mwse.github.io/MWSE/types/tes3item/)): The item that is being filtered.
--- --- 			- `itemData` ([tes3itemData](https://mwse.github.io/MWSE/types/tes3itemData/)): The item data of the item that is being filtered. Can be `nil`.
--- --- 
--- 
--- `callback`: function? — *Optional*. A function which will be called once the inventory select menu has been closed, including when no item has been selected. A table `callbackParams` will be passed to this function.
--- --- 		- `callbackParams` (table)
--- --- 			- `item` ([tes3item](https://mwse.github.io/MWSE/types/tes3item/)): The item that has been selected. Can be `nil`.
--- --- 			- `itemData` ([tes3itemData](https://mwse.github.io/MWSE/types/tes3itemData/)): The item data of the item that has been selected. Can be `nil`.
--- --- 			- `count` (number): The number of items that have been selected. Only valid if `item` is not `nil`.
--- --- 			- `inventory` ([tes3inventory](https://mwse.github.io/MWSE/types/tes3inventory/)): The inventory containing the items.
--- --- 			- `actor` ([tes3actor](https://mwse.github.io/MWSE/types/tes3actor/)): The actor containing the inventory.
--- --- 
function tes3ui.showInventorySelectMenu(params) end

---Table parameter definitions for `tes3ui.showInventorySelectMenu`.
--- @class tes3ui.showInventorySelectMenu.params
--- @field reference tes3reference? *Default*: `tes3player`. The reference of a `tes3actor` whose inventory will be used.
--- @field title string The text used for the title of the inventory select menu.
--- @field leaveMenuMode boolean? *Optional*. Determines if menu mode should be exited after closing the inventory select menu. By default, it will be in the state it was in before this function was called.
--- @field noResultsText string? *Optional*. The text used for the message that gets shown to the player if no items have been found in the inventory. The default text is equivalent to the `sInventorySelectNoItems` GMST value, unless `"ingredients"` or `"soulgemFilled"` has been assigned to `filter`, in which case the default text is equivalent to either the `sInventorySelectNoIngredients` or `sInventorySelectNoSoul` GMST value respectively.
--- @field noResultsCallback function? *Optional*. A function which is called when no items have been found in the inventory, right before the message containing `noResultsText` is shown.
--- @field filter function|string|nil *Optional*. This determines which items should be shown in the inventory select menu. Accepts either a string or a function.
--- 
--- 		If assigning a string it has to be one of the following values:
--- 
--- 		- `alembic`: Only [tes3apparatus](https://mwse.github.io/MWSE/types/tes3apparatus/) items of type `tes3.apparatusType.alembic` will be shown. 
--- 		- `calcinator`: Only [tes3apparatus](https://mwse.github.io/MWSE/types/tes3apparatus/) items of type `tes3.apparatusType.calcinator` will be shown. 
--- 		- `enchanted`: Only enchanted items will be shown. 
--- 		- `ingredients`: Only [tes3ingredient](https://mwse.github.io/MWSE/types/tes3ingredient/) items will be shown. 
--- 		- `mortar`: Only [tes3apparatus](https://mwse.github.io/MWSE/types/tes3apparatus/) items of type `tes3.apparatusType.mortarAndPestle` will be shown. 
--- 		- `quickUse`: Only items available for quick use will be shown.
--- 		- `retort`: Only [tes3apparatus](https://mwse.github.io/MWSE/types/tes3apparatus/) items of type `tes3.apparatusType.retort` will be shown. 
--- 		- `soulgemFilled`: Only filled soulgems will be shown.
--- 
--- 		If assigning a function it will be called when determining if an item should be added to the inventory select menu. A table `filterParams` will be passed to this function. Returning `true` from this function will add the item to the inventory select menu, whereas returning `false` will prevent it from being added.
--- 
--- 		- `filterParams` (table)
--- 			- `item` ([tes3item](https://mwse.github.io/MWSE/types/tes3item/)): The item that is being filtered.
--- 			- `itemData` ([tes3itemData](https://mwse.github.io/MWSE/types/tes3itemData/)): The item data of the item that is being filtered. Can be `nil`.
--- 
--- @field callback function? *Optional*. A function which will be called once the inventory select menu has been closed, including when no item has been selected. A table `callbackParams` will be passed to this function.
--- 		- `callbackParams` (table)
--- 			- `item` ([tes3item](https://mwse.github.io/MWSE/types/tes3item/)): The item that has been selected. Can be `nil`.
--- 			- `itemData` ([tes3itemData](https://mwse.github.io/MWSE/types/tes3itemData/)): The item data of the item that has been selected. Can be `nil`.
--- 			- `count` (number): The number of items that have been selected. Only valid if `item` is not `nil`.
--- 			- `inventory` ([tes3inventory](https://mwse.github.io/MWSE/types/tes3inventory/)): The inventory containing the items.
--- 			- `actor` ([tes3actor](https://mwse.github.io/MWSE/types/tes3actor/)): The actor containing the inventory.
--- 

--- Displays the scroll menu with arbitrary text. It needs to follow book text conventions as in the Construction Set. In essence, it uses HTML syntax. Important: every book needs to end with a `<BR>` statement to be displayed properly. See [`bookGetText`](https://mwse.github.io/MWSE/events/bookGetText/#examples) for an example of properly formatted scroll text.
--- @param text string No description yet available.
function tes3ui.showScrollMenu(text) end

--- 
function tes3ui.stealHelpMenu() end

--- Controls hiding of world object tooltips.
--- @param suppress boolean Turns on suppression if true, immediately hiding any active tooltip and further world object tooltips. Turns off suppression if false.
function tes3ui.suppressTooltip(suppress) end

--- Forces the game to update the barter menu's tile GUI elements.
function tes3ui.updateBarterMenuTiles() end

--- Forces the game to update the contents menu's tile GUI elements.
function tes3ui.updateContentsMenuTiles() end

--- Forces the game to update the dialog disposition GUI element.
function tes3ui.updateDialogDisposition() end

--- Forces the game to update the enchanting menu GUI.
function tes3ui.updateEnchantingMenu() end

--- Tells the game to update the character image in the player's inventory. It will update immediately if the inventory is open, or the next time the inventory is opened otherwise.
function tes3ui.updateInventoryCharacterImage() end

--- Forces the game to update the inventory selection GUI elements.
function tes3ui.updateInventorySelectTiles() end

--- Forces the game to update the inventory tile GUI elements.
function tes3ui.updateInventoryTiles() end

--- Forces the game to update the spellmaking menu GUI.
function tes3ui.updateSpellmakingMenu() end

