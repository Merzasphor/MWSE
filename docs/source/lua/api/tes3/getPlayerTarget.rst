
tes3.getPlayerTarget
========================================================

**Parameters:**

- *None*

**Returned:**

- ``reference`` **reference**: A `reference`_ of what the player is looking at, or ``nil``.

This function is used to see what the player is looking at. Unlike a real raycast, this does not work in all circumstances. As a general rule, it will return the reference if the information box is shown when it is looked at.

Examples
--------------------------------------------------------

.. code-block:: lua

  -- Show the ID of what the player is looking at.
  local target = tes3.getPlayerTarget()
  if (target) then
      print(target.object.id)
  end

.. _`reference`: ../../type/tes3/reference.html
