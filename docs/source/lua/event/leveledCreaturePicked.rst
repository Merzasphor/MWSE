
leveledCreaturePicked
====================================================================================================

This event is called after any leveled creature list is resolved, either from normal gameplay or ``leveledCreature:pickFrom()``. The event may be filtered by its **list**, and its **pick** can be overwritten. While this event allows for customization, the leveled list may be altered directly as well.

.. note:: See the `Event Guide`_ for more information on event data, return values, and filters.

Event Data
----------------------------------------------------------------------------------------------------

list
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`Leveled Creature`_. Read-only. The list responsible for creating a pick.

pick
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Creature`_. The result of the pick by vanilla mechanism. This can be modified to change the result to something else.

Filter
----------------------------------------------------------------------------------------------------
This event may be filtered by **list**.


.. _`Event Guide`: ../guide/events.html

.. _`Leveled Creature`: ../type/tes3/leveledCreature.html
.. _`Creature`: ../type/tes3/creature.html