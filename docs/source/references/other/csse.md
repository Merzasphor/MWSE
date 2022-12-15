# Construction Set Extender

The Construction Set Extender, also known as CSSE, is a project that aims to improve the functionality of the TES Construction Set. This page serves to document the project.

To request a feature, visit the [Construction Set Extender Development issue](https://github.com/MWSE/MWSE/issues/397) on GitHub. Support for the project can be found in the #mwse channel in the [Morrowind Modding Community](https://discord.me/page/mwmods).

## Requirements

CSSE requires [MGE XE](https://www.nexusmods.com/morrowind/mods/41102?) v0.14.3 (released July 29, 2022) or later in order to be automatically loaded into the Construction Set.

If using OpenMW, you will still need to install MGE XE into your Morrowind installation directory (the same directory that you launch the Construction Set).

## Installation

You can obtain the CSSE using one of the following methods:

### MWSE-Updater

MGE XE includes the MWSE-Update program. This program will download the latest CSSE file (as well as the latest MWSE) into your Morrowind installation directory.

To get CSSE with this method, simply run the program and follow any prompts that may be displayed (such as closing the Construction Set). It may only open briefly, in which case you are likely already up-to-date. The updater won't download the file if you already have the latest version.

### Manually

The same download can be found on the [Automated Build release on GitHub](https://github.com/MWSE/MWSE/releases/tag/build-automatic). You can download the mwse.zip file, which contains both MWSE and CSSE.

Once you have the zip file downloaded, extract its contents to the Morrowind installation directory. Both CSSE.dll and TES Construction Set.exe must reside in the same directory.

If you are strictly an OpenMW user but also a TES Construction Set user, you need only extract the CSSE.dll file into your Morrowind directory. However, for testing in the vanilla engine you should still have the [Morrowind Code Patch](https://www.nexusmods.com/morrowind/mods/19510) and MWSE installed. MWSE offers various [patches and other features](https://mwse.github.io/MWSE/references/other/patches/) to help make the original engine faster and more stable, in the same way that CSSE does for the Construction Set.

## Compatibility

If you are using [Construction Set Better UI](https://www.nexusmods.com/morrowind/mods/50311), CSSE will not automatically load. To get CSSE to work with Better UI, you will need to rename the Better UI executable to "TES Construction Set" and replace the existing vanilla CS file. Be sure to back the original up first!

## Features

### General

* General optimizations to UI rendering. Status updates are throttled to only update once every 20ms, which drastically improves load times.
* The following warnings will no longer or only conditionally create popup windows, but will still be written to Warnings.txt:
	* "Following string is different for topic" and "Previous string is different for topic" are suppressed to Warnings.txt entirely.
	* The "1 duplicate references were removed" from loading Tribunal and Bloodmoon will no longer make a popup. If this is not the vanilla duplicate reference, or if there is more than one duplicate reference, a popup will still be shown.

### Object Window

* Significantly improved UI responsiveness.
* Added a footer to the window, with a new filter input. This input can be focused by using CTRL+F while the Object Window is active. This can be used to filter objects by a matching object ID fragment.

### Dialogue Window

* Optimized UI initialization. With TR, average dialogue load time decreased by about 60%. Displaying INFO details is a minimum twice as fast (which is still really slow for any INFO that has certain conditions).

### Render Window

* Reference rotation is now performed on the world axis, rather than the local axis. To rotate on the local axis as it worked in vanilla, hold the alt key.
* References can be group-scaled. By holding the alt key when scaling, all selected references will scale together and reposition accordingly.
* References can be moved onto surfaces. By holding the alt key when drag-moving a reference, it will rotate and snap onto the surface under the cursor.
* Extended editor marker support. Toggling markers (M) will now also toggle markers supported by the game executable. This allows custom markers to be toggled by tagging them with a MRK string and adding a EditorMarker node, or by defining objects whose name begins with or matches "Tri EditorMarker".

The following changes to the rendering window apply when landscape editing:

* The terrain editing disc is no longer hidden when hiding objects (Shift+C).
* You can use the P key to sample the texture at the cursor's position. This will select the matching texture under the cursor automatically in the landscape editing menu.

### Cell View

* Significantly improved UI responsiveness.


## Bug Fixes

* Fixed GMST pollution bug caused when not loading Tribunal and Bloodmoon.
