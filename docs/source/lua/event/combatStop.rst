
combatStop
========================================================

The **combatStop** event occurs when an actor is about to leave combat. This event allows scripts to prevent combat from stopping.

.. note:: See the `Event Guide`_ for more information on event data, return values, and filters.


Event Data
--------------------------------------------------------

actor
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`tes3mobileActor`_. Read-only. The mobile actor who is exiting combat.


Filter
--------------------------------------------------------
This event can be filtered on **actor**'s associated `reference`_.


.. _`Event Guide`: ../guide/events.html

.. _`tes3mobileActor`: ../type/tes3/mobileActor.html
.. _`reference`: ../type/tes3/reference.html
