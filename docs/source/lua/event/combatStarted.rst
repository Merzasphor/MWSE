
combatStarted
========================================================

The **combatStarted** event occurs after combat has began between two actors. This event is preceded by the `combatStart`_ event.

.. note:: See the `Event Guide`_ for more information on event data, return values, and filters.


Event Data
--------------------------------------------------------

actor
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`tes3mobileActor`_. Read-only. The mobile actor who has entered combat.

target
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`tes3mobileActor`_. Read-only. The mobile actor who combat is being triggered against.


Filter
--------------------------------------------------------
This event can be filtered on **actor**'s associated `reference`_.


.. _`Event Guide`: ../guide/events.html

.. _`tes3mobileActor`: ../type/tes3/mobileActor.html
.. _`reference`: ../type/tes3/reference.html

.. _`combatStart`: combatStart.html
