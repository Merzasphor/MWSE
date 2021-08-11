# lfsLock

An object that represents a file lock.

## Methods

### `free`

Frees the lock, so that another lock can be made. Deletes the associated lock file.

```lua
lfsLock:free()
```

***

