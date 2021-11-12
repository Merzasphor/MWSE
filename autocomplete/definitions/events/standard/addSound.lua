return {
	type = "event",
    description = "This event is triggered when a sound is played by the game or when tes3.playSound is called.",
	related = { "addTempSound" },
    eventData = {
        ["sound"] = {
            type = "tes3sound",
            description = "The sound going to be played.",
        },
        ["reference"] = {
            type = "tes3reference",
            description = "The reference which is emiting the sound.",
        },
        ["flags"] = {
            type = "number",
            readOnly = true,
            description = "A flag whether the sound is looping or not. 0 means the sound doesn't loop, 1 means the sound loops."
        },
        ["volume"] = {
            type = "number",
            description = "The volume of the sound. Volume = 1 means 100 % loudness. Values lower than 1 make the sound quiter.",
        },
        ["pitch"] = {
            type = "number",
            description = "Pitch of the sound.",
        },
        ["isVoiceover"] = {
            type = "boolean",
            description = "A flag whether the sound is a voiced line, which are usually found in the Sound\\Vo data folder.",
        },
    },
	blockable = true,
    -- TODO - Add an example: return false, e.block = true, or e.volume = 0
}
