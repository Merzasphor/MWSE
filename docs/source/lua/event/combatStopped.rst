
combatStopped
========================================================

The **combatStopped** event occurs after an actor has left combat. This event is preceded by the `combatStop`_ event.

.. note:: See the `Event Guide`_ for more information on event data, return values, and filters.


Event Data
--------------------------------------------------------

actor
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`tes3mobileActor`_. Read-only. The mobile actor who has left combat.


Filter
--------------------------------------------------------
This event can be filtered on **actor**'s associated `reference`_.


.. _`Event Guide`: ../guide/events.html

.. _`tes3mobileActor`: ../type/tes3/mobileActor.html
.. _`reference`: ../type/tes3/reference.html

.. _`combatStop`: combatStop.html
