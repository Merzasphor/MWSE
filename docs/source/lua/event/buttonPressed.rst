
buttonPressed
========================================================

The **buttonPressed** event is unique in that it is invoked only when using `tes3.messageBox`_ to present buttons to the player.

.. note:: See the `Event Guide`_ for more information on event data, return values, and filters.


Event Data
--------------------------------------------------------

button
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Number`_. Read-only. The index of the button pressed.

.. note:: The first button is button 0, not button 1.


Filter
--------------------------------------------------------
This event does not support filters.


.. _`Event Guide`: ../guide/events.html

.. _`Number`: ../type/lua/number.html
.. _`tes3.messageBox`: ../api/tes3/messageBox.html
