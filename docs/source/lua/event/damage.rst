
damage
========================================================

The **damage** event triggers before an actor is damaged. The damage value can be modified, or the damage can be prevented completely by blocking the event.

.. note:: See the `Event Guide`_ for more information on event data, return values, and filters.


Event Data
--------------------------------------------------------

damage
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Number`_. The base amount of damage done.

mobile
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`tes3mobileActor`_. Read-only. The mobile actor that is taking damage.

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
