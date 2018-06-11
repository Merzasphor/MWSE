
uiShowRestMenu
========================================================

The **uiShowRestMenu** event is raised when the rest menu is about to be displayed. It allows the callback to change if sleeping is allowed, or to prevent the UI from showing at all.

.. note:: See the `Event Guide`_ for more information on event data, return values, and filters.


Event Data
--------------------------------------------------------

allowRest
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Boolean`_. ``true`` if the player is allowed to sleep (determined primarily from the cell flags), or ``false`` if they must wait instead. This value can be modified. 

scripted
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Boolean`_. Read-only. This value is ``true`` when the menu is shown from using the ``ShowRestMenu`` or equivalent function.


Filter
--------------------------------------------------------
This event does not support filtering.


.. _`Event Guide`: ../guide/events.html

.. _`Boolean`: ../type/lua/boolean.html
