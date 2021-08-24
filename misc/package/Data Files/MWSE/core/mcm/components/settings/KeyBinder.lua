--[[
	Button Setting for binding a key combination. Variable returned in the form:
		{
			keyCode = tes3.scanCode,
			isAltPressed = true/false,
			isShiftPressed = true/false,
			isCtrlPressed = true/false
		}
]]--

local Parent = require("mcm.components.settings.Button")

local KeyBinder = Parent:new()
KeyBinder.allowCombinations = true
KeyBinder.currentCombo = {}
KeyBinder.messageDoRebind = mwse.mcm.i18n("Set new key binding to: %s")
KeyBinder.messageRebinded = mwse.mcm.i18n("Key binding changed to '%s'")
KeyBinder.sOkay = mwse.mcm.i18n("Rebind")
KeyBinder.sNotChanged = mwse.mcm.i18n("Key binding not changed.")
KeyBinder.sCancel = tes3.findGMST(tes3.gmst.sCancel).value

function KeyBinder:getText()
	return self:getComboString(self.variable.value)
end

function KeyBinder:getLetter(keyCode)
	for letter, code in pairs(tes3.scanCode) do
		if code == keyCode then
			local returnString = tes3.scanCodeToNumber[code] or letter
			return string.upper(returnString)
		end
	end
	return nil
end

function KeyBinder:getComboString(keyCombo)
	-- Returns "SHIFT-X" if shift is held down but the active key is not Shift, 
	-- otherwise just "X" (X being the key being pressed)
	-- And so on for Alt and Ctrl

	local letter = self:getLetter(keyCombo.keyCode) or string.format("{%s}", mwse.mcm.i18n("unknown key"))

	-- if you set allowCombinations to false, nothing functionally changes
	-- but the player doesn't see the prefix
	if not self.allowCombinations then
		return letter
	end

	local hasAlt = (keyCombo.isAltDown and keyCombo.keyCode ~= tes3.scanCode.lAlt and keyCombo.keyCode ~=
	               tes3.scanCode.rAlt)
	local hasShift = (keyCombo.isShiftDown and keyCombo.keyCode ~= tes3.scanCode.lShift and keyCombo.keyCode ~=
	                 tes3.scanCode.rShift)
	local hasCtrl = (keyCombo.isControlDown and keyCombo.keyCode ~= tes3.scanCode.lCtrl and keyCombo.keyCode ~=
	                tes3.scanCode.rCtrl)
	local prefix = (hasAlt and "Alt-" or hasShift and "Shift-" or hasCtrl and "Ctrl-" or "")
	return (prefix .. letter)
end

function KeyBinder:keySelected(e)
	-- If not set then we ignore this trigger as we've pressed okay or cancel
	if not self.currentCombo.keyCode then
		return
	end
	self.currentCombo = {
		keyCode = e.keyCode,
		isAltDown = e.isAltDown,
		isShiftDown = e.isShiftDown,
		isControlDown = e.isControlDown,
	}

	-- This messagebox forces the next messagebox to have the same layout as the previous one
	tes3.messageBox({ message = "An error has occured", buttons = { self.sOkay } })
	self:showKeyBindMessage(self.currentCombo)
end

function KeyBinder:bindKey(e)
	-- Retrigger if Spacebar/Return was pressed
	local inputController = tes3.worldController.inputController
	local okay = 0
	if e.button == okay then
		if self.currentCombo == self.variable.value then
			tes3.messageBox(self.sNotChanged)
		else
			tes3.messageBox(self.messageRebinded, self:getComboString(self.currentCombo))
			self.variable.value = self.currentCombo
			self:setText(self:getText())
		end
	end
	self.currentCombo = { keyCode = nil }
end

function KeyBinder:showKeyBindMessage(keyCombo)
	-- Register keyDown event
	event.register("keyDown", function(e)
		self:keySelected(e)
	end, { doOnce = true })

	-- Show keybind Message
	local message = string.format(self.messageDoRebind, self:getComboString(keyCombo))
	tes3.messageBox({
		message = message,
		buttons = { self.sOkay, self.sCancel },
		callback = (function(e)
			self:bindKey(e)
		end),
	})
end

function KeyBinder:update()
	-- Initialise combo to existing keybind
	self.currentCombo = self.variable.value
	-- Display message to change keybinding
	self:showKeyBindMessage(self.variable.value)
end

-- UI methods

function KeyBinder:createOuterContainer(parentBlock)
	Parent.createOuterContainer(self, parentBlock)
	self.elements.outerContainer.autoWidth = false
	self.elements.outerContainer.widthProportional = 1.0
	-- self.elements.outerContainer.borderRight = self.indent
end

function KeyBinder:makeComponent(parentBlock)
	Parent.makeComponent(self, parentBlock)
	-- self.elements.button.absolutePosAlignX = 1.0
end

return KeyBinder
