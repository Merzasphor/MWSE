return {
	type = "event",
	description = "This event fires whenever a keybind is tested by the game. A keybind test is often to see if a button is pressed, but it can also be done to see if an input was toggled or released. Blocking this event is equivalent to setting the `result` event data to false.",
	eventData = {
		["keybind"] = {
			type = "number",
			readOnly = true,
			description = "The keybind that was tested. This maps to the `tes3.keybind.*` constants.",
		},
		["transition"] = {
			type = "number",
			readOnly = true,
			description = "The transition for the keybind that was tested. This is typically `tes3.keyTransition.down` but not guaranteed to be. Always be sure to check what transition is being used.",
		},
		["result"] = {
			type = "boolean",
			description = "The read state of the keybind. If true, the key was pressed/released/toggled as determined by the `transition` event data.",
		},
	},
	filter = "keybind",
	blockable = true,
	examples = {
		["BlockJournal"] = {
			title = "Block Journal Keybind",
			description = "Prevents the journal keybind from ever being registered as pressed.",
		},
	},
}