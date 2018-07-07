
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

resting
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Boolean`_. If ``true``, the player is attempting to rest, as opposed to wait.

waiting
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Boolean`_. If ``true``, the player is attempting to wait, as opposed to rest.


.. _`Event Guide`: ../guide/events.html

.. _`Boolean`: ../type/lua/boolean.html
.. _`Number`: ../type/lua/number.html
