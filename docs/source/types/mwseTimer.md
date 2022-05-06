# mwseTimer

A Timer is a class used to keep track of callback that should be invoked at a later time.

## Properties

### `callback`

*Read-only*. The callback that will be invoked when the timer elapses.

**Returns**:

* `result` (function)

***

### `data`

Arbitrary json-serializable data stored in the timer. This defaults to `nil`, but can be set at the time of timer creation, or changed later.

**Returns**:

* `result` (table, nil)

***

### `duration`

*Read-only*. The amount of time left on the timer.

**Returns**:

* `result` (number)

***

### `iterations`

*Read-only*. The amount of iterations left for the timer.

**Returns**:

* `result` (number)

***

### `state`

*Read-only*. The state of the timer, matching `timer.active`, `timer.paused`, or `timer.expired`.

**Returns**:

* `result` (number)

***

### `timeLeft`

*Read-only*. The amount of time left before this timer will complete.

**Returns**:

* `result` (number)

***

### `timing`

*Read-only*. When this timer ends, or the time remaining if the timer is paused.

**Returns**:

* `result` (number)

***

## Methods

### `cancel`

Cancels the timer.

```lua
myObject:cancel()
```

***

### `pause`

Pauses the timer.

```lua
myObject:pause()
```

***

### `reset`

Resets the timer completion time, as if it elapsed. Only works if the timer is active.

```lua
myObject:reset()
```

***

### `resume`

Resumes a paused timer.

```lua
myObject:resume()
```

***

