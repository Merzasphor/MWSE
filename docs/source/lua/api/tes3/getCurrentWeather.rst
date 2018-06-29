
tes3.getCurrentWeather
====================================================================================================

**Parameters:**

- *None*

**Returned:**

- ``weather`` **weather**: The `weather`_ from the player's current `region`_.

Returns the current weather in the region that the player is in, or ``nil`` if either the player's region or its weather couldn't be determined.


Examples
----------------------------------------------------------------------------------------------------

.. code-block:: lua

  -- Print the current weather index to the log.
  local weather = tes3.getCurrentWeather()
  mwse.log("Current weather: %d", weather.index)


.. _`region`: ../../type/tes3/region.html
.. _`weather`: ../../type/tes3/weather.html
