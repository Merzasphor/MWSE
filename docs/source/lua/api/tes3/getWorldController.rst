
tes3.getWorldController
========================================================

**Parameters:**

- *None*

**Returned:**

- ``worldController`` **worldController**: The core `worldController`_ object.

One of the main functions to get core game structures. The others are `tes3.getDataHandler()`_ and `tes3.getGame()`_.

Examples
--------------------------------------------------------

.. code-block:: lua

  -- Show the current difficulty.
  local worldController = tes3.getWorldController()
  print("Difficulty: " .. worldController.difficulty)

.. _`worldController`: ../../type/tes3/worldController.html
.. _`tes3.getDataHandler()`: getDataHandler.html
.. _`tes3.getGame()`: getGame.html
