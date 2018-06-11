
damaged
========================================================

The **damaged** event triggers after an actor has been damaged.

.. note:: See the `Event Guide`_ for more information on event data, return values, and filters.


Event Data
--------------------------------------------------------

damage
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Number`_. Read-only. The base amount of damage done.

mobile
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`tes3mobileActor`_. Read-only. The mobile actor that took damage.

reference
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`tes3reference`_. Read-only. **mobile**'s associated reference.


Filter
--------------------------------------------------------
This event can be filtered on **reference**.


.. _`Event Guide`: ../guide/events.html

.. _`Number`: ../type/lua/number.html

.. _`tes3mobileActor`: ../type/tes3/mobileActor.html
.. _`tes3reference`: ../type/tes3/reference.html
