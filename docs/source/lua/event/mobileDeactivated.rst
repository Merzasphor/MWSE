
mobileDeactivated
====================================================================================================

This event is called when a `Mobile Actor`_ is deactivated. 

Typically this happens when transitioning through cells. When the player enters a cell, the `mobileActivated`_ event will fire for each new actor. When the player leaves the cell, the **mobileActivated** event is called.

.. note:: See the `Event Guide`_ for more information on event data, return values, and filters.


Event Data
----------------------------------------------------------------------------------------------------

reference
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Reference`_. The reference that the mobile has been activated for.


Filter
----------------------------------------------------------------------------------------------------
This event may be filtered by **reference**.


.. _`Event Guide`: ../guide/events.html

.. _`mobileActivated`: mobileActivated.html

.. _`Mobile Actor`: ../type/tes3/mobileActor.html
.. _`Reference`: ../type/tes3/reference.html