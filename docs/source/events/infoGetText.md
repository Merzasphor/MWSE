# infoGetText

This event fires when a dialogue info object text is retrieved. That can be when starting a conversation with an NPC, a service was refused to the player, NPC's responses to player persuading them and if the subtitles are enabled, getting the text for the subtitle will also trigger `infoGetText` event.

```lua
--- @param e infoGetTextEventData
local function infoGetTextCallback(e)
end
event.register(tes3.event.infoGetText, infoGetTextCallback)
```

!!! tip
	This event can be filtered based on the **`info`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `info` ([tes3dialogueInfo](../../types/tes3dialogueInfo)): *Read-only*. The dialogue info object.
* `loadOriginalText` (method): Loads the original text for the info from the game files, bypassing this event.
* `text` (string): The text to return. This can be modified. Does not contain the original text. If not set, the original text will be used instead.

## Examples

!!! example "Example: Append custom text to a greeting line."

	```lua
	-- This will make Ra'virr give the player 2 Moon Sugar when the conversation is initiated
	
	local function onInfoGetText(e)
		if e.info.actor.id ~= "ra'virr" then
			return
		end
	
		if e.info.type == tes3.dialogueType.greeting then
			-- e.text is empty by default.
			e.text = e:loadOriginalText() .. "\n\nSweet sugar! Have some."
			tes3.addItem({
				reference = tes3.player,
				item = "ingred_moon_sugar_01",
				count = 2,
			})
		end
	end
	
	event.register(tes3.event.infoGetText, onInfoGetText)

	```

