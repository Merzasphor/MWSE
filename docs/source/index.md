# About

The Morrowind Script Extender makes additional functions available for use in Morrowind scripts, beyond those provided by the game's construction set.

These extra functions allow modders to add features and behavior to scripts that would otherwise be impractical or impossible.

!!! info "Morrowind Modding Community Discord"
	If you are looking for MWSE scripting advice or discussions, try the [Morrowind Modding Community Discord](https://discord.gg/QDEBbaP).

## Installation

- Install the [Visual Studio x86 2022 Redistributable](https://aka.ms/vs/17/release/vc_redist.x86.exe) is required for MWSE. Note that you will need the x86 version, even if you already have the x64 redistributable installed.
- Install the [Morrowind Code Patch](https://www.nexusmods.com/morrowind/mods/19510/) modifies the game executable, and MWSE assumes you have at least the base patches performed for its own modifications.
- Install the [Morrowind Graphic Extender XE](https://www.nexusmods.com/morrowind/mods/41102) (MGE XE) allows MWSE to be loaded.
- Run MWSE-Update.exe in your Morrowind install folder. This was downloaded and installed as part of MGE XE's installation.


## Contributing

The Morrowind Script Extender is open source software that welcomes contributions in the forms of ideas, bug fixes, documentation, and new features. There is a separate guide for documentation contributions found [here](https://github.com/MWSE/MWSE/tree/docs-contributions-guide/docs).

### Requirements

#### Visual Studio

Contributing to MWSE requires a copy of [Visual Studio 2022](https://www.visualstudio.com/downloads/), with the following features enabled:

- Workloads:
	- Desktop development with C++

#### LuaJIT

[LuaJIT](https://luajit.org/) needs to be compiled once, and is included in the project. To compile, use **Tools > Visual Studio Command Prompt** and run the following:

```bat
cd deps\LuaJIT\src
msvcbuild.bat
```


### GitHub

Code contributions are managed via [GitHub](https://github.com/MWSE/MWSE).


### Discord

Communication of features, designs, and requests are handled on Discord. See the #mwse channel in the [Morrowind Modding Community Discord](https://discord.gg/QDEBbaP).


## Authors

The following individuals have contributed to the Morrowind Script Extender.

- Anthony Garcia
- [C3pa](https://github.com/C3pa)
- Charles Cooley (cdcooley)
- Cody Erekson (Fliggerty)
- FreshFish
- Grant McDorman
- [Greatness7](https://github.com/Greatness7)
- [Hrnchamd](https://github.com/Hrnchamd)
- [Merzasphor](https://github.com/Merzasphor)
- [Michael Wallar (NullCascade)](https://github.com/NullCascade)
- [OperatorJack](https://github.com/OperatorJack)
- [Pete Goodfellow (Petethegoat)](https://github.com/Petethegoat)
- [Sebastien Levy (MetaBarj0)](https://github.com/MetaBarj0)
- Tim Peters
- Timeslip
