--- @meta

--- This event fires when a dialogue response is triggered.
--- @class infoResponseEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field command string The command.
--- @field info tes3dialogueInfo The dialogue info object.
--- @field dialogue tes3dialogue The dialogue object.
--- @field reference tes3reference The reference.
--- @field variables tes3scriptVariables The script variables.
infoResponse = {}

