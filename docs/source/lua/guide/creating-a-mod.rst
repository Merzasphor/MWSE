========================================================
Creating A Mod
========================================================

This guide will demonstrate the most basic steps of creating a mod for *The Elder Scrolls III: Morrowind* using MWSE 2.1 Lua.

To facilitate this, this guide will explain how to create a mod that displays a unique messagebox every time the player draws a two-handed weapon.

This guide assumes that you have a basic understanding of the Lua Scripting Language, event based programming, and have at least minimal general programming and Visual Studio Code experience.

Simple Development Workflow
--------------------------------------------------------
A Development Workflow is the environment and processes used to facilitate software development. There are many ways that you can develop MWSE-Lua mods. This guide offers one possible way. For the purposes of this guide, this guide will assume that you are using the Development Workflow described here.

A simple development environment consists of the following software applications:

- A clean Morrowind install, hereafter referred to as the Morrowind-Dev install.
- A `Wrye Mash`_ install linked to the Mororwind-Dev install.
- `Visual Studio Code`_ with the Lua AutoComplete extension installed.
- A current set of MWSE Lua AutoComplete files. These can be downloaded from the `Morrowind Modding Discord`_ MWSE channel.

To setup this environment, do the following:

1. Create a clean Morrowind install, Morrowind-Dev.
2. Install Wrye Mash
3. Configure Wrye Mash to use your Morrowind-Dev install as the Morrowind directory.
4. Configure Wrye Mash to use your development folder as the Mod directory. This can be any location on your computer where you want to store your development files.
5. Install Visual Studio Code.
6. Install the Lua AutoComplete extension in Visual Studio Code.
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

Creating the Mod File Structure
--------------------------------------------------------
Now that you have setup a development workflow, you are ready to create a mod. 

In Visual Studio Code, in your Mod directory work space, create a new folder. Name the folder whatever display name you want to use for your mod. For this guide, we will name the folder "MWSE Guide Demo".

This folder will contain all of the mod files needed to run the mod. 

Next, the folder structure for MWSE must be created:

- In "MWSE Guide Demo", create a folder named "MWSE". This is the folder that contains any MWSE code.
- In "MWSE", create a folder named "mods". This is the folder that contains any MWSE mod code. Other options are "core", for the MWSE framework files, and "lib" for user-made frameworks and libraries.
- In "mods", create a folder names "MWSE-Guide-Demo". This is the folder that contains the MWSE code for our mod. This folder can include spaces in the folder name. In a normal Morrowind install, you may see other folders here. These represent other mod's code files.

The newly created folder structure should look like this:

- MWSE Guide Demo
    - MWSE
        - mods
            - MWSE-Guide-Demo

Now that the folder structure is complete, you must create a code file to run your code in. 
- In "mods", create a file named *main.lua*. This file will contain the Lua code for the mod. 

Generally, the main file of your mod should be named *main.lua*. This file should configure and initialize any other code files in your mod. The name *main.lua* is not required, but it is convention.


Registering an Event
--------------------------------------------------------
The Morrowind game engine, through MWSE, provides a variety of *events* that can be used to trigger code. An *event* is a trigger that will notify any registered functions of it's occurrence. 

For example, consider the `loaded` event. This event is triggered whenever the player loads a save game. If you register a function to be called when this event occurs, your function will be called when the player loads a save game. By cleverly using Morrowind's events, powerful functionality can be created.

In our file, *main.lua*, we will register an event to trigger our code. It is convention to register your mod's events inside of another event, the `initialized` event. The `initialized` event represents the point when the game and it's mods have been loaded. You can imagine this as the point which the title screen is first shown.

So, first, we will create the `initialized` event.

.. code-block:: lua
   :linenos:

    -- The function to call on the initialized event.
    local function initialized() -- 1.
    
        -- Print a "Ready!" statement to the MWSE.log file.
        print("[MWSE Guide Demo: INFO] MWSE Guide Demo Initialized") --2.
    end
    
    -- Register our initialized function to the initialized event.
    event.register("initialized", initialized) --3.

1. Declare a function to call whenever the `initialized` event is triggered.
2. It is convention to print a statement stating your mod is initialized at the end of your initialized event function. This is used for debugging.
3. Register our `initialized` function to the `initialized` event.

Now, we want to register an event for what we are actually interested in. In this guide, we are creating a mod that displays a unique messagebox every time the player draws a two-handed weapon. There is an event for that! It is called the `weaponReadied` event.

.. code-block:: lua
   :linenos:

    -- The function to call on the showMessageboxOnWeaponReadied event.
    local function showMessageboxOnWeaponReadied(e) -- 1.
        tes3.messageBox("I just drew some weapon.") -- 2.
    end
    
    -- The function to call on the initialized event.
    local function initialized()
        -- Register our function to the onReadied event.
        event.register("weaponReadied", showMessageboxOnWeaponReadied) --3.
    
        -- Print a "Ready!" statement to the MWSE.log file.
        print("[MWSE Guide Demo: INFO] MWSE Guide Demo Initialized")
    end
    
    -- Register our initialized function to the initialized event.
    event.register("initialized", initialized)

1. Declare a function to call whenever the `weaponReadied` event is triggered.
2. Add a simple messagebox command.
3. Register our `showMessageboxOnWeaponReadied` function to the `weaponReadied` event.

.. warning:: Be careful when registering events outside of the initialized event. It is possible to access data that is unavailable in a given event, causing bugs or a crash-to-desktop.

At this point, the mod can be tested to confirm the events are set up correctly. To do this, follow the workflow described at the beginning of this guide. When you draw your weapon in-game, you should see a messagebox popup!

The details of which events are available and what event data is exposed to them can be found on the `events`_ page.

Validating the Event & Showing a Messagebox
--------------------------------------------------------
Now that the required events have been set up, the `showMessageboxOnWeaponReadied` function should be updated to restrict the types of actions that our code applies to. For the purposes of this guide, the function will only apply to two-handed weapons, and only to the player. The updated function is as follows:

.. code-block:: lua
   :linenos:

    -- The function to call on the showMessageboxOnWeaponReadied event.
    local function showMessageboxOnWeaponReadied(e)
        -- Exit the function is the actor is not the player.
        if (e.reference ~= tes3.player) then --1.
            return
        end
    
        -- Locally store the weapon reference being readied in the event.
        local weaponStack = e.weaponStack --2.
    
        -- Check that the reference exists and the reference object is a two-handed weapon.
        if (weaponStack and weaponStack.object.isTwoHanded) then --3.
            -- Print our statement.
            tes3.messageBox("I just drew " .. weaponStack.object.name .. ", destroyer of worlds!") --4.
        end
    end

1. We must check that the event was triggered by the player. Without this step, the code would be executed for all actors, including NPCs and creatures! `e.reference` is an property of the `weaponedReadied` event. `tes3.player` is an easy way to access the player reference.
2. Store a copy of the weaponStack reference in a local variable to prevent typing `e.weaponStack` more than once. 
3. The first part of this if condition checks that the reference exists. This should be done to prevent null reference exceptions. The second part of this if condition performs our validation: it ensures that the weapon being readied is a two-handed weapon.
4. Show a messagebox with some custom object information. `.name` is available on any object.

The mod should be tested again, using the workflow described at the beginning of this guide. When drawing a two-handed weapon, you should now see a custom messagebox!

Conclusion
--------------------------------------------------------
This guide provided a simple introduction to modding *The Elder Scrolls III: Morrowind* using MWSE 2.1 Lua. 

This guide:
- explained how to set up a simple development environment and showed one possible workflow to use that environment.
- explained the required folder structure to create a MWSE-Lua mod.
- explained the basics of event registration and callbacks.
- explained how to implement some basic logic in an event callback.

At this point, you should look at the MWSE ReadTheDocs for additional information on the MWSE-Lua API. Documentation is constantly being improved upon, so ask a question in the Morrowind Modding Community Discord if you need help.

Here is the final code in *main.lua* for the demo mod:

.. code-block:: lua
   :linenos:

    -- The function to call on the showMessageboxOnWeaponReadied event.
    local function showMessageboxOnWeaponReadied(e)
        -- Exit the function is the actor is not the player.
        if (e.reference ~= tes3.player) then
            return
        end
    
        -- Locally store the weapon reference being readied in the event.
        local weaponStack = e.weaponStack
    
        -- Check that the reference exists and the reference object is a two-handed weapon.
        if (weaponStack and weaponStack.object.isTwoHanded) then
            -- Print our statement.
            tes3.messageBox("I just drew " .. weaponStack.object.name .. ", destroyer of worlds!")
        end
    end
    
    -- The function to call on the initialized event.
    local function initialized()
        -- Register our function to the onReadied event.
        event.register("weaponReadied", showMessageboxOnWeaponReadied)
    
        -- Print a "Ready!" statement to the MWSE.log file.
        print("[MWSE Guide Demo: INFO] MWSE Guide Demo Initialized")
    end
    
    -- Register our initialized function to the initialized event.
    event.register("initialized", initialized)




.. _`Wrye Mash`: https://www.nexusmods.com/morrowind/mods/45439
.. _`Visual Studio Code`: https://code.visualstudio.com
.. _`Morrowind Modding Discord`: https://discordapp.com/invite/QDEBbaP
.. _`events`: ../events.html
