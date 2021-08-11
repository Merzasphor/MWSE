# calcRestInterrupt

This event is called when the player is about to start resting. The hour and count of creatures can be modified, or disabled. Blocking this event blocks any interrupting spawn.

```lua
--- @type e event.calcRestInterrupt
local function calcRestInterruptCallback(e)
end
event.register("calcRestInterrupt", calcRestInterruptCallback)
```

## Event Data

* `waiting` (boolean): If true, the player is attempting to wait, as opposed to rest.
* `count` (number): The number of creatures interrupting rest. Set to 0 to prevent a spawn.
* `resting` (boolean): If true, the player is attempting to rest, as opposed to wait.
* `hour` (number): The hour of rest remaining that the rest will be interrupted on.

