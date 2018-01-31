
xGetMCPFeatureState
========================================================

:Parameters:

    - ``long`` **id**: Identifier for the MCP feature.

:Returned:

    - ``short`` **state**: 1 if the feature is enabled, 0 if it is disabled, or -1 if MWSE couldn't determine the MCP installation state.

This function can be used to attempt to ensure that the user has the correct `Morrowind Code Patch <https://www.nexusmods.com/morrowind/mods/19510/?>`_ features enabled.

.. note:: The **id** parameter comes from **mcpatch\\describe.json**. For example, 137 matches with the *Slowfall Overhaul* component.

.. warning:: This functions depends on the user not deleting their **mcpatch\\installed** file. If the user doesn't have this file (because they deleted it or don't have the MCP installed), this function returns a value of -1.


Example
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

::

  begin DetectPickPocketOverhaul
  
  short state

  setx state to xGetMCPFeatureState 77

  if (state) then
      MessageBox "Pickpocket overhaul is enabled in MCP."
  endif
  
  end
