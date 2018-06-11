
combatStart
========================================================

The **combatStart** event occurs when combat is about to begin between two actors. This event allows scripts to prevent combat from starting.

.. note:: See the `Event Guide`_ for more information on event data, return values, and filters.


Event Data
--------------------------------------------------------

actor
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`tes3mobileActor`_. Read-only. The mobile actor who is entering combat.

target
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`tes3mobileActor`_. Read-only. The mobile actor who combat is being triggered against.


Filter
--------------------------------------------------------
This event can be filtered on **actor**'s associated `reference`_.


.. _`Event Guide`: ../guide/events.html

.. _`tes3mobileActor`: ../type/tes3/mobileActor.html
.. _`reference`: ../type/tes3/reference.html
