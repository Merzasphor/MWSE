
xGetRef
========================================================

**Parameters:**

- ``long`` **objectID**: An object ID to get a reference to, or ``0`` to get the script caller's reference.

**Returned:**

- ``long`` **reference**: The reference requested, or ``0`` if none were found.

Returns a reference to one of the active objects that match the object ID. An active object is an object in one of the loaded cells, or a persistent object such as an NPC.