
tes3.getPlayerCell
========================================================

**Parameters:**

- *None*

**Returned:**

- ``cell`` **cell**: The `cell`_ the player is currently in.

Returns the current cell the player is in.

Examples
--------------------------------------------------------

.. code-block:: lua

  -- Show the name of the player's cell.
  local cell = tes3.getPlayerCell()
  print(cell.id)

.. _`cell`: ../../type/tes3/cell.html
