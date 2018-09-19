
weaponUnreadied
====================================================================================================

This event is called when a weapon is no longer readied, and pairs with the `weaponReadied`_ event. It can be used to reliably tell if a specific weapon is readied for attack.

.. attention:: This does not necessarily mean that the animation state has changed for the first time. If an actor equips a weapon while having their hands up to attack with, the event will fire for the new weapon.

.. note:: See the `Event Guide`_ for more information on event data, return values, and filters.


Event Data
----------------------------------------------------------------------------------------------------

reference
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Reference`_. The reference associated with the change in readied weapon.


Filter
----------------------------------------------------------------------------------------------------
This event may be filtered by **reference**.


.. _`Event Guide`: ../guide/events.html

.. _`weaponReadied`: weaponReadied.html

.. _`Equipment Stack`: ../type/tes3/equipmentStack.html
.. _`Reference`: ../type/tes3/reference.html