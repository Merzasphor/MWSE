
xSetTrap
========================================================

**Parameters:**

- ``string`` **spellID** : The spell ID to set as the trap, or ``0`` to unset a trap.

**Returned:**

- ``short`` **result**: ``1`` if the reference's trap was modified, otherwise ``0``.

Sets a trap. Only works on containers or doors. In order to have a trap, a reference must also have a lock. For references without locks, call ``Lock 0`` and ``Unlock`` prior to ``xSetTrap``.

Traps that are set this way do not persist through saving and loading. If a trap is removed its removal persists only if the object is activated or its lock is manipulated before saving.

If you want to set a trap on a door/container, first check for an existing lock (``xGetLockLevel``). If no lock is already installed, use ``Lock 0``, ``Unlock`` to create the lock/trap record. Set the trap. To make sure the trap is persistent, manipulate the lock, but then put it back to its original state. In other words, if the lock is currently unlocked, lock it (use ``xGetLockLevel`` to determine the correct lock level) then unlock it. Do the reverse if it's currently unlocked.

.. tip:: Use `xGetTrap`_ to read this value.

.. _`xGetTrap`: xGetTrap.html