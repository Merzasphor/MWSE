
calcMoveSpeed
====================================================================================================

This event is called when an actor's movement speed is calculated. The event allows modification of this value, to dehardcode actor movement speeds. Invoked after all other movement speed events are finished.

The movement event flow is described below:

- Walking: `calcWalkSpeed`_ -> **calcMoveSpeed**
- Running: `calcWalkSpeed`_ -> `calcRunSpeed`_ -> **calcMoveSpeed**
- Swimming: `calcWalkSpeed`_ -> `calcSwimSpeed`_ -> **calcMoveSpeed**
- Swimming (while running): `calcWalkSpeed`_ -> `calcSwimSpeed`_ -> `calcSwimRunSpeed`_ -> **calcMoveSpeed**
- Flying: `calcFlySpeed`_ -> **calcMoveSpeed**

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
`Number`_. The type of movement that was calculated. This is always 0 for this event.


Filter
----------------------------------------------------------------------------------------------------
This event may be filtered by **reference**.


Examples
----------------------------------------------------------------------------------------------------

20% Faster Player Movement
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

This example increases the player's movement speed in all forms by 20%, without mechanically adjusting their speed stat.

.. code-block:: lua

    local function onCalcMoveSpeed(e)
        if (e.reference == tes3.player) then
            e.speed = e.speed * 1.2
        end
    end
    event.register("calcMoveSpeed", onCalcMoveSpeed)


.. _`Event Guide`: ../guide/events.html

.. _`calcWalkSpeed`: calcWalkSpeed.html
.. _`calcRunSpeed`: calcRunSpeed.html
.. _`calcSwimSpeed`: calcSwimSpeed.html
.. _`calcSwimRunSpeed`: calcSwimRunSpeed.html
.. _`calcFlySpeed`: calcFlySpeed.html

.. _`Number`: ../type/lua/number.html

.. _`Mobile Actor`: ../type/tes3/mobileActor.html
.. _`Reference`: ../type/tes3/reference.html
