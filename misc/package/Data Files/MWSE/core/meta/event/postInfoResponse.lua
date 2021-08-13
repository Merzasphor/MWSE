--- @meta

--- This event fires immediately after a dialogue response is processed.
--- @class postInfoResponseEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field command string The command.
--- @field dialogue tes3dialogue The dialogue object.
--- @field info tes3dialogueInfo The dialogue info object.
--- @field reference tes3reference The reference.
--- @field variables tes3scriptVariables The script variables.
