
equip
========================================================

The **equip** event fires when an actor is about to equip an item. This event allows scripts to block equipping.

.. note:: See the `Event Guide`_ for more information on event data, return values, and filters.


Event Data
--------------------------------------------------------

reference
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`tes3reference`_. Read-only. A reference to the mobile actor that is equipping the item.

item
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`tes3baseObject`_. Read-only. The object being equipped.

itemData
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`tes3itemData`_. Read-only. The item data of `item`.


Filter
--------------------------------------------------------
This event may be filtered by `reference`.


.. _`Event Guide`: ../guide/events.html
.. _`tes3reference`: ../type/tes3/reference.html
.. _`tes3baseObject`: ../type/tes3/baseObject.html
.. _`tes3itemData`: ../type/tes3/itemData.html
