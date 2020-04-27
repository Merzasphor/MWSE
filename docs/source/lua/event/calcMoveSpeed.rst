calcMoveSpeed
====================================================================================================

This event is called when an actor’s movement speed is calculated. The event allows modification of this value, to dehardcode actor movement speeds.
Invoked after all other movement speed events are finished.

The movement event flow is described below:

- Walking: `calcWalkSpeed`_ -> **calcMoveSpeed**
- Running: `calcWalkSpeed`_ -> `calcRunSpeed`_ -> **calcMoveSpeed**
- Swimming: `calcWalkSpeed`_ -> `calcSwimSpeed`_ -> **calcMoveSpeed**
- Swimming (while running): `calcWalkSpeed`_ -> `calcSwimSpeed`_ -> `calcSwimRunSpeed`_ -> **calcMoveSpeed**
- Flying: `calcFlySpeed`_ -> **calcMoveSpeed**

Event Data
----------------------------------------------------------------------------------------------------

speed
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`number`_. The previous speed calculated, starting with the base engine values.

mobile
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

tes3mobileActor. Read-only. The mobile actor whose speed is being calculated.

reference
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

tes3reference. Read-only. mobile’s related reference.

type
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

`number`_. Read-only. The type of movement that was calculated. This is always 0 for this event.

Examples
----------------------------------------------------------------------------------------------------

20% Faster Player Movement
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: lua

    local function onCalcMoveSpeed(e)
        if (e.reference == tes3.player) then
            e.speed = e.speed * 1.2
        end
    end
    event.register(tes3.event.calcMoveSpeed, onCalcMoveSpeed)


.. _`calcWalkSpeed`: ../../lua/event/calcWalkSpeed.html
.. _`calcSwimRunSpeed`: ../../lua/event/calcSwimRunSpeed.html
.. _`calcFlySpeed`: ../../lua/event/calcFlySpeed.html
.. _`calcRunSpeed`: ../../lua/event/calcRunSpeed.html
.. _`calcSwimSpeed`: ../../lua/event/calcSwimSpeed.html
.. _`bool`: ../../lua/type/boolean.html
.. _`nil`: ../../lua/type/nil.html
.. _`table`: ../../lua/type/table.html
.. _`string`: ../../lua/type/string.html
.. _`number`: ../../lua/type/number.html
.. _`boolean`: ../../lua/type/boolean.html
.. _`function`: ../../lua/type/function.html
