--- @meta

--- The weatherTransitionStarted event occurs when the currently simulated weather has started to gradually transition to a new weather.
--- @class weatherTransitionStartedEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field from tes3weatherAsh|tes3weatherBlight|tes3weatherBlizzard|tes3weatherClear|tes3weatherCloudy|tes3weatherFoggy|tes3weatherOvercast|tes3weatherRain|tes3weatherSnow|tes3weatherThunder *Read-only*. The weather object that is the current weather.
--- @field to tes3weatherAsh|tes3weatherBlight|tes3weatherBlizzard|tes3weatherClear|tes3weatherCloudy|tes3weatherFoggy|tes3weatherOvercast|tes3weatherRain|tes3weatherSnow|tes3weatherThunder The weather object that will be transitioned to.
