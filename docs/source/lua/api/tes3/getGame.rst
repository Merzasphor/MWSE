
tes3.getGame
========================================================

**Parameters:**

- *None*

**Returned:**

- ``game`` **game**: The core `game`_ object.

One of the main functions to get core game structures. The others are `tes3.getDataHandler()`_ and `tes3.getWorldController()`_.

Examples
--------------------------------------------------------

.. code-block:: lua

  -- Disable screenshots.
  local game = tes3.getGame()
  game.screenShotsEnabled = false

.. _`game`: ../../type/tes3/game.html
.. _`tes3.getDataHandler()`: getDataHandler.html
.. _`tes3.getWorldController()`: getWorldController.html
