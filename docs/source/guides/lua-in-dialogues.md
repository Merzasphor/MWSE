# Lua in Dialogues

It is possible to use lua inside the mwscript results pane in the dialogue menu of the Construction Set.

!!! note
	The execution order of the Results pane is not mixed. All lua commands will be executed before the mwscript is parsed and executed.

!!! tip
	The keyboard shortcut Control+A does not work in the Construction Set. Right-clicking still allows selecting all text for quick replacement.

## Basic Usage

To write lines with lua, prefix them with a mwscript comment starting with `;lua `. This allows the lua commands to be backwards-compatible for users that do not have MWSE, including users of OpenMW.

!!! example "Example: Goodbye with a Message"

	```
	; The next line will execute lua.
	;lua tes3.messageBox("This will run as lua!")

	; The next line will just be normal mwscript.
	goodbye
	```

## Executing a Lua File

It may be useful only use this as a way to get back to a normal lua file, by use of `dofile`.

!!! example "Example: Execute Lua File from Dialogue"

	```lua
	;lua dofile("myMod.onSomeDialogueResult")
	```

## Environment

All commands from the same results text share the same lua environment. This allows persistent values between lines. To do this however, the `local` keyword cannot be used. This does not pollute the normal global namespace.

!!! example "Example: Multi Line Values"

	```lua
	;lua playerName = tes3.player.object.name
	;lua tes3.messageBox("Hello %s", playerName)
	```

Additionally, some information has been provided in the environment. These values are `reference`, `dialogue`, and `info` for the specifics of what result is being executed, and on who.

!!! example "Example: Print Results Context"

	```lua
	;lua tes3.messageBox("Reference: %s; Dialogue/INFO: %s/%s;", reference, dialogue, info.id)
	```
