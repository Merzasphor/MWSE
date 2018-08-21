
leveledItemPicked
====================================================================================================

This event is called after any leveled item list is resolved, either from normal gameplay or ``leveledItem:pickFrom()``. The event may be filtered by its **list**, and its **pick** can be overwritten. While this event allows for customization, the leveled list may be altered directly as well.

.. note:: See the `Event Guide`_ for more information on event data, return values, and filters.

Event Data
----------------------------------------------------------------------------------------------------

list
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`Leveled Item`_. Read-only. The list responsible for creating a pick.

pick
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*Item*. The result of the pick by vanilla mechanism. This can be modified to change the result to something else.

Filter
----------------------------------------------------------------------------------------------------
This event may be filtered by **list**.


.. _`Event Guide`: ../guide/events.html

.. _`Leveled Item`: ../type/tes3/leveledItem.html