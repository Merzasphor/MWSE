# dialogueEnvironmentCreated

This event is fired when a dialogue with lua scripting is about to be executed. It allows third party code to inject themselves into the dialogue environment, so new functionality can be added more easily for dialogue scripters.

```lua
--- @param e dialogueEnvironmentCreatedEventData
local function dialogueEnvironmentCreatedCallback(e)
end
event.register(tes3.event.dialogueEnvironmentCreated, dialogueEnvironmentCreatedCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `environment` (table): *Read-only*. The lua environment for the dialogue scripting. Any data added to it will be available as global variables to dialogue scripts.

