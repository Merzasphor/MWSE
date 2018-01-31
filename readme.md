# Morrowind Script Extender v2

Visit the documentation over at [mwse.readthedocs.io](https://mwse.readthedocs.io/en/latest/).

## Synopsis

The Morrowind Script Extender makes additional functions available for use in Morrowind scripts, beyond those provided by the game's construction set. 

These extra functions allow modders to add features and behavior to scripts that would otherwise be impractical or impossible.

For a list of MWSE functions, see the [function list](https://mwse.readthedocs.io/en/latest/mwscript/functions.html). For a list of recent releases, see the [changelog](https://mwse.readthedocs.io/en/latest/changelog.html). Some functions require special values, which can be found in the [references](https://mwse.readthedocs.io/en/latest/mwscript/references.html).

## Installation

* Download the latest MWSE release from [GitHub](https://github.com/MWSE/MWSE/releases) and unpack to a temporary directory.
* If you use MGE XE 0.10.0 beta 9 or later:
	* (Optional) Backup `MWSE.dll` in your Morrowind directory.
	* Copy `MWSE.dll` from the archive in step 1 to your Morrowind directory.
	* You can now start Morrowind as before. MGE XE will load the updated `MWSE.dll` on startup.
* If you do not use MGE XE:
	* (Optional) If they exist, backup the following files in your Morrowind directory: `MWSE.dll`, `MWSE Launcher.exe`.
	* Copy `MWSE.dll` and `MWSE Launcher.exe` from the archive in step 1 to your Morrowind directory.
	* To run Morrowind with MWSE enabled, run `MWSE Launcher.exe` and click "Launch Morrowind".
* (Optional) MWEdit
	* (Optional) Backup `customfunctions.dat` in your MWEdit directory.
	* Copy `customfunctions.dat` from the archive in step 1 to your MWEdit directory.
	* MWEdit will now be able to compile scripts that contain MWSE functions.

The [Morrowind Code Patch](https://www.nexusmods.com/morrowind/mods/19510/) is highly recommended.

## License
The Morrowind Script Extender is free software, licensed according to the GNU General Public License, and comes with ABSOLUTELY NO WARRANTY. See the file LICENSE.TXT for details if you are interested in distributing or modifying the program.
