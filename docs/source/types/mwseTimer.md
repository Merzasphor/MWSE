# mwseTimer

A Timer is a class used to keep track of callback that should be invoked at a later time.

## Properties

### `callback`

The callback that will be invoked when the timer elapses.

**Returns**:

* `result` (function)

***

### `duration`

The amount of time left on the timer.

**Returns**:

* `result` (number)

***

### `iterations`

The amount of iterations left for the timer.

**Returns**:

* `result` (number)

***

### `state`

The state of the timer, matching `timer.active`, `timer.paused`, or `timer.expired`.

**Returns**:

* `result` (number)

***

### `timeLeft`

The amount of time left before this timer will complete.

**Returns**:

* `result` (number)

***

### `timing`

When this timer ends, or the time remaining if the timer is paused.

**Returns**:

* `result` (number)

***

## Methods

### `cancel`

Cancels the timer.

```lua
mwseTimer:cancel()
```

***

### `pause`

Pauses the timer.

```lua
mwseTimer:pause()
```

***

### `reset`

Resets the timer completion time, as if it elapsed. Only works if the timer is active.

```lua
mwseTimer:reset()
```

***

### `resume`

Resumes a paused timer.

```lua
mwseTimer:resume()
```

***

