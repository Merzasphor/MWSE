# timer.frame

Convenience access to frame timer functions. This is the same as passing `type = timer.real` to any of the functions from timer API.

## Functions

### `timer.frame.delayOneFrame`

Creates a timer that will finish the next frame.

```lua
local timer = timer.frame.delayOneFrame(callback)
```

**Parameters**:

* `callback` (function): The callback function that will execute when the timer expires.

**Returns**:

* `timer` ([mwseTimer](../../types/mwseTimer))

***

