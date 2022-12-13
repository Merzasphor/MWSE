# Construction Set Extender

## Installation

Currently, the Construction Set Extender is only available from the #mwse channel in the [Morrowind Modding Community](https://discord.me/page/mwmods) discord. Check the latest pinned CSSE post there.

Once you have downloaded the .7z file, extract it to the Morrowind installation directory (to be in the same folder as TES Construction Set.exe).

CSSE requires [MGE XE](https://www.nexusmods.com/morrowind/mods/41102?) v0.14.3 (released July 29, 2022) or later to be automatically loaded into the Construction Set.


## Features

### General

* General optimizations to UI rendering. Status updates are throttled to only update once every 20ms, which drastically improves load times.
* The following warnings will no longer or only conditionally create popup windows, but will still be written to Warnings.txt:
	* "Following string is different for topic" and "Previous string is different for topic" are suppressed to Warnings.txt entirely.
	* The "1 duplicate references were removed" from loading Tribunal and Bloodmoon will no longer make a popup. If this is not the vanilla duplicate reference, or if there is more than one duplicate reference, a popup will still be shown.

### Object Window

* Significantly improved UI responsiveness.
* Added a footer to the window, with a new filter input. This input can be focused by using CTRL+F while the Object Window is active. This can be used to filter objects by a matching object ID fragment.

### Render Window

* Reference rotation is now performed on the world axis, rather than the local axis. To rotate on the local axis as it worked in vanilla, hold the alt key.
* Extended editor marker support. Toggling markers (M) will now also toggle markers supported by the game executable. This allows custom markers to be toggled by tagging them with a MRK string and adding a EditorMarker node, or by defining objects whose name begins with or matches "Tri EditorMarker".
* The landscape editing disc is no longer hidden when hiding objects (Shift+C).
* While landscape editing is enabled, and the render window selected, you can use the P key to sample the texture at the cursor's position. This will select the matching texture under the cursor automatically in the landscape editing menu.

### Cell View

* Significantly improved UI responsiveness.


## Bug Fixes

* Fixed GMST pollution bug caused when not loading Tribunal and Bloodmoon.
