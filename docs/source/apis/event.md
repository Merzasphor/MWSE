# event

The event library helps to instruct mwse to call a given function when a specific action is taken in the game.

## Functions

### `event.clear`

Removes all callbacks registered for a given event.

```lua
event.clear(eventId, options)
```

**Parameters**:

* `eventId` (string)
* `options` (table): *Optional*.

***

### `event.register`

Registers a function to be called when an event is raised.

```lua
event.register(eventId, callback, options)
```

**Parameters**:

* `eventId` (string)
* `callback` (function)
* `options` (table): *Optional*.

***

### `event.trigger`

Triggers an event. This can be used to trigger custom events with specific data.

```lua
event.trigger(eventId, payload, options)
```

**Parameters**:

* `eventId` (string)
* `payload` (table): *Optional*.
* `options` (table): *Optional*.

***

### `event.unregister`

Unregisters a function previously registered for an event with `event.register()`.

```lua
event.unregister(eventId, callback, options)
```

**Parameters**:

* `eventId` (string)
* `callback` (function)
* `options` (table): *Optional*.

***

