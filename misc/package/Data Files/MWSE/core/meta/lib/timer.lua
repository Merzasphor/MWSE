--- @meta

--- The timer library provides helper functions for creating delayed executors.
--- @class timerlib
--- @field active any Constant to represent a timer that is actively running.
--- @field expired any Constant to represent a timer that has completed.
--- @field game any Constant to represent timers that run based on in-world time. Duration measured in game-scale hours.
--- @field paused any Constant to represent a timer that is paused.
--- @field real any Constant to represent timers that run in real-time.
--- @field simulate any Constant to represent timers that run when the game isn't paused. It matches the `simulate` event's timing. If the game is simulating, simulate events and simulate timers progress. Duration is measured in seconds.
timer = {}

--- Creates a timer that will finish the next frame. It defaults to the next simulation frame.
--- @param callback function The callback function that will execute when the timer expires.
--- @param type number *Default*: ``timer.simulate``. Type of the timer. This value can be `timer.simulate`, `timer.game` or `timer.real`.
--- @return mwseTimer timer No description yet available.
function timer.delayOneFrame(callback, type) end

--- Registers a named timer with a callback to persist between game sessions. Bear in mind that nothing in MWSE is sandboxed, so all the registered timers are in the global namespace. Consider prefixing your timer with mod name or something else to avoid name collisions. For instance, `iceCreamMod:myTimer`.
---
--- [Examples available in online documentation](https://mwse.github.io/MWSE/types/timer/#timerregister).
--- @param name string Name of the registered timer.
--- @param fn function A callback function for the timer.
function timer.register(name, fn) end

--- Creates a timer.
---
--- [Examples available in online documentation](https://mwse.github.io/MWSE/types/timer/#timerstart).
--- @param params timer.start.params This table accepts the following values:
--- 
--- `type`: number — *Default*: ``timer.simulate``. Type of the timer. This value can be `timer.simulate`, `timer.game` or `timer.real`.
--- 
--- `duration`: number — Duration of the timer. The method of time passing depends on the timer type.
--- 
--- `callback`: function — The callback function that will execute when the timer expires.
--- 
--- `iterations`: number — *Default*: `1`. The number of iterations to run. Use `-1` for infinite looping.
--- 
--- `persist`: boolean — *Default*: `true`. Registering a timer with persist flag set to `true` will serialize the callback string in the save to persist between sessions. Only a registered timer will persist between sessions. See `timer.register()`.
--- @return mwseTimer timer No description yet available.
function timer.start(params) end

---Table parameter definitions for `timer.start`.
--- @class timer.start.params
--- @field type number *Default*: ``timer.simulate``. Type of the timer. This value can be `timer.simulate`, `timer.game` or `timer.real`.
--- @field duration number Duration of the timer. The method of time passing depends on the timer type.
--- @field callback function The callback function that will execute when the timer expires.
--- @field iterations number *Default*: `1`. The number of iterations to run. Use `-1` for infinite looping.
--- @field persist boolean *Default*: `true`. Registering a timer with persist flag set to `true` will serialize the callback string in the save to persist between sessions. Only a registered timer will persist between sessions. See `timer.register()`.

