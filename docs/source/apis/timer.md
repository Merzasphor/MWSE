# timer

The timer library provides helper functions for creating delayed executors.

## Properties

### `timer.active`

Constant to represent a timer that is actively running.

***

### `timer.expired`

Constant to represent a timer that has completed.

***

### `timer.game`

Constant to represent timers that run based on in-world time. Duration measured in game-scale hours.

***

### `timer.paused`

Constant to represent a timer that is paused.

***

### `timer.real`

Constant to represent timers that run in real-time.

***

### `timer.simulate`

Constant to represent timers that run when the game isn't paused. It matches the simulate event's timing. If the game is simulating, simulate events and simulate timers progress. Duration is measured in seconds.

***

## Functions

### `timer.delayOneFrame`

Creates a timer that will finish the next frame. It defaults to the next simulation frame.

```lua
local timer = timer.delayOneFrame(callback, type)
```

**Parameters**:

* `callback` (function): The callback function that will execute when the timer expires.
* `type` (number): *Default*: `timer.simulate`. Type of the timer. This value can be timer.simulate, timer.game or timer.real.

**Returns**:

* `timer` ([mwseTimer](../../types/mwseTimer))

***

### `timer.start`

Creates a timer.

```lua
local timer = timer.start({ type = ..., duration = ..., callback = ..., iterations = ... })
```

**Parameters**:

* `params` (table)
	* `type` (number): *Default*: `timer.simulate`. Type of the timer. This value can be timer.simulate, timer.game or timer.real.
	* `duration` (number): Duration of the timer. The method of time passing depends on the timer type.
	* `callback` (function): The callback function that will execute when the timer expires.
	* `iterations` (number): *Default*: `1`. The number of iterations to run. Use `-1` for infinite looping.

**Returns**:

* `timer` ([mwseTimer](../../types/mwseTimer))

??? example "Example: Show a Countdown Message"

	```lua
	local timeLeft = 0;
	
	local function onTimerExpired() 
		timeLeft = timeLeft - 1;
		tes3.messageBox("%d seconds left", timeLeft);
	end
	
	local function onActivate(eventData)
		if (eventData.activator == tes3.player) then
			timeLeft = 10;
			timer.start{ duration = 1, iterations = 10, type = timer.simulate, callback = onTimerExpired }
		end
	end
	event.register("activate", onActivate)

	```

***

