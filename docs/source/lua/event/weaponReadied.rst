
weaponReadied
====================================================================================================

This event is called when a weapon is readied, and pairs with the `weaponUnreadied`_ event. It can be used to reliably tell if a specific weapon is readied for attack.

.. attention:: This does not necessarily mean that the animation state has changed for the first time.

.. note:: See the `Event Guide`_ for more information on event data, return values, and filters.


Event Data
----------------------------------------------------------------------------------------------------

reference
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Reference`_. The reference associated with the change in readied weapon.

weaponStack
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Equipment Stack`_. The bundle that contains the newly readied weapon and its associated data.


Filter
----------------------------------------------------------------------------------------------------
This event may be filtered by **reference**.


.. _`Event Guide`: ../guide/events.html

.. _`weaponUnreadied`: weaponUnreadied.html

.. _`Reference`: ../type/tes3/reference.html