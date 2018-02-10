
xGetLockLevel
========================================================

**Parameters:**

- **None**

**Returned:**

- ``short`` **lockLevel**: The reference's lock level, or -1 if none was found.

Returns the lock level of a door or container. This function returns -1 for doors/containers that have never been locked and for items that aren't doors or containers.

This returns the lock level regardless of whether the item is locked or unlocked. Use GetLocked to determine the state of the lock.

Lock level is stored as a signed short (16 bits, max value = 32,767). Values less than 0 do not survive saving, exiting, and reloading. They are converted to their absolute value and the door/container is flagged as unlocked.