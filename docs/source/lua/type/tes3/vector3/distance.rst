
distance
========================================================

Calculates the distance to another `Vector3`_.

.. code-block:: lua

    vector:distance(secondVector)

Return Value
--------------------------------------------------------

`Number`_. The result of the operation.


Parameters
--------------------------------------------------------

Operand (`Vector3`_)
    The second vector to get the distance to.


Example
--------------------------------------------------------

.. code-block:: lua

    -- Get the player position.
    local playerPos = tes3.getPlayerRef().position

    -- Get Galbedir's position.
    local galbedirPos = tes3.getReference("galbedir").position

    -- Print the distance to Galbedir.
    local distance = playerPos:distance(galbedirPos)
    mwse.log("Distance to Galbedir: %f", distance)


.. _`Number`: ../../lua/number.html

.. _`Vector3`: ../vector3.html
