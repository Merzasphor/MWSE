
mwscript.getDetected
====================================================================================================

**Parameters:**

All parameters are passed via a table.

- ``tes3reference`` **reference**: The actor to perform detection on.
- ``tes3reference`` **target**: The actor to check detection for.

**Returned:**

- ``Boolean``: True if the **target** is detected by **reference**.

This functions wraps around the vanilla ``GetDetected`` function.

Examples
----------------------------------------------------------------------------------------------------

Detect if Galbedir detects the player
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: lua

  local player = tes3.getPlayerRef()
  local galbedir = tes3.getReference("galbedir")
  if (mwscript.getDetected({ reference = galbedir, target = player })) then
      tes3.messageBox("Galbedir detects the player!")
  end

.. _`Boolean`: ../../type/lua/boolean.html

.. _`tes3reference`: ../../type/tes3/reference.html
