
Action Data
========================================================

This represents an action being taken by a `MobileCreature`_, `MobileNPC`_, or `MobilePlayer`_.


Properties
--------------------------------------------------------

aiBehaviorState
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Number`_. The behavior state of the action.

===== =========
Value Behavior
===== =========
0     Hello
2     Idle
3     Attack
4     Avoid
6     Flee
8     Walk
12    Greet
255   Undecided
===== =========

animationAttackState
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Number`_.

.. warning:: This field still needs research. Please feel free to play with it, and modify the documentation.

attackDirection
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Number`_. When attacking, the direction swung with the weapon. This shows if the actor was thrusting, swinging, or chopping.

attackSwing
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Number`_. When attacking, this value represents how much the weapon has been pulled back. The value ranges from [0.0 - 1.0].

currentAnimationGroup
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Number`_.

.. warning:: This field still needs research. Please feel free to play with it, and modify the documentation.

hitTarget
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`MobileCreature`_, `MobileNPC`_, or `MobilePlayer`_.

.. warning:: This field still needs research. Please feel free to play with it, and modify the documentation.

lastBarterHoursPassed
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Number`_.

.. warning:: This field still needs research. Please feel free to play with it, and modify the documentation.

nockedProjectile
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Weapon`_. The currently knocked projectile the associated actor is using.

stolenFrom
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Faction`_ or `NPC`_.

.. warning:: This field still needs research. Please feel free to play with it, and modify the documentation.

target
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`MobileCreature`_, `MobileNPC`_, or `MobilePlayer`_.

.. warning:: This field still needs research. Please feel free to play with it, and modify the documentation.

physicalDamage
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Number`_. When attacking, this is the value of the weapon damage that was rolled. This value doesn't take into account the actor's strength, or other additional damage.

walkDestination
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Vector3`_. If moving to a location, this is the position to be walked to.


.. _`Boolean`: ../lua/boolean.html
.. _`Number`: ../lua/number.html
.. _`String`: ../lua/string.html
.. _`Table`: ../lua/table.html

.. _`Faction`: faction.html
.. _`MobileCreature`: mobileCreature.html
.. _`MobileNPC`: mobileNPC.html
.. _`MobilePlayer`: mobileCreature.html
.. _`NPC`: npc.html
.. _`Weapon`: weapon.html
.. _`Vector3`: vector3.html

.. _`Object Type`: ../../../mwscript/references.html#object-types
