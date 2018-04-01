
tes3.getDataHandler
========================================================

**Parameters:**

- *None*

**Returned:**

- ``dataHandler`` **dataHandler**: The core `dataHandler`_ object.

One of the main functions to get core game structures. The others are `tes3.getGame()`_ and `tes3.getWorldController()`_.

Examples
--------------------------------------------------------

.. code-block:: lua

  -- Show the central grid x/y.
  local dataHandler = tes3.getDataHandler()
  print("Grid center: " .. dataHandler.centralGridX .. ", " .. dataHandler.centralGridY)

.. _`dataHandler`: ../../type/tes3/dataHandler.html
.. _`tes3.getGame()`: getGame.html
.. _`tes3.getWorldController()`: getWorldController.html
