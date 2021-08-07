---
hide:
  - toc
---

# TES3 UI Example

This example allows you to rename the object you are targetting. When the '/' key is pressed, a custom input window is opened.

```lua linenums="1"
--[[
    Mod: TES3UI TextInput
    Author: Hrnchamd
]]--

local this = {}


function this.init()
    this.id_menu = tes3ui.registerID("example:MenuTextInput")
    this.id_input = tes3ui.registerID("example:MenuTextInput_Text")
    this.id_ok = tes3ui.registerID("example:MenuTextInput_Ok")
    this.id_cancel = tes3ui.registerID("example:MenuTextInput_Cancel")
end


-- Create window and layout. Called by onCommand.
function this.createWindow()
    -- Return if window is already open
    if (tes3ui.findMenu(this.id_menu) ~= nil) then
        return
    end

    -- Create window and frame
    local menu = tes3ui.createMenu{ id = this.id_menu, fixedFrame = true }

    -- To avoid low contrast, text input windows should not use menu transparency settings
    menu.alpha = 1.0

    -- Create layout
    local input_label = menu:createLabel{ text = "Rename your item" }
    input_label.borderBottom = 5

    local input_block = menu:createBlock{}
    input_block.width = 300
    input_block.autoHeight = true
    input_block.childAlignX = 0.5  -- centre content alignment

    local border = input_block:createThinBorder{}
    border.width = 300
    border.height = 30
    border.childAlignX = 0.5
    border.childAlignY = 0.5

    local input = border:createTextInput{ id = this.id_input }
    input.text = this.item.name  -- initial text
    input.borderLeft = 5
    input.borderRight = 5
    input.widget.lengthLimit = 31  -- TextInput custom properties
    input.widget.eraseOnFirstKey = true

    local button_block = menu:createBlock{}
    button_block.widthProportional = 1.0  -- width is 100% parent width
    button_block.autoHeight = true
    button_block.childAlignX = 1.0  -- right content alignment

    local button_cancel = button_block:createButton{ id = this.id_cancel, text = tes3.findGMST("sCancel").value }
    local button_ok = button_block:createButton{ id = this.id_ok, text = tes3.findGMST("sOK").value }

    -- Events
    button_cancel:register("mouseClick", this.onCancel)
    menu:register("keyEnter", this.onOK) -- only works when text input is not captured
    input:register("keyEnter", this.onOK)
    button_ok:register("mouseClick", this.onOK)

    -- Final setup
    menu:updateLayout()
    tes3ui.enterMenuMode(this.id_menu)
    tes3ui.acquireTextInput(input) -- automatically reset when menu is closed
end


-- OK button callback.
function this.onOK(e)
    local menu = tes3ui.findMenu(this.id_menu)

    if (menu) then
        -- Copy text *before* the menu is destroyed
        local name = menu:findChild(this.id_input).text

        tes3ui.leaveMenuMode()
        menu:destroy()

        tes3.messageBox{ message = this.item.name .. " renamed to " .. name }
        this.item.name = name
    end
end

-- Cancel button callback.
function this.onCancel(e)
    local menu = tes3ui.findMenu(this.id_menu)

    if (menu) then
        tes3ui.leaveMenuMode()
        menu:destroy()
    end
end

-- Keydown callback.
function this.onCommand(e)
    local t = tes3.getPlayerTarget()
    if (t) then
        t = t.object.baseObject or t.object -- Select actor base object

        if (t.name) then
            this.item = t
            this.createWindow()
        end
    end
end

event.register("initialized", this.init)
event.register("keyDown", this.onCommand, { filter = 53 }) -- "/" key
```