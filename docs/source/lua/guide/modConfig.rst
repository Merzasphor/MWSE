
Mod Configuration Menu
====================================================================================================

Starting with MWSE 2.1, mods can create new GUIs. One GUI that that MWSE ships with is the Mod Configuration menu. By registering into this system, mods can create settings pages for their mods in a place where users can easily find and manipulate them.


Creating a Config Package
----------------------------------------------------------------------------------------------------

The mod config system operates through a single package that is registered. Below is the simplest code required to get a mod's name into the mod config list:

.. code-block:: lua

    -- Define our mod config package. For now, there's nothing interesting.
    local modConfigPackage = {}

    -- The callback to create the mod config GUI when our mod was clicked.
    function modConfigPackage.onCreate(container)
        container:createLabel({ text = "Hello world!" })
    end

    -- When the mod config menu is ready to start accepting registrations, register this mod.
    local function registerModConfig()
        mwse.registerModConfig("My Awesome Mod", modConfigPackage)
    end
    event.register("modConfigReady", registerModConfig)

After loading up the game, you should see "My Awesome Mod" in the mod config menu, with a single "Hello world!" in its configuration pane.


Handling Close State
----------------------------------------------------------------------------------------------------

It may be desirable to put off saving config options until after the close button has been clicked, or until after the user switched to a new mod. The optional ``modConfigPackage.onClose`` callback is called in both cases.

.. code-block:: lua

    -- The callback to do any cleanup needed when our menu is about to be destroyed.
    function modConfigPackage.onClose(container)
        tes3.messageBox("Goodbye!")
    end


Hiding from the Config Menu
----------------------------------------------------------------------------------------------------

It may become desirable to hide a mod from the config menu. For example, you may not wish it to be displayed until after the player is in-game if settings are stored in the save game file instead of another file. This can be done by setting the ``modConfigPackage.hidden`` field to ``true``. In the below example, we'll hide the mod from the config menu until the game has loaded.

.. code-block:: lua

    local modConfigPackage = { hidden = true }

    local function enableModConfigOnLoaded()
        modConfigPackage.hidden = false
    end
    event.register("loaded", enableModConfigOnLoaded)
