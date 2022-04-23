--- @meta
--- @diagnostic disable:undefined-doc-name

--- A Timer is a class used to keep track of callback that should be invoked at a later time.
--- @class mwseTimer
--- @field callback function *Read-only*. The callback that will be invoked when the timer elapses.
--- @field data table|nil Arbitrary json-serializable data stored in the timer. This defaults to `nil`, but can be set at the time of timer creation, or changed later.
--- @field duration number *Read-only*. The amount of time left on the timer.
--- @field iterations number *Read-only*. The amount of iterations left for the timer.
--- @field state number *Read-only*. The state of the timer, matching `timer.active`, `timer.paused`, or `timer.expired`.
--- @field timeLeft number *Read-only*. The amount of time left before this timer will complete.
--- @field timing number *Read-only*. When this timer ends, or the time remaining if the timer is paused.
mwseTimer = {}

--- Cancels the timer.
function mwseTimer:cancel() end

--- Pauses the timer.
function mwseTimer:pause() end

--- Resets the timer completion time, as if it elapsed. Only works if the timer is active.
function mwseTimer:reset() end

--- Resumes a paused timer.
function mwseTimer:resume() end

