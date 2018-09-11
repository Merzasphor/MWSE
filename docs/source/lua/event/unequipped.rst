
unequipped
========================================================

The **unequipped** event fires after an actor has successfully equipped an item.

.. note:: See the `Event Guide`_ for more information on event data, return values, and filters.


Event Data
--------------------------------------------------------

actor
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`tes3actor`_. Read-only. The actor that has unequipped the item.

mobile
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`tes3mobileActor`_. Read-only. The mobile actor that has unequipped the item.

reference
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`tes3reference`_. Read-only. **actor**'s associated reference.

item
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`tes3baseObject`_. Read-only. The object being unequipped.

itemData
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`tes3itemData`_. Read-only. The item data of **item**.


Filter
--------------------------------------------------------
This event does not support filters.


.. _`Event Guide`: ../guide/events.html
.. _`tes3actor`: ../type/tes3/actor.html
.. _`tes3mobileActor`: ../type/tes3/mobileActor.html
.. _`tes3reference`: ../type/tes3/reference.html
.. _`tes3baseObject`: ../type/tes3/baseObject.html
.. _`tes3itemData`: ../type/tes3/itemData.html
