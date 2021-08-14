# calcRestInterrupt

This event is called when the player is about to start resting. The hour and count of creatures can be modified, or disabled. Blocking this event blocks any interrupting spawn.

```lua
--- @param e calcRestInterruptEventData
local function calcRestInterruptCallback(e)
end
event.register("calcRestInterrupt", calcRestInterruptCallback)
```

!!! tip
	This event supports blocking by setting `e.block` to `true` or returning `false`. Blocking the event prevents vanilla behavior from happening. For example, blocking an `equip` event prevents the item from being equipped.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `count` (number): The number of creatures interrupting rest. Set to 0 to prevent a spawn.
* `hour` (number): The hour of rest remaining that the rest will be interrupted on.
* `resting` (boolean): *Read-only*. If true, the player is attempting to rest, as opposed to wait.
* `waiting` (boolean): *Read-only*. If true, the player is attempting to wait, as opposed to rest.

