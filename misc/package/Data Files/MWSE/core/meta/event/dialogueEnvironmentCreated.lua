--- @meta
--- @diagnostic disable:undefined-doc-name

--- This event is fired when a dialogue with lua scripting is about to be executed. It allows third party code to inject themselves into the dialogue environment, so new functionality can be added more easily for dialogue scripters.
--- @class dialogueEnvironmentCreatedEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field environment table *Read-only*. The lua environment for the dialogue scripting. Any data added to it will be available as global variables to dialogue scripts.
