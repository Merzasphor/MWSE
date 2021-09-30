# Patches

The following patches are included by MWSE.

## Features

- Allows Morrowind to run when not in focus.
- Allows NiFlipController to specify its affected map correctly.
- Allows NiLinesData to be loaded from meshes.
- Allows NiUVController to specify its texture correctly.
- Creates crash dump files and logging information to help diagnose mod issues.
- `Disable` mwscript function updates collision information so the player won't collide with invisible references.
- Improves load times when using Mod Organizer 2.
- Optimizes `DontThreadLoad` ini file access to not always fetch from the file system.
- Optimizes `ShowMap` and `FillMap` to not be absurdly slow.
- Optimizes access to global variables.
- Optimizes access to player kill count, via `GetDeadCount` or dialogue filtering.
- Raises mod limit from 256 to 1024.

## Bug Fixes

- Allows the game to correctly close when quit with a messagebox popup, preventing rogue Morrowind.exe processes from hanging in the background.
- Athletics and sneak skill progress code made consistent with other skill advancements. Useful to modders.
- Correctly initialize MobileProjectile tag/objectType. Useful to modders.
- `Enable` and `Disable` mwscript functions no longer can cause crashes with script variables unset.
- Fixes book and weapon enchantment copying. Useful to modders.
- Fixes crash when updating cell markers at the border of the drawable map area.
- Fixes crash with paper doll equipping/unequipping.
- Fixes crash with uncloned actors removing items.
- Fixes time being nudged forward by small extra increments when resting.
- Fixes time being truncated when advancing time past midnight.
- Fixes transparency effects from invisibility/chameleon from being desynced when changing equipment.
- Prevents empty menu positions from saving to the ini file.
- Updates animations for third person and first person player reference when idle mode is flagged.
