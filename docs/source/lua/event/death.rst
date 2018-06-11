
death
========================================================

This event triggers when an actor dies.

.. note:: See the `Event Guide`_ for more information on event data, return values, and filters.

.. warning:: With the Morrowind Code Patch, this event doesn't trigger until after the death animation has finished playing.

Event Data
--------------------------------------------------------

mobile
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`tes3mobileActor`_. Read-only. The actor that has died.

reference
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`tes3reference`_. Read-only. A shortcut to the reference of **mobile**.

Filter
--------------------------------------------------------
This event may be filtered by **reference**.


.. _`Event Guide`: ../guide/events.html

.. _`tes3mobileActor`: ../type/tes3/mobileActor.html
.. _`tes3reference`: ../type/tes3/reference.html