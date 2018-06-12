
projectileExpire
========================================================

The **projectileExpire** event fires just prior to a fired projectile expiring.

.. note:: See the `Event Guide`_ for more information on event data, return values, and filters.


Event Data
--------------------------------------------------------

mobile
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`tes3mobileProjectile`_. Read-only. The mobile projectile that is expiring.

firingReference
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`tes3reference`_. Read-only. Reference to the actor that fired the projectile.

firingWeapon
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`tes3weapon`_. Read-only. The weapon that fired the projectile.


Filter
--------------------------------------------------------
This event may be filtered by **firingReference**.


.. _`Event Guide`: ../guide/events.html
.. _`tes3mobileProjectile`: ../type/tes3/mobileProjectile.html
.. _`tes3reference`: ../type/tes3/reference.html
.. _`tes3weapon`: ../type/tes3/weapon.html
