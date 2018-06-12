
projectileHitActor
========================================================

The **projectileHitActor** event fires when a projectile collides with an actor.

.. note:: See the `Event Guide`_ for more information on event data, return values, and filters.


Event Data
--------------------------------------------------------

mobile
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`tes3mobileProjectile`_. Read-only. The mobile projectile that is expiring.

target
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`tes3reference`_. Read-only. Reference to the actor that was hit.

firingReference
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`tes3reference`_. Read-only. Reference to the actor that fired the projectile.

firingWeapon
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`tes3weapon`_. Read-only. The weapon that fired the projectile.


Filter
--------------------------------------------------------
This event may be filtered by **target**.


.. _`Event Guide`: ../guide/events.html
.. _`tes3mobileProjectile`: ../type/tes3/mobileProjectile.html
.. _`tes3reference`: ../type/tes3/reference.html
.. _`tes3weapon`: ../type/tes3/weapon.html
