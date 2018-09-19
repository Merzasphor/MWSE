
menuEnter
========================================================

The **menuEnter** event fires when the player enters menu mode.

.. note:: See the `Event Guide`_ for more information on event data, return values, and filters.


Event Data
--------------------------------------------------------

menuMode
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Boolean`_. Read-only. Always true for this event. This parameter is only useful when registering the same callback for menuEnter and menuExit events.

menu
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`tes3uiBlock`_. Read-only. The new top-level menu.


Filter
--------------------------------------------------------
This event can be filtered using **menu**'s ``.name`` property.


.. _`Event Guide`: ../guide/events.html

.. _`Boolean`: ../type/lua/boolean.html
.. _`tes3uiBlock`: ../type/tes3/tes3uiBlock.html
