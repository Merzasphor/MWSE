--- @meta

--- A structure containing properties specific to text inputs.
--- @class tes3uiTextInput
--- @field eraseOnFirstKey boolean *Default*: `true`. If `true`, clears the initial value if the first keypress is not an edit action.
--- @field lengthLimit number The character limit. Inputting additional characters will not be possible if this limit has been reached. Setting this to `nil` will remove the limit.
tes3uiTextInput = {}

