
tes3.getPlayerRef
========================================================

**Parameters:**

- *None*

**Returned:**

- ``reference`` **reference**: A `reference`_ to the player.

Returns a reference to the player.

Examples
--------------------------------------------------------

.. code-block:: lua

  -- Print the player's name to the log.
  local player = tes3.getPlayerRef()
  mwse.log("Player's name: %s", player.object.name)

.. _`reference`: ../../type/tes3/reference.html
