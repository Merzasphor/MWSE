
tes3.getRegion
====================================================================================================

**Parameters:**

- *None*

**Returned:**

- ``region`` **region**: The `region`_ the player is in.

Returns the region that the player is currently residing in.


Examples
----------------------------------------------------------------------------------------------------

.. code-block:: lua

  -- Print the player's region to the log.
  local region = tes3.getRegion()
  mwse.log("Player's region: %s", region.name)


.. _`region`: ../../type/tes3/region.html
