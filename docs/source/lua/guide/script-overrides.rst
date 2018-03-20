
Script Overrides
========================================================

This guide will help you through creating the most basic Lua script. This type of script will be executed whenever a normal Morrowind script would run, and can read and write the script's variables.

Create MW Script
--------------------------------------------------------

To create a Lua script that will run every frame, like a normal Morrowind script, start off by creating your vanilla script. Open up the .esp file in the Morrowind Construction Set or MWEdit.

Add a new script, and create its contents as normal:

.. code-block:: text
  
  Begin TestLuaScript

  long sharedVariable

  MessageBox "Something went wrong! This message box should never be shown."
  StopScript "TestLuaScript"

  End

There are a few things that are important here:

1. The script name *TestLuaScript* is important and must match your Lua script name.

2. Any actual script commands will never be executed by the script. In this case, the ``MessageBox`` will never be called if the Lua script is valid.

3. Variables declared by the script are exposed to Lua. This is useful for cross-talk between normal Morrowind scripts and Lua scripts. No script data is automatically saved, and these variables are one way to persist data through saves.

Create Lua File
--------------------------------------------------------

With a basic Morrowind script created, we can now create an override for it. When the game is initially loading, Morrowind Script Extender locates any Lua files that match the name of loading scripts.

To cause a Lua file to execute instead of the vanilla Morrowind script, place a Lua file in the *Data Files\\MWSE\\lua* folder. The name of the file must exactly match the name of the script. So for to overwrite our script defined above, we would need to create *Data Files\\MWSE\\lua\\TestLuaScript.lua*.

The contents of the file should begin with the following template:

.. code-block:: lua

  local this = LuaScript.new()
  
  -- Called once, when the script has been hooked into the system.
  -- This happens before the main menu is reached.
  function this:initialized()
      
  end
  
  -- Called every time the mwscript would normally execute.
  function this:execute()
      print("I ran!")

      return false
  end
  
  return this

And that's it! Calling ``StartScript TestLuaScript`` from the console will write "I ran!" to the MWSE log file then stop execution. If you want your script to run every frame, either ``return true`` or do not return a specific value (e.g. omit ``return`` entirely).