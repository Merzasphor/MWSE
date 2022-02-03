--- @meta

--- A structure containing properties specific to text selects.
--- @class tes3uiTextSelect
--- @field idle table The RGB color of the text when `state` is set to `normal`. An array of 3 floats with values ranging from `0.0` to `1.0`.
--- @field idleActive table The RGB color of the text when `state` is set to `active`. An array of 3 floats with values ranging from `0.0` to `1.0`.
--- @field idleDisabled table The RGB color of the text when `state` is set to `disabled`. An array of 3 floats with values ranging from `0.0` to `1.0`.
--- @field over table The RGB color of the text when the text select is selected and `state` is set to `normal`. An array of 3 floats with values ranging from `0.0` to `1.0`.
--- @field overActive table The RGB color of the text when the text select is selected and `state` is set to `active`. An array of 3 floats with values ranging from `0.0` to `1.0`.
--- @field overDisabled table The RGB color of the text when the text select is selected and `state` is set to `disabled`. An array of 3 floats with values ranging from `0.0` to `1.0`.
--- @field pressed table The RGB color of the text when the text select is pressed and `state` is set to `normal`. An array of 3 floats with values ranging from `0.0` to `1.0`.
--- @field pressedActive table The RGB color of the text when the text select is pressed and `state` is set to `active`. An array of 3 floats with values ranging from `0.0` to `1.0`.
--- @field pressedDisabled table The RGB color of the text when the text select is pressed and `state` is set to `disabled`. An array of 3 floats with values ranging from `0.0` to `1.0`.
--- @field state number The state of the text select. Controls which color set to use for text. Maps to values in [`tes3.uiState`](https://mwse.github.io/MWSE/references/ui-states/).
tes3uiTextSelect = {}

