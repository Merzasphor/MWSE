
calcRestInterrupt
====================================================================================================

This event is called when the player is about to start resting. The **hour** and **count** of creatures can be modified, or disabled.

.. note:: See the `Event Guide`_ for more information on event data, return values, and filters.


Event Data
----------------------------------------------------------------------------------------------------

hour
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Number`_. The hour of rest remaining that the rest will be interrupted on.

count
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Number`_. The number of creatures interrupting rest. Set to 0 to prevent a spawn.


.. _`Event Guide`: ../guide/events.html

.. _`Number`: ../type/lua/number.html
