--- @meta

--- A structure containing properties specific to sliders.
--- @class tes3uiSlider
--- @field current number The current value. The position of the slider handle is determined by dividing `current` by `max`.
--- @field jump number The change in value when clicking into the empty areas next to the slider handle.
--- @field max number The maximum value. The position of the slider handle is determined by dividing `current` by `max`.
--- @field step number The change in value when clicking the left and right arrow buttons.
tes3uiSlider = {}

