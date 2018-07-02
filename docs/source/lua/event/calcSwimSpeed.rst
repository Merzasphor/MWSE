
calcSwimSpeed
====================================================================================================

One of the movement events, **calcSwimSpeed** is used when calculating the movement speed while in water.

The movement event flow is described below:

- Swimming: `calcWalkSpeed`_ -> **calcSwimSpeed** -> `calcMoveSpeed`_
- Swimming (while running): `calcWalkSpeed`_ -> **calcSwimSpeed** -> `calcSwimRunSpeed`_ -> `calcMoveSpeed`_

.. note:: See the `Event Guide`_ for more information on event data, return values, and filters.


Event Data
----------------------------------------------------------------------------------------------------

mobile
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Mobile Actor`_. The mobile actor whose speed is being calculated.

reference
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Reference`_. **mobile**'s related reference. The event is filtered by this reference.

speed
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Number`_. The previous speed calculated, starting with the base engine values. This value is modifiable.

type
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
`Number`_. The type of movement that was calculated. This is always 3 for this event.


Filter
----------------------------------------------------------------------------------------------------
This event may be filtered by **reference**.


.. _`calcMoveSpeed`: calcMoveSpeed.html
.. _`calcWalkSpeed`: calcWalkSpeed.html
.. _`calcSwimSpeed`: calcSwimSpeed.html
.. _`calcSwimRunSpeed`: calcSwimRunSpeed.html
.. _`calcFlySpeed`: calcFlySpeed.html

.. _`Event Guide`: ../guide/events.html

.. _`Number`: ../type/lua/number.html

.. _`Mobile Actor`: ../type/tes3/mobileActor.html
.. _`Reference`: ../type/tes3/reference.html
