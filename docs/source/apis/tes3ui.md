# tes3ui

The tes3ui library provides access to manipulating the game's GUI.

## Functions

### `tes3ui.acquireTextInput`

Sends all text input to the specified element.  Calling this function with a nil argument will release text input and allow keybinds to work. Suppresses most keybinds while active, except the Journal open/close keybind (it's up to the individual menu implementation).

Only one element can have control of input, and there is no automatic restoration of control if one element takes control from another. Be careful of conflicts with other users of this function.

```lua
tes3ui.acquireTextInput(element)
```

**Parameters**:

* `element` ([tes3uiElement](../../types/tes3uiElement)): *Optional*.

***

### `tes3ui.captureMouseDrag`

When used in a mouse event, causes the element to capture further mouse events even when the cursor goes outside the element. Setting mouse capture should always be accompanied by releasing it on a complementary event. This is commonly used for dragging, so that it can continue even if the mouse moves slightly outside the element.

The capture is always removed when the element is destroyed. The capture may also be removed when the mouse is released, but this is not reliable, as the engine forgets what to do if there is input from any other controller while the mouse is held down.

```lua
tes3ui.captureMouseDrag(capture)
```

**Parameters**:

* `capture` (boolean): Turns on mouse capture for the element currently processing a mouse event if true, sending all further mouse events to that element. Turns off capture if false.

??? example "Example: Basic Usage"

	Using the UI event system, cause a given element to capture the mouse drag.

	```lua
	element:register("mouseDown", function(e)
		-- Capture must be inside a mouse event.
		tes3ui.captureMouseDrag(true)
	end)
	
	element:register("mouseRelease", function(e)
		-- Release may be anywhere.
		tes3ui.captureMouseDrag(false)
	end)

	```

***

### `tes3ui.choice`

Creates a simple dialogue choice, as per the `Choice` mwscript function.

```lua
tes3ui.choice(text, index)
```

**Parameters**:

* `text` (string): The text to display for the choice.
* `index` (number): The choice index associated with the given text.

***

### `tes3ui.closeJournal`

Closes the Journal.

```lua
local result = tes3ui.closeJournal()
```

**Returns**:

* `result` (boolean)

***

### `tes3ui.createHelpLayerMenu`

Creates a help layer menu. Help layer menus include notifications and tooltips that are always above the rest of the interface. The game realizes this using a separate menu root and set of functions.

Note, to create tooltips with the correct behaviour, use tes3ui.createTooltipMenu.

Unlike standard menus, help layer menus are always created with a fixed frame.

```lua
local result = tes3ui.createHelpLayerMenu({ id = ... })
```

**Parameters**:

* `params` (table)
	* `id` (string, number): The menu’s ID. The menu can be later accessed by tes3ui.findHelpLayerMenu(id).

**Returns**:

* `result` ([tes3uiElement](../../types/tes3uiElement))

***

### `tes3ui.createMenu`

Creates a top-level menu.

```lua
local result = tes3ui.createMenu({ id = ..., dragFrame = ..., fixedFrame = ..., loadable = ... })
```

**Parameters**:

* `params` (table)
	* `id` (string, number): The menu’s ID. The menu can be later accessed by tes3ui.findMenu(id).
	* `dragFrame` (boolean): *Default*: `false`. Constructs a draggable and resizeable frame and background for the menu. It is similar to the stats, inventory, magic and map menus in the standard UI. After construction, position and minimum dimensions should be set.
	* `fixedFrame` (boolean): *Default*: `false`. Constructs a fixed (non-draggable) frame and background for the menu. The layout system should automatically centre and size it to fit whatever is added to the menu.
	* `loadable` (boolean): *Default*: `true`. If set to false, calls to loadMenuPosition will fail.

**Returns**:

* `result` ([tes3uiElement](../../types/tes3uiElement))

***

### `tes3ui.createResponseText`

Creates a respond text. This function is used for the mwscript `Choice` function.

```lua
tes3ui.createResponseText({ text = ..., type = ..., index = ... })
```

**Parameters**:

* `params` (table)
	* `text` (string): The text to display.
	* `type` (number): *Optional*. The type for the response. Defaults to `choice` responses.
	* `index` (number): *Optional*. The answer index for the response. Only used for `choice` responses.

***

### `tes3ui.createTooltipMenu`

Creates a tooltip menu, which can be an empty menu or an item tooltip. This should be called from within a tooltip event callback. These automatically follow the mouse cursor, and are also destroyed automatically when the mouse leaves the originating element. Creating an item tooltip will invoke the uiObjectTooltip event.

```lua
local result = tes3ui.createTooltipMenu({ item = ..., itemData = ... })
```

**Parameters**:

* `params` (table): *Optional*.
	* `item` ([tes3item](../../types/tes3item), string): *Optional*. The item to create a tooltip for. If not specified, the tooltip will be empty.
	* `itemData` ([tes3itemData](../../types/tes3itemData)): *Optional*. The item data for the item.

**Returns**:

* `result` ([tes3uiElement](../../types/tes3uiElement))

??? example "Example: Add an item tooltip to a new element"

	This demonstrates adding an item tooltip to a button using the help event.

	```lua
	local button = menu:createButton{text = "- Item -"}
	local item = tes3.getObject("iron_shield")
	
	button:register("help", function(e)
		local tooltip = tes3ui.createTooltipMenu{item = item}
		tooltip:createLabel{text = "Additional custom text"}
	end)

	```

***

### `tes3ui.enterMenuMode`

Requests menu mode be activated on a menu with a given id.

```lua
local result = tes3ui.enterMenuMode(id)
```

**Parameters**:

* `id` (string, number)

**Returns**:

* `result` (boolean)

***

### `tes3ui.findHelpLayerMenu`

Locates a help layer menu through its id. Help layer menus include notifications and tooltips that are always above the rest of the interface. The game realizes this using a separate menu root and set of functions.

```lua
local result = tes3ui.findHelpLayerMenu(id)
```

**Parameters**:

* `id` (string, number)

**Returns**:

* `result` ([tes3uiElement](../../types/tes3uiElement))

***

### `tes3ui.findMenu`

Locates a top-level menu through its id.

```lua
local result = tes3ui.findMenu(id)
```

**Parameters**:

* `id` (string, number): The ID of the menu to locate.

**Returns**:

* `result` ([tes3uiElement](../../types/tes3uiElement))

***

### `tes3ui.forcePlayerInventoryUpdate`

Forces the game to update the inventory tile GUI elements. Unlike tes3ui.updateInventoryTiles, this will force-resync the player's inventory to the GUI, rather than updating what is already in the GUI system.

```lua
tes3ui.forcePlayerInventoryUpdate()
```

***

### `tes3ui.getInventorySelectType`

Determines what sort of search is being done when performing an inventory selection, e.g. "alembic" or "ingredient" or "soulGemFilled".

```lua
local result = tes3ui.getInventorySelectType()
```

**Returns**:

* `result` (string)

***

### `tes3ui.getMenuOnTop`

Returns the top-most, active menu.

```lua
local result = tes3ui.getMenuOnTop()
```

**Returns**:

* `result` ([tes3uiElement](../../types/tes3uiElement))

***

### `tes3ui.getPalette`

Gets a standard palette color. Returns an array containing the RGB color values, in the range [0.0, 1.0].

```lua
local palette = tes3ui.getPalette(name)
```

**Parameters**:

* `name` (string): The name of the palette color. Maps to values in [`tes3.palette`](https://mwse.github.io/MWSE/references/palettes/) enumeration.

**Returns**:

* `palette` (number[]): An array containing the RGB color values, in the range [0.0, 1.0].

***

### `tes3ui.getServiceActor`

Returns the mobile actor currently providing services to the player.

```lua
local result = tes3ui.getServiceActor()
```

**Returns**:

* `result` ([tes3mobileActor](../../types/tes3mobileActor))

***

### `tes3ui.getViewportScale`

Returns the UI scale, set in MGE.

```lua
local scale = tes3ui.getViewportScale()
```

**Returns**:

* `scale` (number): The UI scale value set from MGE.

***

### `tes3ui.getViewportSize`

Returns both the viewport width and the viewport height. Note that this value is not necessarily the real resolution of the screen. For that value, see the [`same-named function`](https://mwse.github.io/MWSE/apis/tes3/#tes3getviewportsize) in the tes3 namespace. To get the scale used, check `getViewportScale`.

```lua
local width, height = tes3ui.getViewportSize()
```

**Returns**:

* `width` (number): The scaled width of the viewport.
* `height` (number): The scaled height of the viewport.

***

### `tes3ui.leaveMenuMode`

Requests menu mode be deactivated on a menu with a given id.

```lua
local result = tes3ui.leaveMenuMode()
```

**Returns**:

* `result` (boolean)

***

### `tes3ui.log`

Logs a message to the console. The message accepts formatting and additional parameters matching string.format's usage.

```lua
tes3ui.log(message, formatValues)
```

**Parameters**:

* `message` (string)
* `formatValues` (variadic): *Optional*.

??? example "Example: Print the type of each of the player's skills to the console"

	```lua
	
	local function printNames(e)
		local skillTypeNames = {
			[0] = "Major",
			[1] = "Minor",
			[2] = "Miscellaneous"
		}
	
		for _, skillId in pairs(tes3.skill) do
			local skillStat = tes3.mobilePlayer:getSkillStatistic(skillId)
			local name = tes3.getSkillName(skillId)
			local typeName = skillTypeNames[skillStat.type]
	
			tes3ui.log("%s, type: %s skill", name, typeName)
		end
	
		tes3.messageBox("Done! Open the console to see the result.")
	end
	
	event.register(tes3.event.keyDown, printNames, { filter = tes3.scanCode.u })

	```

***

### `tes3ui.logToConsole`

Logs a message to the console.

```lua
tes3ui.logToConsole(text, isCommand)
```

**Parameters**:

* `text` (string)
* `isCommand` (boolean): *Default*: `false`. Passing `true` will make the text in the console selectable by using up arrow key. If it is a valid command, then pressing enter will call it.

??? example "Example: This example describes how this function behaves with isCommand = true."

	```lua
	
	local function example()
		-- This will make "player->ModStrength 10" appear in the console coloured brown.
		-- It can't be selected by using up arrow key.
		tes3ui.logToConsole("player->ModStrength 10", false)
	
		-- This will make "player->ModWillpower 10" appear in the console coloured blue.
		-- It CAN be selected by using up arrow key, and when the enter is pressed,
		-- it will call that function.
		tes3ui.logToConsole("player->ModWillpower 10", true)
	
		tes3.messageBox("Done! Open the console to see the result.")
	end
	
	event.register(tes3.event.keyDown, example, { filter = tes3.scanCode.u })

	```

***

### `tes3ui.lookupID`



```lua
local executed = tes3ui.lookupID(unknown)
```

**Parameters**:

* `unnamed`

**Returns**:

* `executed` (string)

***

### `tes3ui.menuMode`

Checks if the game is in menu mode.

```lua
local result = tes3ui.menuMode()
```

**Returns**:

* `result` (boolean)

***

### `tes3ui.refreshTooltip`

Causes the tooltip to be redisplayed. This will not use a configured delay. This will not function if the help menu does not currently exist, or if it is not currently visible.

```lua
tes3ui.refreshTooltip()
```

***

### `tes3ui.registerID`

Registers a UI element name, returning a UI_ID. Once a property is registered, this function always returns the same UI_ID. These UI_IDs are used by the API to locate elements that may not exist (a weak reference), instead of by element name.

The registry namespace is shared between Property and UI_ID. It is advisable to use a namespace prefix to avoid collisions with other mods.

```lua
local result = tes3ui.registerID(s)
```

**Parameters**:

* `s` (string)

**Returns**:

* `result` (number)

***

### `tes3ui.registerProperty`

Registers a property name, returning a Property. Once a property is registered, this function always returns the same Property.

The registry namespace is shared between Property and UI_ID. It is advisable to use a namespace prefix to avoid collisions with other mods.

```lua
local result = tes3ui.registerProperty(s)
```

**Parameters**:

* `s` (string)

**Returns**:

* `result` (number)

***

### `tes3ui.showBookMenu`

Displays the book menu with arbitrary text. Paging is automatically handled. It needs to follow book text conventions as in the Construction Set. In essence, it uses HTML syntax. Important: every book needs to end with a `<BR>` statement to be displayed properly. See [`bookGetText`](https://mwse.github.io/MWSE/events/bookGetText/#examples) for an example of properly formatted book text.

```lua
tes3ui.showBookMenu(text)
```

**Parameters**:

* `text` (string)

***

### `tes3ui.showDialogueMessage`



```lua
tes3ui.showDialogueMessage({ text = ..., style = ..., answerIndex = ... })
```

**Parameters**:

* `params` (table)
	* `text` (string): *Default*: ``. The text of the shown message.
	* `style` (number): *Default*: `0`. 
	* `answerIndex` (number): *Default*: `0`. 

***

### `tes3ui.showInventorySelectMenu`

This function opens the inventory select menu which lets the player select items from an inventory. These items can be selected from any actor's inventory and can be filtered with the `filter` callback. The selected item can be retrieved in the function assigned to `callback`.

```lua
tes3ui.showInventorySelectMenu({ reference = ..., title = ..., leaveMenuMode = ..., noResultsText = ..., noResultsCallback = ..., filter = ..., callback = ... })
```

**Parameters**:

* `params` (table)
	* `reference` ([tes3reference](../../types/tes3reference)): *Default*: `tes3player`. The reference of a `tes3actor` whose inventory will be used.
	* `title` (string): The text used for the title of the inventory select menu.
	* `leaveMenuMode` (boolean): *Optional*. Determines if menu mode should be exited after closing the inventory select menu. By default, it will be in the state it was in before this function was called.
	* `noResultsText` (string): *Optional*. The text used for the message that gets shown to the player if no items have been found in the inventory. The default text is equivalent to the `sInventorySelectNoItems` GMST value, unless `"ingredients"` or `"soulgemFilled"` has been assigned to `filter`, in which case the default text is equivalent to either the `sInventorySelectNoIngredients` or `sInventorySelectNoSoul` GMST value respectively.
	* `noResultsCallback` (function): *Optional*. A function which is called when no items have been found in the inventory, right before the message containing `noResultsText` is shown.
	* `filter` (function, string): *Optional*. This determines which items should be shown in the inventory select menu. Accepts either a string or a function.

		If assigning a string it has to be one of the following values:

		- `alembic`: Only [tes3apparatus](https://mwse.github.io/MWSE/types/tes3apparatus/) items of type `tes3.apparatusType.alembic` will be shown. 
		- `calcinator`: Only [tes3apparatus](https://mwse.github.io/MWSE/types/tes3apparatus/) items of type `tes3.apparatusType.calcinator` will be shown. 
		- `enchanted`: Only enchanted items will be shown. 
		- `ingredients`: Only [tes3ingredient](https://mwse.github.io/MWSE/types/tes3ingredient/) items will be shown. 
		- `mortar`: Only [tes3apparatus](https://mwse.github.io/MWSE/types/tes3apparatus/) items of type `tes3.apparatusType.mortarAndPestle` will be shown. 
		- `quickUse`: Only items available for quick use will be shown.
		- `retort`: Only [tes3apparatus](https://mwse.github.io/MWSE/types/tes3apparatus/) items of type `tes3.apparatusType.retort` will be shown. 
		- `soulgemFilled`: Only filled soulgems will be shown.

		If assigning a function it will be called when determining if an item should be added to the inventory select menu. A table `filterParams` will be passed to this function. Returning `true` from this function will add the item to the inventory select menu, whereas returning `false` will prevent it from being added.

		- `filterParams` (table)
			- `item` ([tes3item](https://mwse.github.io/MWSE/types/tes3item/)): The item that is being filtered.
			- `itemData` ([tes3itemData](https://mwse.github.io/MWSE/types/tes3itemData/)): The item data of the item that is being filtered. Can be `nil`.

	* `callback` (function): *Optional*. A function which will be called once the inventory select menu has been closed, including when no item has been selected. A table `callbackParams` will be passed to this function.
		- `callbackParams` (table)
			- `item` ([tes3item](https://mwse.github.io/MWSE/types/tes3item/)): The item that has been selected. Can be `nil`.
			- `itemData` ([tes3itemData](https://mwse.github.io/MWSE/types/tes3itemData/)): The item data of the item that has been selected. Can be `nil`.
			- `count` (number): The number of items that have been selected. Only valid if `item` is not `nil`.
			- `inventory` ([tes3inventory](https://mwse.github.io/MWSE/types/tes3inventory/)): The inventory containing the items.
			- `actor` ([tes3actor](https://mwse.github.io/MWSE/types/tes3actor/)): The actor containing the inventory.


***

### `tes3ui.showScrollMenu`

Displays the scroll menu with arbitrary text. It needs to follow book text conventions as in the Construction Set. In essence, it uses HTML syntax. Important: every book needs to end with a `<BR>` statement to be displayed properly. See [`bookGetText`](https://mwse.github.io/MWSE/events/bookGetText/#examples) for an example of properly formatted scroll text.

```lua
tes3ui.showScrollMenu(text)
```

**Parameters**:

* `text` (string)

***

### `tes3ui.stealHelpMenu`



```lua
tes3ui.stealHelpMenu()
```

***

### `tes3ui.suppressTooltip`

Controls hiding of world object tooltips.

```lua
tes3ui.suppressTooltip(suppress)
```

**Parameters**:

* `suppress` (boolean): Turns on suppression if true, immediately hiding any active tooltip and further world object tooltips. Turns off suppression if false.

***

### `tes3ui.updateBarterMenuTiles`

Forces the game to update the barter menu's tile GUI elements.

```lua
tes3ui.updateBarterMenuTiles()
```

***

### `tes3ui.updateContentsMenuTiles`

Forces the game to update the contents menu's tile GUI elements.

```lua
tes3ui.updateContentsMenuTiles()
```

***

### `tes3ui.updateDialogDisposition`

Forces the game to update the dialog disposition GUI element.

```lua
tes3ui.updateDialogDisposition()
```

***

### `tes3ui.updateEnchantingMenu`

Forces the game to update the enchanting menu GUI.

```lua
tes3ui.updateEnchantingMenu()
```

***

### `tes3ui.updateInventoryCharacterImage`

Tells the game to update the character image in the player's inventory. It will update immediately if the inventory is open, or the next time the inventory is opened otherwise.

```lua
tes3ui.updateInventoryCharacterImage()
```

***

### `tes3ui.updateInventorySelectTiles`

Forces the game to update the inventory selection GUI elements.

```lua
tes3ui.updateInventorySelectTiles()
```

***

### `tes3ui.updateInventoryTiles`

Forces the game to update the inventory tile GUI elements.

```lua
tes3ui.updateInventoryTiles()
```

***

### `tes3ui.updateSpellmakingMenu`

Forces the game to update the spellmaking menu GUI.

```lua
tes3ui.updateSpellmakingMenu()
```

***

