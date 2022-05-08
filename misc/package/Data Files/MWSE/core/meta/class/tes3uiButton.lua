--- @meta
--- @diagnostic disable:undefined-doc-name

--- A structure containing properties specific to buttons.
--- @class tes3uiButton
--- @field idle niColor The RGB color of the button's text when `state` is set to `normal`.	An array of 3 floats with values ranging from `0.0` to `1.0`.
--- @field idleActive niColor The RGB color of the button's text when `state` is set to `active`. An array of 3 floats with values ranging from `0.0` to `1.0`.
--- @field idleDisabled niColor The RGB color of the button's text when `state` is set to `disabled`. An array of 3 floats with values ranging from `0.0` to `1.0`.
--- @field over niColor The RGB color of the button's text when the button is selected and `state` is set to `normal`. An array of 3 floats with values ranging from `0.0` to `1.0`.
--- @field overActive niColor The RGB color of the button's text when the button is selected and `state` is set to `active`. An array of 3 floats with values ranging from `0.0` to `1.0`.
--- @field overDisabled niColor The RGB color of the button's text when the button is selected and `state` is set to `disabled`. An array of 3 floats with values ranging from `0.0` to `1.0`.
--- @field pressed niColor The RGB color of the button's text when the button is pressed and `state` is set to `normal`. An array of 3 floats with values ranging from `0.0` to `1.0`.
--- @field pressedActive niColor The RGB color of the button's text when the button is pressed and `state` is set to `active`. An array of 3 floats with values ranging from `0.0` to `1.0`.
--- @field pressedDisabled niColor The RGB color of the button's text when the button is pressed and `state` is set to `disabled`. An array of 3 floats with values ranging from `0.0` to `1.0`.
--- @field state number The state of the button. Controls which color set to use for its text. Maps to values in [`tes3.uiState`](https://mwse.github.io/MWSE/references/ui-states/).
tes3uiButton = {}

