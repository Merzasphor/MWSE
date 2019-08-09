========================================================
Development Workflows
========================================================

This guide will demonstrate some different development workflows for developing mods for *The Elder Scrolls III: Morrowind* using MWSE 2.1 Lua.

A Development Workflow is the environment and processes used to facilitate software development. There are many ways that you can develop MWSE-Lua mods. This guide offers a few possible ways. However, you can develop in whatever environment is most comfortable to you.

.. warning:: Be careful if using a standard text editor. More advanced code editing tools provide syntax highlighting, which can help to reduce errors in your code. 

Simple Development Workflow
--------------------------------------------------------
To setup this environment, do the following:

1. Create a clean Morrowind install, Morrowind-Dev.
2. In the *Morrowind\Data Files\MWSE* directory, develop your mod.

To use this environment to develop mods while maintaining a clean install, you can do the following:

1. Make changes as needed to your code.
2. Start Morrowind and complete testing as needed.
3. Close Morrowind.

This workflow has some drawbacks. If you develop your mods directly in your Morrowind-Dev install, you have to be aware of other mod installations to prevent conflicts during testing.

Advanced Development Workflow
--------------------------------------------------------
Please note that the workflow described below is the preferred environment of the author. Please, feel free to choose to use other code editors, text editors, mod management tools, or extensions as you see fit.

A more advanced development environment consists of the following software applications:

- A clean Morrowind install, hereafter referred to as the Morrowind-Dev install.
- A `Wrye Mash`_ install linked to the Mororwind-Dev install.
- `Visual Studio Code`_ with the Lua AutoComplete extension installed.
- A current set of MWSE LuaCoderAssist AutoComplete files. These can be downloaded from the `Morrowind Modding Discord`_ MWSE channel.

To setup this environment, do the following:

1. Create a clean Morrowind install, Morrowind-Dev.
2. Install Wrye Mash
3. Configure Wrye Mash to use your Morrowind-Dev install as the Morrowind directory.
4. Configure Wrye Mash to use your development folder as the Mod directory. This can be any location on your computer where you want to store your development files.
5. Install Visual Studio Code.
6. Install the LuaCoderAssist extension in Visual Studio Code.
7. In Visual Studio Code, open the Mod directory from step 4 as a work space. 
8. Place the MWSE Lua AutoComplete files in this directory.

To use this environment to develop mods while maintaining a clean install, you can do the following:

1. Make changes as needed to your code.
2. Open Wrye Mash.
3. If you created or deleted files as part of your code changes, use Wrye Mash's 'Refresh Data' tool to reload the install files for your mod.
4. Install your updated mod using Wrye Mash.
5. Start Morrowind and complete testing as needed.
6. Close Morrowind.
7. Uninstall your updated mod using Wrye Mash.

This workflow ensures that you maintain a clean Morrowind-Dev install, do not have mod conflicts during testing, and are always testing with the most up-to-date files.

.. _`Wrye Mash`: https://www.nexusmods.com/morrowind/mods/45439
.. _`Visual Studio Code`: https://code.visualstudio.com
.. _`Morrowind Modding Discord`: https://discordapp.com/invite/QDEBbaP