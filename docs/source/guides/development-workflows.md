
# Development Workflows

This guide will demonstrate how to set up your workflow for modding *The Elder Scrolls III: Morrowind* using MWSE-Lua.

A development workflow is the environment and processes used to facilitate software development. There are many ways that you can develop MWSE-Lua mods. This guide will show you how to to use [Visual Studio Code](https://code.visualstudio.com) to get syntax highlighting, autocompletion, and doc integration. It will also show you how to use a simple install, Wrye Mash, or Mod Organizer 2 to work on your mods.

!!! summary 
	Want to simply get to work? Open the `Data Files\MWSE` folder in [Visual Studio Code](https://code.visualstudio.com). Install the recommended plugins MWSE suggests in that workspace. You're good to go.

## Requirements

All workflows require an installation of [Visual Studio Code](https://code.visualstudio.com). After it is installed, we will also need some Lua-focused extensions. You will also need to make sure that MWSE is up to date. [Install](../#installation) MWSE and run MWSE-Update.

The simplest way to install these extensions is to open the `Data Files\MWSE` folder in Visual Studio Code using `File > Open Folder`. A prompt should show up to install a few extensions.

Other editors can be used if desired, but little support will be offered. All MWSE-Lua content is in simple text files, and any text editor can be used. However, MWSE has only generated meta files for autocompletion with the suggested Visual Studio Code extension in mind.


## Workflows

### Simple

The simplest workflow is already complete for you. There's nothing extra to download, simple open 

!!! note
	This workflow has some drawbacks. If you develop your mods directly in your Morrowind-Dev install, you have to be aware of other mod installations to prevent conflicts during testing.


### Wrye Mash

A advanced development environment uses [Wrye Mash](https://www.nexusmods.com/morrowind/mods/45439) to manage your mod.

To setup this environment, do the following:

1. Create a clean Morrowind install, Morrowind-Dev.
1. Install MWSE and all its requirements. Be sure to run `MWSE-Update.exe` to get the latest version.
1. Install [Wrye Mash](https://www.nexusmods.com/morrowind/mods/45439).
1. Configure [Wrye Mash](https://www.nexusmods.com/morrowind/mods/45439) to use your Morrowind-Dev install as the Morrowind directory.
1. Configure [Wrye Mash](https://www.nexusmods.com/morrowind/mods/45439) to use your development folder as the mod directory. This can be any location on your computer where you want to store your development files.
1. Open the `Data Files\MWSE` folder in [Visual Studio Code](https://code.visualstudio.com).

To use this environment to develop mods while maintaining a clean install, you can do the following:

1. Make changes as needed to your code.
1. Open Wrye Mash.
1. If you created or deleted files as part of your code changes, use Wrye Mash's *Refresh Data* tool to reload the install files for your mod.
1. Install your updated mod using Wrye Mash.
1. Start Morrowind and complete testing as needed.
1. Close Morrowind.
1. Uninstall your updated mod using Wrye Mash.

This workflow ensures that you maintain a clean Morrowind-Dev install, do not have mod conflicts during testing, and are always testing with the most up-to-date files.


## Other Recommendations

### Lua Formatting Configuration

One of the recommended plugins ([vscode-lua-format](https://github.com/Koihik/vscode-lua-format)) allows the formatting of lua code. Some bits of this may want to be customized. To do so, create a `Data Files\MWSE\.lua-format` file. Information on the style options can be found [here](https://github.com/Koihik/LuaFormatter/blob/master/docs/Style-Config.md).

Below are some preferred formatting config files for developers.

??? example "NullCascade's Styling"
	```
	column_limit: 120
	indent_width: 1
	use_tab: true
	tab_width: 4
	continuation_indent_width: 0
	spaces_before_call: 1
	keep_simple_control_block_one_line: false
	keep_simple_function_one_line: false
	align_args: true
	break_after_functioncall_lp: false
	break_before_functioncall_rp: false
	spaces_inside_functioncall_parens: false
	spaces_inside_functiondef_parens: false
	align_parameter: true
	chop_down_parameter: false
	break_after_functiondef_lp: false
	break_before_functiondef_rp: false
	align_table_field: true
	break_after_table_lb: true
	break_before_table_rb: true
	chop_down_table: true
	chop_down_kv_table: true
	table_sep: ","
	column_table_limit: 120
	extra_sep_at_table_end: true
	spaces_inside_table_braces: true
	break_after_operator: true
	double_quote_to_single_quote: false
	single_quote_to_double_quote: false
	spaces_around_equals_in_field: true
	line_breaks_after_function_body: 1
	line_separator: input
	```
