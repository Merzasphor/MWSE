
bodyPartsUpdated
========================================================

The **bodyPartsUpdated** event fires after an actor's body part models have been updated. This occurs on actor load and on equipment change (armor or clothing only). For the player, the event triggers for the player's first person and third person reference separately.

.. note:: See the `Event Guide`_ for more information on event data, return values, and filters.


Event Data
--------------------------------------------------------

mobile
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`tes3mobileActor`_. Read-only. The mobile actor that has equipped the item.

reference
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`tes3reference`_. Read-only. **actor**'s associated reference.


Filter
--------------------------------------------------------
This event does not support filters.


.. _`Event Guide`: ../guide/events.html
.. _`tes3mobileActor`: ../type/tes3/mobileActor.html
.. _`tes3reference`: ../type/tes3/reference.html
