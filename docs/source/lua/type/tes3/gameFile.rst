
Game File
========================================================

This interface represents a master, plugin, or savegame.


Properties
--------------------------------------------------------

**filename** (`string`_, read-only)
    The filename, including extension.

**path** (`string`_, read-only)
    Path to the file.

**author** (`string`_, read-only)
    The author of a plugin.

**description** (`string`_, read-only)
    The description text of a plugin, or the title of the savegame.

**currentHealth** (`number`_, read-only)
    Savegame only. Current health at the time of saving.

**maxHealth** (`number`_, read-only)
    Savegame only. Maximum health at the time of saving.

**gameHour** (`number`_, read-only)
    Savegame only. Value of GameHour global variable at the time of saving.
    
**day** (`number`_, read-only)
    Savegame only. Value of Day global variable at the time of saving.
    
**month** (`number`_, read-only)
    Savegame only. Value of Month global variable at the time of saving.
    
**year** (`number`_, read-only)
    Savegame only. Value of Year global variable at the time of saving.
    
**cellName** (`string`_, read-only)
    Starting cell.

**daysPassed** (`number`_, read-only)
    Savegame only. Value of DaysPassed global variable at the time of saving.
    
**playerName** (`string`_, read-only)
    Savegame only. Player name.
    
**fileSize** (`number`_, read-only)
    File size.

**modifiedTime** (`number`_, read-only)
    Modified time, in Windows FILETIME format.

**masters** (`table`_, read-only)
    A list of GameFiles that are the master, plugin, or savegame's masters. The table order is the same as the load order.


--------------------------------------------------------

.. _`number`: ../lua/number.html
.. _`string`: ../lua/string.html
.. _`table`: ../lua/table.html
